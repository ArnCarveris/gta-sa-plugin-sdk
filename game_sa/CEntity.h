#pragma once
#include "plugin\plugin.h"
#include "CPlaceable.h"
#include "RenderWare.h"
#include "CReference.h"
#include "eEntityType.h"
#include "eEntityStatus.h"
#include "CRect.h"

#pragma pack(push, 4)
class PLUGIN_API CEntity : public CPlaceable
{
public:
	RwObject *m_pRwObject;
	/* https://code.google.com/p/mtasa-blue/source/browse/trunk/MTA10/game_sa/CEntitySA.h */
	unsigned __int32 bUsesCollision : 1;           // does entity use collision
    unsigned __int32 bCollisionProcessed : 1;  // has object been processed by a ProcessEntityCollision function
    unsigned __int32 bIsStatic : 1;                // is entity static
    unsigned __int32 bHasContacted : 1;            // has entity processed some contact forces
    unsigned __int32 bIsStuck : 1;             // is entity stuck
    unsigned __int32 bIsInSafePosition : 1;        // is entity in a collision free safe position
    unsigned __int32 bWasPostponed : 1;            // was entity control processing postponed
    unsigned __int32 bIsVisible : 1;               //is the entity visible
    unsigned __int32 bIsBIGBuilding : 1;           // Set if this entity is a big building
    unsigned __int32 bRenderDamaged : 1;           // use damaged LOD models for objects with applicable damage
    unsigned __int32 bStreamingDontDelete : 1; // Dont let the streaming remove this 
    unsigned __int32 bRemoveFromWorld : 1;     // remove this entity next time it should be processed
    unsigned __int32 bHasHitWall : 1;              // has collided with a building (changes subsequent collisions)
    unsigned __int32 bImBeingRendered : 1;     // don't delete me because I'm being rendered
    unsigned __int32 bDrawLast :1;             // draw object last
    unsigned __int32 bDistanceFade :1;         // Fade entity because it is far away
    unsigned __int32 bDontCastShadowsOn : 1;       // Dont cast shadows on this object
    unsigned __int32 bOffscreen : 1;               // offscreen flag. This can only be trusted when it is set to true
    unsigned __int32 bIsStaticWaitingForCollision : 1; // this is used by script created entities - they are static until the collision is loaded below them
    unsigned __int32 bDontStream : 1;              // tell the streaming not to stream me
    unsigned __int32 bUnderwater : 1;              // this object is underwater change drawing order
    unsigned __int32 bHasPreRenderEffects : 1; // Object has a prerender effects attached to it
    unsigned __int32 bIsTempBuilding : 1;          // whether or not the building is temporary (i.e. can be created and deleted more than once)
    unsigned __int32 bDontUpdateHierarchy : 1; // Don't update the aniamtion hierarchy this frame
    unsigned __int32 bHasRoadsignText : 1;     // entity is roadsign and has some 2deffect text stuff to be rendered
    unsigned __int32 bDisplayedSuperLowLOD : 1;
    unsigned __int32 bIsProcObject : 1;            // set object has been generate by procedural object generator
    unsigned __int32 bBackfaceCulled : 1;          // has backface culling on
    unsigned __int32 bLightObject : 1;         // light object with directional lights
    unsigned __int32 bUnimportantStream : 1;       // set that this object is unimportant, if streaming is having problems
    unsigned __int32 bTunnel : 1;          // Is this model part of a tunnel
    unsigned __int32 bTunnelTransition : 1;        // This model should be rendered from within and outside of the tunnel
	/* */
	unsigned __int16 m_wRandomSeed;
	signed __int16 m_wModelIndex;
	CReference *m_pReferences;
	void *m_pStreamingLink;
	__int16 m_wScanCode;
	__int8 m_nIplIndex;
	unsigned __int8 m_nAreaCode;
	class CEntity *m_pLod;
	unsigned __int8 m_nNumLodChildren;
	unsigned __int8 m_nNumLodChildrenRendered;
	unsigned __int8 m_nTypeState;
	unsigned __int8 m_nType : 3;
    unsigned __int8 m_nStatus : 5;

	CEntity();
	~CEntity();

	virtual void Add(CRect &rect);
	virtual void Add(); // similar to previous, but with entity bound rect
	virtual void Remove();
	virtual void SetIsStatic(bool isStatic);
	virtual void SetModelIndex(unsigned int index);
	virtual void SetModelIndexNoCreate(unsigned int index);
};
#pragma pack(pop)

VALIDATE_SIZE(CEntity, 0x38);
