#ifndef _BATTLE_PHASE_
#define _BATTLE_PHASE_

#include "StateMachine.h"
#include "../Creature/Enemy/EnemyController.h"
#include "../Creature/Player/PlayerController.h"
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
	BattlePhase():m_battleEndFlag(false){}
	~BattlePhase() {}

private:
	bool							m_battleEndFlag;
	EnemyController					m_enemyController;
	std::vector<EnemyParent*>		m_enemyVec;
	std::vector<CreatureParent*>	m_attackSort;
};
#endif // !_BATTLE_PHASE_
