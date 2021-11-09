#include "Mage.h"

Mage::Mage() :
	RoleParent(
		defaultMage::m_name,
		defaultMage::HpMax,
		defaultMage::ManaMax,
		defaultMage::Atk,
		defaultMage::Speed
	) {
}
Mage::~Mage() {
}