;Copyright (C) 2004-2008 John T. Haller

;Website: http://PortableApps.com/Notepad++Portable

;This software is OSI Certified Open Source Software.
;OSI Certified is a certification mark of the Open Source Initiative.

;This program is free software; you can redistribute it and/or
;modify it under the terms of the GNU General Public License
;as published by the Free Software Foundation; either version 2
;of the License, or (at your option) any later version.

;This program is distributed in the hope that it will be useful,
;but WITHOUT ANY WARRANTY; without even the implied warranty of
;MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;GNU General Public License for more details.

;You should have received a copy of the GNU General Public License
;along with this program; if not, write to the Free Software
;Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

!define NAME "Notepad++Portable"
!define PORTABLEAPPNAME "Notepad++ Portable"
!define APPNAME "Notepad++"
!define VER "1.6.7.0"
!define WEBSITE "PortableApps.com/Notepad++Portable"
!define DEFAULTEXE "Notepad++.exe"
!define DEFAULTAPPDIR "Notepad++"
!define DEFAULTSETTINGSDIR "settings"
!define LAUNCHERLANGUAGE "English"

;=== Program Details
Name "${PORTABLEAPPNAME}"
OutFile "..\..\${NAME}.exe"
Caption "${PORTABLEAPPNAME} | PortableApps.com"
VIProductVersion "${VER}"
VIAddVersionKey ProductName "${PORTABLEAPPNAME}"
VIAddVersionKey Comments "Allows ${APPNAME} to be run from a removable drive.  For additional details, visit ${WEBSITE}"
VIAddVersionKey CompanyName "PortableApps.com"
VIAddVersionKey LegalCopyright "John T. Haller"
VIAddVersionKey FileDescription "${PORTABLEAPPNAME}"
VIAddVersionKey FileVersion "${VER}"
VIAddVersionKey ProductVersion "${VER}"
VIAddVersionKey InternalName "${PORTABLEAPPNAME}"
VIAddVersionKey LegalTrademarks "PortableApps.com is a Trademark of Rare Ideas, LLC."
VIAddVersionKey OriginalFilename "${NAME}.exe"
;VIAddVersionKey PrivateBuild ""
;VIAddVersionKey SpecialBuild ""

;=== Runtime Switches
CRCCheck On
WindowIcon Off
SilentInstall Silent
AutoCloseWindow True
RequestExecutionLevel user

; Best Compression
SetCompress Auto
SetCompressor /SOLID lzma
SetCompressorDictSize 32
SetDatablockOptimize On

;=== Include
;(Standard NSIS)
!include Registry.nsh
!include TextFunc.nsh
!insertmacro GetParameters
!include FileFunc.nsh
!insertmacro GetRoot

;(NSIS Plugins)
!include TextReplace.nsh

;(Custom)
!include GetWindowsVersion.nsh
!include MoveFiles.nsh
!include ReadINIStrWithDefault.nsh
!include ReplaceInFileWithTextReplace.nsh


;=== Program Icon
Icon "..\..\App\AppInfo\appicon.ico"

;=== Icon & Stye ===
!define MUI_ICON "..\..\App\AppInfo\appicon.ico"

;=== Languages
;!insertmacro MUI_LANGUAGE "${LAUNCHERLANGUAGE}"
LoadLanguageFile "${NSISDIR}\Contrib\Language files\${LAUNCHERLANGUAGE}.nlf"
!include PortableApps.comLauncherLANG_${LAUNCHERLANGUAGE}.nsh

Var PROGRAMDIRECTORY
Var SETTINGSDIRECTORY
Var ADDITIONALPARAMETERS
Var EXECSTRING
Var PROGRAMEXECUTABLE
Var DISABLESPLASHSCREEN
Var SECONDARYLAUNCH
Var DEFAULTLOCATION
Var USERTYPE
Var MISSINGFILEORPATH
Var COMSPEC
Var APPLANGUAGE
Var USINGPORTABLERECOVERYFILES
Var WINDOWSVERSION
Var UsingANSIVersion

