// Copyright (c) 2017 by HHD Software Ltd.
// This file is part of the HHD Software Hex Editor Neo
// For usage and distribution policies, consult the license distributed with a product installation program

// This file describes the low-level API interface to the hexpatch.dll library.

// In addition to this low-level interface, hexpatch.dll also provides high-level COM Automation-compatible interface. 
// Please consult the included documentation for more information.

// The functionality provided by automation interface is the same as a one provided by this low-level interface except that
// automation interface does not allow you to provide a callback routine nor to cancel patch application.
// Therefore, to get a full power from this library, use a low-level interface whenever possible. 

// Note: this library must be registered (regsvr32.exe hexpatch.dll) to publish its automation interface. Registration is not necessary
// if you plan to use the low-level interface exclusively. Registration is usually performed automatically by the product installation program.

#pragma once

// ApplyPatch options flags
enum
{
	APO_NORMAL						=0x00000000,	// standard processing
	APO_SKIPFILENAMECHECK	=0x00000001,	// do not check file name
	APO_SKIPHASHCHECK			=0x00000002,	// do not calculate and check file hash
	APO_SKIPBACKUP				=0x00000004,	// do not create file backup
};

// Patching stages
enum
{
	StageUnknown,		// the stage is unknown
	StageCalculatingHash,		// ApplyPatch is currently calculating file hash
	StageCreatingBackup,		// ApplyPatch is currently writing file backup
	StageProcessingRelocations,		// ApplyPatch is processing file relocations
	StageApplyingPatch,		// ApplyPatch is applying patch
};

// Actions (to be returned from callback function)
enum
{
	ActionContinue,	// continue processing
	ActionCancel,		// cancel processing
};

#ifdef _HHD_PATCH_DLL_
	#define HHD_PATCHAPI __declspec(dllexport) __stdcall
#else
	#define HHD_PATCHAPI __declspec(dllimport) __stdcall
#endif

// Declaration of a callback routine (to be replaced by user routine)
typedef DWORD (__stdcall *ProgressRoutine)(DWORD Stage,int Percent) throw();

// Declarations of exported functions
extern "C"
{
	HRESULT HHD_PATCHAPI ApplyPatchFromStream(LPCTSTR FileName,IStream *pStream,DWORD options,ProgressRoutine progress=NULL);
	HRESULT HHD_PATCHAPI ApplyPatch(LPCTSTR FileName,LPCTSTR PatchName,DWORD options,ProgressRoutine progress=NULL);
};

// Parameter description follows:
//	> FileName is a full path to the patched file
//	> pStream is a pointer to a stream object located at the position where the patch data starts
//	> PatchName is a full path to the patch file
//	> options is one or more APO_* options combined using the logical OR (|) operator
//	> progress is an optional pointer to the callback routine (may be NULL)

//	The function returns standard OLE error code, or S_OK to signal success.

typedef HRESULT (__stdcall *ApplyPatchFromStreamRoutineType)(LPCTSTR FileName,IStream *pStream,DWORD options,ProgressRoutine progress);
typedef HRESULT (__stdcall *ApplyPatchRoutineType)(LPCTSTR FileName,LPCTSTR PatchName,DWORD options,ProgressRoutine progress);
