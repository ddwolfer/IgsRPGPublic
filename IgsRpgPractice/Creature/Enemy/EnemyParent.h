#ifndef _ENEMY_PARENT_
#define _ENEMY_PARENT_

#include "../CreatureParent.h"
#include <iostream>

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

private:

};


#endif // !_ENEMY_PARENT_
