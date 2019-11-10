

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


#include "cmddefs.h"

#include "luna.h"
#include <iomanip>

extern globals global;

void cmddefs_t::init()
{

  /////////////////////////////////////////////////////////////////////////
  //
  // Document domains, commands, parameters, output tables and variables 
  //
  /////////////////////////////////////////////////////////////////////////


  //
  // base URL
  //

  url_root = "http://zzz.bwh.harvard.edu/luna/ref/";


  //
  // Domains
  //

  add_domain( "summ"     , "Summaries"       , "Basic summary commands" );
  add_domain( "annot"    , "Annotations"     , "Adding and displaying annotations" );
  add_domain( "expr"     , "Expressions"     , "Evaluating more advanced annotation-based expressions" );
  add_domain( "epoch"    , "Epochs"          , "Epoching signals and epoch-level annotations" );
  add_domain( "mask"     , "Masks"           , "Masking epochs based on annotations and other criteria" );
  add_domain( "manip"    , "Manipulations"   , "Manipulating signal data" );
  add_domain( "output"   , "Outputs"         , "Commands to output signals in different formats" );
  add_domain( "filter"   , "FIR filters"     , "FIR filter design and application" );
  add_domain( "artifact" , "Artifacts"       , "Artifacts detection/correction routines" );
  add_domain( "hypno"    , "Hypnograms"      , "Characterizations of hypnograms" );
  add_domain( "power"    , "Power spectra"   , "Power spectral density estimation" );
  add_domain( "spindles" , "Spindles and SO" , "Spindles and slow oscillations" );
  add_domain( "topo"     , "Cross-signal analyses"    , "Coherence and other topographical analyses" );
  add_domain( "cfc"      , "Cross-frequency coupling" , "Phase-amplitude and spindle/SO coupling" );
  add_domain( "misc"     , "Misc"           , "Misc. commands" );
  add_domain( "exp"      , "Experimental"   , "Experimental features: under heavy development, for internal use only" );

  
   

  /////////////////////////////////////////////////////////////////////////////////
  //
  // SUMMARIES
  //
  /////////////////////////////////////////////////////////////////////////////////


  //
  // DESC
  //

  add_cmd( "summ" , "DESC" , "Simple description of an EDF, sent to the console" );

  
  //
  // SUMMARY
  //

  add_cmd( "summ" , "SUMMARY" , "More verbose description, sent to the console" );


  //
  // HEADERS
  //
  
  add_cmd( "summ" , "HEADERS" , "Tabulate (channel-specific) EDF header information" );

  add_table( "HEADERS" , "." , "Basic EDF header information" );
  add_var( "HEADERS" , "." , "NR" , "Number of records" );
  add_var( "HEADERS" , "." , "NS" , "Number of signals/channels" );
  add_var( "HEADERS" , "." , "REC.DUR" , "Duration of each record (seconds)" );
  add_var( "HEADERS" , "." , "TOT.DUR.SEC" , "Total duration of EDF (seconds)" );
  add_var( "HEADERS" , "." , "TOT.DUR.HMS" , "Total duration of EDF (hh:mm:ss string)" );

  add_table( "HEADERS" , "CH" , "Per-channel header information" );
  add_var( "HEADERS" , "CH" , "DMAX" , "Digital max" );
  add_var( "HEADERS" , "CH" , "DMIN" , "Digital min" );
  add_var( "HEADERS" , "CH" , "PDIM", "Physical dimension" );
  add_var( "HEADERS" , "CH" , "PMAX", "Physical min" );
  add_var( "HEADERS" , "CH" , "PMIN", "Physical max" );
  add_var( "HEADERS" , "CH" , "SR", "Sample rate (Hz)" );


  //
  // TAG
  //

  add_cmd( "summ" , "TAG" , "Generic command to add a tag (level/factor) to the output" );  
  add_param( "TAG" , ""    , "RUN/L1" , "" , "Add tag with level L1 to factor RUN in output" );
  add_param( "TAG" , "tag" , "RUN/L1" , "" , "Identical to the above, but explicitly using the tag option" );


  //
  // STATS
  //

  add_cmd( "summ"   , "STATS" , "Basic signal statistics (min/max, mean, RMS, etc)" );
  add_param( "STATS" , "sig" , "C3,C4" , "" , "Restrict analysis to these channels" );
  add_param( "STATS" , "epoch" , "" , "" , "Calculate per-epoch statistics" );
  
  add_table( "STATS" , "CH" , "Whole-night, per-channel statistics, based on all epochs" );
  add_var( "STATS" , "CH" , "MIN" , "Signal minimum (from data, not EDF header)" );
  add_var( "STATS" , "CH" , "MAX" , "Signal maximum (from data, not EDF header)" );
  add_var( "STATS" , "CH" , "MEAN" , "Signal mean" );
  add_var( "STATS" , "CH" , "MEDIAN" , "Signal median" );
  add_var( "STATS" , "CH" , "RMS" , "Signal root mean square" );

  add_var( "STATS" , "CH" , "NE" ,  "Total number of epochs in record [epoch]" );
  add_var( "STATS" , "CH" , "NE1" , "Number of unmasked epochs actually used in calculations [epoch]" );
  add_var( "STATS" , "CH" , "MEDIAN.MEAN" , "Median of all per-epoch means [epoch]" );
  add_var( "STATS" , "CH" , "MEDIAN.MEDIAN" , "Median of all per-epoch medians [epoch]" );
  add_var( "STATS" , "CH" , "MEDIAN.RMS" , "Median of all per-epoch RMS [epoch]" );

  add_table( "STATS" , "CH,E" , "Per-epoch, per-channel statistics for unmasked epochs only" );
  add_var( "STATS" , "CH,E" , "MIN" , "Signal minimum (from data, not EDF header)" );
  add_var( "STATS" , "CH,E" , "MAX" , "Signal maximum (from data, not EDF header)" );
  add_var( "STATS" , "CH,E" , "MEAN" , "Signal mean" );
  add_var( "STATS" , "CH,E" , "MEDIAN" , "Signal median" );
  add_var( "STATS" , "CH,E" , "RMS" , "Signal root mean square" );

    
  /////////////////////////////////////////////////////////////////////////////////
  //
  // ANNOTATIONS
  //
  /////////////////////////////////////////////////////////////////////////////////
  
  //
  // --xml
  //

  add_cmd( "annot" , "--xml" , "Quickly view an NSRR XML annotation file" );


  //
  // ANNOTS
  //
  
  add_cmd( "annot" , "ANNOTS" , "Tabulate all annotations" );
  add_url( "ANNOTS" , "annotations/#annots" );
  //  add_note( "ANNOTS" , "Any formatted free text goes here,\n shown at end of verbose help link\n");

  add_param( "ANNOTS" , "epoch" , "" , "" , "Show epoch-level summaries" );
  add_param( "ANNOTS" , "show-masked" , "" , "" , "Show masked annotations (default is not to do so)" );
  add_param( "ANNOTS" , "any" , "" , "" , "Keep annotations that have any overlap with one or more unmasked epochs (default)" );
  add_param( "ANNOTS" , "all" , "" , "" , "Only keep annotations that are completely within unmasked epochs" );
  add_param( "ANNOTS" , "start" , "" , "" , "Keep annotations that start in an unmasked epoch" );

  add_table( "ANNOTS" , "ANNOT" , "Class-level annotation summary" );
  add_var( "ANNOTS" , "ANNOT" , "COUNT" , "Number of instances of that annotation class" );
  add_var( "ANNOTS" , "ANNOT" , "DUR" , "Combined duration (seconds) of all instances of that annotation class" );

  add_table( "ANNOTS" , "ANNOT,INST" , "Instance-level annotation summary" );
  add_var( "ANNOTS" , "ANNOT,INST" , "COUNT" , "Number of instances of that annotation class and instance ID" );
  add_var( "ANNOTS" , "ANNOT,INST" , "DUR" , "Combined duration (seconds) of all instances of that annotation class and instance ID" );

  add_table( "ANNOTS" , "ANNOT,INST,T" , "Instance-level annotation tabulation" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "START" , "Start time (seconds) of this instance" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "STOP" , "Stop time (seconds) of this instance" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "VAL" , "The meta-data for this instance, if any exists (otherwise missing NA)" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "ALL_MASKED" , "? [show-masked]" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "ALL_UNMASKED" , "? [show-masked]" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "SOME_MASKED" , "? [show-masked]" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "SOME_UNMASKED" , "? [show-masked]" );
  add_var( "ANNOTS" , "ANNOT,INST,T" , "START_MASKED" , "? [show-masked]" );

  add_table( "ANNOTS" , "E,INTERVAL,INST" , "Per-epoch instance-level annotation tabulation" );
  add_var( "ANNOTS" , "E,INTERVAL,INST" , "ANNOT_MASK" , "Annotation instance mask status (1=masked/excluded) [epoch]" );
  add_var( "ANNOTS" , "E,INTERVAL,INST" , "EPOCH_MASK" , "Epoch mask status (1=masked/excluded) [epoch]" );



  /////////////////////////////////////////////////////////////////////////////////
  //
  // EPOCHS
  //
  /////////////////////////////////////////////////////////////////////////////////
  
  // EPOCH 

  add_cmd( "epoch" , "EPOCH" , "Set epochs" );
  add_url ( "EPOCH" , "epochs/#epoch" );

  add_param( "EPOCH" , "len" , "30" , "" , "Epoch length (seconds), defaults to 30" );
  add_param( "EPOCH" , "dur" , "30" , "" , "Same as len" );
  add_param( "EPOCH" , "inc" , "30" , "" , "Epoch increment (seconds), defaults to len (i.e. no overlap)" );
  add_param( "EPOCH" , "epoch" , "30,15" , "" , "Same as len=30 inc=15" );
  add_param( "EPOCH" , "require" , "10" , "" , "Stop processing that EDF if there are not at least N epochs" );
  add_param( "EPOCH" , "verbose" , "" , "" , "Output epoch-level information" );

  add_table( "EPOCH" , "" , "Epoch-level summaries" );
  add_var( "EPOCH" , "" , "DUR" , "Epoch duration (seconds)" );
  add_var( "EPOCH" , "" , "INC" , "Epoch increment (seconds)" );
  add_var( "EPOCH" , "" , "NE" , "Number of epochs" );

  add_table( "EPOCH" , "E" , "Per-epoch interval information [verbose]" );
  add_var( "EPOCH" , "E" , "E1" , "Current epoch number (which may differ from E if the EDF has been restructured)" );
  add_var( "EPOCH" , "E" , "HMS" , "Clock-time for epoch start (hh:mm:ss)" );
  add_var( "EPOCH" , "E" , "INTERVAL" , "String label of epoch interval (seconds)" );
  add_var( "EPOCH" , "E" , "MID" , "Midpoint of epoch (seconds elapsed from EDF start)" );
  add_var( "EPOCH" , "E" , "START" , "Start of epoch (seconds elapsed from EDF start)" );
  add_var( "EPOCH" , "E" , "STOP" , "Stop of epoch (seconds elapsed from EDF start)" );


  // EPOCH-ANNOT

  add_cmd( "epoch" , "EPOCH-ANNOT" , "Attach epoch-level annotations from a file, to an epoched EDF" );
  add_url( "EPOCH-ANNOT" , "epochs/#epoch-annot" );  
  add_param( "EPOCH-ANNOT" , "file" , "annots/id1.epochs" , "" , "File path/name to read annotations from [required]" );
  add_param( "EPOCH-ANNOT" , "recode" , "NREM1=N1,NREM2=N2" , "" , "Comma-delimited list of recodings (from=to)");
  
  
  
  /////////////////////////////////////////////////////////////////////////////////
  //
  // MASKS
  //
  /////////////////////////////////////////////////////////////////////////////////


  // MASK

  add_cmd( "mask" , "MASK" , "Mask epochs based on annotations and other features" );
  add_url( "MASK" , "masks/#mask" );

  add_param( "MASK" , "if"    , "NREM2" , "" , "Mask NREM2 epochs, unmask all others" );
  add_param( "MASK" , "ifnot" , "NREM2" , "" , "Unmask NREM2 epochs, mask all others" );
  add_param( "MASK" , "expr" , "A>2" , "" , "Mask epochs with A>2, unmask all others" );
  add_param( "MASK" , "not-expr" , "A>2" , "" , "Unmask epochs with A>2, mask all others" );

  add_param( "MASK" , "mask-if" , "NREM2" , "" , "Mask NREM2 epochs" );
  add_param( "MASK" , "mask-ifnot" , "NREM2" , "" , "Mask non-NREM2 epochs" );
  add_param( "MASK" , "mask-expr" , "A>2" , "" , "Mask epochs with A>2" );

  add_param( "MASK" , "unmask-if" , "NREM2" , "" , "Unask NREM2 epochs" );
  add_param( "MASK" , "unmask-ifnot" , "NREM2" , "" , "Unask non-NREM2 epochs" );
  add_param( "MASK" , "unmask-expr" , "A>2" , "" , "Unmask epochs with A>2" );

  add_param( "MASK" , "none" , "" , "" , "Clear mask (i.e. unmask all)" );
  add_param( "MASK" , "clear" , "" , "" , "Clear mask (i.e. unmask all)" );
  add_param( "MASK" , "include-all" , "" , "" , "Clear mask (i.e. unmask all)" );

  add_param( "MASK" , "all" , "" , "" , "Mask all epochs" );
  add_param( "MASK" , "total" , "" , "" , "Mask all epochs" );
  add_param( "MASK" , "exclude-all" , "" , "" , "Mask all epochs" );


  add_param( "MASK" , "epoch" , "1-10" , "" , "Select epochs 1 to 10" );
  add_param( "MASK" , "sec" , "60-120" , "" , "Select epochs overlapping this interval" );
  add_param( "MASK" , "hms" , "8:00-9:00" , "" , "Select epochs overlapping this interval" );

  add_param( "MASK" , "random" , "20" , "" , "Select 20 random (currently unmasked) epochs" );

  add_param( "MASK" , "flip" , "" , "" , "Reverse all masks" );
  add_param( "MASK" , "leading" , "W" , "" , "Remove all leading epochs matching W" );
  add_param( "MASK" , "flanked" , "REM,2" , "" , "Select only REM epochs flanked by 2+ REM epochs before/after" );
  
  
  add_table( "MASK" , "EPOCH_MASK" , "Output stratified by mask" );
  add_var( "MASK" , "EPOCH_MASK", "N_MATCHES" , "Number of epochs that match the condition (e.g. having annotation A)");
  add_var( "MASK" , "EPOCH_MASK", "N_MASK_SET" , "Number of previously unmasked epochs that were masked by this operation");
  add_var( "MASK" , "EPOCH_MASK", "N_MASK_UNSET" , "Number of previously masked epochs that were unmasked by this operation");
  add_var( "MASK" , "EPOCH_MASK", "N_UNCHANGED" , "Number of epochs whose mask status was not changed by this operation");
  add_var( "MASK" , "EPOCH_MASK", "N_RETAINED" , "Number of epochs retained after this operation");
  add_var( "MASK" , "EPOCH_MASK", "N_TOTAL" , "Total number of epochs");
  
  // DUMP-MASK
  
  add_cmd( "mask" , "DUMP-MASK" , "Output epoch-level mask information" );
  add_url( "DUMP-MASK" , "masks/#dump-mask" );

  add_table( "DUMP-MASK" , "E" , "Epoch-level mask tabulation" );
  add_var( "EPOCH" , "E" , "EPOCH_MASK" , "Mask status: 0 is unmasked (included), and 1 is masked (i.e. excluded)" );
 

  // RE (or RESTRUCTURE)

  add_cmd( "mask"   , "RE" , "Restructure an EDF (drop channels/epochs)" );
  add_url( "RE" , "masks/#restructure" );

  add_table( "RE" , "" , "Restructured data duration" );
  add_var( "RE" , "" , "DUR1" , "Duration pre-restructuring (secs)");
  add_var( "RE" , "" , "DUR2" , "Duration post-restructuring (secs)");
  add_var( "RE" , "" , "NR1" , "Duration pre-restructuring (records)");
  add_var( "RE" , "" , "NR2" , "Duration post-restructuring (records)");

  add_cmd( "mask"   , "RESTRUCTURE" , "Restructure an EDF (drop channels/epochs)" );
  add_url( "RESTRUCTURE" , "masks/#restructure" );

  add_table( "RESTRUCTURE" , "" , "Restructured data duration" );
  add_var( "RESTRUCTURE" , "" , "DUR1" , "Duration pre-restructuring (secs)");
  add_var( "RESTRUCTURE" , "" , "DUR2" , "Duration post-restructuring (secs)");
  add_var( "RESTRUCTURE" , "" , "NR1" , "Duration pre-restructuring (records)");
  add_var( "RESTRUCTURE" , "" , "NR2" , "Duration post-restructuring (records)");


  /////////////////////////////////////////////////////////////////////////////////
  //
  // MANIPULATIONS
  //
  /////////////////////////////////////////////////////////////////////////////////
  
  // SIGNALS

  add_cmd( "manip" , "SIGNALS" , "Retain/remove specific EDF channels" );
  add_url( "SIGNALS" , "manipulatons/#signals" );
  add_param( "SIGNALS" , "drop" , "EMG,ECG" , "" , "Drop channels EMG and ECG" );
  add_param( "SIGNALS" , "keep" , "C3,C4" , "" , "Drop all channels except C3 and C4" );

  // COPY

  add_cmd( "manip" , "COPY" , "Duplicate one or more EDF channels" );
  add_url( "COPY" , "manipulations/#copy" );
  add_param( "COPY" , "sig" , "C3,C4" , "" , "List of channels to duplicate" );
  add_param( "COPY" , "tag" , "V2" , "" , "Tag add to new channel names, e.g. C3_V2 [required] " );
    
  // RESAMPLE 

  add_cmd( "manip" , "RESAMPLE" , "Resample signal(s)" );
  add_url( "RESAMPLE" , "manipulations/#resample" );
  add_param( "RESAMPLE" , "sig" , "C3,C4" , "" , "List of channels to resample" );
  add_param( "RESAMPLE" , "sr" , "200" , "" , "New sampling rate (Hz) [required]" );
  
  // REFERENCE

  add_cmd( "manip" , "REFERENCE" , "Resample signal(s)" );
  add_url( "REFERENCE" , "manipulations/#resample" );
  add_param( "REFERENCE" , "sig" , "C3,C4" , "" , "List of signals to re-reference" );
  add_param( "REFERENCE" , "ref" , "A1,A2" , "" , "Signal(s) providing the reference [required]" );

  // uV

  add_cmd( "manip" , "uV" , "Converts a signal to uV units" );
  add_url( "uV" , "manipulations/#uv" );
  add_param( "uV" , "sig" , "C3,C4" , "" , "List of signals to convert" );

  // mV

  add_cmd( "manip" , "mV" , "Converts a signal to mV units" );
  add_url( "mV" , "manipulations/#mv" );
  add_param( "mV" , "sig" , "C3,C4" , "" , "List of signals to convert" );

  // FLIP

  add_cmd( "manip" , "FLIP" , "Flips the polarity of a signal" );
  add_url( "FLIP" , "manipulations/#flip" );
  add_param( "FLIP" , "sig" , "C3,C4" , "" , "List of signals to flip" );

  // RECORD-SIZE

  add_cmd( "manip" , "RECORD-SIZE" , "Alters the record size of an EDF, and writes a new EDF" );
  add_url( "RECORD-SIZE" , "manipulations/#record-size" );
  add_param( "RECORD-SIZE" , "dur" , "1" , "" , "New EDF record/block size" );
  add_param( "RECORD-SIZE" , "edf-dir" , "edfs/" , "" , "Folder for writing new EDFs" );
  add_param( "RECORD-SIZE" , "edf-tag" , "rec1" , "" , "Tag added to new EDFs" );
  add_param( "RECORD-SIZE" , "sample-list" , "s2.lst" , "" , "Generate a sample-list pointing to the new EDFs" );

  // ANON

  add_cmd( "manip" , "ANON" , "Strips EDF ID and and Start Date headers" );
  add_url( "ANON" , "manipulations/#anon" );


  /////////////////////////////////////////////////////////////////////////////////
  //
  // OUTPUTS
  //
  /////////////////////////////////////////////////////////////////////////////////

  // WRITE

  add_cmd( "output" , "WRITE" , "Write a new EDF file" );
  add_url( "WRITE" , "outputs/#write" );
  add_param( "WRITE" , "edf-dir" , "edfs/" , "" , "Set folder where new EDFs should be written" );
  add_param( "WRITE" , "edf-tag" , "v2" , "" , "Add a tag to each new EDF filename" );
  add_param( "WRITE" , "sample-list" , "v2.lst" , "" , "Name of the new sample-list" );


  // MATRIX

  add_cmd( "output" , "MATRIX" , "Dumps signal information to a file" );
  add_url( "MATRIX" , "outputs/#matrix" );
  add_param( "MATRIX" , "file" , "signals.txt" , "" , "Required parameter, to specify the filename for the output" );
  add_param( "MATRIX" , "sig" , "C3,C4" , "" , "Restrict output to these signal(s)" );
  add_param( "MATRIX" , "hms" , "" , "" , "Add a clock-time column in hh:mm:ss format" );
  add_param( "MATRIX" , "hms2" , "" , "" , "Add a clock-time column in hh:mm:ss:microsecond format" );
  add_param( "MATRIX" , "annot" , "X,Y" , "" , "Add columns with values 1/0 to indicate the presence/absence of that annotation" );
  add_param( "MATRIX" , "min" , "" , "" , "Minimal output to show only signal information (no headers or lead columns)" );
  

  // DUMP-RECORDS

  add_cmd( "output" , "DUMP-RECORDS" , "Writes detailed annotation and signal data to standard output" );
  add_url( "DUMP-RECORDS" , "outputs/#dump-records" );
  add_param( "DUMP-RECORDS" , "no-signals" , "" , "" , "Do not show signal data" );
  add_param( "DUMP-RECORDS" , "no-annots" , "" , "" , "Do not show annotation information" );


  /////////////////////////////////////////////////////////////////////////////////
  //
  // FILTERS
  //
  /////////////////////////////////////////////////////////////////////////////////

  // FILTER

  add_cmd( "filter" , "FILTER" , "Apply a FIR filter to one or more signals");
  add_url( "FILTER" , "fir-filters/#filter" );
  add_param( "FILTER" , "sig" , "C3,C4" , "" , "Restrict analysis to these channels" );

  add_param( "FILTER" , "bandpass" , "0.3,35" , "" , "Band-pass filter between 0.3 and 35 Hz" );
  add_param( "FILTER" , "lowpass"  , "35" , "" , "Low-pass filter with cutoff of 35 Hz" );
  add_param( "FILTER" , "highpass" , "0.3" , "" , "High-pass filter with cutiff of 0.3 Hz" );
  add_param( "FILTER" , "bandstop" , "55,65" , "" , "Band-stop filter between 55 and 65 Hz" );
  add_param( "FILTER" , "ripple" , "0.02" , "" , "Ripple (as a proportion)" );
  add_param( "FILTER" , "tw" , "1" , "" , "Transition width (in Hz)" );


  // FILTER-DESIGN

  add_cmd( "filter" , "FILTER-DESIGN" , "Apply a FIR filter to one or more signals");
  add_url( "FILTER-DESIGN" , "fir-filters/#filter-design" );
  add_param( "FILTER-DESIGN" , "bandpass" , "0.3,35" , "" , "Band-pass filter between 0.3 and 35 Hz" );
  add_param( "FILTER-DESIGN" , "lowpass"  , "35" , "" , "Low-pass filter with cutoff of 35 Hz" );
  add_param( "FILTER-DESIGN" , "highpass" , "0.3" , "" , "High-pass filter with cutiff of 0.3 Hz" );
  add_param( "FILTER-DESIGN" , "bandstop" , "55,65" , "" , "Band-stop filter between 55 and 65 Hz" );
  add_param( "FILTER-DESIGN" , "ripple" , "0.02" , "" , "Ripple (as a proportion)" );
  add_param( "FILTER-DESIGN" , "tw" , "1" , "" , "Transition width (in Hz)" );
  add_param( "FILTER-DESIGN" , "fs" , "200" , "" , "Specify sample rate (in Hz)" ); 


  /////////////////////////////////////////////////////////////////////////////////
  //
  // ARTIFACTS
  //
  /////////////////////////////////////////////////////////////////////////////////

  add_cmd( "artifact" , "SIGSTATS" , "Per-epoch outlier detection (RMS, Hjorth parameters, clipped signals)" );
  add_url( "SIGSTATS" , "artifacts/#sigstats" );
  add_param( "SIGSTATS" , "sig" , "C3,C4" , "" , "Restrict analysis to these channels" );

  add_param( "SIGSTATS" , "verbose" , "" , "" , "Report epoch-level statistics" );
  add_param( "SIGSTATS" , "mask" , "" , "" , "Set mask for outlier epochs" );
  add_param( "SIGSTATS" , "threshold" , "2,2" , "" , "Set standard unit threshold(s) for (iterative) outlier detection" );
  add_param( "SIGSTATS" , "th" , "2,2" , "" , "Same as 'threshold'" );

  add_table( "SIGSTATS" , "CH" , "Per-channel whole-signal statistics" );
  add_var( "SIGSTATS" , "CH" , "CLIP" , "Proportion of clipped sample points" );
  add_var( "SIGSTATS" , "CH" , "H1" , "First Hjorth parameter (activity)" );
  add_var( "SIGSTATS" , "CH" , "H2" , "Second Hjorth parameter (mobility)" );
  add_var( "SIGSTATS" , "CH" , "H3" , "Third Hjorth parameter (complexity)" );
  add_var( "SIGSTATS" , "CH" , "RMS" , "Signal root mean square" );

  add_var( "SIGSTATS" , "CH" , "CNT_ACT" , "Number of epochs flagged based on H1 [mask]" );
  add_var( "SIGSTATS" , "CH" , "CNT_MOB" , "Number of epochs flagged based on H2 [mask]" );
  add_var( "SIGSTATS" , "CH" , "CNT_CMP" , "Number of epochs flagged based on H3 [mask]" );
  add_var( "SIGSTATS" , "CH" , "CNT_CLP" , "Number of epochs flagged based on clipping metric" );
  add_var( "SIGSTATS" , "CH" , "CNT_RMS" , "Number of epochs flagged based on RMS" );

  add_var( "SIGSTATS" , "CH" , "FLAGGED_EPOCHS" , "Number of epochs flagged as outliers [mask]" );
  add_var( "SIGSTATS" , "CH" , "ALTERED_EPOCHS" , "Number of epochs whose mask was altered [mask]" );
  add_var( "SIGSTATS" , "CH" , "TOTAL_EPOCHS" , "Total number of masked epochs [mask]" );


  /////////////////////////////////////////////////////////////////////////////////
  //
  // HYPNOGRAMS
  //
  /////////////////////////////////////////////////////////////////////////////////


  add_cmd( "hypno" , "STAGE" , "Output sleep stage annotations, per epoch" );
  add_url( "STAGE" , "hypnograms/#stage" );
  add_param( "STAGE" , "N1" , "NREM1" , "" , "Set the annotation used for N1 sleep" );
  add_param( "STAGE" , "N2" , "NREM2" , "" , "Set the annotation used for N2 sleep" );
  add_param( "STAGE" , "N3" , "NREM3" , "" , "Set the annotation used for N3 sleep" );
  add_param( "STAGE" , "REM" , "REM" , "" , "Set the annotation used for REM sleep" );
  add_param( "STAGE" , "wake" , "W" , "" , "Set the annotation used for N3 sleep" );
  add_param( "STAGE" , "?" , "-9" , "" , "Set the annotation used for unknown/other" );

  add_table( "STAGE" , "E" , "Stage annotations per-epoch" );
  add_var( "STAGE" , "E" , "CLOCK_TIME" , "Clock time (hh:mm:ss)" );
  add_var( "STAGE" , "E" , "MINS" , "Elapsed time from start of EDF (minutes)" );
  add_var( "STAGE" , "E" , "STAGE" , "Sleep stage (text value)" );
  add_var( "STAGE" , "E" , "STAGE_N" , "Numeric encoding of sleep stage" );


  add_cmd( "hypno" , "HYPNO" , "Metrics based on sleep stage annotations" );
  add_url( "HYPNO" , "hypnograms/#hypno" );

  add_param( "HYPNO" , "file" , "stages.txt" , "" , "Optionally, read stages from file" );
  add_param( "HYPNO" , "N1" , "NREM1" , "" , "Set the annotation used for N1 sleep" );
  add_param( "HYPNO" , "N2" , "NREM2" , "" , "Set the annotation used for N2 sleep" );
  add_param( "HYPNO" , "N3" , "NREM3" , "" , "Set the annotation used for N3 sleep" );
  add_param( "HYPNO" , "REM" , "REM" , "" , "Set the annotation used for REM sleep" );
  add_param( "HYPNO" , "wake" , "W" , "" , "Set the annotation used for N3 sleep" );
  add_param( "HYPNO" , "?" , "-9" , "" , "Set the annotation used for unknown/other" );


  add_table( "HYPNO" , "" , "Individual-level output" );
  add_var( "HYPNO" , "" , "TST" , "Total sleep time" );
  add_var( "HYPNO" , "" , "TPST" , "Total persistent sleep time" );
  add_var( "HYPNO" , "" , "TIB" , "Time in bed" );
  add_var( "HYPNO" , "" , "TWT" , "Total wake time" );
  add_var( "HYPNO" , "" , "WASO" , "Wake after sleep onset" );
  add_var( "HYPNO" , "" , "LIGHTS_OFF" , "Lights off time (hours since midnight)" );
  add_var( "HYPNO" , "" , "SLEEP_ONSET" , "Sleep onset time (hours since midnight)" );
  add_var( "HYPNO" , "" , "SLEEP_MIDPOINT" , "Sleep midpoint time (hours since midnight)" );
  add_var( "HYPNO" , "" , "LIGHTS_ON" , "Lights on time (hours since midnight)" );
  add_var( "HYPNO" , "" , "FINAL_WAKE" , "Final wake time (hours since midnight)" );
  add_var( "HYPNO" , "" , "SLP_EFF" , "Sleep efficiency" );
  add_var( "HYPNO" , "" , "SLP_EFF2" , "Sleep efficiency (alternate defn.)" );
  add_var( "HYPNO" , "" , "SLP_MAIN_EFF" , "Sleep maintenance efficiency" );
  add_var( "HYPNO" , "" , "SLP_LAT" , "Sleep latency (minutes from lights off)" );
  add_var( "HYPNO" , "" , "PER_SLP_LAT" , "Persistent sleep latency (mins from lights off)" );
  add_var( "HYPNO" , "" , "REM_LAT" , "REM latency (minutes from onset of sleep)" );
  add_var( "HYPNO" , "" , "MINS_N1" , "Total duration of N1 sleep (mins)" );
  add_var( "HYPNO" , "" , "MINS_N2" , "Total duration of N2 sleep (mins)" );
  add_var( "HYPNO" , "" , "MINS_N3" , "Total duration of N3 sleep (mins)" );
  add_var( "HYPNO" , "" , "MINS_N4" , "Total duration of N4 (NREM4) sleep (mins)" );
  add_var( "HYPNO" , "" , "MINS_REM" , "Total duration of REM sleep (mins)" );
  add_var( "HYPNO" , "" , "PCT_N1" , "Proportion N1 of total sleep time" );
  add_var( "HYPNO" , "" , "PCT_N2" , "Proportion N2 of total sleep time" );
  add_var( "HYPNO" , "" , "PCT_N3" , "Proportion N3 of total sleep time" );
  add_var( "HYPNO" , "" , "PCT_N4" , "Proportion N4 of total sleep time" );
  add_var( "HYPNO" , "" , "PCT_REM" , "Proportion REM of total sleep time" );
  add_var( "HYPNO" , "" , "NREMC" , "Number of sleep cycles" );
  add_var( "HYPNO" , "" , "NREMC_MINS" , "Mean duration of each sleep cycle" );


  add_table( "HYPNO" , "C" , "NREM cycle-level output" );
  add_var( "HYPNO" , "C" , "NREMC_START" , "First epoch number of this NREM cycle" );
  add_var( "HYPNO" , "C" , "NREMC_MINS" , "Total duration of this cycle (mins)" );
  add_var( "HYPNO" , "C" , "NREMC_NREM_MINS" , "Duration of NREM in this cycle (mins)" );
  add_var( "HYPNO" , "C" , "NREMC_REM_MINS" , "Duration of REM in this cycle (mins)" );
  add_var( "HYPNO" , "C" , "NREMC_OTHER_MINS" , "Minutes of wake and unscored epochs" );


  add_table( "HYPNO" , "E" , "Epoch-level output" );
  add_var( "HYPNO" , "E" , "CLOCK_HOURS" , "Start time of epoch (hours since midnight)" );
  add_var( "HYPNO" , "E" , "CLOCK_TIME" , "Start time of epoch (hh:mm:ss)" );
  add_var( "HYPNO" , "E" , "MINS" , "Start time of epoch (minutes since start of EDF)" );
  add_var( "HYPNO" , "E" , "STAGE" , "Text description of sleep stage" );
  add_var( "HYPNO" , "E" , "STAGE_N" , "Numeric encoding of sleep stage" );
  add_var( "HYPNO" , "E" , "PERSISTENT_SLEEP" , "Flag to indicate persistent sleep" );
  add_var( "HYPNO" , "E" , "WASO" , "Flag to indicate wake after sleep onset" );
  add_var( "HYPNO" , "E" , "E_N1" , "Cumulative elapsed N1 sleep (minutes)" );
  add_var( "HYPNO" , "E" , "E_N2" , "Cumulative elapsed N2 sleep (minutes)" );
  add_var( "HYPNO" , "E" , "E_N3" , "Cumulative elapsed N3 sleep (minutes)" );
  add_var( "HYPNO" , "E" , "E_REM" , "Cumulative elapsed REM (minutes)" );
  add_var( "HYPNO" , "E" , "E_SLEEP" , "Cumulative elapsed sleep (minutes)" );
  add_var( "HYPNO" , "E" , "E_WAKE" , "Cumulative elapsed wake (minutes)" );
  add_var( "HYPNO" , "E" , "E_WASO" , "Cumulative elapsed WASO (minutes)" );
  add_var( "HYPNO" , "E" , "PCT_E_N1" , "Cumulative elapsed N1 as proportion of total N1 sleep" );
  add_var( "HYPNO" , "E" , "PCT_E_N2" , "Cumulative elapsed N2 as proportion of total N2 sleep" );
  add_var( "HYPNO" , "E" , "PCT_E_N3" , "Cumulative elapsed N3 as proportion of total N3 sleep" );
  add_var( "HYPNO" , "E" , "PCT_E_REM" , "Cumulative elapsed REM as proportion of total REM sleep" );
  add_var( "HYPNO" , "E" , "PCT_E_SLEEP" , "Cumulative elapsed sleep as proportion of total sleep" );
  add_var( "HYPNO" , "E" , "FLANKING_SIM" , "Number of similarly-staged epochs,either forwards or backwards" );

  add_var( "HYPNO" , "E" , "N2_WGT" , "Score to indicate ascending versus descending N2 sleep" );
  add_var( "HYPNO" , "E" , "NEAREST_WAKE" , "Number of epochs (forward or backwards) since nearest wake epoch" );
  add_var( "HYPNO" , "E" , "NREM2REM" , "Number of epochs from this N2 epoch to the N2/REM transition" );
  add_var( "HYPNO" , "E" , "NREM2REM_TOTAL" , "Total number of contiguous N2 epochs until a REM transition" );
  add_var( "HYPNO" , "E" , "NREM2WAKE" , "Number of epochs from this N2 epoch to the N2/Wake transition" );
  add_var( "HYPNO" , "E" , "NREM2WAKE_TOTAL" , "Total number of contiguous N2 epochs until a Wake transition" );
  add_var( "HYPNO" , "E" , "CYCLE" , "Cycle number, if this epoch is in a sleep cycle" );
  add_var( "HYPNO" , "E" , "CYCLE_POS_ABS" , "Absolute position of this epoch in the current NREM cycle (mins)" );
  add_var( "HYPNO" , "E" , "CYCLE_POS_REL" , "Relative position of this epoch in the current NREM cycle (0-1)" );
  add_var( "HYPNO" , "E" , "PERIOD" , "Cycle period: NREMP or REMP, or missing if not in a cycle" );


  /////////////////////////////////////////////////////////////////////////////////
  //
  // SPECTRAL
  //
  /////////////////////////////////////////////////////////////////////////////////


  //
  // PSD
  //

  add_cmd( "power"   , "PSD" , "Power spectral density estimation (Welch)" );
  add_url( "PSD" , "power-spectra/#psd" );

  add_param( "PSD" , "sig" , "C3,C4" , "" , "Restrict analysis to these channels" );
  add_param( "PSD" , "epoch" , "" , "" , "Calculate per-epoch statistics" );
  add_param( "PSD" , "max" , "100" , "" , "Calculate per-epoch statistics" );
  add_param( "PSD" , "spectrum" , "" , "" , "Calculate per-epoch statistics" );
  add_param( "PSD" , "epoch-spectrum" , "" , "" , "Calculate per-epoch statistics" );
  
  add_table( "PSD" , "CH" , "Number of epochs" );
  add_var( "PSD" , "CH" , "NE" , "Number of epochs" );

  add_table( "PSD" , "CH,B" , "Whole-night, per-channel band power" );
  add_var( "PSD" , "CH,B" , "PSD" , "Power" );
  add_var( "PSD" , "CH,B" , "RELPSD" , "Relative power" );

  add_table( "PSD" , "CH,F" , "Whole-night, per-channel power" );
  add_var( "PSD" , "CH,F" , "PSD" , "Power" );

  add_table( "PSD" , "CH,B,E" , "Whole-night, per-channel per-epoch band power" );
  add_var( "PSD" , "CH,B,E" , "PSD" , "Power" );
  add_var( "PSD" , "CH,B,E" , "RELPSD" , "Relative power" );

  add_table( "PSD" , "CH,F,E" , "Whole-night, per-channel per-epoch power" );
  add_var( "PSD" , "CH,F,E" , "PSD" , "Power" );
  set_compressed( "PSD" , tfac_t( "CH,F,E" ) );


  //
  // MTM
  //

  add_cmd( "power"   , "MTM" , "Power spectral density estimation (Welch)" );
  add_url( "MTM" , "power-spectra/#mtm" );

  add_param( "MTM" , "sig" , "C3,C4" , "" , "Restrict analysis to these channels" );
  add_param( "MTM" , "epoch" , "" , "" , "Calculate per-epoch statistics" );
  add_param( "MTM" , "max" , "100" , "" , "Calculate per-epoch statistics" );
  add_param( "MTM" , "dB" , "" , "" , "Decibel scale output" );
  add_param( "MTM" , "spectrum" , "" , "" , "Calculate per-epoch statistics" );
  add_param( "MTM" , "epoch-spectrum" , "" , "" , "Calculate per-epoch statistics" );
  
  add_table( "MTM" , "CH,F" , "Whole-night, per-channel power" );
  add_var( "MTM" , "CH,F" , "MTM" , "Power" );

  add_table( "MTM" , "CH,F,E" , "Whole-night, per-channel per-epoch power" );
  add_var( "MTM" , "CH,F,E" , "MTM" , "Power" );
  set_compressed( "MTM" , tfac_t( "CH,F,E" ) );

  //
  // MSE
  //

  add_cmd( "power" , "MSE" , "Multi-scale entropy statistics" );
  add_url( "MSE" , "power-spectra/#mse" );


  //
  // LZW 
  //

  add_cmd( "power" , "LZW" , "LZW compression index" );
  add_url( "LZW" , "power-spectra/#lzw" );


  //
  // HILBERT 
  //

  add_cmd( "power" , "HILBERT" , "Applies filter-Hilbert transform" );
  add_url( "HILBERT" , "power-spectra/#hilbert" );

  add_param( "HILBERT" , "sig" , "C3,C4" , "" , "Restrict analysis to these channels" );
  add_param( "HILBERT" , "f" , "0.5,4" , "" , "Lower and upper transition frequencies" );
  add_param( "HILBERT" , "ripple" , "0.02" , "" , "FIR filter ripple (as proportion)" );
  add_param( "HILBERT" , "tw" , "0.5" , "" , "Transition width (in Hz)" );
  add_param( "HILBERT" , "tag" , "v1" , "" , "Optional tag to be added to new signals" );
  add_param( "HILBERT" , "phase" , "" , "" , "As well as magnitude, generate signal with instantaneous phase" );


  //
  // CWT
  //

  
  
  //
  // CWT-DESIGN 
  //


  //
  // 1FNORM
  //


  //
  // TV
  //



  /////////////////////////////////////////////////////////////////////////////////
  //
  // SPINDLES/SO
  //
  /////////////////////////////////////////////////////////////////////////////////



  /////////////////////////////////////////////////////////////////////////////////
  //
  // CROSS-SIGNAL
  //
  /////////////////////////////////////////////////////////////////////////////////



  /////////////////////////////////////////////////////////////////////////////////
  //
  // CFC
  //
  /////////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////////
  //
  // MISC
  //
  /////////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////////
  //
  // EXPERIMENTAL
  //
  /////////////////////////////////////////////////////////////////////////////////



}





