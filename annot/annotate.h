
//    --------------------------------------------------------------------
//
//    This file is part of Luna.
//
//    LUNA is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Luna is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Luna. If not, see <http://www.gnu.org/licenses/>.
//
//    Please see LICENSE.txt for more details.
//
//    --------------------------------------------------------------------


#ifndef __ANNOT_ANNOTATE_H__
#define __ANNOT_ANNOTATE_H__

#include <map>
#include <set>
#include <string>
#include <vector>
#include "intervals/intervals.h"


typedef std::map<std::string,std::map<uint64_t,std::map<std::string,std::set<interval_t> > > > interval_map_t;


struct named_interval_t {
  interval_t i;
  std::string n;
  named_interval_t( const interval_t & i , const std::string & n )
    : i(i), n(n) { }
  bool operator<( const named_interval_t & rhs ) const
  {
    if ( i < rhs.i ) return true;
    if ( rhs.i < i ) return false;
    return n < rhs.n;
  }
};

struct edf_t;
struct annot_t;
struct param_t;
struct annotate_stats_t {
  
  annotate_stats_t()
  {
    nss.clear();
    nsa.clear();
    psa.clear();
    ns.clear();
    adist.clear();
    sdist.clear();
    ndist.clear();    
  }
  
  // seed-seed group counts
  std::map<std::string,double> nss;

  // seed-annot counts
  std::map<std::string,std::map<std::string,double> > nsa;

  // seed-annot proportion (of seeds overlapped by 1+ annot)
  std::map<std::string,std::set<interval_t> > psa;
  std::map<std::string,double> ns; // denom (# flat seeds)
   
  // seed-annot abs(dist)
  std::map<std::string,std::map<std::string,double> > adist;

  // seed-annot signed(dist)
  std::map<std::string,std::map<std::string,double> > sdist;

  // denominator for distance means
  std::map<std::string,std::map<std::string,double> > ndist;

};


struct annotate_t {
  
  // initiate from a single attached EDF/timeline 
  annotate_t( edf_t & edf , param_t & param );
  
  // initiate from a list of annotation files
  //  (with permutation done w/in each list)
  //  for command-line calls
  annotate_t( param_t & param );
  
  void set_options( param_t & param );
  
  void prep();
  
  void loop();

  annotate_stats_t eval();

  void shuffle();
  
  void output();
  

  //
  // param
  //

  bool midpoint;
  
  double flanking_sec;

  double window_sec;

  bool include_overlap_in_dist;
  
  double overlap_th;
  
  bool pool_channels;

  std::set<std::string> pool_channel_sets;

  std::set<std::string> aligned_permutes;
  
  bool ordered_groups;
  
  int nreps;

  std::set<std::string> fixed;

  std::map<std::string,double> flt_lwr, flt_upr;

  // annot class specific channel inc/exc [ annot -> chs ] 
  std::map<std::string,std::set<std::string> > chs_inc, chs_exc;
  
  void proc_chlist( const std::string & s , const bool );
  bool process_channel( const std::string & a , const std::string & ch );

  //
  // data
  //

  bool single_indiv_mode;
  
  edf_t * edf;
  
  uint64_t maxtp;
  
  std::set<std::string> sseeds, sannots, sbgs;

  double edge_sec;
  
  std::set<annot_t*> seeds, annots, bgs;

  // add new annotations (seed<_TAG>) depending on whether existing
  // seeds match or do not match one+ annots

  bool make_anew;
  std::string out_tag;
  bool out_include;
  int mcount; // must match at least this many 
  bool seed_nonseed; // show only seed-nonseed hits
  // track how many 'overlaps' a seed annot has
  std::map<named_interval_t,int> hits;
  void new_seeds();
  
  // includes ANNOT_CH formats (maps to events) 
  std::set<std::string> sachs; // Seed Annotation/CHannels
  std::set<std::string> achs; // All Annotation/CHannels
  std::map<std::string,std::pair<std::string,std::string> > achs_name_ch; // track originals
  
  // track indiv ID
  std::string iid;
  
  // main interval map
  //  indiv -> segment(start-point) -> annot -> events
  interval_map_t events;
  
  // for each segment, the offset --> size (i.e. map elements to 0... size on reading)
  std::map<std::string,std::map<uint64_t,uint64_t> > seg; // offset --> size 
  
  //
  // mask/breakpoints
  //
  
  std::set<uint64_t> brk;
  uint64_t tottp;
  
  //
  // accumulators
  //

  // seed-seed all overlaps (can be >2)
  // label is A,B,C, for group overlap
  std::map<std::string,double> obs;
  std::map<std::string,double> exp;
  std::map<std::string,double> expsq;
  std::map<std::string,double> pv;
  std::map<std::string,double> z;
  
  // seed-annot pairwise overlap counts
  std::map<std::string,std::map<std::string,double> > p_obs;
  std::map<std::string,std::map<std::string,double> > p_exp;
  std::map<std::string,std::map<std::string,double> > p_expsq;
  std::map<std::string,std::map<std::string,double> > p_pv;
  std::map<std::string,std::map<std::string,double> > p_z;

  // seed-annot proportion seeds spanned by 1+ annot
  std::map<std::string,double> prop_obs;
  std::map<std::string,double> prop_exp;
  std::map<std::string,double> prop_expsq;
  std::map<std::string,double> prop_pv;
  std::map<std::string,double> prop_z;

  // abs distance to nearest
  std::map<std::string,std::map<std::string,double> > absd_obs;
  std::map<std::string,std::map<std::string,double> > absd_exp;
  std::map<std::string,std::map<std::string,double> > absd_expsq;
  std::map<std::string,std::map<std::string,double> > absd_pv;
  std::map<std::string,std::map<std::string,double> > absd_z;
    
  // signed distance to nearest
  std::map<std::string,std::map<std::string,double> > sgnd_obs;
  std::map<std::string,std::map<std::string,double> > sgnd_exp;
  std::map<std::string,std::map<std::string,double> > sgnd_expsq;
  std::map<std::string,std::map<std::string,double> > sgnd_pv;
  std::map<std::string,std::map<std::string,double> > sgnd_z;

  // number of events included in the nearest-neighbour calcs
  std::map<std::string,std::map<std::string,double> > dn_obs;
  std::map<std::string,std::map<std::string,double> > dn_exp;

  //
  // helpers
  //

  // merge overlapping annots
  std::set<interval_t> flatten( const std::set<interval_t> & x );

  uint64_t total_duration( const std::set<interval_t> & x );
  
  bool place_interval( const interval_t & , uint64_t * ) const ;

  // which segment does this annotation /completely/ fall in? (or -1 if not )
  
  bool segment( const std::string & id , const interval_t & i , uint64_t * segoff ) const;

  // seed-seed enrichment group 
  std::map<std::string,double> pileup( const std::set<named_interval_t> & intervals ) const;
  std::string stringize( const std::set<named_interval_t> & ) const;
  
  // seed-annot stats calc
  void seed_annot_stats( const std::set<interval_t> & a , const std::string & astr ,
			 const std::set<interval_t> & b , const std::string & bstr ,
			 annotate_stats_t * r );
  
  // handle stats from orig/perms
  void observed( const annotate_stats_t & s ) ;
  void build_null( const annotate_stats_t & s ) ;

  
};


#endif