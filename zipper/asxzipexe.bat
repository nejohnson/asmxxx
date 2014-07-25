rem  Zip File Created  with Info-Zip   Zip v2.31
rem  Zip File Verified with Info-Zip UnZip v5.52
rem
rem  Remove Old Zipped Files
rem
del *cygwin.zip
del *djgpp.zip
del *linux.zip
del *turboc30.zip
del *symantec.zip
del *vc6.zip
del *vs05.zip
del *vs10.zip
del *watcom.zip
rem
rem  Zip The Executables Directories
rem
cd ..\asxmak\cygwin\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\cygwin.zip *.exe
cd ..\..\..\zipper
zip -T cygwin.zip
rem
cd ..\asxmak\djgpp\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\djgpp.zip *.exe
cd ..\..\..\zipper
zip -T djgpp.zip
rem
cd ..\asxmak\linux\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\linux.zip *
cd ..\..\..\zipper
zip -T linux.zip
rem
cd ..\asxmak\turboc30\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\turboc30.zip *.exe
cd ..\..\..\zipper
zip -T turboc30.zip
rem
cd ..\asxmak\symantec\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\symantec.zip *.exe
cd ..\..\..\zipper
zip -T symantec.zip
rem
cd ..\asxmak\vc6\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\vc6.zip *.exe
cd ..\..\..\zipper
zip -T vc6.zip
rem
cd ..\asxmak\vs05\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\vs05.zip *.exe
cd ..\..\..\zipper
zip -T vs05.zip
rem
cd ..\asxmak\vs10\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\vs10.zip *.exe
cd ..\..\..\zipper
zip -T vs10.zip
rem
cd ..\asxmak\watcom\exe\
..\..\..\zipper\zip.exe ..\..\..\zipper\watcom.zip *.exe
cd ..\..\..\zipper
zip -T watcom.zip
rem
rem  Final File Verification
rem
unzip -t cygwin.zip
unzip -t djgpp.zip
unzip -t linux.zip
unzip -t turboc30.zip
unzip -t symantec.zip
unzip -t vc6.zip
unzip -t vs05.zip
unzip -t vs10.zip
unzip -t watcom.zip
rem
rem Rename Files With Version Number
rem
rename cygwin.zip %1cygwin.zip
rename djgpp.zip %1djgpp.zip
rename linux.zip %1linux.zip
rename turboc30.zip %1turboc30.zip
rename symantec.zip %1symantec.zip
rename vc6.zip %1vc6.zip
rename vs05.zip %1vs05.zip
rename vs10.zip %1vs10.zip
rename watcom.zip %1watcom.zip