tfac_t::tfac_t( const std::string & s ) { 
  std::vector<std::string> tok = Helper::parse( s , "," );
  for (int i=0;i<tok.size();i++) 
    {
      if ( tok[i][0] != '_' && ! globals::cmddefs.is_tag( tok[i] ) )
	fac.insert( tok[i] );
    } 
}

cmddefs_t::cmddefs_t()
{
  init();
}



//
// Help display commands
//

std::string cmddefs_t::help_domains( ) const
{
  std::stringstream ss;
  std::map<std::string,std::string>::const_iterator ii = domain_desc.begin();
  while ( ii != domain_desc.end() ) { 
    ss << std::left << std::setw( 10 ) << ii->first << " " 
       << std::setw( 28 ) << domain_label.find( ii->first )->second << "\n";
      //<< ii->second << "\n";
    ++ii;
  }
  return ss.str();
}


bool cmddefs_t::check( const std::string & cmd ) const
{
  return cmds.find( cmd ) != cmds.end() ;
}

bool cmddefs_t::check( const std::string & cmd , const std::set<std::string> & k , std::set<std::string> * unknown ) const
{

  if ( k.size() == 0 ) return true;
  
  if ( cmds.find( cmd ) == cmds.end() ) return false;

  if ( pdesc.find( cmd ) == pdesc.end() ) 
    {
      *unknown = k;
      return false;
    }

  bool okay = true;

  const std::map<std::string,std::string> & p = pdesc.find( cmd )->second ;


  // check if command allows wild-cards, i.e. TAG 
  // this is specified by having "" as a registered parameter. 
  // in this case, we let anything go
  
  if ( p.find( "" ) != p.end() ) return true;
  
  // otherwise, explicitly check, one-by-one
  
  std::set<std::string>::const_iterator kk = k.begin();
  
  while ( kk != k.end() )
    {
      if ( p.find( *kk ) == p.end() ) 
	{
	  unknown->insert( *kk );
	  okay = false; 
	}
      ++kk;
    }
  
  return okay;
}


