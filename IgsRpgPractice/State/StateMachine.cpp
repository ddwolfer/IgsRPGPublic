#include "StateMachine.h"
//
// 建構解構
//
StateMachine::StateMachine() {
	m_current = nullptr;
	pageMachine = this;
}
StateMachine::~StateMachine() {}
//
// 回傳page用的state machine
//
StateMachine* StateMachine::GetPageStateMachine() {
	return pageMachine;
}
//
// 加入新狀態
//
void StateMachine::AddState(E_GamePage pageID, EmptyState* state) {
	m_stateMap[pageID] = state;
	return;
}
//
// 改變狀態
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
// 顯示該狀態內容
//
void StateMachine::Update() {
	if (m_current != nullptr) {
		m_current->Update();
	}
}
//
// 執行該狀態的輸入
//
void StateMachine::HandleInput() {
	if (m_current != nullptr) {
		m_current->HandleInput();
	}
}