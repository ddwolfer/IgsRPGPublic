#include "EnemyController.h"

EnemyParent* EnemyFactory::CreateSlime() {
	return new Slime();
}
EnemyParent* EnemyFactory::CreateGoblin() {
	return new Goblin();
}

EnemyParent* EnemyController::CreateEnemy(E_Enemy EnemyType) {
	switch (EnemyType)
	{
	case Type_Slime:
		return m_enemyFactory->CreateSlime();
		break;
	case Type_Goblin:
		return m_enemyFactory->CreateGoblin();
		break;
	default:
		break;
	}
}

EnemyController::EnemyController() {
	m_enemyFactory = new EnemyFactory();
}
EnemyController::~EnemyController() {
	delete m_enemyFactory;
}

EnemyFactory::EnemyFactory() {
}
EnemyFactory::~EnemyFactory() {
}