#include "PlayerController.h"

RoleParent* PlayerController::m_player = nullptr;

RoleParent* PlayerController::GetPlayer() {
	return m_player; 
}

void PlayerController::SetPlayer(RoleParent* inputRole) {
	if (m_player != NULL) {
		delete m_player;
	}
	m_player = inputRole;
}