#include "StateMachine.h"

StateMachine::StateMachine() {
	m_current = nullptr;
	pageMachine = this;
}
StateMachine* StateMachine::GetStateMachine() {
	return pageMachine;
}
StateMachine::~StateMachine() {}

void StateMachine::AddState(E_GamePage pageID, EmptyState* state) {
	m_stateMap[pageID] = state;
	return;
}
