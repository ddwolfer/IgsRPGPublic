#include "Slime.h"

Slime::Slime() :
	EnemyParent(
		defaultSlime::name,
		defaultSlime::hpMax,
		defaultSlime::manaMax,
		defaultSlime::atk,
		defaultSlime::speed
	) {
}
Slime::~Slime() {
}