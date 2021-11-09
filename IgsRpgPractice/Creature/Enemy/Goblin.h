#ifndef _GOBLIN_
#define _GOBLIN_

#include "EnemyParent.h"

namespace defaultGoblin {
	const string	name = "­ô¨BªL";
	const int		hpMax = 30;
	const int		manaMax = 0;
	const int		atk = 10;
	const int		speed = 11;
}

class Goblin : public EnemyParent
{
public:
	Goblin();
	~Goblin();

private:

};

#endif // !_GOBLIN_