#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"

namespace Offset
{
	inline DWORD EntityList;
	inline DWORD Matrix;
	inline DWORD ViewAngle;
	inline DWORD LocalPlayerController;
	inline DWORD LocalPlayerPawn;
	inline DWORD ForceJump;
	inline DWORD GlobalVars;
	inline DWORD InventoryServices;
	inline DWORD PlantedC4;

	/*
DWORD Health = m_iHealth 0x32C
DWORD TeamID = m_iTeamNum 0x3BF
DWORD IsAlive = m_bPawnIsAlive 0x7F4
DWORD PlayerPawn = m_hPlayerPawn; 0x7EC
DWORD iszPlayerName = m_iszPlayerName; 0x640
DWORD EnemySensor = m_flDetectedByEnemySensorTime; 0x13DC
DWORD GravityScale = m_flGravityScale; 0x434

*/

	struct
	{
		DWORD Health = 0x32C;
		DWORD TeamID = 0x3BF;
		DWORD IsAlive = 0x7F4;
		DWORD PlayerPawn = 0x7EC;
		DWORD iszPlayerName = 0x640;
		DWORD EnemySensor = 0x13DC;
		DWORD GravityScale = 0x434;
	} Entity;

	struct
	{
		DWORD BulletServices = 0x16B0;
		DWORD TotalHit = 0x40;
		DWORD Pos = 0x1224;	// m_vOldOrigin
		DWORD MaxHealth = 0x328;
		DWORD CurrentHealth = 0x32C; // m_iHealth
		DWORD GameSceneNode = 0x310;
		DWORD BoneArray = 0x1E0;
		DWORD angEyeAngles = 0x1510;
		DWORD vecLastClipCameraPos = 0x128C;
		DWORD pClippingWeapon = 0x12A8;
		DWORD iShotsFired = 0x1418;
		DWORD flFlashDuration = 0x1468;
		DWORD aimPunchAngle = 0x1714;
		DWORD aimPunchCache = 0x1738;
		DWORD iIDEntIndex = 0x153C;
		DWORD iTeamNum = 0x3BF;
		DWORD CameraServices = 0x10E0; // m_pCameraServices
		DWORD iFovStart = 0x214;
		DWORD fFlags = 0x3C8;
		DWORD bSpottedByMask = 0x1630 + 0xC; // entitySpottedState + bSpottedByMask
	} Pawn;

	struct
	{
		DWORD CurrentHealth = 0x2A8; // m_iHealth
	} ServerPawn;

	struct
	{
		DWORD RealTime = 0x00;
		DWORD FrameCount = 0x04;
		DWORD MaxClients = 0x10;
		DWORD IntervalPerTick = 0x14;
		DWORD CurrentTime = 0x2C;
		DWORD CurrentTime2 = 0x30;
		DWORD TickCount = 0x40;
		DWORD IntervalPerTick2 = 0x44;
		DWORD CurrentNetchan = 0x0048;
		DWORD CurrentMap = 0x0180;
		DWORD CurrentMapName = 0x0188;
	} GlobalVar;

	struct
	{
		DWORD m_hPawn = 0x5DC;
		DWORD m_pObserverServices = 0x10C0;
		DWORD m_hObserverTarget = 0x44;
		DWORD m_hController = 0x123C;
	} PlayerController;

	struct
	{
		DWORD m_szName = 0xC18;
	} WeaponBaseData;

	struct
	{
		DWORD m_bBeingDefused = 0xEBC;
		DWORD m_flDefuseCountDown = 0xED0;
		DWORD m_nBombSite = 0xE84;
	} C4;

	// Never have a try for external skin changer
	struct
	{
		DWORD MusicID = 0x40;
		DWORD Rank = 0x44;
		DWORD AuthoritativeWeaponSlots = 0x70;
	} Inventory;

	namespace Signatures
	{
		const std::string InventoryServices = "E8 ?? ?? ?? ?? 8B 45 D0 48 8B 55 D8";
		const std::string GlobalVars = "48 89 0D ?? ?? ?? ?? 48 89 41";
		const std::string EntityList = "48 8B 0D ?? ?? ?? ?? 48 89 7C 24 ?? 8B FA C1";
		const std::string LocalPlayerController = "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 4F";
		const std::string ViewAngles = "48 8B 0D ?? ?? ?? ?? 48 8B 01 48 FF 60 30";
		const std::string ViewMatrix = "48 8D 0D ?? ?? ?? ?? 48 C1 E0 06";
		const std::string LocalPlayerPawn = "48 8D 05 ?? ?? ?? ?? C3 CC CC CC CC CC CC CC CC 48 83 EC ?? 8B 0D";
		const std::string ForceJump = "48 8B 05 ?? ?? ?? ?? 48 8D 1D ?? ?? ?? ?? 48 89 45";
		const std::string PlantedC4 = "48 8B 15 ?? ?? ?? ?? FF C0 48 8D 4C 24";
	}

	// Ò»¼ü¸üÐÂ»ùÖ·
	bool UpdateOffsets();
}
