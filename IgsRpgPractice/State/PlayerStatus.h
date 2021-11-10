#ifndef _PLAYER_STATUS_
#define _PLAYER_STATUS_

#include "StateMachine.h"
#include "../Creature/Player/PlayerController.h"

using namespace std;

//
// 角色狀態 
// 1) 返回
//
class PlayerStatus : public EmptyState
{
public:
	void Update();		// 顯示角色狀態
	void HandleInput(); // 按下任意key返回
	void Enter() {}
	void Exit() {}

	PlayerStatus() {}
	~PlayerStatus() {}
};

#endif // !_PLAYER_STATUS_