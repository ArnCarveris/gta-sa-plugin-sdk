/**********************SA Plugin SDK **************************/
/* This file is a part of SA Plugin SDK project.              */
/* File descrip: Basic header for working with plugins.       */
/* File creator: DK22Pac                                      */
/* File editors:                                              */
/* Last edited: 31/08/13                                      */
/**************************************************************/
#pragma once

#include <Windows.h>

#ifdef PLUGIN_EXPORT
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#pragma comment(lib, "plugin.lib")
#endif

#define FUNC(a) (void (*a)())

#define PREPARE_FOR_REDIRECTION() __asm { mov eax, -1 }
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)

typedef void (__cdecl* tRegisteredFunction)();

enum eFuncType
{
	FUNC_BEFORE_RESET,      /* calls at 0x7F9788
	                        /*          0x7F9710
							/*          0x7F935C
							/*          0x7F9248
							/*          0x7F86C2
							/*          0x7F9A16
							/*          0x7F839F
							/*          0x7F8327
							/*          0x7F81FF
							/*          0x7F8187
							/*          0x7F7AA4
							/*          0x7F8B79
							/*          0x7F7990
							/*          0x7F9B43
							/*          0x7F8C86
							/*          0x7F87C4
							*/
	FUNC_AFTER_RESET,       /* calls at 0x7F9788
	                        /*          0x7F9710
							/*          0x7F935C
							/*          0x7F9248
							/*          0x7F86C2
							/*          0x7F9A16
							/*          0x7F839F
							/*          0x7F8327
							/*          0x7F81FF
							/*          0x7F8187
							/*          0x7F7AA4
							/*          0x7F8B79
							/*          0x7F7990
							/*          0x7F9B43
							/*          0x7F8C86
							/*          0x7F87C4
							*/
	FUNC_DRAWING,           /* calls at 0x53E293
							*/
	FUNC_MENU_DRAWING,      /* calls at 0x57C2B5
							*/
	FUNC_PRERENDER_BEFORE,
	FUNC_PRERENDER_AFTER,
	FUNC_INITIALISE_RW,    // when RenderWare is initialising
	FUNC_SHUTDOWN_RW       // when RenderWare is closing
};

enum eGame
{
	GAME_SA_1_0_US = 1
};

class CPlugin
{
public:
	char name[16];
	char author[32];
	char fileName[32];
	char version[8];
	unsigned int versionId;
	unsigned int game;
	void *additionalData;
	int reserved[2];
};

namespace plugin
{
	namespace Core
	{
		PLUGIN_API void RegisterFunc(eFuncType type, tRegisteredFunction func);
		PLUGIN_API void DeviceResetAfterFunc();
		PLUGIN_API void DeviceResetBeforeFunc();
		PLUGIN_API long DeviceResetFuncExe();
		PLUGIN_API void DefaultDrawingFunc();
		PLUGIN_API void DefaultDrawingFuncExe();
		PLUGIN_API void MenuDrawingFunc();
		PLUGIN_API void MenuDrawingFuncExe();
		PLUGIN_API void PreRenderBeforeFunc();
		PLUGIN_API void PreRenderBeforeFuncExe();
		PLUGIN_API void PreRenderAfterFunc();
		PLUGIN_API void PreRenderAfterFuncExe();
		PLUGIN_API void InitialiseRwFunc();
		PLUGIN_API void InitialiseRwFuncExe();
		PLUGIN_API void ShutdownRwFunc();
		PLUGIN_API void ShutdownRwFuncExe();
	};
	namespace System
	{
		PLUGIN_API CPlugin const * RegisterPlugin(char *name, char *author, char *filename, char *version, unsigned int versionId, 
			unsigned int game, void *additionalData);
		PLUGIN_API CPlugin const * GetPluginByName(char *name);
	};
};