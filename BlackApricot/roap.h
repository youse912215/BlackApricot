#pragma once
#include "item.h"

class Roap : public Item {
private:
	const int roap_len; //���[�v����
	const int speed; //����
	const int fixed_value; //�Œ�l
	const int moving_value; //�^����
	int rx; //���[�v��x���W
	int ry; //���[�v��y���W

	int moving_roap();
	void drawing_roap();
public:
	static bool roap_flag; //���[�v�̃t���O
	static int roap_timer; //���[�v�̃^�C�}�[

	Roap();
	~Roap();
	
	void roap_update();
};
