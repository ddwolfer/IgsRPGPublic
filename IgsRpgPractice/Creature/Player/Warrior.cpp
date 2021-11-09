#include "Warrior.h"

Warrior::Warrior() :
	RoleParent(
		defaultWarrior::name,
		defaultWarrior::hpMax,
		defaultWarrior::manaMax,
		defaultWarrior::atk,
		defaultWarrior::speed
	) {
}
Warrior::~Warrior() {
}