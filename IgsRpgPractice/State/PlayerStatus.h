#ifndef _PLAYER_STATUS_
#define _PLAYER_STATUS_

#include "StateMachine.h"
#include "../Creature/Player/PlayerController.h"

using namespace std;

//
// ���⪬�A 
// 1) ��^
//
class PlayerStatus : public EmptyState
{
public:
	void Update();		// ��ܨ��⪬�A
	void HandleInput(); // ���U���Nkey��^
	void Enter() {}
	void Exit() {}

	PlayerStatus() {}
	~PlayerStatus() {}
};

#endif // !_PLAYER_STATUS_