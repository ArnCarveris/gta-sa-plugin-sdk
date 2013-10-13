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
#define NOINLINE __declspec(noinline)

typedef void (__cdecl* tRegisteredFunction)();

enum eFuncType
{
	FUNC_BEFORE_RESET,     // D3D9 Reset
	FUNC_AFTER_RESET,
	FUNC_DRAWING,           /* calls at 0x53E293
							*/
	FUNC_MENU_DRAWING,      /* calls at 0x57C2B5
							*/
	FUNC_PRERENDER_BEFORE,
	FUNC_PRERENDER_AFTER,
	FUNC_INITIALISE_RW,    // when RenderWare is initialising
	FUNC_SHUTDOWN_RW,      // when RenderWare is closing
	FUNC_INIT_GAME,        // when game is loading in first
	FUNC_RE_INIT_GAME,     // when game is re-loading
	FUNC_GAME_PROCESS,     // when game is processing
	FUNC_GAME_PROCESS_BEFORE_SCRIPTS, // before scripts processing
	FUNC_GAME_PROCESS_AFTER_SCRIPTS   // after scripts processing
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
		PLUGIN_API void InitGameFunc();
		PLUGIN_API void InitGameFuncExe();
		PLUGIN_API void ReInitGameFunc();
		PLUGIN_API void ReInitGameFuncExe();
		PLUGIN_API void GameProcessFunc();
		PLUGIN_API void GameProcessFuncExe();
		PLUGIN_API void GameProcessScriptsFuncExe();
		PLUGIN_API void GameProcessBeforeScriptsFunc();
		PLUGIN_API void GameProcessAfterScriptsFunc();
	};
	namespace System
	{
		PLUGIN_API CPlugin const * RegisterPlugin(char *name, char *author, char *filename, char *version, unsigned int versionId, 
			unsigned int game, void *additionalData);
		PLUGIN_API CPlugin const * GetPluginByName(char *name);
	};
};