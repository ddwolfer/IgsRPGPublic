#ifndef _SLIME_
#define _SLIME_

#include "EnemyParent.h"

namespace defaultSlime {
	const string	name = "¥vµÜ©i";
	const int		hpMax = 20;
	const int		manaMax = 0;
	const int		atk = 5;
	const int		speed = 5;
}


class Slime : public EnemyParent
{
public:
	Slime();
	~Slime();

private:

};

#endif // !_SLIME_
