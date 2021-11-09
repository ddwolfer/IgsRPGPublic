#include "Mage.h"

Mage::Mage() :
	RoleParent(
		defaultMage::name,
		defaultMage::hpMax,
		defaultMage::manaMax,
		defaultMage::atk,
		defaultMage::speed
	) {
}
Mage::~Mage() {
}