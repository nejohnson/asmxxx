rem  Zip File Created  with Info-Zip   Zip v2.31
rem  Zip File Verified with Info-Zip UnZip v5.52
rem
rem Remove Old Versions
rem
del asxs*.*
rem
rem  Zip The asxv5pxx Directory and Subdirectories
rem
cd ..\..\
asxv5pxx\zipper\zip.exe -r .\asxv5pxx\zipper\asxs5pxx.zip asxv5pxx\*.*
cd asxv5pxx\zipper
zip -T asxs5pxx.zip
rem
rem  Remove Zipped Files and the Zip/Unzip Utilities
rem
zip -d asxs5pxx.zip asxv5pxx\zipper\*.exe asxv5pxx\zipper\*.txt asxv5pxx\zipper\*.zip
zip -T asxs5pxx.zip
rem
rem  Remove Non-Distribution Directories
rem
zip -d asxs5pxx.zip asxv5pxx\update\*
rem
zip -d asxs5pxx.zip asxv5pxx\asxdoc\* asxv5pxx\asxhtmw\*
zip -d asxs5pxx.zip asxv5pxx\updater\* asxv5pxx\test\*
rem
zip -d asxs5pxx.zip asxv5pxx\asxmak\cygwin\exe\* asxv5pxx\asxmak\djgpp\exe\*
zip -d asxs5pxx.zip asxv5pxx\asxmak\linux\exe\* asxv5pxx\asxmak\symantec\exe\*
zip -d asxs5pxx.zip asxv5pxx\asxmak\turboc30\exe\* asxv5pxx\asxmak\vc6\exe\*
zip -d asxs5pxx.zip asxv5pxx\asxmak\vs05\exe\* asxv5pxx\asxmak\vs10\exe\*
zip -d asxs5pxx.zip asxv5pxx\asxmak\watcom\exe\*
zip -T asxs5pxx.zip
rem
rem  Remove Pad File
rem
zip -d asxs5pxx.zip asxv5pxx\asxv5p00.xml
zip -T asxs5pxx.zip
rem
rem  Copy Current readme.txt File To asxv5pxx.txt
rem  And Add To The Zip Archive
rem
copy ..\readme.txt asxs%1.txt
zip -g asxs5pxx.zip asxs%1.txt
zip -T asxs5pxx.zip
rem
rem  Change Name To Current Version
rem
ren asxs5pxx.zip asxs%1.zip
rem
rem  Final File Verification
rem
unzip -t asxs%1.zip

