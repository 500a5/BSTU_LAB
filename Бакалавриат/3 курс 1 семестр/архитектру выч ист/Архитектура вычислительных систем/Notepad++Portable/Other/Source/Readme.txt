Notepad++ Portable Launcher
===========================

Copyright 2004-2008 John T. Haller

Website: http://PortableApps.com/NotepadppPortable

This software is OSI Certified Open Source Software.
OSI Certified is a certification mark of the Open Source Initiative.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

ABOUT NOTEDPAD++ PORTABLE
=========================
The Notepad++ Portable Launcher allows you to run Notepad++ from a removable drive whose
letter changes as you move it to another computer.  The application can be entirely self-
contained on the drive and then used on any Windows computer.


LICENSE
=======
This code is released under the GPL.  The full code is included with this package as
Notepad++Portable.nsi.


INSTALLATION / DIRECTORY STRUCTURE
==================================
By default, the program expects this directory structure:

-\ <--- Directory with Notepad++Portable.exe
	+\App\
		+\Notepad++\
	+\Data\
		+\settings\

It can be used in other directory configurations by including the Notepad++Portable.ini
file in the same directory as Notepad++Portable.exe and configuring it as details in the
INI file section below.


Notepad++Portable.INI CONFIGURATION
===================================
The Notepad++ Portable Launcher will look for an ini file called Notepad++Portable.ini
within its directory (see the Installation/Directory Structure section above for more
details).  If you are happy with the default options, it is not necessary, though.  The
INI file is formatted as follows:

[Notepad++Portable]
Notepad++Directory=App\Notepad++
SettingsDirectory=Data\settings
Notepad++Executable=Notepad++.exe
AdditionalParameters=
DisableSplashScree=false

The Notepad++Directory and SettingsDirectory entries should be set to the *relative* path
to the directory containing Notepad++.exe and the settings files.  They must be a
subdirectory (or multiple subdirectories) of the directory containing
Notepad++Portable.exe.  The default entries for these are described in the installation
section above.

The Notepad++Executable entry allows you to set the Notepad++ Portable Launcher to use an
alternate EXE call to launch Notepad++.  This is helpful if you are using a machine that
is set to deny Notepad++.exe from running or to launch the writer, calc, etc directly.
You'll need to rename the Notepad++.exe file and then enter the name you gave it on the
Notepad++Executable= line of the INI.

The AdditionalParameters entry allows you to pass additional commandline parameter
entries to Notepad++.exe.  Whatever you enter here will be appended to the call to
Notepad++.exe.

The SkipBackups entry allows you to disable the launcher's automatic backup
functionality.  This is useful when running Notepad++ Portable on a USB flash drive with
the read/write switch set to read-only, thus avoiding the write-protection errors that
would be produced.

DisableSplashScreen allows you to disable the splash screen when set to true.


PROGRAM HISTORY / ABOUT THE AUTHOR
==================================
This launcher grew out of my work on the Firefox Portable and Thunderbird Portable
projects.  Some of the ideas arose from discussions relating to Firefox Portable &
Thunderbird Portable in the mozillaZine forums.