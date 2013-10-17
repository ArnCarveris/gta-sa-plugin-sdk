#pragma once

#include "plugin\plugin.h"
#include "ePedType.h"
#include "CPhysical.h"
#include "CPedCollisionAudio.h"
#include "CPedVoice.h"
#include "CWeaponAudio.h"
#include "CPedIntelligence.h"
#include "CPlayerData.h"
#include "AnimBlendFrameData.h"
#include "CPedAcquaintance.h"
#include "CPedIK.h"
#include "CWeapon.h"

#pragma pack(push, 1)
class PLUGIN_API CPed : public CPhysical
{
	CPedCollisionAudio  m_CollisionAudio;
	CPedVoice           m_PedVoice;
	CWeaponAudio        m_WeaponAudio;
	__int8 field_43C[36];
	__int8 field_460[8];
	__int32 field_468;
	/* https://code.google.com/p/mtasa-blue/source/browse/tags/1.3.4/MTA10/game_sa/CPedSA.h */
	unsigned __int32    m_bIsStanding : 1; // is ped standing on something
	unsigned __int32    m_bWasStanding : 1; // was ped standing on something
	unsigned __int32    m_bIsLooking : 1; // is ped looking at something or in a direction
	unsigned __int32    m_bIsRestoringLook : 1; // is ped restoring head postion from a look
	unsigned __int32    m_bIsAimingGun : 1; // is ped aiming gun
	unsigned __int32    m_bIsRestoringGun : 1; // is ped moving gun back to default posn
	unsigned __int32    m_bCanPointGunAtTarget : 1; // can ped point gun at target
	unsigned __int32    m_bIsTalking : 1; // is ped talking(see Chat())
	unsigned __int32    m_bInVehicle : 1; // is in a vehicle
	unsigned __int32    m_bIsInTheAir : 1; // is in the air
	unsigned __int32    m_bIsLanding : 1; // is landing after being in the air
	unsigned __int32    m_bHitSomethingLastFrame : 1; // has been in a collision last fram
	unsigned __int32    m_bIsNearCar : 1; // has been in a collision last fram
	unsigned __int32    m_bRenderPedInCar : 1; // has been in a collision last fram
	unsigned __int32    m_bUpdateAnimHeading : 1; // update ped heading due to heading change during anim sequence
	unsigned __int32    m_bRemoveHead : 1; // waiting on AntiSpazTimer to remove head
	unsigned __int32    m_bFiringWeapon : 1; // is pulling trigger
	unsigned __int32    m_bHasACamera : 1; // does ped possess a camera to document accidents
	unsigned __int32    m_bPedIsBleeding : 1; // Ped loses a lot of blood if true
	unsigned __int32    m_bStopAndShoot : 1; // Ped cannot reach target to attack with fist, need to use gun
	unsigned __int32    m_bIsPedDieAnimPlaying : 1; // is ped die animation finished so can dead now
	unsigned __int32    m_bStayInSamePlace :1; // when set, ped stays put
	unsigned __int32    m_bKindaStayInSamePlace :1; // when set, ped doesn't seek out opponent or cover large distances. Will still shuffle and look for cover
	unsigned __int32    m_bBeingChasedByPolice :1; // use nodes for routefind
	unsigned __int32    m_bNotAllowedToDuck :1; // Is this ped allowed to duck at all?
	unsigned __int32    m_bCrouchWhenShooting :1; // duck behind cars etc
	unsigned __int32    m_bIsDucking :1; // duck behind cars etc
	unsigned __int32    m_bGetUpAnimStarted :1; // don't want to play getup anim if under something
	unsigned __int32    m_bDoBloodyFootprints :1; // unsigned int bIsLeader :1;
	unsigned __int32    m_bDontDragMeOutCar :1;
	unsigned __int32    m_bStillOnValidPoly :1; // set if the polygon the ped is on is still valid for collision
	unsigned __int32    m_bAllowMedicsToReviveMe :1;
	unsigned __int32    m_bResetWalkAnims :1;
	unsigned __int32    m_bOnBoat :1; // flee but only using nodes
	unsigned __int32    m_bBusJacked :1; // flee but only using nodes
	unsigned __int32    m_bFadeOut :1; // set if you want ped to fade out
	unsigned __int32    m_bKnockedUpIntoAir :1; // has ped been knocked up into the air by a car collision
	unsigned __int32    m_bHitSteepSlope :1; // has ped collided/is standing on a steep slope (surface type)
	unsigned __int32    m_bCullExtraFarAway :1; // special ped only gets culled if it's extra far away (for roadblocks)
	unsigned __int32    m_bTryingToReachDryLand :1; // has ped just exited boat and trying to get to dry land
	unsigned __int32    m_bCollidedWithMyVehicle :1;
	unsigned __int32    m_bRichFromMugging :1; // ped has lots of cash cause they've been mugging people
	unsigned __int32    m_bChrisCriminal :1; // Is a criminal as killed during Chris' police mission (should be counted as such)
	unsigned __int32    m_bShakeFist :1; // test shake hand at look entity
	unsigned __int32    m_bNoCriticalHits : 1; // ped cannot be killed by a single bullet
	unsigned __int32    m_bHasAlreadyBeenRecorded : 1; // Used for replays
	unsigned __int32    m_bUpdateMatricesRequired : 1; // if PedIK has altered bones so matrices need updated this frame
	unsigned __int32    m_bFleeWhenStanding :1; //
	unsigned __int32    m_bMiamiViceCop :1;  //
	unsigned __int32    m_bMoneyHasBeenGivenByScript :1; //
	unsigned __int32    m_bHasBeenPhotographed :1;  //
	unsigned __int32    m_bIsDrowning : 1;
	unsigned __int32    m_bDrownsInWater : 1;
	unsigned __int32    m_bHeadStuckInCollision : 1;
	unsigned __int32    m_bDeadPedInFrontOfCar :1;
	unsigned __int32    m_bStayInCarOnJack :1;
	unsigned __int32    m_bDontFight :1;
	unsigned __int32    m_bDoomAim :1;
	unsigned __int32    m_bCanBeShotInVehicle : 1;
	unsigned __int32    m_bPushedAlongByCar :1; // ped is getting pushed along by car collision (so don't take damage from horz velocity)
	unsigned __int32    m_bNeverEverTargetThisPed :1;
	unsigned __int32    m_bThisPedIsATargetPriority :1;
	unsigned __int32    m_bCrouchWhenScared :1;
	unsigned __int32    m_bKnockedOffBike :1;
	unsigned __int32    m_bDonePositionOutOfCollision :1;
	unsigned __int32    m_bDontRender : 1;
	unsigned __int32    m_bHasBeenAddedToPopulation :1;
	unsigned __int32    m_bHasJustLeftCar :1;
	unsigned __int32    m_bIsInDisguise :1;
	unsigned __int32    m_bDoesntListenToPlayerGroupCommands :1;
	unsigned __int32    m_bIsBeingArrested :1;
	unsigned __int32    m_bHasJustSoughtCover :1;
	unsigned __int32    m_bKilledByStealth :1;
	unsigned __int32    m_bDoesntDropWeaponsWhenDead :1;
	unsigned __int32    m_bCalledPreRender :1;
	unsigned __int32    m_bBloodPuddleCreated : 1; // Has a static puddle of blood been created yet
	unsigned __int32    m_bPartOfAttackWave :1;
	unsigned __int32    m_bClearRadarBlipOnDeath :1;
	unsigned __int32    m_bNeverLeavesGroup :1; // flag that we want to test 3 extra spheres on col model
	unsigned __int32    m_bTestForBlockedPositions :1; // this sets these indicator flags for various posisions on the front of the ped
	unsigned __int32    m_bRightArmBlocked :1;
	unsigned __int32    m_bLeftArmBlocked :1;
	unsigned __int32    m_bDuckRightArmBlocked :1;
	unsigned __int32    m_bMidriffBlockedForJump :1;
	unsigned __int32    m_bFallenDown :1;
	unsigned __int32    m_bUseAttractorInstantly :1;
	unsigned __int32    m_bDontAcceptIKLookAts :1;
	unsigned __int32    m_bHasAScriptBrain : 1;
	unsigned __int32    m_bWaitingForScriptBrainToLoad : 1;
	unsigned __int32    m_bHasGroupDriveTask :1;
	unsigned __int32    m_bCanExitCar :1;
	unsigned __int32    m_CantBeKnockedOffBike :2; // 0=Default(harder for mission peds) 1=Never 2=Always normal(also for mission peds)
	unsigned __int32    m_bHasBeenRendered : 1;
	unsigned __int32    m_bIsCached :1;
	unsigned __int32    m_bPushOtherPeds :1; // GETS RESET EVERY FRAME - SET IN TASK: want to push other peds around (eg. leader of a group or ped trying to get in a car)
	unsigned __int32    m_bHasBulletProofVest :1;
	unsigned __int32    m_bUsingMobilePhone :1;
	unsigned __int32    m_bUpperBodyDamageAnimsOnly :1;
	unsigned __int32    m_bStuckUnderCar :1;
	unsigned __int32    m_bKeepTasksAfterCleanUp :1; // If true ped will carry on with task even after cleanup
	unsigned __int32    m_bIsDyingStuck :1;
	unsigned __int32    m_bIgnoreHeightCheckOnGotoPointTask :1; // set when walking round buildings, reset when task quits
	unsigned __int32    m_bForceDieInCar:1;
	unsigned __int32    m_bCheckColAboveHead:1;
	unsigned __int32    m_bIgnoreWeaponRange : 1;
	unsigned __int32    m_bDruggedUp : 1;
	unsigned __int32    m_bWantedByPolice : 1; // if this is set, the cops will always go after this ped when they are doing a KillCriminal task
	unsigned __int32    m_bSignalAfterKill: 1;
	unsigned __int32    m_bCanClimbOntoBoat :1;
	unsigned __int32    m_bPedHitWallLastFrame: 1; // useful to store this so that AI knows (normal will still be available)
	unsigned __int32    m_bIgnoreHeightDifferenceFollowingNodes: 1;
	unsigned __int32    m_bMoveAnimSpeedHasBeenSetByTask: 1;
	unsigned __int32    m_bGetOutUpsideDownCar :1;
	unsigned __int32    m_bJustGotOffTrain :1;
	unsigned __int32    m_bDeathPickupsPersist :1;
	unsigned __int32    m_bTestForShotInVehicle :1;
	unsigned __int32    m_bUsedForReplay : 1; // This ped is controlled by replay and should be removed when replay is done.
	/* */
	CPedIntelligence   *m_pIntelligence;
	CPlayerData        *m_pPlayerData;
	unsigned __int8     m_dwUsageType;
	__int8 _pad0[3];
	AnimBlendFrameData *m_apBones[19];
	unsigned __int32    m_dwAnimGroup;
	__int32 field_4D8;
	__int32 field_4DC;
	CPedAcquaintance    m_Acquaintance;
	RwObject           *m_pWeaponObject;
	RwFrame            *m_pGunflashObject;
	RwObject           *m_pGogglesObject;
	unsigned __int8    *m_pGogglesState;
	__int16             m_wWeaponGunflashAlphaMP1;
	__int16 field_506;
	__int16             m_wWeaponGunflashAlphaMP2;
	__int16 field_50A;
	CPedIK              m_PedIK;
	__int32 field_52C;
	__int32             m_nState;
	__int32             m_dwAnimToPlay;
	__int32 field_538;
	__int32 field_53C;
	float               m_fHealth;
	float               m_fMaxHealth;
	float               m_fArmour;
	__int32 field_54C;
	__int32 field_550;
	float field_554;
	float               m_fCurrentRotation;
	float               m_fAimingRotation;
	float               m_fHeadingChangeRate;
	__int32             m_dwMovingState;
	__int32 field_568;
	CVector field_56C;
	CVector field_578;
	CEntity            *m_pContactEntity;
	float field_588;
	void               *m_pVehicle; // CVehicle *
	__int32 field_590;
	__int32 field_594;
	__int32             m_nPedType;
	void               *m_pStats; // CPedStat *
	CWeapon             m_aWeapons[13];
	__int32 field_70C;
	__int32 field_710;
	__int32 field_714;
	__int8              m_nActiveWeaponSlot;
	__int8 field_719;
	__int8              m_nWeaponAccuracy;
	__int8 field_71B;
	void               *m_pTargetedObject; // CObject *
	__int32 field_720;
	__int32 field_724;
	__int32 field_728;
	__int8              m_nWeaponSkill;
	__int8              m_nFightingStyle;
	__int8              m_nAllowedAttackMoves;
	__int8 field_72F;
	void               *m_pFire; // CFire *
	__int32 field_734;
	__int32 field_738;
	__int32 field_73C;
	__int32             m_dwWeaponModelId;
	__int32 field_744;
	__int32 field_748;
	__int32 field_74C;
	__int32             m_dwTimeForBloodFootpr__int32s;
	__int8              m_nBodypartToRemove;
	__int8 field_755;
	__int16             m_wMoneyCount;
	__int32 field_758;
	__int32 field_75C;
	__int8              m_nKilledWeapon;
	__int8 field_761[3];
	class CPed         *m_pKilledPed;
	__int32 field_768;
	CVector             m_vTurretOffset;
	__int32             m_fTurretAngleA;
	__int32             m_fTurretAngleB;
	__int32             m_dwTurretPosnMode;
	__int32             m_dwTurretAmmo;
	void               *m_pNaviPoint; // CNaviPoint *
	void               *m_pEnex; // CEnEx *
	__int32 field_790;
	__int16             m_wSpecialModelIndex;
	__int8 field_796[2];
	__int32 field_798;
	class CPed         *m_pTargetedPed;
};
#pragma pack(pop)

VALIDATE_SIZE(CPed, 0x7A0);