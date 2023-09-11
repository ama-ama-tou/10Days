#pragma once
#include"Vec2.h"
#include"Matrix3x3.h"

/// <summary>
/// ���s�ړ�
/// </summary>
/// <param name="target">�Ώ�</param>
/// <param name="trans">�ړ�����</param>
/// <returns></returns>
Vec2 Translation(Vec2& target, Vec2 trans);
/// <summary>
/// �g��k��
/// </summary>
/// <param name="target">�Ώ�</param>
/// <param name="scale">�g�k��</param>
/// <returns></returns>
Vec2 Scaling(Vec2& target, Vec2 scale);
/// <summary>
/// ��]
/// </summary>
/// <param name="target">�Ώ�</param>
/// <param name="theta">theta�x��]����(1�x��)</param>
/// <returns></returns>
Vec2 Rotating(Vec2& target, float theta);
/// <summary>
/// �A�t�B���ϊ�
/// </summary>
/// <param name="target">�Ώ�</param>
/// <param name="target2origine">�Ώۂ���ϊ����_�܂ł̋���</param>
/// <param name="scale">�g�k��</param>
/// <param name="theta">theta�x��]����(1�x��)</param>
/// <returns></returns>
Vec2 Affine(Vec2& target, Vec2 target2origine, Vec2 scale, float theta);
