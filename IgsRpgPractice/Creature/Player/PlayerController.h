#ifndef _PLAYER_CONTROLLER_
#define _PLAYER_CONTROLLER_

#include "Warrior.h"
#include "Mage.h"
#include "RoleParent.h"

class PlayerController {
public:
	static RoleParent* GetPlayer();
	static void SetPlayer(RoleParent* inputRole);

private:
	static RoleParent* m_player;
};

#endif // !_PLAYER_CONTROLLER_