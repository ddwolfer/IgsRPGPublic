#ifndef _BATTLE_PHASE_
#define _BATTLE_PHASE_

#include "StateMachine.h"
#include "../BattleController.h"
#include "../State/StateMachine.h"
#include <list>
#include <random>
#include <time.h>

//
// 戰鬥階段
//
class BattlePhase : public EmptyState
{
public:
	//
	// 戰鬥流程 
	//
	void Update(); 

	void HandleInput();
	//
	// 隨機生成1~3隻隨機的敵人
	//
	void Enter(); 
	void Exit() {}
	BattlePhase() {}
	~BattlePhase() {}

private:
};
#endif // !_BATTLE_PHASE_
