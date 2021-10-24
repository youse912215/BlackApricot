#include "color.h"
#include "DxLib.h"
#include "card.h"

#include "roap.h"

bool Color::roap_active[6] = {false, false, false, false, false, false};
bool Color::color_active[3][6] = {
		{false, false, false, false, false, false},
		{false, false, false, false, false, false},
		{false, false, false, false, false, false}
	};

Color::Color() {
	red = LoadGraph("Source/Color/apricot_red.png");
	blue = LoadGraph("Source/Color/apricot_blue.png");
	yellow = LoadGraph("Source/Color/apricot_yellow.png");
	green = LoadGraph("Source/Color/apricot_green.png");
	black = LoadGraph("Source/Color/apricot_black.png");
}

Color::~Color() {
	DeleteGraph(red);
	DeleteGraph(blue);
	DeleteGraph(yellow);
	DeleteGraph(green);
	DeleteGraph(black);
}

/// <summary>
/// �摜Gr�ɐFCr�̃m�[�}���u�����h
/// </summary>
/// <param name="Gr">�摜</param>
/// <param name="Cr">�w��̐F</param>
void Color::change_color_normal(const int& Gr, const int& Cr, const int& Br) {
	GraphBlend(Gr, Cr, Br, DX_GRAPH_BLEND_NORMAL);
}

/// <summary>
/// �摜Gr�ɐFCr�̏�Z�u�����h
/// </summary>
/// <param name="Gr">�摜</param>
/// <param name="Cr">�w��̐F</param>
/// <param name="Br">�u�����h�l</param>
void Color::change_color_multiple(const int& Gr, const int& Cr, const int& Br) {
	GraphBlend(Gr, Cr, Br, DX_GRAPH_BLEND_MULTIPLE);
}

/// <summary>
/// �J�[�h���}������Ă���Ƃ��Ɏw��̃J�[�h�̐F�̃t���O�������Ă���΁A�w��̐F�ɕύX����
/// </summary>
/// <param name="Gr">�摜</param>
/// <param name="Cr">�w��̐F</param>
void Color::changing_card_color(const int& Gr, const int& Cr) {
	if (Card::card_timer == 0) {
		if (color_active[Red][Cr] && Card::card_flag[Red]) {
			change_color_normal(Gr, red, 255);
		}
		else if (color_active[Blue][Cr] && Card::card_flag[Blue]) {
			change_color_normal(Gr, blue, 255);
		}
		else if (color_active[Yellow][Cr] && Card::card_flag[Yellow]) {
			change_color_normal(Gr, yellow, 255);
		}
	}
}

/// <summary>
/// �F�ƃ��[�v�̃t���O�����Ă�
/// </summary>
/// <param name="count">���[�v�̃J�E���g</param>
void Color::changing_color_flag(const int& count) {
	Roap::roap_flag = true; //���[�v�̃t���O��true
	memset(roap_active, false, 6); //�����ȊO�̃A�C�e����false
	roap_active[count] = true; //count�Ԃ̃��[�v�̏�Ԃ�true

	//count�Ԃ̃��[�v�̏�Ԃ�true���J�[�h���w��̐F�̂̂Ƃ�count�Ԗڂ̎w��F�̏�Ԃ�true�ɂ���
	if (Card::card_flag[Red] && roap_active[count]) {
		color_active[Red][count] = true;
	}
	else if (Card::card_flag[Blue] && roap_active[count]) {
		color_active[Blue][count] = true;
	}
	else if (Card::card_flag[Yellow] && roap_active[count]) {
		color_active[Yellow][count] = true;
	}
}
