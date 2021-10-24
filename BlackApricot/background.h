#pragma once
#include "color.h"

class Background : public Color {
private:
	int x; //x座標
	int y; //y座標
	int bg; //背景画像
	int frame; //フレーム画像
	int circle; //円の画像
	int r_min; //ランダム最小値
	int r_max; //ランダム最大値

	void drawing_frame();
	void drawing_circle(const int& x1, const int& y1, const int& size, const int& Cr, const int& Br);

public:
	void update();
	Background();
	~Background();
	void drawing_bg();
};
