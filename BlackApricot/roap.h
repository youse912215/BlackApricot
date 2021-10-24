#pragma once
#include "item.h"

class Roap : public Item {
private:
	const int roap_len; //ロープ長さ
	const int speed; //速さ
	const int fixed_value; //固定値
	const int moving_value; //運動量
	int rx; //ロープのx座標
	int ry; //ロープのy座標

	int moving_roap();
	void drawing_roap();
public:
	static bool roap_flag; //ロープのフラグ
	static int roap_timer; //ロープのタイマー

	Roap();
	~Roap();
	
	void roap_update();
};
