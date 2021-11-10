#ifndef _BATTLE_CONTROLLER_
#define _BATTLE_CONTROLLER_
#include "Creature/Enemy/EnemyController.h"
#include "Creature/Player/PlayerController.h"

class BattleController
{
public:
	BattleController() {
		m_enemyVec.clear();
		m_attackSort.clear();
		// �H����1~3��
		m_enemyCount = (int)(rand() % 3) + 1;
		// �H�� �v�ܩior�����L
		for (size_t idx = 0; idx < m_enemyCount; idx++) {
			m_enemyVec.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
		}
	}
	~BattleController() {}

private:
	int								m_enemyCount;
	EnemyController					m_enemyController;
	std::vector<EnemyParent*>		m_enemyVec;
	std::vector<CreatureParent*>	m_attackSort;
};



#endif // !_BATTLE_CONTROLLER_
