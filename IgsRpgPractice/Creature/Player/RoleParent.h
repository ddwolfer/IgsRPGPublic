#ifndef _PLAYER_ROLE_
#define _PLAYER_ROLE_

//
// �Ҧ�¾�~�������O
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
	// ��ܨ��⪬�A
	//
	virtual void ShowStatus();
	//
	// �԰��ɿ�ܨ���ʧ@
	//
	E_BattleAction PlayerBattleAction();
	/*
		��@��choose action �԰��ɪ����
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