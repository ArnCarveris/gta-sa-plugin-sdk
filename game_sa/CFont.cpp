#include "CFont.h"

CSprite2d *CFont::Sprite = (CSprite2d *)0xC71AD0;
CSprite2d *CFont::ButtonSprite = (CSprite2d *)0xC71AD8;

void CFont::Initialise()
{
	((void (__cdecl *)())0x5BA690)();
}

void CFont::Shutdown()
{
	((void (__cdecl *)())0x7189B0)();
}

void CFont::PrintChar(float x, float y, char character)
{
	((void (__cdecl *)(float, float, char))0x718A10)(x, y, character);
}

char *CFont::GetNextSpace(char *string)
{
	return ((char *(__cdecl *)(char *))0x718ED0)(string);
}

char *CFont::ParseToken(char *text, CRGBA & color, bool isBlip, char *tag)
{
	return ((char *(__cdecl *)(char *, CRGBA &, bool, char *))0x718F00)(text, color, isBlip, tag);
}

void CFont::SetScale(float w, float h)
{
	((void (__cdecl *)(float, float))0x719380)(w, h);
}

void CFont::SetScaleForCurrentlanguage(float w, float h)
{
	((void (__cdecl *)(float, float))0x7193A0)(w, h);
}

void CFont::SetSlantRefPoint(float x, float y)
{
	((void (__cdecl *)(float, float))0x719400)(x, y);
}

void CFont::SetSlant(float value)
{
	((void (__cdecl *)(float))0x719420)(value);
}

void CFont::SetColor(CRGBA color)
{
	((void (__cdecl *)(CRGBA))0x719430)(color);
}

void CFont::SetFontStyle(short style)
{
	((void (__cdecl *)(short))0x719490)(style);
}

void CFont::SetWrapx(float value)
{
	((void (__cdecl *)(float))0x7194D0)(value);
}

void CFont::SetCentreSize(float value)
{
	((void (__cdecl *)(float))0x7194E0)(value);
}

void CFont::SetRightJustifyWrap(float value)
{
	((void (__cdecl *)(float))0x7194F0)(value);
}

void CFont::SetAlphaFade(float alpha)
{
	((void (__cdecl *)(float))0x719500)(alpha);
}

void CFont::SetDropColor(CRGBA color)
{
	((void (__cdecl *)(CRGBA))0x719510)(color);
}

void CFont::SetDropShadowPosition(short value)
{
	((void (__cdecl *)(short))0x719570)(value);
}

void CFont::SetOutlinePosition(short value)
{
	((void (__cdecl *)(short))0x719590)(value);
}


#ifdef SetProp
#define SET_PROP_USED
#undef SetProp
#endif
void CFont::SetProp(bool on)
{
	((void (__cdecl *)(bool))0x7195B0)(on);
}
#ifdef SET_PROP_USED
#undef SET_PROP_USED
#define SetProp SetPropA
#endif

void CFont::SetBackground(bool background, bool backgroundOnlyText)
{
	((void (__cdecl *)(bool, bool))0x7195C0)(background, backgroundOnlyText);
}

void CFont::SetBackgroundColor(CRGBA color)
{
	((void (__cdecl *)(CRGBA))0x7195E0)(color);
}

void CFont::SetJustify(bool on)
{
	((void (__cdecl *)(bool))0x719600)(on);
}

void CFont::SetAlignment(eFontAlignment alignment)
{
	((void (__cdecl *)(eFontAlignment))0x719610)(alignment);
}

void CFont::InitPerFrame()
{
	((void (__cdecl *)())0x719800)();
}

void CFont::RenderFontBuffer()
{
	((void (__cdecl *)())0x719840)();
}

float CFont::GetStringWidth(char *string, bool unk1, bool unk2)
{
	return ((float (__cdecl *)(char *, bool, bool))0x71A0E0)(string, unk1, unk2);
}

void CFont::DrawFonts()
{
	((void (__cdecl *)())0x71A210)();
}

int CFont::GetNumberLines(bool print, float x, float y, char *text)
{
	return ((int (__cdecl *)(bool, float, float, char *))0x71A220)(print, x, y, text);
}

int CFont::GetNumberLinesNoPrint(float x, float y, char *text)
{
	return ((int (__cdecl *)(float, float, char *))0x71A5E0)(x, y, text);
}

int CFont::GetNumberLinesPrint(float x, float y, char *text)
{
	return ((int (__cdecl *)(float, float, char *))0x71A600)(x, y, text);
}

void CFont::GetTextRect(CRect *rect, float x, float y, char *text)
{
	((void (__cdecl *)(CRect *, float, float, char *))0x71A620)(rect, x, y, text);
}

void CFont::PrintString(float x, float y, char *text)
{
	((void (__cdecl *)(float, float, char *))0x71A700)(x, y, text);
}

void CFont::PrintStringFromBottom(float x, float y, char *text)
{
	((void (__cdecl *)(float, float, char *))0x71A820)(x, y, text);
}