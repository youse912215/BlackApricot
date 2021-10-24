#pragma once
#include "item.h"

class Roap : public Item {
private:
	int rx; //ロープのx座標
	int ry; //ロープのy座標

	void drawing_roap();
public:
	static bool roap_flag; //ロープのフラグ
	static int roap_timer; //ロープのタイマー

	Roap();
	~Roap();
	int moving_roap();
	void roap_update();
};
