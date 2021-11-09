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
		// ±Æ§ðÀ»¶¶§Ç
		if (m_attackSort.size() == 0) {
			for (size_t idx = 0; idx < m_enemyList.size(); idx++) {
				m_attackSort.push_back(m_enemyList[idx]);
			}
		}
		m_attackSort.push_back(PlayerController::GetPlayer());
		sort(m_attackSort.begin(), m_attackSort.end(), [](CreatureParent* Target1, CreatureParent* Target2) {
			return Target1->GetSpeed() > Target2->GetSpeed();
			});

		cout << "[----------¾Ô°«----------]" << endl;
		for (size_t idx = 0; idx < m_enemyList.size(); idx++) {
			cout << " (" << idx + 1 << ") ";
			m_enemyList[idx]->ShowEnemyHp();
		}
		cout << "[------------------------]" << endl <<endl;
		cout << "§ðÀ»¶¶§Ç: ";
		for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
			cout << m_attackSort[idx]->GetName() ;
			if (idx + 1 < m_attackSort.size()) {
				cout << " -> ";
			}
		}
		cout << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
	}
	void Enter() {
		// ÀH¾÷¥Í1~3°¦
		int enemyCount = (int)(rand() % 3) + 1;
		// ÀH¾÷ ¥vµÜ©ior­ô¥¬ªL
		for (size_t idx = 0; idx < enemyCount; idx++) {
			m_enemyList.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
		}
	}
	void Exit() {
	
	}
	BattlePhase() {}
	~BattlePhase() {}

private:
	EnemyController					m_enemyController;
	std::vector<EnemyParent*>		m_enemyList;
	std::vector<CreatureParent*>	m_attackSort;
	//CreatureParent*					m_attackNow; <- maybe ¤£¥Î
};
#endif // !_BATTLE_PHASE_
