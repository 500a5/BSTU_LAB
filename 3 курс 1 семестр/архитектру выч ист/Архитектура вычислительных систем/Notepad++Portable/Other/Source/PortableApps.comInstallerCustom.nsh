!macro CustomCodePreInstall
	IfFileExists "$INSTDIR\App\AppInfo\appinfo.ini" "" CustomCodePreInstallEnd
		ReadINIStr $0 "$INSTDIR\App\AppInfo\appinfo.ini" "Version" "PackageVersion"
			${VersionCompare} "$0" "5.1.1.0" $1
			IntCmp $1 1 CustomCodePreInstallEnd CustomCodePreInstallWasANSI

	CustomCodePreInstallWasANSI:
		Rename "$INSTDIR\App\Notepad++" "$INSTDIR\App\Notepad++_ansi"
		CreateDirectory "$INSTDIR\App\Notepad++"
		Rename "$INSTDIR\App\Notepad++_ansi\locales" "$INSTDIR\App\Notepad++\locales"
		Rename "$INSTDIR\Data\settings\plugins\NPPTextFX" "$INSTDIR\Data\settings\plugins\Config\tidy" ;preserve custom tidy settings

	CustomCodePreInstallEnd:
!macroend