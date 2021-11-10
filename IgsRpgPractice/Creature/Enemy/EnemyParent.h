#ifndef _ENEMY_PARENT_
#define _ENEMY_PARENT_

#include "../CreatureParent.h"
#include <iostream>
#include <map>

using namespace std;

class EnemyParent : public CreatureParent
{
public:
	EnemyParent(
		string inputName = "defaultName",
		int inputHp		 = 1,
		int inputMana    = 1,
		int inputAtk     = 1,
		int inputSpeed   = 1
	);
	~EnemyParent();

	static void ResetCountMap();
	static int AddEnemyInCountMap(string inputName);

protected:
	static map<string, int> m_countEachTypeEnemy;
};


#endif // !_ENEMY_PARENT_
