/**********************SA Plugin SDK **************************/
/* This file is a part of SA Plugin SDK project.              */
/* File descrip: Basic header for working with plugins.       */
/* File creator: DK22Pac                                      */
/* File editors:                                              */
/* Last edited: 03/01/14                                      */
/**************************************************************/
#pragma once

#include <Windows.h>
#include <stddef.h>

#define PLUGIN_EXPORT

#ifdef PLUGIN_EXPORT
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#pragma comment(lib, "plugin.lib")
#endif

#define PREPARE_FOR_REDIRECTION() const char* __GFDIKGJDSFSF__ = __FUNCTION__; __asm { mov eax, __GFDIKGJDSFSF__ }
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
#define VALIDATE_OFFSET(struc, member, offset) \
	static_assert(offsetof(struc, member) == offset, "The offset of " #member " in " #struc " is not " #offset "...")
#define NOINLINE __declspec(noinline)

// basic types for structures describing
typedef signed __int32 Int32;
typedef unsigned __int32 UInt32;
typedef signed __int16 Int16;
typedef unsigned __int16 UInt16;
typedef signed __int8 Int8;
typedef unsigned __int8 UInt8;
typedef unsigned __int8 Bool;
typedef float Float;