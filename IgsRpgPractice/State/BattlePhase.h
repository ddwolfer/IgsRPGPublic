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
	BattlePhase():m_battleEndFlag(false){}
	~BattlePhase() {}

private:
	bool							m_battleEndFlag;
	EnemyController					m_enemyController;
	std::vector<EnemyParent*>		m_enemyVec;
	std::vector<CreatureParent*>	m_attackSort;
};
#endif // !_BATTLE_PHASE_
