#include "Goblin.h"

Goblin::Goblin() :
	EnemyParent(
		defaultGoblin::name,
		defaultGoblin::hpMax,
		defaultGoblin::manaMax,
		defaultGoblin::atk,
		defaultGoblin::speed
	) {
}
Goblin::~Goblin() {
}