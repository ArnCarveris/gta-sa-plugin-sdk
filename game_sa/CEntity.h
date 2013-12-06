#pragma once
#include "plugin\plugin.h"
#include "CPlaceable.h"
#include "RenderWare.h"
#include "CReference.h"
#include "eEntityType.h"
#include "eEntityStatus.h"
#include "CRect.h"
#include "CColModel.h"

#pragma pack(push, 4)
class PLUGIN_API CEntity : public CPlaceable
{
public:
	RwObject *m_pRwObject;
	/* https://code.google.com/p/mtasa-blue/source/browse/trunk/MTA10/game_sa/CEntitySA.h */
	unsigned __int32 m_bUsesCollision : 1;           // does entity use collision
	unsigned __int32 m_bCollisionProcessed : 1;  // has object been processed by a ProcessEntityCollision function
	unsigned __int32 m_bIsStatic : 1;                // is entity static
	unsigned __int32 m_bHasContacted : 1;            // has entity processed some contact forces
	unsigned __int32 m_bIsStuck : 1;             // is entity stuck
	unsigned __int32 m_bIsInSafePosition : 1;        // is entity in a collision free safe position
	unsigned __int32 m_bWasPostponed : 1;            // was entity control processing postponed
	unsigned __int32 m_bIsVisible : 1;               //is the entity visible
	unsigned __int32 m_bIsBIGBuilding : 1;           // Set if this entity is a big building
	unsigned __int32 m_bRenderDamaged : 1;           // use damaged LOD models for objects with applicable damage
	unsigned __int32 m_bStreamingDontDelete : 1; // Dont let the streaming remove this 
	unsigned __int32 m_bRemoveFromWorld : 1;     // remove this entity next time it should be processed
	unsigned __int32 m_bHasHitWall : 1;              // has collided with a building (changes subsequent collisions)
	unsigned __int32 m_bImBeingRendered : 1;     // don't delete me because I'm being rendered
	unsigned __int32 m_bDrawLast :1;             // draw object last
	unsigned __int32 m_bDistanceFade :1;         // Fade entity because it is far away
	unsigned __int32 m_bDontCastShadowsOn : 1;       // Dont cast shadows on this object
	unsigned __int32 m_bOffscreen : 1;               // offscreen flag. This can only be trusted when it is set to true
	unsigned __int32 m_bIsStaticWaitingForCollision : 1; // this is used by script created entities - they are static until the collision is loaded below them
	unsigned __int32 m_bDontStream : 1;              // tell the streaming not to stream me
	unsigned __int32 m_bUnderwater : 1;              // this object is underwater change drawing order
	unsigned __int32 m_bHasPreRenderEffects : 1; // Object has a prerender effects attached to it
	unsigned __int32 m_bIsTempBuilding : 1;          // whether or not the building is temporary (i.e. can be created and deleted more than once)
	unsigned __int32 m_bDontUpdateHierarchy : 1; // Don't update the aniamtion hierarchy this frame
	unsigned __int32 m_bHasRoadsignText : 1;     // entity is roadsign and has some 2deffect text stuff to be rendered
	unsigned __int32 m_bDisplayedSuperLowLOD : 1;
	unsigned __int32 m_bIsProcObject : 1;            // set object has been generate by procedural object generator
	unsigned __int32 m_bBackfaceCulled : 1;          // has backface culling on
	unsigned __int32 m_bLightObject : 1;         // light object with directional lights
	unsigned __int32 m_bUnimportantStream : 1;       // set that this object is unimportant, if streaming is having problems
	unsigned __int32 m_bTunnel : 1;          // Is this model part of a tunnel
	unsigned __int32 m_bTunnelTransition : 1;        // This model should be rendered from within and outside of the tunnel
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

	// originally virtual functions
	void Add(CRect &rect);
	void Add(); // similar to previous, but with entity bound rect
	void Remove();
	void SetIsStatic(bool isStatic);
	void SetModelIndex(unsigned int index);
	void SetModelIndexNoCreate(unsigned int index);
	void CreateRwObject();
	void DeleteRwObject();
	CRect GetBoundRect();
	void ProcessControl();
	void ProcessCollision();
	void ProcessShift();
	bool TestCollision();
	void Teleport(CVector destination, bool resetRotation);
	void SpecialEntityPreCollisionStuff(class CEntity *colEntity, bool unk1, unsigned char *unk2, unsigned char *unk3, unsigned char *unk4, unsigned char *unk5);
	void SpecialEntityCalcCollisionSteps(unsigned char *unk1, unsigned char *unk2);
	void PreRender();
	void Render();
	bool SetupLighting();
	void RemoveLighting();
	void FlagToDestroyWhenNextProcessed();

	void UpdateRwFrame();
	void UpdateRpHAnim();
	bool HasPreRenderEffects();
	void ModifyMatrixForPoleInWind();
	void PreRenderForGlassWindow();
	void SetRwObjectAlpha(int alpha);
	CVector GetSlotmachineWheelPosn(unsigned int wheelId);
	void Initialise2dEffects();
	void Destroy2dEffects();
	void AttachToRwObject(RwObject *object, bool moveToObject);
	CVector GetBoundCentre();
	void GetBoundCentre(CVector& out);
	bool GetIsTouching(class CEntity *entity);
	bool GetIsTouching(CVector const &posn, float radius);
	bool GetIsOnScreen();
	void ModifyMatrixForTreeInWind();
	void ModifyMatrixForBannerInWind(); // left from GTAIII
	CColModel *GetColModel();
	float GetDistanceFromCentreOfMassToBaseOfModel();
	void CleanUpOldReference(class CEntity**pEntity);
	void ResolveReferences();
	void PruneReferences();
	void RegisterReference(CEntity**pEntity);
	void ProcessLightsForEntity();
	void RemoveEscalator();
	bool IsEntityOccluded();
	// calls RpAnimBlendClumpUpdateAnimations()
	void UpdateAnimations();
};
#pragma pack(pop)

VALIDATE_SIZE(CEntity, 0x38);