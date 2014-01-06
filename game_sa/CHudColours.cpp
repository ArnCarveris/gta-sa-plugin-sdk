#include "CHudColours.h"

CHudColours &HudColour = *(CHudColours *)0xBAB22C;

NOINLINE CHudColours::CHudColours()
{
	PREPARE_FOR_REDIRECTION();
	// ((void (__thiscall *)(CHudColours *))0x58FDA0)(this);
}

NOINLINE CHudColours::~CHudColours()
{
	PREPARE_FOR_REDIRECTION();
	// ((void (__thiscall *)(CHudColours *))0x58FD90)(this);
}

void CHudColours::SetRGBAValue(unsigned char color, unsigned char red, unsigned char green, 
							   unsigned char blue, unsigned char alpha)
{
	((void (__thiscall *)(CHudColours *, unsigned char, unsigned char, unsigned char, unsigned char, 
		unsigned char))0x58FD20)(this, color, red, green, blue, alpha);
}

unsigned int CHudColours::GetIntColour(unsigned char color)
{
	return ((unsigned int (__thiscall *)(CHudColours *, unsigned char))0x58FD50)(this, color);
}

CRGBA CHudColours::GetRGB(unsigned char color, unsigned char alpha)
{
	CRGBA result;
	((void (__thiscall *)(CHudColours *, CRGBA *, unsigned char, unsigned char))0x58FEE0)(this,
		&result, color, alpha);
	return result;
}

CRGBA CHudColours::GetRGBA(unsigned char color)
{
	CRGBA result;
	((void (__thiscall *)(CHudColours *, CRGBA *, unsigned char))0x58FEA0)(this, &result, color);
	return result;
}