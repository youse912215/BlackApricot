#pragma once
#include "constant.h"

class Color {
public:
	int blue; //�F
	int yellow; //���F
	int red; //�ԐF
	int green; //�ΐF
	int black; //���F
	static bool roap_active[6]; //���[�v�̏��
	static bool color_active[3][6]; //�F�̏��

	Color();
	~Color();

protected:
	void change_color_normal(const int& Gr, const int& Cr, const int& Br);
	void change_color_multiple(const int& Gr, const int& Cr, const int& Br);
	void changing_card_color(const int& Gr, const int& Cr);

public:
	void changing_color_flag(const int& count);
};
