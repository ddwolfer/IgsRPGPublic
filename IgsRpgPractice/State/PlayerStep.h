#ifndef _PLAYER_STEP_
#define _PLAYER_STEP_
#include "StateMachine.h"

enum E_StepChoose {
	State_nextBattle = 1,
	State_showPlayerStatus = 2
};

//
// 遊戲階段 
// 1) 前進(戰鬥) 
// 2) 看角色狀態欄位
//
class PlayerStep : public EmptyState
{
public:
	//
	// 顯示選擇畫面
	//
	void Update();
	//
	// 選擇並動作
	//
	void HandleInput();
	void Enter() {}
	void Exit() {}

	PlayerStep() {}
	~PlayerStep() {}
};
#endif // !_PLAYER_STEP_
