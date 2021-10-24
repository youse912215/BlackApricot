#pragma once
#include "item.h"

class Watch : public Item {
private:
	double wx1; //ウォッチのx座標1
	double wy1; //ウォッチのy座標1
	double wx2; //ウォッチのx座標2
	double wy2; //ウォッチのy座標2
	double width; //ウォッチの横幅
	double height; //ウォッチの縦幅
	double length; //針の長さ
	double radians; //ラジアン
	const int needle_size;

	void drawing();
	void light_up();
	void flag_check();
	void rotate_needle();

public:
	static double watch_num; //ウォッチの時間（0～11,12時間分）
	static bool watch_flag; //ウォッチの起動の有無を確認するフラグ
	static double timer; //ウォッチをスライドする制御に使用するタイマー

	Watch();
	~Watch();
	void update();
	void moving();
	double sliding();
};
