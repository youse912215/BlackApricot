#pragma once
#include "color.h"

class Input {

public:
	char keys[256] = {0}; //最新のキーボード情報用
	char oldkeys[256] = {0}; //1ループ(フレーム)前のキーボード情報
	static double mx; //横軸方向
	static double my; //縦軸方向
	static bool timer_flag; //入力のタイマーフラグ
	static int count; //ロープの入力カウント

	Input();
	void input_info();
	void update(Color& cr);

private:
	int m_distance; //移動量
	double m_rate; //拡大率

	void moving_player();
	void tips();
	void light_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max, const int& num);
	void card_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max);
	void watch_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max);
	void roap_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max, Color& cr);
	void roap_count();
	void reset();
};
