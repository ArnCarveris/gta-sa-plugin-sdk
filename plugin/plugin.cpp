#include "plugin.h"
#include <d3d9.h>
#include <list>
#include "patch\CPatch.h"
#include "game_sa\CPool.h"
#include "game_sa\CVehicle.h"

using namespace std;

void AllocateVehicleAdditional();

unsigned int RyosukesChange3D = 0;
unsigned int RyosukesReset3D = 0;
HRESULT RyosukeResult;
void CheckForRyosukesPlugins();

void **vehicleAdditional;
unsigned int vehiclePluginsSize;
void **pedAdditional;
unsigned int pedPluginsSize;
void **objectAdditional;
unsigned int objectPluginsSize;

class CStructPlugin
{
public:
	unsigned int size;
	unsigned int userId;
	void *constructor;
	void *destructor;
};

list<CStructPlugin*>vehiclePlugins;

#define ProcessOneCommand(script) ((void (__thiscall *)(CRunningScript *))0x469EB0)(script);

list<CPlugin*>pluginList;
list<void (*)()>DeviceResetBeforeList;
list<void (*)()>DeviceResetAfterList;
list<void (*)()>DefaultDrawingList;
list<void (*)()>MenuDrawingList;
list<void (*)()>PreRenderBeforeList;
list<void (*)()>PreRenderAfterList;
list<void (*)()>InitialiseRWList;
list<void (*)()>ShutdownRWList;
list<void (*)()>InitGameList;
list<void (*)()>ReInitGameList;
list<void (*)()>GameProcessList;
list<void (*)()>GameProcessBeforeScriptsList;
list<void (*)()>GameProcessAfterScriptsList;
list<void (*)()>DrawBlipsBeforeList;
list<void (*)()>DrawBlipsAfterList;

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

/*unsigned int DeviceResetAddr[] = {0x7F9788, 0x7F9710, 0x7F935C, 0x7F9248, 0x7F9A16, 0x7F839F, 0x7F8327, 0x7F81FF,
	0x7F8187, 0x7F7AA4, 0x7F8B79, 0x7F7990, 0x7F9B43, 0x7F8C86, 0x7F87C4 };*/

void Initialise()
{
	CheckForRyosukesPlugins();
	CPatch::RedirectCall(0x7F9788, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F978D, 6);
	CPatch::RedirectCall(0x7F9710, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F9715, 6);
	CPatch::RedirectCall(0x7F935C, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F9361, 6);
	CPatch::RedirectCall(0x7F9248, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F924D, 6);
	CPatch::RedirectCall(0x7F9A16, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F9A1B, 6);
	CPatch::RedirectCall(0x7F839F, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F83A4, 6);
	CPatch::RedirectCall(0x7F8327, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F832C, 6);
	CPatch::RedirectCall(0x7F81FF, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F8204, 6);
	CPatch::RedirectCall(0x7F8187, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F818C, 6);
	CPatch::RedirectCall(0x7F7AA4, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F7AA9, 6);
	CPatch::RedirectCall(0x7F8B7B, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F8B80, 4);
	CPatch::RedirectCall(0x7F7990, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F7995, 6);
	CPatch::RedirectCall(0x7F9B43, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F9B48, 6);
	CPatch::RedirectCall(0x7F8C88, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F8C8D, 4);
	CPatch::RedirectCall(0x7F87C6, plugin::Core::DeviceResetFuncExe);
	CPatch::Nop(0x7F87CB, 4);
	CPatch::RedirectCall(0x7F86C4, plugin::Core::DeviceResetChangeFuncExe);
	CPatch::Nop(0x7F86C9, 4);
	CPatch::RedirectCall(0x53E293, plugin::Core::DefaultDrawingFuncExe);
	CPatch::RedirectCall(0x53E82D, plugin::Core::MenuDrawingFuncExe);
	CPatch::RedirectCall(0x53EB8C, plugin::Core::MenuDrawingFuncExe);
	CPatch::RedirectCall(0x53EA03, plugin::Core::PreRenderAfterFuncExe);
	CPatch::RedirectCall(0x5BD779, plugin::Core::InitialiseRwFuncExe);
	CPatch::RedirectCall(0x53BC21, plugin::Core::ShutdownRwFuncExe);
	CPatch::RedirectCall(0x748CFB, plugin::Core::InitGameFuncExe);
	CPatch::RedirectCall(0x748E09, plugin::Core::ReInitGameFuncExe);
	CPatch::RedirectCall(0x748E48, plugin::Core::ReInitGameFuncExe);
	CPatch::RedirectCall(0x53E981, plugin::Core::GameProcessFuncExe);
	CPatch::RedirectCall(0x440A0D, plugin::Core::GameProcessScriptsFuncExe);
	CPatch::RedirectCall(0x53BCC9, plugin::Core::GameProcessScriptsFuncExe); // _LoadGame
	CPatch::RedirectCall(0x53BE8D, plugin::Core::GameProcessScriptsFuncExe); // CGame::ReInitGameObjectVariables()
	CPatch::RedirectCall(0x53BFC7, plugin::Core::GameProcessScriptsFuncExe); // CGame::Process
	CPatch::RedirectCall(0x618F05, plugin::Core::GameProcessScriptsFuncExe);
	CPatch::RedirectJump(0x58AA2D, plugin::Core::DrawBlipsFuncExe);
}

