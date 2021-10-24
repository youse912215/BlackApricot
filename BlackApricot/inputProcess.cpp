#include "DxLib.h"
#include "inputProcess.h"
#include "player.h"
#include "item.h"
#include "constant.h"
#include "card.h"
#include "watch.h"
#include "roap.h"
#include "char.h"
#include "background.h"

double Input::mx = 0.0;
double Input::my = 0.0;
bool Input::timer_flag = true;
int Input::count = 0;

Input::Input() {
	m_distance = 15;
	m_rate = 0.03;
}

/// <summary>
/// �L�[�{�[�h���
/// </summary>
void Input::input_info() {
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; ++i) {
		oldkeys[i] = keys[i];
	}
	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

/// <summary>
/// ���͍X�V
/// </summary>
void Input::update() {
	moving_player();
	tips();
	light_action(65, 125, 65, 110, back_left);
	light_action(440, 515, 65, 110, back_center);
	light_action(545, 620, 65, 110, back_right);
	watch_action(155, 305, 65, 110);
	card_action(720, 880, 335, 410);
	roap_action(365, 425, 65, 110);
	reset();
}

/// <summary>
/// �v���C���[�̈ړ�����
/// </summary>
void Input::moving_player() {
	if ((keys[KEY_INPUT_RIGHT] || keys[KEY_INPUT_D]) && Player::px < 850) {
		/* �e�B�[�Z�b�g��ʉ߂ł��Ȃ��悤�ɂ��� */
		if (Player::px == 260 && Player::py >= 185 && Player::py <= 230) {
			Player::px -= m_distance;
		}
		Player::px += m_distance;
		Player::graph++;
		Player::reverse = false;
	}
	if ((keys[KEY_INPUT_LEFT] || keys[KEY_INPUT_A]) && Player::px > 75) {
		/* �e�B�[�Z�b�g��ʉ߂ł��Ȃ��悤�ɂ��� */
		if (Player::px == 710 && Player::py >= 185 && Player::py <= 230) {
			Player::px += m_distance;
		}
		Player::px -= m_distance;
		Player::graph++;
		Player::reverse = true;
	}
	if ((keys[KEY_INPUT_DOWN] || keys[KEY_INPUT_S]) && Player::py < 400) {
		/* �e�B�[�Z�b�g��ʉ߂ł��Ȃ��悤�ɂ��� */
		if (Player::py == 185 && Player::px >= 260 && Player::px <= 710) {
			Player::py -= m_distance;
		}
		else {
			mx -= m_rate;
			my -= m_rate;
		}
		Player::py += m_distance;
		Player::graph++;
	}
	if ((keys[KEY_INPUT_UP] || keys[KEY_INPUT_W]) && Player::py > 75) {
		/* �e�B�[�Z�b�g��ʉ߂ł��Ȃ��悤�ɂ��� */
		if (Player::py == 230 && Player::px >= 260 && Player::px <= 710) {
			Player::py += m_distance;
		}
		else {
			mx += m_rate;
			my += m_rate;
		}
		Player::py -= m_distance;
		Player::graph++;
	}
	else if ((keys[KEY_INPUT_UP] || keys[KEY_INPUT_W]) && Watch::watch_flag) {
		/* �o���������Ă���Ƃ��A�o���̂Ƃ���ňړ�����ƃT�C�Y������������i���ɕ����\���j */
		if (Player::px >= 200 && Player::px <= 260) {
			Player::graph++;
			mx += m_rate;
			my += m_rate;
		}
	}
}

/// <summary>
/// �q���g�\��
/// </summary>
void Input::tips() {
	if (keys[KEY_INPUT_Q] && !oldkeys[KEY_INPUT_Q] && !Char::tips_flag) Char::tips_flag = true;
	else if (keys[KEY_INPUT_Q] && !oldkeys[KEY_INPUT_Q] && Char::tips_flag) Char::tips_flag = false;
}

