# BMSParser

Parsing BMS format which is for non-commercial rhythm game.

## References  
[http://cosmic.mearie.org/2005/03/bmsguide/](http://cosmic.mearie.org/2005/03/bmsguide/ "Guide to understand BMS format")  
[http://hitkey.nekokan.dyndns.info/cmds.htm](http://hitkey.nekokan.dyndns.info/cmds.htm "BMS command memo (draft)")  

## Parsable preprocessors of HEADER FIELD

\#PLAYER, \#GENRE, \#TITLE, \#ARTIST, \#BPM, \#PLAYLEVEL, \#RANK, \#TOTAL, \#VOLWAV, \#STAGEFILE, \#STOPxx, \#LNTYPE 1, \#LNTYPE 2, \#LNOBJ, \#BPMxx  

## Parsable preprocessors of MAIN DATA FIELD

\#WAVxx, \#BMPxx

## Unimplemented preprocessors

\#BGAxx 

### Origined from nanasi

Please create an issue if one of these options are **highly recommended** to implement.  
Else, I'm not going to add.

\#DEFEXRANK, \#EXRANKxx, \#BANNER, \#DIFFICULTY, \#SUBTITLE, \#SUBARTIST, \#OCT/FP, \#EXWAVxx, \#EXBMPxx, \#@BGAxx, \#POORBGA, \#SWBGAxx, \#ARGBxx, \#OPTION, \#CHANGEOPTIONxx

### Not in plan

Please create an issue if one of these options are **EXTRA highly recommended** to implement.  

\#BACKBMP, \#CHARFILE, \#MAKER, \#COMMENT, \#TEXTxx, \#SONGxx, \#PATH_WAV, \#EXBPMxx, \#BASEBPM, \#STP, \#WAVCMD, \#CDDA, \#MIDIFILE, \#VIDEOf/s, \#VIDEOCOLORS, \#VIDEOFILE, \#VIDEODLY, \#MOVIE, \#SEEKxx, \#ExtChr, \#MATERIALS,

%URL, %EMAIL  

### Definitely not in plan

Those are depricated.  
  
\#MATERIALSWAV, \#MATERIALSBMP, \#DIVIDEPROP, \#CHARSET, 
