#ifndef _ENEMY_CONTROLLER_
#define _ENEMY_CONTROLLER_

#include "Slime.h"
#include "Goblin.h"

enum E_Enemy {
	Type_Slime,
	Type_Goblin
};

class EnemyFactory
{
public:
	EnemyParent* CreateSlime();
	EnemyParent* CreateGoblin();

	EnemyFactory();
	~EnemyFactory();
};

class EnemyController
{
public:
	EnemyController();
	~EnemyController();
	EnemyParent* CreateEnemy(E_Enemy EnemyType);

private:
	EnemyFactory* m_enemyFactory;
};



#endif // !_ENEMY_CONTROLLER_
