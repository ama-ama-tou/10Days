#include "CollisionManager.h"
#include "player.h"
#include "Vec2.h"
#include "Block.h"


///�v���C���[�̓����蔻��
void CollisionManager::playerCollision() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
		{
			block_[i][j]->getType();
		}
	}

	///�����蔻��
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		//���_�̔Ԓn�̌v�Z
		rowAddress_ = player_.CalcuRowAddress(vertexNum);
		colAddress_ = player_.CalcuColAddress(vertexNum);

		///�e���_�̔Ԓn����ǂ̃u���b�N�Ɠ������Ă��邩�̔���
		if (block_[colAddress_][rowAddress_]->getType() != NONE) {
			if (vertexNum == 0) {
				player_.setIsHit(0); //���オ�������Ă���

			}else if (vertexNum == 1) {
				player_.setIsHit(1); //�E�オ�������Ă���

			} else if (vertexNum == 2) {
				player_.setIsHit(2); //�E�����������Ă���

			} else if (vertexNum == 3) {
				player_.setIsHit(3); //�������������Ă���
			}
		}
	}
};

///�u���b�N�ƃu���b�N
void  CollisionManager::blockCollision() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
		{
			block_[i][j]->getType();
		}
	}

	///�����蔻��
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		//���_�̔Ԓn�̌v�Z
		rowAddress_ = player_.CalcuRowAddress(vertexNum);
		colAddress_ = player_.CalcuColAddress(vertexNum);

		///�u���b�N�̊e���_����ǂ̃u���b�N�Ɠ������Ă��邩���肷��
		if (block_[colAddress_][rowAddress_]->getType() == N_POLE) {
			if (vertexNum == 0) {

			}
		}

	}
};
