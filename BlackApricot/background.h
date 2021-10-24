#pragma once
#include "color.h"

class Background : public Color {
private:
	int x; //x���W
	int y; //y���W
	int bg; //�w�i�摜
	int frame; //�t���[���摜
	int circle; //�~�̉摜
	int r_min; //�����_���ŏ��l
	int r_max; //�����_���ő�l

	void drawing_frame();
	void drawing_circle(const int& x1, const int& y1, const int& size, const int& Cr, const int& Br);

public:
	void update();
	Background();
	~Background();
	void drawing_bg();
};
