#ifndef _MAGE_
#define _MAGE_

#include "RoleParent.h"

namespace defaultMage {
	const string	m_name = "ªk®v";
	const int		HpMax = 65;
	const int		ManaMax = 75;
	const int		Atk = 10;
	const int		Speed = 12;
}

class Mage : public RoleParent {
public:
	Mage();
	~Mage();
};

#endif // !_MAGE_
