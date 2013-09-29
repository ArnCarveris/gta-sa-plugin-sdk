#include "plugin.h"
#include <d3d9.h>
#include <list>
#include "patch\CPatch.h"

using namespace std;

#define ProcessOneCommand(script) ((void (__thiscall *)(CRunningScript *))0x469EB0)(script);

list<CPlugin*>pluginList;
list<void (*)()>DeviceResetBeforeList;
list<void (*)()>DeviceResetAfterList;
list<void (*)()>DefaultDrawingList;
list<void (*)()>MenuDrawingList;
list<void (*)()>PreRenderAfterList;
list<void (*)()>InitialiseRWList;
list<void (*)()>ShutdownRWList;

void Initialise();
void Shutdown();

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		Initialise();
		break;
	case DLL_PROCESS_DETACH:
		Shutdown();
	}
	return TRUE;
}

unsigned int DeviceResetAddr[] = {0x7F9788, 0x7F9710, 0x7F935C, 0x7F9248, 0x7F86C2, 0x7F9A16, 0x7F839F, 0x7F8327, 0x7F81FF,
	0x7F8187, 0x7F7AA4, 0x7F8B79, 0x7F7990, 0x7F9B43, 0x7F8C86, 0x7F87C4 };

void Initialise()
{
	for(int i=0; i<16; i++)
	{
		CPatch::RedirectCall(DeviceResetAddr[i], plugin::Core::DeviceResetFuncExe);
		CPatch::Nop(DeviceResetAddr[i] + 5, 6);
	}
	CPatch::RedirectCall(0x53E293, plugin::Core::DefaultDrawingFuncExe);
	CPatch::RedirectCall(0x57C2B5, plugin::Core::MenuDrawingFuncExe);
	CPatch::RedirectCall(0x53EA03, plugin::Core::PreRenderAfterFuncExe);
	CPatch::RedirectCall(0x5BD779, plugin::Core::InitialiseRwFuncExe);
	CPatch::RedirectCall(0x53BC21, plugin::Core::ShutdownRwFuncExe);
}

void Shutdown()
{
	for(auto i = pluginList.begin(); i != pluginList.end(); ++i)
		delete *i;
}

void plugin::Core::RegisterFunc(eFuncType type, tRegisteredFunction func)
{
	switch(type)
	{
	case FUNC_BEFORE_RESET:
		DeviceResetBeforeList.push_back(func);
		break;
	case FUNC_AFTER_RESET:
		DeviceResetAfterList.push_back(func);
		break;
	case FUNC_DRAWING:
		DefaultDrawingList.push_back(func);
		break;
	case FUNC_MENU_DRAWING:
		MenuDrawingList.push_back(func);
		break;
	case FUNC_PRERENDER_AFTER:
		PreRenderAfterList.push_back(func);
		break;
	case FUNC_INITIALISE_RW:
		InitialiseRWList.push_back(func);
		break;
	case FUNC_SHUTDOWN_RW:
		ShutdownRWList.push_back(func);
		break;
	}
}

CPlugin const * plugin::System::RegisterPlugin(char *name, 
						  char *author, 
						  char *filename, 
						  char *version, 
						  unsigned int versionId, 
						  unsigned int game, 
						  void *additionalData)
{
	CPlugin *plug = new CPlugin;
	strcpy_s(plug->author, author);
	strcpy_s(plug->fileName, filename);
	strcpy_s(plug->name, name);
	strcpy_s(plug->version, version);
	plug->game = game;
	plug->additionalData = additionalData;
	plug->versionId = versionId;
	pluginList.push_back(plug);
	return plug;
}

CPlugin const * plugin::System::GetPluginByName(char *name)
{
	for(auto i = pluginList.begin(); i != pluginList.end(); ++i)
	{
		if(!strcmp((*i)->name, name))
			return *i;
	}
	return NULL;
}

long plugin::Core::DeviceResetFuncExe()
{
	plugin::Core::DeviceResetBeforeFunc();
	HRESULT result = (*(IDirect3DDevice9 **)0xC97C28)->Reset((D3DPRESENT_PARAMETERS *)0xC9C040);
	plugin::Core::DeviceResetAfterFunc();
	return result;
}

void plugin::Core::DeviceResetBeforeFunc()
{
	for(auto i = DeviceResetBeforeList.begin(); i != DeviceResetBeforeList.end(); ++i)
		(*i)();
}

void plugin::Core::DeviceResetAfterFunc()
{
	for(auto i = DeviceResetAfterList.begin(); i != DeviceResetAfterList.end(); ++i)
		(*i)();
}

void plugin::Core::DefaultDrawingFunc()
{
	for(auto i = DefaultDrawingList.begin(); i != DefaultDrawingList.end(); ++i)
		(*i)();
}

void plugin::Core::DefaultDrawingFuncExe()
{
	plugin::Core::DefaultDrawingFunc();
}

void plugin::Core::MenuDrawingFunc()
{
	for(auto i = MenuDrawingList.begin(); i != MenuDrawingList.end(); ++i)
		(*i)();
}

void plugin::Core::MenuDrawingFuncExe()
{
	plugin::Core::MenuDrawingFunc();
	CALLVOID(0x734750);
}

void plugin::Core::PreRenderAfterFunc()
{
	for(auto i = PreRenderAfterList.begin(); i != PreRenderAfterList.end(); ++i)
		(*i)();
}

void plugin::Core::PreRenderAfterFuncExe()
{
	CALLVOID(0x563430);
	plugin::Core::PreRenderAfterFunc();
}

PLUGIN_API void plugin::Core::InitialiseRwFunc()
{
	for(auto i = InitialiseRWList.begin(); i != InitialiseRWList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::InitialiseRwFuncExe()
{
	CALLVOID(0x704630);
	plugin::Core::InitialiseRwFunc();
}

PLUGIN_API void plugin::Core::ShutdownRwFunc()
{
	for(auto i = ShutdownRWList.begin(); i != ShutdownRWList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::ShutdownRwFuncExe()
{
	CALLVOID(0x730900);
	plugin::Core::ShutdownRwFunc();
}