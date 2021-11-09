#ifndef _WARRIOR_
#define _WARRIOR_

#include "RoleParent.h"

namespace defaultWarrior {
	const string	name = "¾Ô¤h";
	const int		hpMax = 100;
	const int		manaMax = 20;
	const int		atk = 25;
	const int		speed = 10;
}

class Warrior : public RoleParent {
public:
	Warrior();
	~Warrior();
};

#endif // !_WARRIOR_
