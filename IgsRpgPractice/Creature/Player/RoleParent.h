#ifndef _PLAYER_ROLE_
#define _PLAYER_ROLE_

//
// 所有職業的父類別
//
#include "../CreatureParent.h"

#include <string>
#include <iostream>

using namespace std;

class RoleParent : public CreatureParent
{
public:
	//virtual void PlayerNormalAttack() = 0;
	//virtual void PlayerBattleEscape() = 0;
	//
	// 顯示角色狀態
	//
	virtual void ShowStatus();
	//
	// 戰鬥時選擇角色動作
	//
	E_BattleAction PlayerBattleAction();
	/*
		放一個choose action 戰鬥時的行動
	*/
	RoleParent(
		string inputName = "defaultName",
		int inputHp		= 1,
		int inputMana	= 1,
		int inputAtk	= 1,
		int inputSpeed	= 1
	);
	~RoleParent() {}
};

#endif //! _PLAYER_ROLE_