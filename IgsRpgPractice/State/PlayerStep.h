#ifndef _PLAYER_STEP_
#define _PLAYER_STEP_
#include "StateMachine.h"

enum E_StepChoose {
	State_nextBattle = 1,
	State_showPlayerStatus = 2
};

//
// �C�����q 
// 1) �e�i(�԰�) 
// 2) �ݨ��⪬�A���
//
class PlayerStep : public EmptyState
{
public:
	//
	// ��ܿ�ܵe��
	//
	void Update();
	//
	// ��ܨðʧ@
	//
	void HandleInput();
	void Enter() {}
	void Exit() {}

	PlayerStep() {}
	~PlayerStep() {}
};
#endif // !_PLAYER_STEP_
