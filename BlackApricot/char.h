#pragma once
#include "color.h"

class Char : public Color {
private:
	int R; //赤の画像
	int B; //青の画像
	int Y; //黄の画像
	int G; //緑の画像
	int Num; //数字の画像
	int n_size; //数字のサイズ
	int tips; //ヒントの画像
	int tips_q; //ヒントのQコマンドの画像
	int char_x; //文字のx座標
	int char_y; //文字のy座標

	void changing_char();
	void drawing_char(const int& Gr);
	void drawing_green(const int& Gr);
	void drawing_number(const int& Gn);

public:
	static bool tips_flag; //ヒントのフラグ

	Char();
	~Char();
	void char_update();
	void drawing_message();
};
