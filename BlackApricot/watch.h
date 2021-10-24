#pragma once
#include "item.h"

class Watch : public Item {
private:
	double wx1; //�E�H�b�`��x���W1
	double wy1; //�E�H�b�`��y���W1
	double wx2; //�E�H�b�`��x���W2
	double wy2; //�E�H�b�`��y���W2
	double width; //�E�H�b�`�̉���
	double height; //�E�H�b�`�̏c��
	double length; //�j�̒���
	double radians; //���W�A��
	const int needle_size;

	void drawing();
	void light_up();
	void flag_check();
	void rotate_needle();

public:
	static double watch_num; //�E�H�b�`�̎��ԁi0�`11,12���ԕ��j
	static bool watch_flag; //�E�H�b�`�̋N���̗L�����m�F����t���O
	static double timer; //�E�H�b�`���X���C�h���鐧��Ɏg�p����^�C�}�[

	Watch();
	~Watch();
	void update();
	void moving();
	double sliding();
};
