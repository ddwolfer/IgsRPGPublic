#include "StateMachine.h"
//
// �غc�Ѻc
//
StateMachine::StateMachine() {
	m_current = nullptr;
	pageMachine = this;
}
StateMachine::~StateMachine() {}
//
// �^��page�Ϊ�state machine
//
StateMachine* StateMachine::GetPageStateMachine() {
	return pageMachine;
}
//
// �[�J�s���A
//
void StateMachine::AddState(E_GamePage pageID, EmptyState* state) {
	m_stateMap[pageID] = state;
	return;
}
//
// ���ܪ��A
//
void StateMachine::Change(E_GamePage pageID) {

	if (m_current != nullptr) {
		m_current->Exit();
	}
	EmptyState* nextState = m_stateMap[pageID];
	nextState->Enter();
	m_current = nextState;
}
//
// ��ܸӪ��A���e
//
void StateMachine::Update() {
	if (m_current != nullptr) {
		m_current->Update();
	}
}
//
// ����Ӫ��A����J
//
void StateMachine::HandleInput() {
	if (m_current != nullptr) {
		m_current->HandleInput();
	}
}