Section "Main"
	ReadEnvStr $COMSPEC COMSPEC

	;=== Check if already running
	System::Call 'kernel32::CreateMutexA(i 0, i 0, t "${NAME}") i .r1 ?e'
	Pop $0
	StrCmp $0 0 CheckRunning
		StrCpy $SECONDARYLAUNCH "true"
		Goto CheckINI

	CheckRunning:
		FindProcDLL::FindProc "Notepad++.exe"
		StrCmp $R0 "1" "" CheckINI
			MessageBox MB_OK|MB_ICONEXCLAMATION `$(LauncherAlreadyRunning)`
			Abort
		
	CheckINI:
		;=== Find the INI file, if there is one
		IfFileExists "$EXEDIR\${NAME}.ini" "" NoINI

			;=== Read the parameters from the INI file
			${ReadINIStrWithDefault} $PROGRAMEXECUTABLE "$EXEDIR\${NAME}.ini" "${NAME}" "${APPNAME}Executable" "${DEFAULTEXE}"
			
			${GetWindowsVersion} $WINDOWSVERSION
			StrCpy $WINDOWSVERSION $WINDOWSVERSION 2
			StrCmp $WINDOWSVERSION '95' UseANSIDefaultEXE
			StrCmp $WINDOWSVERSION '98' UseANSIDefaultEXE
			StrCmp $WINDOWSVERSION 'ME' UseANSIDefaultEXE
			
			${ReadINIStrWithDefault} $0 "$EXEDIR\${NAME}.ini" "${NAME}" "${APPNAME}Directory" "App\${DEFAULTAPPDIR}"
			StrCpy $PROGRAMDIRECTORY "$EXEDIR\$0"
			IfFileExists "$PROGRAMDIRECTORY\$PROGRAMEXECUTABLE" ReadSettingsDirectoryINI UseANSIDefaultEXE
			
			UseANSIDefaultEXE:
				${ReadINIStrWithDefault} $0 "$EXEDIR\${NAME}.ini" "${NAME}" "${APPNAME}Directory" "App\${DEFAULTAPPDIR}_ansi"
				StrCpy $PROGRAMDIRECTORY "$EXEDIR\$0"
				StrCpy $UsingANSIVersion "true"
			
			ReadSettingsDirectoryINI:
			${ReadINIStrWithDefault} $0 "$EXEDIR\${NAME}.ini" "${NAME}" "SettingsDirectory" "Data\${DEFAULTSETTINGSDIR}"
			StrCpy $SETTINGSDIRECTORY "$EXEDIR\$0"
			${ReadINIStrWithDefault} $ADDITIONALPARAMETERS "$EXEDIR\${NAME}.ini" "${NAME}" "AdditionalParameters" ""
			${ReadINIStrWithDefault} $DISABLESPLASHSCREEN "$EXEDIR\${NAME}.ini" "${NAME}" "DisableSplashScreen" "false"
			
			StrCmp $PROGRAMDIRECTORY "$EXEDIR\App\${DEFAULTAPPDIR}" "" CheckForFile
			StrCmp $SETTINGSDIRECTORY "$EXEDIR\Data\${DEFAULTSETTINGSDIR}" "" CheckForFile
				StrCpy $DEFAULTLOCATION "true"

		CheckForFile:
			IfFileExists "$PROGRAMDIRECTORY\$PROGRAMEXECUTABLE" FoundProgramEXE NoProgramEXE

	NoINI:
		;=== No INI file, so we'll use the defaults
		StrCpy $ADDITIONALPARAMETERS ""
		StrCpy $PROGRAMEXECUTABLE "${DEFAULTEXE}"
		StrCpy $DISABLESPLASHSCREEN "false"
		StrCpy $DEFAULTLOCATION "true"
		
		${GetWindowsVersion} $WINDOWSVERSION
		StrCpy $WINDOWSVERSION $WINDOWSVERSION 2
		StrCmp $WINDOWSVERSION '95' UseANSIEXE
		StrCmp $WINDOWSVERSION '98' UseANSIEXE
		StrCmp $WINDOWSVERSION 'ME' UseANSIEXE
	
		IfFileExists "$EXEDIR\App\${DEFAULTAPPDIR}\${DEFAULTEXE}" "" UseANSIEXE
			StrCpy $PROGRAMDIRECTORY "$EXEDIR\App\${DEFAULTAPPDIR}"
			StrCpy $SETTINGSDIRECTORY "$EXEDIR\Data\${DEFAULTSETTINGSDIR}"
			GoTo EndINI

	UseANSIEXE:
		IfFileExists "$EXEDIR\App\${DEFAULTAPPDIR}_ansi\${DEFAULTEXE}" "" NoProgramEXE
			StrCpy $PROGRAMDIRECTORY "$EXEDIR\App\${DEFAULTAPPDIR}_ansi"
			StrCpy $SETTINGSDIRECTORY "$EXEDIR\Data\${DEFAULTSETTINGSDIR}"
			StrCpy $UsingANSIVersion "true"

	EndINI:
		IfFileExists "$PROGRAMDIRECTORY\$PROGRAMEXECUTABLE" FoundProgramEXE

	NoProgramEXE:
		;=== Program executable not where expected
		StrCpy $MISSINGFILEORPATH $PROGRAMEXECUTABLE
		MessageBox MB_OK|MB_ICONEXCLAMATION `$(LauncherFileNotFound)`
		Abort
		
	FoundProgramEXE:
		StrCmp $SECONDARYLAUNCH "true" GetPassedParameters
		StrCmp $DISABLESPLASHSCREEN "true" SkipSplashScreen
			;=== Show the splash screen before processing the files
			InitPluginsDir
			File /oname=$PLUGINSDIR\splash.jpg "${NAME}.jpg"
			newadvsplash::show /NOUNLOAD 1200 0 0 -1 /L "$PLUGINSDIR\splash.jpg"

	SkipSplashScreen:
		;=== Check for data files
		IfFileExists "$PROGRAMDIRECTORY\config.xml" CheckRecoveryFiles ;=== settings already in program directory
		IfFileExists "$SETTINGSDIRECTORY\config.xml" MoveSettings ;=== settings found in data directory
		
		;=== Copy the default settings files
		StrCmp $DEFAULTLOCATION "true" "" MoveSettings ;=== if not default location, user should already have their settings setup
		CreateDirectory "$SETTINGSDIRECTORY"
		CopyFiles /SILENT "$EXEDIR\App\DefaultData\settings\*.*" "$SETTINGSDIRECTORY\"
		CreateDirectory "$SETTINGSDIRECTORY\plugins"
		CopyFiles /SILENT "$EXEDIR\App\DefaultData\settings\plugins\*.*" "$SETTINGSDIRECTORY\plugins\"
		CreateDirectory "$SETTINGSDIRECTORY\plugins\config"
		CreateDirectory "$SETTINGSDIRECTORY\plugins\config\tidy"
		CopyFiles /SILENT "$EXEDIR\App\DefaultData\settings\plugins\config\tidy\*.*" "$SETTINGSDIRECTORY\plugins\config\tidy"
	
	MoveSettings:
		Rename "$SETTINGSDIRECTORY\config.xml" "$PROGRAMDIRECTORY\config.xml"
		Rename "$SETTINGSDIRECTORY\contextMenu.xml" "$PROGRAMDIRECTORY\contextMenu.xml"
		Rename "$SETTINGSDIRECTORY\ConvertExt.enc" "$PROGRAMDIRECTORY\ConvertExt.enc"
		Rename "$SETTINGSDIRECTORY\ConvertExt.ini" "$PROGRAMDIRECTORY\ConvertExt.ini"
		Rename "$SETTINGSDIRECTORY\ConvertExt.lng" "$PROGRAMDIRECTORY\ConvertExt.lng"
		Rename "$SETTINGSDIRECTORY\insertExt.ini" "$PROGRAMDIRECTORY\insertExt.ini"
		Rename "$SETTINGSDIRECTORY\LightExplorer.ini" "$PROGRAMDIRECTORY\LightExplorer.ini"
		Rename "$SETTINGSDIRECTORY\NPPTextFX.ini" "$PROGRAMDIRECTORY\NPPTextFX.ini"
		Rename "$SETTINGSDIRECTORY\QuickText.ini" "$PROGRAMDIRECTORY\QuickText.ini"
		Rename "$SETTINGSDIRECTORY\session.xml" "$PROGRAMDIRECTORY\session.xml"
		Rename "$SETTINGSDIRECTORY\shortcuts.xml" "$PROGRAMDIRECTORY\shortcuts.xml"
		Rename "$SETTINGSDIRECTORY\SpellChecker.ini" "$PROGRAMDIRECTORY\SpellChecker.ini"
		Rename "$SETTINGSDIRECTORY\stylers.xml" "$PROGRAMDIRECTORY\stylers.xml"
		Rename "$SETTINGSDIRECTORY\nativeLang.xml" "$PROGRAMDIRECTORY\nativeLang.xml"
		Rename "$SETTINGSDIRECTORY\plugins\NPPTextFX.ini" "$PROGRAMDIRECTORY\plugins\NPPTextFX.ini"
		IfFileExists "$PROGRAMDIRECTORY\plugins\config" "" MoveConfigDirectory
			${MoveFiles} FORCE "*.*" "$SETTINGSDIRECTORY\plugins\config" "$PROGRAMDIRECTORY\plugins\config"
			RMDir /r "$SETTINGSDIRECTORY\plugins\config"
		MoveConfigDirectory:
			Rename "$SETTINGSDIRECTORY\plugins\config" "$PROGRAMDIRECTORY\plugins\config"
		;Other INIs from older plugins
		${MoveFiles} FORCE "*.ini" "$SETTINGSDIRECTORY" "$PROGRAMDIRECTORY"
		Rename "$PROGRAMDIRECTORY\Notepad++PortableSettings.ini" "$SETTINGSDIRECTORY\Notepad++PortableSettings.ini"
		
		;Move tidy files to the proper (but incorrect) location
		CreateDirectory "$PROGRAMDIRECTORY\plugins\Config\tidy"
		Rename "$PROGRAMDIRECTORY\plugins\tidy\AsciiToEBCDIC.bin" "$PROGRAMDIRECTORY\plugins\Config\tidy\AsciiToEBCDIC.bin"
		Rename "$PROGRAMDIRECTORY\plugins\tidy\libTidy.dll" "$PROGRAMDIRECTORY\plugins\Config\tidy\libTidy.dll"
		Rename "$PROGRAMDIRECTORY\plugins\tidy\W3C-CSSValidator.htm" "$PROGRAMDIRECTORY\plugins\Config\tidy\W3C-CSSValidator.htm"
		Rename "$PROGRAMDIRECTORY\plugins\tidy\W3C-HTMLValidator.htm" "$PROGRAMDIRECTORY\plugins\Config\tidy\W3C-HTMLValidator.htm"

		;=== Check for registry permissions and backup the key
		UserInfo::GetAccountType
		Pop $0
		StrCpy $USERTYPE $0
		StrCmp $USERTYPE "Guest" UpdateLocations
		StrCmp $USERTYPE "User" UpdateLocations
		${registry::KeyExists} "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file" $R0
		StrCmp $R0 "-1" UpdateLocations
		${registry::MoveKey} "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file" "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file-BackupByNotepad++Portable" $R0
	
	UpdateLocations:
		;=== Update files for new location
		${GetRoot} $EXEDIR $0
		ReadINIStr $1 "$SETTINGSDIRECTORY\Notepad++PortableSettings.ini" "Notepad++PortableSettings" "LastDriveLetter"
		StrCmp $1 "" StoreCurrentDriveLetter
		StrCmp $1 $0 StoreCurrentDriveLetter
		IfFileExists "$PROGRAMDIRECTORY\session.xml" "" UpdateExplorerPlugin
		${ReplaceInFile} "$PROGRAMDIRECTORY\session.xml" "$1\" "$0\"
	
	UpdateExplorerPlugin:
		IfFileExists "$PROGRAMDIRECTORY\plugins\config\Explorer.ini" "" UpdateLightExplorerPlugin
			${ReplaceInFile} "$PROGRAMDIRECTORY\plugins\config\Explorer.ini" "$1\" "$0\"
	
	UpdateLightExplorerPlugin:
		IfFileExists "$PROGRAMDIRECTORY\LightExplorer.ini" "" UpdateConfig
			${ReplaceInFile} "$PROGRAMDIRECTORY\LightExplorer.ini" "$1\" "$0\"

	UpdateConfig:
		IfFileExists "$PROGRAMDIRECTORY\config.xml" "" UpdateShortcuts
			${ReplaceInFile} "$PROGRAMDIRECTORY\config.xml" "$1\" "$0\"

	UpdateShortcuts:
		IfFileExists "$PROGRAMDIRECTORY\shortcuts.xml" "" StoreCurrentDriveLetter
			${ReplaceInFile} "$PROGRAMDIRECTORY\shortcuts.xml" "$1\" "$0\"
		
	StoreCurrentDriveLetter:
		WriteINIStr "$SETTINGSDIRECTORY\Notepad++PortableSettings.ini" "Notepad++PortableSettings" "LastDriveLetter" "$0"
		
	;SetLanguage
		ReadEnvStr $APPLANGUAGE "PortableApps.comLocaleWinName"
		StrCpy $APPLANGUAGE $APPLANGUAGE "" 5
		StrCmp $APPLANGUAGE "" CheckRecoveryFiles ;if not set, skip
		StrCmp $APPLANGUAGE "ENGLISH" RemoveLanguageFile
		StrCmp $APPLANGUAGE "TRADCHINESE" "" +2
			StrCpy $APPLANGUAGE "CHINESE"
		StrCmp $APPLANGUAGE "SIMPCHINESE" "" +2
			StrCpy $APPLANGUAGE "CHINESESIMPLIFIED"
		StrCmp $APPLANGUAGE "PORTUGUESEBR" "" +2
			StrCpy $APPLANGUAGE "BRAZILIAN_PORTUGUESE"
		StrCmp $APPLANGUAGE "SPANISHINTERNATIONAL" "" +2
			StrCpy $APPLANGUAGE "SPANISH_AR"
		IfFileExists "$PROGRAMDIRECTORY\localization\$APPLANGUAGE.xml" "" CheckRecoveryFiles
			Delete "$PROGRAMDIRECTORY\nativeLang.xml"
			CopyFiles /SILENT "$PROGRAMDIRECTORY\localization\$APPLANGUAGE.xml" "$PROGRAMDIRECTORY"
			Rename "$PROGRAMDIRECTORY\$APPLANGUAGE.xml" "$PROGRAMDIRECTORY\nativeLang.xml"
			Goto CheckRecoveryFiles

	RemoveLanguageFile:
		Delete "$PROGRAMDIRECTORY\nativeLang.xml"

	CheckRecoveryFiles:
		ReadEnvStr $0 "SystemDrive"
		StrCmp $0 "" 0 +2
			StrCpy $0 "C:"
		IfFileExists "$0\N++RECOV\*.*" 0 +2
			Rename "$0\N++RECOV" "$0\N++RECOV-BackupByNotepad++Portable"
			IfFileExists "$0\N++RECOV-BackupByNotepad++Portable\*.*" 0 MoveDirectoriesIfANSI
			StrCpy $USINGPORTABLERECOVERYFILES "true"
		IfFileExists "$SETTINGSDIRECTORY\Recovery\*.*" 0 MoveDirectoriesIfANSI
			CreateDirectory "$0\N++RECOV"
			CopyFiles /SILENT "$SETTINGSDIRECTORY\Recovery\*.*" "$0\N++RECOV"
			IfFileExists "$SETTINGSDIRECTORY\Recovery\*.*" 0 MoveDirectoriesIfANSI
				RMDir /r "$SETTINGSDIRECTORY\Recovery"
	
	MoveDirectoriesIfANSI:
		StrCmp $SECONDARYLAUNCH "true" GetPassedParameters
		StrCmp $UsingANSIVersion "true" "" GetPassedParameters
			Rename "$EXEDIR\App\${DEFAULTAPPDIR}\themes" "$EXEDIR\App\${DEFAULTAPPDIR}_ansi\themes"
	
	GetPassedParameters:
		;=== Get any passed parameters
		${GetParameters} $0
		StrCmp "'$0'" "''" "" LaunchProgramParameters

		;=== No parameters
		StrCpy $EXECSTRING `"$PROGRAMDIRECTORY\$PROGRAMEXECUTABLE"`
		Goto AdditionalParameters

	LaunchProgramParameters:
		StrCpy $EXECSTRING `"$PROGRAMDIRECTORY\$PROGRAMEXECUTABLE" $0`

	AdditionalParameters:
		StrCmp $ADDITIONALPARAMETERS "" LaunchNow

		;=== Additional Parameters
		StrCpy $EXECSTRING `$EXECSTRING $ADDITIONALPARAMETERS`

	LaunchNow:
		StrCmp $SECONDARYLAUNCH "true" LaunchAndExit
		ExecWait $EXECSTRING

		;=== Move settings back
		Delete "$SETTINGSDIRECTORY\config.xml"
		Delete "$SETTINGSDIRECTORY\contextMenu.xml"
		Delete "$SETTINGSDIRECTORY\ConvertExt.enc"
		Delete "$SETTINGSDIRECTORY\ConvertExt.ini"
		Delete "$SETTINGSDIRECTORY\ConvertExt.lng"
		Delete "$SETTINGSDIRECTORY\insertExt.ini"
		Delete "$SETTINGSDIRECTORY\LightExplorer.ini"
		Delete "$SETTINGSDIRECTORY\NPPTextFX.ini"
		Delete "$SETTINGSDIRECTORY\QuickText.ini"
		Delete "$SETTINGSDIRECTORY\session.xml"
		Delete "$SETTINGSDIRECTORY\shortcuts.xml"
		Delete "$SETTINGSDIRECTORY\SpellChecker.ini"
		Delete "$SETTINGSDIRECTORY\stylers.xml"
		Delete "$SETTINGSDIRECTORY\nativeLang.xml"
		Delete "$SETTINGSDIRECTORY\plugins\NPPTextFX.ini"
		Delete "$SETTINGSDIRECTORY\plugins\config\Explorer.ini"
		Delete "$SETTINGSDIRECTORY\plugins\config\HexEditor.ini"
		Delete "$SETTINGSDIRECTORY\plugins\config\NppExec.ini"
		Delete "$SETTINGSDIRECTORY\plugins\config\SpellChecker.ini"
		Rename "$PROGRAMDIRECTORY\config.xml" "$SETTINGSDIRECTORY\config.xml"
		Rename "$PROGRAMDIRECTORY\contextMenu.xml" "$SETTINGSDIRECTORY\contextMenu.xml"
		Rename "$PROGRAMDIRECTORY\ConvertExt.enc" "$SETTINGSDIRECTORY\ConvertExt.enc"
		Rename "$PROGRAMDIRECTORY\ConvertExt.ini" "$SETTINGSDIRECTORY\ConvertExt.ini"
		Rename "$PROGRAMDIRECTORY\ConvertExt.lng" "$SETTINGSDIRECTORY\ConvertExt.lng"
		Rename "$PROGRAMDIRECTORY\insertExt.ini" "$SETTINGSDIRECTORY\insertExt.ini"
		Rename "$PROGRAMDIRECTORY\LightExplorer.ini" "$SETTINGSDIRECTORY\LightExplorer.ini"
		Rename "$PROGRAMDIRECTORY\NPPTextFX.ini" "$SETTINGSDIRECTORY\NPPTextFX.ini"
		Rename "$PROGRAMDIRECTORY\QuickText.ini" "$SETTINGSDIRECTORY\QuickText.ini"
		Rename "$PROGRAMDIRECTORY\session.xml" "$SETTINGSDIRECTORY\session.xml"
		Rename "$PROGRAMDIRECTORY\shortcuts.xml" "$SETTINGSDIRECTORY\shortcuts.xml"
		Rename "$PROGRAMDIRECTORY\SpellChecker.ini" "$SETTINGSDIRECTORY\SpellChecker.ini"
		Rename "$PROGRAMDIRECTORY\stylers.xml" "$SETTINGSDIRECTORY\stylers.xml"
		Rename "$PROGRAMDIRECTORY\nativeLang.xml" "$SETTINGSDIRECTORY\nativeLang.xml"
		CreateDirectory "$SETTINGSDIRECTORY\plugins"
		
		;Move tidy files from the proper (but incorrect) location
		CreateDirectory "$PROGRAMDIRECTORY\plugins\tidy"
		Rename "$PROGRAMDIRECTORY\plugins\Config\tidy\AsciiToEBCDIC.bin" "$PROGRAMDIRECTORY\plugins\tidy\AsciiToEBCDIC.bin"
		Rename "$PROGRAMDIRECTORY\plugins\Config\tidy\libTidy.dll" "$PROGRAMDIRECTORY\plugins\tidy\libTidy.dll"
		Rename "$PROGRAMDIRECTORY\plugins\Config\tidy\W3C-CSSValidator.htm" "$PROGRAMDIRECTORY\plugins\tidy\W3C-CSSValidator.htm"
		Rename "$PROGRAMDIRECTORY\plugins\Config\tidy\W3C-HTMLValidator.htm" "$PROGRAMDIRECTORY\plugins\tidy\W3C-HTMLValidator.htm"
		
		Rename "$PROGRAMDIRECTORY\plugins\config" "$SETTINGSDIRECTORY\plugins\config"
		
		
		Rename "$PROGRAMDIRECTORY\plugins\NPPTextFX.ini" "$SETTINGSDIRECTORY\plugins\NPPTextFX.ini"
		;Other INIs from older plugins
		${MoveFiles} FORCE "*.ini" "$PROGRAMDIRECTORY" "$SETTINGSDIRECTORY"
		
		StrCmp $UsingANSIVersion "true" "" RestoreRegistryKey
			Rename "$EXEDIR\App\${DEFAULTAPPDIR}_ansi\themes" "$EXEDIR\App\${DEFAULTAPPDIR}\themes"

		RestoreRegistryKey:
		StrCmp $USERTYPE "Guest" RestoreRecoveryFiles
		StrCmp $USERTYPE "User" RestoreRecoveryFiles
		${registry::DeleteKey} "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file" $R0
		${registry::KeyExists} "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file-BackupByNotepad++Portable" $R0
		StrCmp $R0 "-1" RestoreRecoveryFiles
		${registry::MoveKey} "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file-BackupByNotepad++Portable" "HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Notepad++_file" $R0
		
	RestoreRecoveryFiles:
		ReadEnvStr $0 "SystemDrive"
		StrCmp $0 "" 0 +2
			StrCpy $0 "C:"
		IfFileExists "$0\N++RECOV\*.*" 0 RenameOriginalRecoveryFiles
			CreateDirectory "$SETTINGSDIRECTORY\Recovery"
			StrCmp $USINGPORTABLERECOVERYFILES "true" 0 RenameOriginalRecoveryFiles
			CopyFiles /SILENT "$0\N++RECOV\*.*" "$SETTINGSDIRECTORY\Recovery"
		RenameOriginalRecoveryFiles:
			IfFileExists "$0\N++RECOV-BackupByNotepad++Portable\*.*" 0 TheEnd
				Rename "$0\N++RECOV-BackupByNotepad++Portable" "$0\N++RECOV"
				Goto TheEnd
	
	LaunchAndExit:
		Exec $EXECSTRING

	TheEnd:
		${registry::Unload}
		newadvsplash::stop /WAIT
SectionEnd