void CheckForRyosukesPlugins()
{
	if(CPatch::CheckChar(0x7F86C4, 0xE8))
		RyosukesChange3D = *(unsigned __int32 *)0x7F86C5 + 0x7F86C9;
	if(CPatch::CheckChar(0x7F9710, 0xE8))
		RyosukesReset3D = *(unsigned __int32 *)0x7F9711 + 0x7F9715;
	else if(CPatch::CheckChar(0x7F9788, 0xE8))
		RyosukesReset3D = *(unsigned __int32 *)0x7F9789 + 0x7F978D;
	else if(CPatch::CheckChar(0x7F9A16, 0xE8))
		RyosukesReset3D = *(unsigned __int32 *)0x7F9A17 + 0x7F9A1B;
}

// vehicle additional data

void AllocateVehicleAdditional()
{
	vehicleAdditional = new void*[(*(CPool<CVehicle> **)0xB74494)->m_Size];
	vehiclePluginsSize = 0;
}

void ReleaseVehicleAdditional()
{
	delete vehicleAdditional;
	for(auto i = vehiclePlugins.begin(); i != vehiclePlugins.end(); ++i)
		delete i._Ptr->_Myval;
}

unsigned int plugin::StructPlugins::RegisterVehiclePlugin(unsigned int size, unsigned int userId, void *constructor, void *destructor)
{
	CStructPlugin *plugin = new CStructPlugin;
	plugin->size = size;
	plugin->userId = userId;
	plugin->constructor = constructor;
	plugin->destructor = destructor;
	vehiclePlugins.push_back(plugin);
	unsigned int result = vehiclePluginsSize;
	vehiclePluginsSize += size;
	return result;
}

void *plugin::StructPlugins::GetVehiclePlugin(CVehicle *vehicle, unsigned int id)
{
	unsigned int vehicleId = ((unsigned int)vehicle - (unsigned int)(*(CPool<CVehicle> **)0xB74494)->m_Objects) / 0xA18;
	return (void *)((unsigned int)vehicleAdditional[vehicleId] + id);
}

void *FindVehiclePluginByUserId(CVehicle *vehicle, unsigned int userId)
{
	unsigned int vehicleId = ((unsigned int)vehicle - (unsigned int)(*(CPool<CVehicle> **)0xB74494)->m_Objects) / 0xA18;
	unsigned int size = 0;
	for(auto i = vehiclePlugins.begin(); i != vehiclePlugins.end(); ++i)
	{
		if(i._Ptr->_Myval->userId == userId)
			return (void *)((unsigned int)vehicleAdditional[vehicleId] + size);
		size += i._Ptr->_Myval->size;
	}
	return NULL;
}

void __fastcall OnVehicleConstructor(CVehicle *vehicle)
{
	unsigned int vehicleId = ((unsigned int)vehicle - (unsigned int)(*(CPool<CVehicle> **)0xB74494)->m_Objects) / 0xA18;
	vehicleAdditional[vehicleId] = new __int8[vehiclePluginsSize];
	unsigned int size = 0;
	for(auto i = vehiclePlugins.begin(); i != vehiclePlugins.end(); ++i)
	{
		((void (*)(void *))i._Ptr->_Myval->constructor)((void *)((unsigned int)vehicleAdditional[vehicleId] + size));
		size += i._Ptr->_Myval->size;
	}
};

void __fastcall OnVehicleDestructor(CVehicle *vehicle)
{
	unsigned int vehicleId = ((unsigned int)vehicle - (unsigned int)(*(CPool<CVehicle> **)0xB74494)->m_Objects) / 0xA18;
	unsigned int size = 0;
	for(auto i = vehiclePlugins.begin(); i != vehiclePlugins.end(); ++i)
	{
		((void (*)(void *))i._Ptr->_Myval->destructor)((void *)((unsigned int)vehicleAdditional[vehicleId] + size));
		size += i._Ptr->_Myval->size;
	}
	delete vehicleAdditional[vehicleId];
};

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
	case FUNC_PRERENDER_BEFORE:
		PreRenderBeforeList.push_back(func);
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
	case FUNC_INIT_GAME:
		InitGameList.push_back(func);
		break;
	case FUNC_RE_INIT_GAME:
		ReInitGameList.push_back(func);
		break;
	case FUNC_GAME_PROCESS:
		GameProcessList.push_back(func);
		break;
	case FUNC_GAME_PROCESS_BEFORE_SCRIPTS:
		GameProcessBeforeScriptsList.push_back(func);
		break;
	case FUNC_GAME_PROCESS_AFTER_SCRIPTS:
		GameProcessAfterScriptsList.push_back(func);
		break;
	case FUNC_DRAWING_BEFORE_BLIPS:
		DrawBlipsBeforeList.push_back(func);
		break;
	case FUNC_DRAWING_AFTER_BLIPS:
		DrawBlipsAfterList.push_back(func);
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

