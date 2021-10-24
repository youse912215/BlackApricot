#pragma once
#include "item.h"

class Card : public Item {
private:
	int red_x; //�Ԃ�x���W
	int red_y; //�Ԃ�y���W
	int blue_x; //��x���W
	int blue_y; //��y���W
	int yellow_x; //����x���W
	int yellow_y; //����y���W
	int green_x; //�΂�x���W
	int green_y; //�΂�y���W

	void drawing_card(const int& cx, const int& cy, const int& R, const int& G, const int& B, const bool& flag);
	int moving_timer();

public:
	static bool card_flag[4]; //4�F�̃J�[�h�t���O
	static int card_timer; //�J�[�h�^�C�}�[
	static int card_color; //�J�[�h�̐F

	Card();
	~Card();
	void card_update();
	void card_flag_check();
};