// all commands
std::string cmddefs_t::help_commands() const
{
  std::stringstream ss;
  std::map<std::string,std::set<std::string> >::const_iterator ii = dcmds.begin();
  while ( ii != dcmds.end() ) { 
    const std::set<std::string> & dc = ii->second;
    std::set<std::string>::const_iterator jj = dc.begin();
    while ( jj != dc.end() ) {
      ss << help( *jj , false ) ;
      ++jj;
    }
    ss << "\n";
    ++ii;
  }
  return ss.str();  
}

// all commands in a domain
std::string cmddefs_t::help_commands( const std::string & d ) const 
{
  std::stringstream ss;
  std::map<std::string,std::set<std::string> >::const_iterator ii = dcmds.find( d );
  if ( ii == dcmds.end() ) return "";
  const std::set<std::string> & c = ii->second;
  std::set<std::string>::const_iterator jj = c.begin();
  while ( jj != c.end() ) { 
    ss << help( *jj , false ) ;
    ++jj;
  }
  return ss.str();    
}
  
// verbose describe commands [cmd] 

std::string cmddefs_t::help( const std::string & cmd , bool verbose ) const
{
  if ( cmds.find( cmd ) == cmds.end() ) return "";
  std::stringstream ss;
  if ( ! verbose ) 
    {
      ss << std::left << std::setw( 18 ) << domain_label.find( cdomain.find( cmd )->second )->second  << " " 
	 << std::left << std::setw( 12 ) << cmd << " "
	 << cmds.find( cmd )->second << "\n";    
    }
  else
    {
      ss << "\n";
      ss << cmd << " : " << cmds.find( cmd )->second 
	 << " (" << domain_label.find( cdomain.find( cmd )->second )->second  << ")\n"; 

      if ( curl.find( cmd ) != curl.end() ) 
	ss << std::string( cmd.size() , ' ' ) << " : " << url_root << curl.find( cmd )->second << "\n";

      //
      // params
      //

      ss << "\nParameters:"
	 << "\n===========\n\n";

      std::map<std::string,std::map<std::string,std::string> >::const_iterator ii = pdesc.find( cmd );
      if ( ii == pdesc.end() ) ss << "   none\n";
      else
	{
	  std::map<std::string,std::string>::const_iterator jj = ii->second.begin();
	  while ( jj != ii->second.end() ) {

	    ss << "  " << std::left << std::setw( 12 ) << jj->first;
	    
  	    // example (if any)
	    std::string ex = px.find( cmd )->second.find( jj->first )->second ; 
	    if ( ex != "" )
	      {
		std::string msg = jj->first + "=" + ex;
		ss << std::left << std::setw( 20 ) << msg;
	      }
 	    else
 	      ss << std::left << std::setw(20) << " ";;

	    // description
	    ss << std::left << std::setw( 12 ) << jj->second ;
	    
	    // requirements?
	    std::string req = preq.find( cmd )->second.find( jj->first )->second ; 
	    if ( req != "" )
	      ss << " [req. " << req << "]";
	    
	    ss << "\n";
	    
	    ++jj;
	  }
	  ++ii;
	}    


      //
      // outputs
      //

      ss << "\nOutputs:"
	 << "\n========\n\n";
      
      if ( otables.find( cmd ) == otables.end() )
	ss << "   none\n";
      else
	{
	  const std::map<tfac_t,std::string> & tab = otables.find( cmd )->second;
	  std::map<tfac_t,std::string>::const_iterator ii = tab.begin();
	  while ( ii != tab.end() )
	    {
	      const tfac_t & tfac = ii->first;
	      
	      ss << "   " << std::left << std::setw( 24 ) << tfac.as_string( " x " ) 
		 << ii->second << "\n";
	      
	      ss << "   " << std::left << std::string( 60 , '-' )
		<< "\n";

	      // dump as compressed text ?
	      bool tdump = allz || ofacs.find( cmd )->second.find( tfac )->second;
	      if ( tdump ) ss << "   (compressed output)\n";

	      // variables?
	      
	      if ( ovars.find( cmd ) != ovars.end() )
		{
		  const std::map<tfac_t,std::map<std::string,std::string> > & t = ovars.find( cmd )->second;
		  if ( t.find( ii->first ) != t.end() ) 
		    {
		      const std::map<std::string,std::string> & v = t.find( ii->first )->second;
		      std::map<std::string,std::string>::const_iterator vv = v.begin();
		      while ( vv != v.end() ) {
			ss << "     " 
			   << std::left 
			   << std::setw(21) 
			   << vv->first << " " 
			   << vv->second << "\n";
			++vv;
		      }
		       
		    }
		}
	      
	      // spacer for next table
	      ss << "\n";
	      ++ii;
	    }
	  
	}
    }

  
  return ss.str();
  
}