void __declspec(naked) RyosukeReset3DSafeFunc()
{
	__asm mov eax, dword ptr ds:[0xC97C28]
	RyosukeResult = ((HRESULT (__cdecl *)())RyosukesReset3D)();
	__asm retn
}

HRESULT RyosukeReset3DFunc()
{
	RyosukeReset3DSafeFunc();
	return RyosukeResult;
}

void __declspec(naked) RyosukeChange3DSafeFunc()
{
	__asm mov eax, dword ptr ds:[0xC97C28]
	__asm mov ecx, [eax]
	RyosukeResult = ((HRESULT (__cdecl *)())RyosukesChange3D)();
	__asm retn
}

HRESULT RyosukeChange3DFunc()
{
	RyosukeChange3DSafeFunc();
	return RyosukeResult;
}

long plugin::Core::DeviceResetChangeFuncExe()
{
	HRESULT result;
	plugin::Core::DeviceResetBeforeFunc();
	if(RyosukesChange3D)
		result = RyosukeChange3DFunc();
	else
		result = (*(IDirect3DDevice9 **)0xC97C28)->Reset((D3DPRESENT_PARAMETERS *)0xC9C040);
	plugin::Core::DeviceResetAfterFunc();
	return result;
}

long plugin::Core::DeviceResetFuncExe()
{
	HRESULT result;
	plugin::Core::DeviceResetBeforeFunc();
	if(RyosukesReset3D)
		result = RyosukeReset3DFunc();
	else
		result = (*(IDirect3DDevice9 **)0xC97C28)->Reset((D3DPRESENT_PARAMETERS *)0xC9C040);
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

void __fastcall plugin::Core::MenuDrawingFuncExe(int menuMgr)
{
	((void (__thiscall *)(int))0x57C290)(menuMgr);
	if(!(*(__int8 *)0xBA677A))
		plugin::Core::MenuDrawingFunc();
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

PLUGIN_API void plugin::Core::InitGameFunc()
{
	for(auto i = InitGameList.begin(); i != InitGameList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::InitGameFuncExe()
{
	CALLVOID(0x53E580); // call LoadTheGame() at WinMain()
	plugin::Core::InitGameFunc();
}

PLUGIN_API void plugin::Core::ReInitGameFunc()
{
	for(auto i = ReInitGameList.begin(); i != ReInitGameList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::ReInitGameFuncExe()
{
	CALLVOID(0x53C680); // call CGame::InitialiseWhenRestarting() at WinMain()
	plugin::Core::ReInitGameFunc();
}

PLUGIN_API void plugin::Core::GameProcessFunc()
{
	for(auto i = GameProcessList.begin(); i != GameProcessList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::GameProcessFuncExe()
{
	CALLVOID(0x53BEE0); // call CGame::Process() at Idle()
	plugin::Core::GameProcessFunc();
}

PLUGIN_API void plugin::Core::GameProcessScriptsFuncExe()
{
	plugin::Core::GameProcessBeforeScriptsFunc();
	CALLVOID(0x46A000); // call CTheScripts::Process
	plugin::Core::GameProcessAfterScriptsFunc();
}

PLUGIN_API void plugin::Core::GameProcessBeforeScriptsFunc()
{
	for(auto i = GameProcessBeforeScriptsList.begin(); i != GameProcessBeforeScriptsList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::GameProcessAfterScriptsFunc()
{
	for(auto i = GameProcessAfterScriptsList.begin(); i != GameProcessAfterScriptsList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::DrawBlipsAfterFunc()
{
	for(auto i = DrawBlipsAfterList.begin(); i != DrawBlipsAfterList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::DrawBlipsBeforeFunc()
{
	for(auto i = DrawBlipsBeforeList.begin(); i != DrawBlipsBeforeList.end(); ++i)
		(*i)();
}

PLUGIN_API void plugin::Core::DrawBlipsFuncExe()
{
	plugin::Core::DrawBlipsBeforeFunc();
	CALLVOID(0x588050);
	plugin::Core::DrawBlipsAfterFunc();
}