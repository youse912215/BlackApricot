#include "roap.h"
#include "DxLib.h"
#include <cmath>

bool Roap::roap_flag = false;
int Roap::roap_timer = 0;

Roap::Roap() :
	roap_len(35), speed(10), fixed_value(40),
	moving_value(fixed_value * fixed_value / speed - speed)
{
	rx = 450;
	ry = roap_len;
}

Roap::~Roap() {
}

/// <summary>
/// ���[�v��`��
/// </summary>
void Roap::drawing_roap() {
	DrawGraph(rx, ry, roap, true);
}

/// <summary>
/// ���[�v����������A�߂�����
/// </summary>
/// <returns>���Ԃɂ��o�͒l</returns>
int Roap::moving_roap() {
	int t = roap_timer * roap_timer; //���[�v�̕ψ�
	int f = fixed_value * fixed_value; //�Œ�l
	return (t - f) / speed + moving_value + roap_len; //��������`���^��
}

/// <summary>
/// ���[�v���X�V
/// </summary>
void Roap::roap_update() {
	if (roap_timer >= speed) {
		roap_timer = 0;
		roap_flag = false;
	}
	drawing_roap();

	if (!roap_flag) return;
	if (roap_timer < speed) roap_timer++;
	ry = moving_roap();
}
