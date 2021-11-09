#ifndef _BATTLE_PHASE_
#define _BATTLE_PHASE_

#include "StateMachine.h"
#include "../Creature/Enemy/EnemyController.h"
#include "../Creature/Player/PlayerController.h"
#include <list>
#include <random>
#include <time.h>


//
// ¾Ô°«¶¥¬q
//
class BattlePhase : public EmptyState
{
public:
	void Update() {
		cout<< "[¾Ô°«]" << endl;
		std::list<EnemyParent*>::iterator eny;
		for (eny = m_enemyList.begin(); eny != m_enemyList.end(); eny++) {
			EnemyParent* it = *eny;
			it->ShowEnemyHp();
		}
	}
	void HandleInput() {
		int choose;
		cin >> choose;
	}
	void Enter() {
		int enemyCount = (int)(rand() % 3) + 1;
		for (size_t idx = 0; idx < enemyCount; idx++) {
			m_enemyList.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
		}
	}
	void Exit() {}
	BattlePhase() {}
	~BattlePhase() {}

private:
	EnemyController			m_enemyController;
	std::list<EnemyParent*> m_enemyList;

};
#endif // !_BATTLE_PHASE_
