#ifndef _SELECT_ROLE_
#define _SELECT_ROLE_
#include "StateMachine.h"
#include "../Creature/Player/PlayerController.h"

enum E_ChooseRole
{
	Type_Warrior = 1,
	Type_Mage = 2
};

//
// ��ܨ��� 
// 1) �Ԥh 
// 2) �k�v
//
class SelectRole : public EmptyState
{
public:
	//
	// ��ܿ��¾�~�e��
	//
	void Update();
	//
	// ��� 1�Ԥh 2�k�v
	//
	void HandleInput();
	void Enter() {}
	void Exit() {}

	SelectRole() {}
	~SelectRole() {}
};

#endif // !_SELECT_CH_