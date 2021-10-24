#include "roap.h"
#include "DxLib.h"

bool Roap::roap_flag = false;
int Roap::roap_timer = 0;

Roap::Roap() {
	rx = 450;
	ry = 35 - moving_roap();
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
	if (roap_flag && roap_timer < 40) roap_timer++;
	if (roap_timer >= 40) {
		roap_timer = 0;
		roap_flag = false;
	}

	return ((roap_timer - 20) * (roap_timer - 20) - 400) / 10; //��������`���^��
}

/// <summary>
/// ���[�v���X�V
/// </summary>
void Roap::roap_update() {
	moving_roap();
	drawing_roap();
}
