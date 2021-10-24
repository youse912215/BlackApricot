#pragma once
#include "constant.h"

class Color {
public:
	int blue; //青色
	int yellow; //黄色
	int red; //赤色
	int green; //緑色
	int black; //黒色
	static bool roap_active[6]; //ロープの状態
	static bool color_active[3][6]; //色の状態

	Color();
	~Color();

protected:
	void change_color_normal(const int& Gr, const int& Cr, const int& Br);
	void change_color_multiple(const int& Gr, const int& Cr, const int& Br);
	void changing_card_color(const int& Gr, const int& Cr);

public:
	void changing_color_flag(const int& count);
};
