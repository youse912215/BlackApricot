#pragma once
#include "item.h"

class Roap : public Item {
private:
	int rx; //���[�v��x���W
	int ry; //���[�v��y���W

	void drawing_roap();
public:
	static bool roap_flag; //���[�v�̃t���O
	static int roap_timer; //���[�v�̃^�C�}�[

	Roap();
	~Roap();
	int moving_roap();
	void roap_update();
};
