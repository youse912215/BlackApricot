#include "watch.h"
#include "DxLib.h"
#include "card.h"
#include "constant.h"
#include <cmath>

double Watch::watch_num = 0.0;
double Watch::timer = 0;
bool Watch::watch_flag = false;

Watch::Watch() : needle_size(11) {
	wx1 = 230.0;
	wy1 = 80.0;
	width = 62.0;
	height = 55.0;
	length = 30.0;	
}

Watch::~Watch() {
}

/// <summary>
/// �E�H�b�`�X�V
/// </summary>
void Watch::update() {
	rotate_needle();
	light_up();
	drawing();
	//sliding_watch();
	/* �S�Ă̓����_�����Ă���Ƃ��A�E�H�b�`�t���O���`�F�b�N */
	if (light_action_flag[back_left] && light_action_flag[back_center]
		&& light_action_flag[back_right] && light_action_flag[front])
		flag_check();
	if (watch_num > needle_size) watch_num = 0; //���������A�j�����Z�b�g
}

/// <summary>
/// �J�[�h���΂̂Ƃ��A�E�H�b�`�̐j����
/// </summary>
void Watch::moving() {
	
	if (Card::card_flag[Green] && Card::card_timer == 0) watch_num++;
}

/// <summary>
/// �E�H�b�`�Ƃ��̐j��`��
/// </summary>
void Watch::drawing() {
	DrawGraph(static_cast<int>(wx1), static_cast<int>(wy1), watch, true); //�E�H�b�`
	DrawLine(static_cast<int>(width + wx1), static_cast<int>(height + wy1),
	         static_cast<int>(width + wx1 + wx2), static_cast<int>(height + wy1 + wy2),
	         GetColor(0, 0, 0), false); //�j
}

/// <summary>
/// �E�H�b�`���X���C�h����
/// </summary>
/// <returns></returns>
double Watch::sliding() {
	if (watch_flag && timer < 50) timer++;
	else if (!watch_flag && timer >= 50) timer--;

	return (timer * timer) / 20;
}

/// <summary>
/// �O���̃E�H�b�`��_��
/// </summary>
void Watch::light_up() {
	if (watch_num != 7.0) light_action_flag[front] = false; //�j��10�����������Ƃ�
	else light_action_flag[front] = true;
}

/// <summary>
/// �E�H�b�`�t���O���`�F�b�N���A�������Ԃɐ��܂��true�ɂ���
/// </summary>
void Watch::flag_check() {
	if (color_active[Red][Art] && color_active[Red][Mirror] && color_active[Red][Tea] && color_active[Red][Vase]
		&& color_active[Red][Bg] && color_active[Red][Frame]) {
		if (Card::card_timer == 0) watch_flag = true;
	}
}

/// <summary>
/// ���v�̐j����]
/// </summary>
void Watch::rotate_needle()
{
	wx1 = 230.0 + sliding();
	radians = DX_PI * watch_num / 6.0;
	wx2 = length * cos(radians);
	wy2 = length * sin(radians);
}
