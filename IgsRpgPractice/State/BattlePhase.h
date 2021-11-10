#ifndef _BATTLE_PHASE_
#define _BATTLE_PHASE_

#include "StateMachine.h"
#include "../BattleController.h"
#include "../State/StateMachine.h"
#include <list>
#include <random>
#include <time.h>

//
// �԰����q
//
class BattlePhase : public EmptyState
{
public:
	//
	// �԰��y�{ 
	//
	void Update(); 

	void HandleInput();
	//
	// �H���ͦ�1~3���H�����ĤH
	//
	void Enter(); 
	void Exit() {}
	BattlePhase() {}
	~BattlePhase() {}

private:
};
#endif // !_BATTLE_PHASE_
