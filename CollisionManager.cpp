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
				player_.setIsHitLt(true); //���オ�������Ă���

			}else if (vertexNum == 1) {
				player_.setIsHitRt(true); //�E�オ�������Ă���

			} else if (vertexNum == 2) {
				player_.setIsHitRb(true); //�E�����������Ă���

			} else if (vertexNum == 3) {
				player_.setIsHitLb(true); //�������������Ă���
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
		rowAddress_ = blockType_[vertexNum].CalcuRowAddress(vertexNum);
		colAddress_ = blockType_[vertexNum].CalcuColAddress(vertexNum);

		///�u���b�N�̊e���_����ǂ̃u���b�N�Ɠ������Ă��邩���肷��
		if (block_[colAddress_][rowAddress_]->getType() == N_POLE) {
			if (vertexNum == 0) {
				blockType_[vertexNum].setHitBlockLtType(N_POLE);///����
			} else if(vertexNum == 1){
				blockType_[vertexNum].setHitBlockRtType(N_POLE);///�E��
			} else if (vertexNum == 2) {
				blockType_[vertexNum].setHitBlockRbType(N_POLE);///�E��
			} else if (vertexNum == 3) {
				blockType_[vertexNum].setHitBlockLbType(N_POLE);///����
			}
		}

	}
};
