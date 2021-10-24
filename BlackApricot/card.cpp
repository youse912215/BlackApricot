#include "card.h"
#include "DxLib.h"
#include "constant.h"
#include "inputProcess.h"

bool Card::card_flag[4] = {false, true, false, false}; //�̂�true
int Card::card_timer = 40;
int Card::card_color = Blue;

Card::Card() {
	red_x = 835;
	red_y = 605;
	blue_x = 865;
	blue_y = 585;
	yellow_x = 890;
	yellow_y = 565;
	green_x = 917;
	green_y = 545;
}

Card::~Card() {
}

/// <summary>
/// �J�[�h�X�V
/// </summary>
void Card::card_update() {
	drawing_card(red_x, red_y, 205, 0, 0, card_flag[Red]);
	drawing_card(blue_x, blue_y, 0, 0, 205, card_flag[Blue]);
	drawing_card(yellow_x, yellow_y, 205, 205, 0, card_flag[Yellow]);
	drawing_card(green_x, green_y, 0, 190, 0, card_flag[Green]);
}

void Card::card_flag_check() {

	card_color++;
	if (card_color > 3) card_color = Red;

	memset(card_flag, false, sizeof(card_flag));

	switch (card_color) {
	case Red:
		card_flag[Red] = true;
		break;
	case Blue:
		card_flag[Blue] = true;
		break;
	case Yellow:
		card_flag[Yellow] = true;
		break;
	case Green:
		card_flag[Green] = true;
		break;
	}
}

/// <summary>
/// �J�[�h�̕`��
/// </summary>
/// <param name="flag">�J�[�h�̃t���O</param>
void Card::drawing_card(const int& cx, const int& cy, const int& R, const int& G, const int& B, const bool& flag) {
	/* �J�[�h�̃^�C�}�[�ɂ���āA�ړ� */
	if (flag) {
		DrawBox(cx, cy - moving_timer(),
		        cx + CARD_WIDTH, (cy + CARD_HEIGHT) - moving_timer(),
		        GetColor(R, G, B), true);
	}
}

/// <summary>
/// �^�C�}�[�t���O���������Ƃ��A�J�[�h���ړ�
/// </summary>
/// <returns>�^�C�}�[��2��</returns>
int Card::moving_timer() {
	if (Input::timer_flag && card_timer < 40) card_timer++; //�^�C�}�[��40�܂ő��₷
	if (!Input::timer_flag && card_timer > 0) card_timer--; //�^�C�}�[��0�܂Ō��炷

	return (card_timer * card_timer) / 15;
}