/// <summary>
/// �i����̓��̑O�Łj��߂�ꂽ�͈͂ɂ��鎞�ɁA���C�g�A�N�V�����iF�j���\�ɂ���
/// </summary>
/// <param name="x_min">x�ŏ��l</param>
/// <param name="x_max">x�ő�l</param>
/// <param name="y_min">y�ŏ��l</param>
/// <param name="y_max">y�ő�l</param>
/// <param name="num">���̔ԍ�</param>
void Input::light_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max, const int& num) {
	if (Player::px >= x_min && Player::px <= x_max) {
		if (Player::py >= y_min && Player::py <= y_max) {
			if (keys[KEY_INPUT_F] && !oldkeys[KEY_INPUT_F] && !Item::light_action_flag[num]) {
				Item::light_action_flag[num] = true;
			}
			else if (keys[KEY_INPUT_F] && !oldkeys[KEY_INPUT_F] && Item::light_action_flag[num]) {
				Item::light_action_flag[num] = false;
			}
		}
	}
}

/// <summary>
/// ��߂�ꂽ�͈͂ɂ��鎞�ɁA�J�[�h�A�N�V�����iF�j���\�ɂ���
/// </summary>
/// <param name="x_min">x�ŏ��l</param>
/// <param name="x_max">x�ő�l</param>
/// <param name="y_min">y�ŏ��l</param>
/// <param name="y_max">y�ő�l</param>
void Input::card_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max) {


	if (Player::px >= x_min && Player::px <= x_max) {
		if (Player::py >= y_min && Player::py <= y_max) {
			if (keys[KEY_INPUT_F] && !oldkeys[KEY_INPUT_F] && Card::card_timer == 0) {
				timer_flag = true;
				Card* card = new Card;
				card->card_flag_check();
				delete card;
			}
			else if (keys[KEY_INPUT_F] && !oldkeys[KEY_INPUT_F] && Card::card_timer >= 40) {
				timer_flag = false;
			}
		}
	}
}

/// <summary>
/// ��߂�ꂽ�͈͂ɂ��鎞�ɁA�E�H�b�`�A�N�V�����iF�j���\�ɂ���
/// </summary>
/// <param name="x_min">x�ŏ��l</param>
/// <param name="x_max">x�ő�l</param>
/// <param name="y_min">y�ŏ��l</param>
/// <param name="y_max">y�ő�l</param>
void Input::watch_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max) {
	if (Player::px >= x_min && Player::px <= x_max) {
		if (Player::py >= y_min && Player::py <= y_max) {
			if (keys[KEY_INPUT_F] && !oldkeys[KEY_INPUT_F]) {
				Watch* watch = new Watch;
				watch->moving_watch();
				delete watch;
			}
		}
	}
}

/// <summary>
/// ��߂�ꂽ�͈͂ɂ��鎞�ɁA���[�v�A�N�V�����iF�j���\�ɂ���
/// </summary>
/// <param name="x_min">x�ŏ��l</param>
/// <param name="x_max">x�ő�l</param>
/// <param name="y_min">y�ŏ��l</param>
/// <param name="y_max">y�ő�l</param>
void Input::roap_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max) {
	if (Player::px >= x_min && Player::px <= x_max) {
		if (Player::py >= y_min && Player::py <= y_max) {
			if (keys[KEY_INPUT_F] && !oldkeys[KEY_INPUT_F] && !Roap::roap_flag) {
				Color* card = new Color;
				card->changing_color_flag(count);
				delete card;
				roap_count(); //���[�v���v��
			}
		}
	}
}

/// <summary>
/// ���[�v���v��
/// </summary>
void Input::roap_count() {
	count = count < 6 ? count += 1 : count = 0;
}

/// <summary>
/// R�������Ƃ��A�e�l�����Z�b�g
/// </summary>
void Input::reset() {
	if (keys[KEY_INPUT_R] && !oldkeys[KEY_INPUT_R]) {
		timer_flag = true;
		count = 0;
		memset(Card::card_flag, false, sizeof(Card::card_flag));
		Card::card_flag[Blue] = true;
		Card::card_timer = 40;
		Card::card_color = Blue;
		Char::tips_flag = false;
		memset(Color::roap_active, false, sizeof(Color::roap_active));
		memset(Color::color_active, false, sizeof(Color::color_active));
		memset(Item::light_action_flag, false, sizeof(Item::light_action_flag));
		Roap::roap_flag = false;
		Roap::roap_timer = 0;
		Watch::watch_num = 0.0;
		Watch::timer = 0.0;
		Watch::watch_flag = false;
	}
}
