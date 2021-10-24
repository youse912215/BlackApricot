#pragma once
#include "color.h"

class Char : public Color {
private:
	int R; //�Ԃ̉摜
	int B; //�̉摜
	int Y; //���̉摜
	int G; //�΂̉摜
	int Num; //�����̉摜
	int n_size; //�����̃T�C�Y
	int tips; //�q���g�̉摜
	int tips_q; //�q���g��Q�R�}���h�̉摜
	int char_x; //������x���W
	int char_y; //������y���W

	void changing_char();
	void drawing_char(const int& Gr);
	void drawing_green(const int& Gr);
	void drawing_number(const int& Gn);

public:
	static bool tips_flag; //�q���g�̃t���O

	Char();
	~Char();
	void char_update();
	void drawing_message();
};
