#pragma once
#include "item.h"

class Card : public Item {
private:
	int red_x; //赤のx座標
	int red_y; //赤のy座標
	int blue_x; //青のx座標
	int blue_y; //青のy座標
	int yellow_x; //黄のx座標
	int yellow_y; //黄のy座標
	int green_x; //緑のx座標
	int green_y; //緑のy座標

	void drawing_card(const int& cx, const int& cy, const int& R, const int& G, const int& B, const bool& flag);
	int moving_timer();

public:
	static bool card_flag[4]; //4色のカードフラグ
	static int card_timer; //カードタイマー
	static int card_color; //カードの色

	Card();
	~Card();
	void card_update();
	void card_flag_check();
};
