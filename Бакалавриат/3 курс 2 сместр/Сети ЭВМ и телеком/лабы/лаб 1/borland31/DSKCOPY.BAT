@echo ---------------------------------------------------
@echo   Перенос дистрибутива Borland C++ 3.1 на дискеты
@echo ---------------------------------------------------
@echo

cd INSTALL

@echo Insert DISK 1
@pause
copy INSTALL.EXE        %1
copy UNZIP.EXE          %1
copy README.COM         %1
copy CLIBSRC.ZIP        %1
copy CLIBSRC1.ZIP       %1
copy CMDLG31.ZIP        %1
copy FILELIST.DOC       %1
copy INCLUDE.ZIP        %1
copy TD.CA2             %1
copy TDW.CA2            %1
copy WHELP2.CAB         %1
copy WINLBSRC.ZIP       %1
copy README             %1

@echo Insert DISK 2
@pause
copy ACLOCK.ZIP         %1
copy BGI.ZIP            %1
copy CLASSINC.ZIP       %1
copy CLASSSRC.ZIP       %1
copy CLIBSRC3.ZIP       %1
copy GDIDEMO.ZIP        %1
copy MATHSRC.ZIP        %1
copy OLESRVR.ZIP        %1
copy OWL.ZIP            %1
copy OWLSRC.ZIP         %1
copy RTLINSRC.ZIP       %1
copy TVDEMOS.ZIP        %1
copy TVINC.ZIP          %1
copy WHELP2.CAA         %1

@echo Insert DISK 3
@pause
copy CHESS.ZIP          %1
copy OWLINC.ZIP         %1
copy WBIN.CA1           %1
copy WHELP2.CA8         %1
copy WHELP2.CA9         %1

@echo Insert DISK 4
@pause
copy BATSRC.ZIP         %1
copy CMDLINE.CA1        %1
copy CURSOR.ZIP         %1
copy TDEXMPL.ZIP        %1
copy WHELP2.CA7         %1
copy WHEREIS.ZIP        %1
copy WINLIB.CA1         %1

@echo Insert DISK 5
@pause
copy BINDLL.ZIP         %1
copy CHECKERS.ZIP       %1
copy CLASSBLD.ZIP       %1
copy CLASSLIB.ZIP       %1
copy CLIBSRC2.ZIP       %1
copy EXAMPLES.ZIP       %1
copy RWCDEMO.ZIP        %1
copy TDWEXMPL.ZIP       %1
copy WHELP2.CA6         %1

@echo Insert DISK 6
@pause
copy CALC.ZIP           %1
copy DOC.ZIP            %1
copy HLIB.ZIP           %1
copy TASMEXMP.ZIP       %1
copy WEXAMPLE.ZIP       %1
copy WHELP2.CA4         %1
copy WHELP2.CA5         %1

@echo Insert DISK 7
@pause
copy BWCC.ZIP           %1
copy CHELP31.ZIP        %1
copy CLASSEXM.ZIP       %1
copy CLIB.ZIP           %1
copy CLIOLE.ZIP         %1
copy DDEML.ZIP          %1
copy DDEML31.ZIP        %1
copy FILEAPP.ZIP        %1
copy LLIB.ZIP           %1
copy OWLDEMOS.ZIP       %1
copy OWLDOC.ZIP         %1
copy RWDOC.ZIP          %1
copy STARTUP.ZIP        %1
copy SWAT.ZIP           %1
copy TFEXMPL.ZIP        %1
copy WIN31DEV.CA1       %1
copy WINCLUDE.ZIP       %1

@echo Insert DISK 8
@pause
copy HEAP.ZIP           %1
copy TASM.CA1           %1
copy WHELP2.CA3         %1
copy WIN31BIN.CA1       %1
copy XLIB.ZIP           %1

@echo Insert DISK 9
@pause
copy CMDLGAP.ZIP        %1
copy EMUSRC.ZIP         %1
copy FILT.ZIP           %1
copy IOSTRSR1.ZIP       %1
copy MLIB.ZIP           %1
copy OLE.ZIP            %1
copy PAINT.ZIP          %1
copy RW.CA1             %1
copy SLIB.ZIP           %1
copy TTFONT.ZIP         %1
copy TVHELP.ZIP         %1
copy WHELP2.CA2         %1

@echo Insert DISK 10
@pause
copy DLOBJ.ZIP          %1
copy DRAG.ZIP           %1
copy IDE.ZIP            %1
copy IOSTRSRC.ZIP       %1
copy MFILEAPP.ZIP       %1
copy OWLHELP.ZIP        %1
copy OWLLIB.CA1         %1
copy OWLPEN.ZIP         %1
copy OWLPRINT.ZIP       %1
copy PROGTALK.ZIP       %1
copy SCRNSAVE.ZIP       %1
copy SHELLAPI.ZIP       %1
copy SOUNDPLY.ZIP       %1
copy STEPS.ZIP          %1
copy SYSINFO.ZIP        %1
copy TCALC.ZIP          %1
copy TTT.ZIP            %1
copy TVSRC.ZIP          %1
copy WHELP1.CA1         %1
copy WLOBJ.ZIP          %1
copy WSOBJ.ZIP          %1

@echo Insert DISK 11
@pause
copy BIN.ZIP            %1
copy SOUNDER.ZIP        %1
copy TRUETYPE.ZIP       %1
copy TVLIB.ZIP          %1
copy WHELP2.CA1         %1
copy WHELP3.CA1         %1

@echo Insert DISK 12
@pause
copy CMDLINE.CA2        %1
copy TASM.CA2           %1
copy TD.CA1g            %1
copy TDW.CA1            %1
copy WHELP3.CA5         %1
copy WMOBJ.ZIP          %1

@echo Insert DISK 13
@pause
copy BC.CA2             %1
copy BINSRC.ZIP         %1
copy DRAGDROP.ZIP       %1
copy INDEPSRC.ZIP       %1
copy QUEUE.ZIP          %1
copy TDUTIL.ZIP         %1
copy TPROFW.ZIP         %1
copy WHELP3.CA4         %1

@echo Insert DISK 14
@pause
copy BC.CA1             %1
copy TPROF.ZIP          %1
copy WHELP3.CA3         %1
copy WIN31DEV.CA2       %1

@echo Insert DISK 15
@pause
copy WBIN.CA2           %1
copy WBIN.CA3           %1
copy WBIN.CA4           %1
copy WBIN.CA5           %1

@echo Insert DISK 16
@pause
copy OWLLIB.CA2         %1
copy TDDLL.ZIP          %1
copy WHELP1.CA2         %1
copy WHELP1.CA3         %1
copy WHELP3.CA2         %1

@echo Insert DISK 17
@pause
copy RW.CA2             %1
copy RW.CA3             %1
copy TVDOCDEM.ZIP       %1
copy WIN31BIN.CA2       %1
copy WINLIB.CA2         %1

@echo Insert DISK 18
@pause
copy WHELP1.CA4         %1

cd ..
