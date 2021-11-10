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
// 選擇角色 
// 1) 戰士 
// 2) 法師
//
class SelectRole : public EmptyState
{
public:
	//
	// 顯示選擇職業畫面
	//
	void Update();
	//
	// 選擇 1戰士 2法師
	//
	void HandleInput();
	void Enter() {}
	void Exit() {}

	SelectRole() {}
	~SelectRole() {}
};

#endif // !_SELECT_CH_