#ifndef _MAGE_
#define _MAGE_

#include "RoleParent.h"

namespace defaultMage {
	const string	name = "�k�v";
	const int		hpMax = 1;
	const int		manaMax = 75;
	const int		atk = 10;
	const int		speed = 12;
}

class Mage : public RoleParent {
public:
	int testHp=10;
	Mage();
	~Mage();
	
};

#endif // !_MAGE_