//
// test if a table exists
//

bool cmddefs_t::exists( const std::string & cmd ,
			const tfac_t & tfac ) const
{

  if ( cmds.find( cmd ) == cmds.end() ) return false;
  return ofacs.find( cmd )->second.find( tfac ) != ofacs.find( cmd )->second.end() ;
}


//
// Output?
//

bool cmddefs_t::out_compressed( const std::string & cmd , const tfac_t & tfac ) const
{
  // all output is in compressed plain-text
  if ( allz ) return true;
  
  // cmd not found
  if ( cmds.find( cmd ) == cmds.end() ) return false;
  
  // table not found
  if ( ofacs.find( cmd )->second.find( tfac ) == ofacs.find( cmd )->second.end() ) return false;
  
  return ofacs.find( cmd )->second.find( tfac )->second ;
  
}


void cmddefs_t::set_compressed( const std::string & cmd , const tfac_t & tfac , const bool b )
{
  if ( cmds.find( cmd ) == cmds.end() ) return;
  if ( ofacs[ cmd ].find( tfac ) == ofacs[ cmd ].end() ) return;
  ofacs[ cmd ][ tfac ] = b;
}



std::set<std::string> cmddefs_t::variables( const std::string & cmd ,  const param_t * param , const tfac_t & tfac  )
{
  // add param restriction on the variable list...
  std::set<std::string> r;
  std::map<std::string,std::map<tfac_t,std::map<std::string,std::string> > >::const_iterator ii = ovars.find( cmd );
  if ( ii == ovars.end() ) return r;
  const std::map<tfac_t,std::map<std::string,std::string> > & v2 = ii->second;
  std::map<tfac_t,std::map<std::string,std::string> >::const_iterator jj = v2.find( tfac );
  if ( jj == v2.end() ) return r;
  const std::map<std::string,std::string> & v3 = jj->second;
  std::map<std::string,std::string>::const_iterator kk = v3.begin();
  while ( kk != v3.end() )
    {
      r.insert( kk->first );
      ++kk;
    }
  return r;
}
