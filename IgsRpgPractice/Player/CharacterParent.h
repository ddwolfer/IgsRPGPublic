#ifndef _PLAYER_ROLE_
#define _PLAYER_ROLE_

#endif _PLAYER_ROLE_// !Character


class RoleParent
{
public:

	int GetHp()		{ return Hp; };
	int GetMana()	{ return Mana; };
	int GetHp()		{ return Atk; };
	int GetHp()		{ return Speed; };
	int GetHp()		{ return Armor; };

	RoleParent();
	~RoleParent();

protected:
	int Hp;
	int Mana;
	int Atk;
	int Speed;
	int Armor;
};

RoleParent::RoleParent() {
}

RoleParent::~RoleParent()
{
}