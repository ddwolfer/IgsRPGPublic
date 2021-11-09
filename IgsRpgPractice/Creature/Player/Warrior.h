#ifndef _WARRIOR_
#define _WARRIOR_

#include "RoleParent.h"

namespace defaultWarrior {
	const string	m_name = "¾Ô¤h";
	const int		HpMax = 100;
	const int		ManaMax = 20;
	const int		Atk = 25;
	const int		Speed = 10;
}

class Warrior : public RoleParent {
public:
	Warrior();
	~Warrior();
};

#endif // !_WARRIOR_
