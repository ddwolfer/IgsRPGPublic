#include "Warrior.h"

Warrior::Warrior() :
	RoleParent(
		defaultWarrior::m_name,
		defaultWarrior::HpMax,
		defaultWarrior::ManaMax,
		defaultWarrior::Atk,
		defaultWarrior::Speed
	) {
}
Warrior::~Warrior() {
}