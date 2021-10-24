#pragma once
#include "color.h"

class Item : public Color {
protected:
	int x; //x座標
	int y; //y座標
	int art; //絵画の画像
	int mirror; //鏡の画像
	int roap; //ロープの画像
	int tea; //ティーセットの画像
	int watch; //ウォッチの画像
	int vase; //壺の画像

private:
	int light; //灯の画像
	int light_color; //灯の色
	double light_x[4] = {light_cx[0], light_cx[1], light_cx[2], light_cx[3]}; //灯のx座標
	double light_cx[4] = {905, 150, 540, 635}; //灯の現在のx座標
	double light_y[4] = {light_cy[0], light_cy[1], light_cy[2], light_cy[3]}; //灯のy座標
	double light_cy[4] = {215, 155, 155, 155}; //灯の現在のy座標
	double distance[4] = {0.0, 0.0, 0.0, 0.0}; //距離
	double max_range; //光が発生する範囲

	void drawing_art();
	void drawing_mirror();
	void drawing_tea_back();
	void drawing_light(double* lx, double* ly, bool& active);
	void diffusion_light(double* lx, double* ly, double* lcx, double* lcy, double* dis, bool& active);
	void active_light(double* lx, double* ly, double* lcx, double* lcy, bool& active);

public:
	bool light_active[4] = {false, false, false, false}; //灯の状態
	static bool light_action_flag[4]; //灯のアクションフラグ

	void drawing_tea_front();
	void drawing_vase();
	void drawing_update();
	void light_update(const int& num);
	void light_process(const int& num);
	Item();
	~Item();
};
