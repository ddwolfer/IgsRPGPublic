#ifndef _MAGE_
#define _MAGE_

#include "RoleParent.h"

namespace defaultMage {
	const string	name = "ªk®v";
	const int		hpMax = 65;
	const int		manaMax = 75;
	const int		atk = 10;
	const int		speed = 12;
}

class Mage : public RoleParent {
public:
	Mage();
	~Mage();
};

#endif // !_MAGE_
