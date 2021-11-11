#include "BattleController.h"

BattleController* BattleController::m_battleController = nullptr;

BattleController::BattleController() {
	EnemyParent::ResetCountMap();
	m_enemyVec.clear();
	m_attackSort.clear();
	// �H����1~3��
	m_enemyCount = (int)(rand() % 3) + 1;
	// �H�� �v�ܩior�����L
	for (size_t idx = 0; idx < m_enemyCount; idx++) {
		m_enemyVec.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
	}
	m_battleEndFlag = false;
	m_playerActionTarget = 0;
}
void BattleController::InitBattleController() {
	delete m_battleController;
	m_battleController = new BattleController();
}
BattleController* BattleController::GetBattleController() {
	if (m_battleController == nullptr) {
		m_battleController = new BattleController();
	}
	return m_battleController;
}

//
// ��ܾ԰���T
//
void BattleController::ShowBattleInfo() {
	// ��� ���a��T
	        
	cout << "[---------------���a----------------]" << endl;
	PlayerController::GetPlayer()->ShowNameHp();
	// ��� �ĤH��T
	cout << "[----------------�ĤH---------------]" << endl;
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		cout << " (" << idx + 1 << ") ";
		m_enemyVec[idx]->ShowNameHp();
	}
	// ��� ��������
	cout << "[-----------------------------------]" << endl;
	cout << "��������: ";
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		cout << m_attackSort[idx]->GetName();
		if ((idx + 1) < m_attackSort.size()) {
			cout << " -> ";
		}
	}
	cout << endl;
	return;
}

//
// �Ƨ�������
//
void BattleController::SortBattleAction() {
	//��l��
	m_attackSort.clear();
	//�[�J�ĤH
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		m_attackSort.push_back(m_enemyVec[idx]);
	}
	//�[�J���a
	m_attackSort.push_back(PlayerController::GetPlayer());
	//�Ƨ�
	sort(m_attackSort.begin(), m_attackSort.end(), [](CreatureParent* Target1, CreatureParent* Target2) {
		return Target1->GetSpeed() > Target2->GetSpeed();
		});

	return;
}
//
// ���a��ܦ��
//
void BattleController::PlayerChooseAction() {
	switch(PlayerController::GetPlayer()->PlayerBattleAction())
	{
		//���q����
	case E_BattleAction::State_normalAttaack:
		PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_normalAttaack);
		break;
		//�ޯ�
	case E_BattleAction::State_specialAttack:
		PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_normalAttaack);
		break;
		//�k�]
	case E_BattleAction::State_escape:
		// �H���k�]���G 0->���\, 1->����
		switch ((int)(rand() % 2)) {
			//�k�]���\ ����return ��U�@��State
		case Escape_Success:
			cout << "�k�]���\!" << endl;
			PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_escape);
			m_battleEndFlag = true;
			return;
			break;
			//�k�]����
		case Escape_Fail:
			cout << "�k�]���� X_X" << endl;
			PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_escape);
			m_battleEndFlag = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return;
}
// 
// ���a��ܧ����ؼ�
//
void BattleController::PlayerChooseAttackTarget() {
	// ��ܥؼ�
	m_playerActionTarget = 0;
	cout << "[-----------------------------------]" << endl << endl;
	cout << "��ܧ�����H 1~" << m_enemyVec.size() << endl;
	while (m_playerActionTarget <= 0 || m_playerActionTarget > m_enemyVec.size()) {
		cout << ">";
		cin >> m_playerActionTarget;
		if (m_playerActionTarget > m_enemyVec.size() || m_playerActionTarget <= 0) {
			cout << "���~�ؼ�, ���s��J" << endl;
		}
	}
	
}
// 
// �]�w�ĤH�ʧ@
//
void BattleController::SetEnemyBattleAction() {
	cout << "[-----------------------------------]" << endl;
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		// �H���o�b/���q����
		m_enemyVec[idx]->SetBattleAction(static_cast<E_BattleAction>(rand() % 2));
	}
	return;
}
//
// ����ӥͪ����ʧ@
//
void BattleController::BattleAction(CreatureParent* inputObj) {
	//
	// �p�G���a���`�N���n�A���F
	//
	if (PlayerController::GetPlayer()->GetHp() <= 0) {
		return;
	}

	//
	// �p�G�ͪ��w�g���`�N���L, �^�X�����ɷ|�����M��
	//
	if (inputObj->GetHp() <= 0) {
		cout << inputObj->GetName() << "\t�w���`." << endl;
		return;
	}
	//
	// �M�w�ؼ� �ĤH: �����a, ���a: �����w���ؼ�
	//
	CreatureParent* ActionTarget = nullptr;
	if (inputObj == PlayerController::GetPlayer() ) {
		// �p�G�ؼЬO 0 �N��o�^�X�S���n����
		if (m_playerActionTarget != 0)
			ActionTarget = m_enemyVec[m_playerActionTarget - 1];
	} else {
		ActionTarget = PlayerController::GetPlayer();
	}
	//
	// �ݭn������ʧ@
	//
	switch (inputObj->GetBattleAction())
	{
	case E_BattleAction::State_idle:
		inputObj->ActionIdle();
		break;
	case E_BattleAction::State_normalAttaack:
		inputObj->NormalAttackHit(ActionTarget);
		break;
	case E_BattleAction::State_specialAttack:
		inputObj->NormalAttackHit(ActionTarget);
		break;
	case E_BattleAction::State_escape:
		inputObj->ActionIdle();
		break;
	default:
		break;
	}
}
// 
// �԰��}�l
//
void BattleController::StartBattlePhase() {
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		BattleAction(m_attackSort[idx]);
	}
}
//
// �M���������a�H
//
void BattleController::CleanDeadEnemy() {
	//�J�즺����enemy (Hp <= 0), �Nerase��
	size_t idx = 0;
	while (idx < m_enemyVec.size()) {
		if (m_enemyVec[idx]->GetHp() <= 0) {
			m_enemyVec.erase(m_enemyVec.begin() + idx);
		}
		else {
			idx++;
		}
	}
}
//
// �T�{�԰��O�_����
//
void BattleController::CheckBattleEnd() {
	// ��������1 �ĤH����
	if (m_enemyVec.size() <= 0) {
		cout << "[-----------------------------------]" << endl;
		cout << "~~�԰��ӧQ~~" << endl;
		m_battleEndFlag = true;
		return;
	}
	// ��������2 ���a���F
	if (PlayerController::GetPlayer()->GetHp() <= 0) {
		cout << "[-----------------------------------]" << endl;
		cout << "        " << PlayerController::GetPlayer()->GetName() << "���`" << endl;
		cout << endl << "[-------------GAME OVER-------------]" << endl << endl;
		m_battleEndFlag = true;
		return;
	}
}