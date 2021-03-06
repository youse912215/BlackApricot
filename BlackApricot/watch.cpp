#include "watch.h"
#include "DxLib.h"
#include "card.h"
#include "constant.h"
#include <cmath>

double Watch::watch_num = 0.0;
double Watch::timer = 0;
bool Watch::watch_flag = false;

Watch::Watch() : needle_size(11) {
	wx1 = 230.0;
	wy1 = 80.0;
	width = 62.0;
	height = 55.0;
	length = 30.0;	
}

Watch::~Watch() {
}

/// <summary>
/// ウォッチ更新
/// </summary>
void Watch::update() {
	rotate_needle();
	light_up();
	drawing();
	//sliding_watch();
	/* 全ての灯が点灯しているとき、ウォッチフラグをチェック */
	if (light_action_flag[back_left] && light_action_flag[back_center]
		&& light_action_flag[back_right] && light_action_flag[front])
		flag_check();
	if (watch_num > needle_size) watch_num = 0; //一周したら、針をリセット
}

/// <summary>
/// カードが緑のとき、ウォッチの針を回す
/// </summary>
void Watch::moving() {
	
	if (Card::card_flag[Green] && Card::card_timer == 0) watch_num++;
}

/// <summary>
/// ウォッチとその針を描画
/// </summary>
void Watch::drawing() {
	DrawGraph(static_cast<int>(wx1), static_cast<int>(wy1), watch, true); //ウォッチ
	DrawLine(static_cast<int>(width + wx1), static_cast<int>(height + wy1),
	         static_cast<int>(width + wx1 + wx2), static_cast<int>(height + wy1 + wy2),
	         GetColor(0, 0, 0), false); //針
}

/// <summary>
/// ウォッチをスライドする
/// </summary>
/// <returns></returns>
double Watch::sliding() {
	if (watch_flag && timer < 50) timer++;
	else if (!watch_flag && timer >= 50) timer--;

	return (timer * timer) / 20;
}

/// <summary>
/// 前方のウォッチを点灯
/// </summary>
void Watch::light_up() {
	if (watch_num != 7.0) light_action_flag[front] = false; //針が10時を示したとき
	else light_action_flag[front] = true;
}

/// <summary>
/// ウォッチフラグをチェックし、部屋が赤に染まればtrueにする
/// </summary>
void Watch::flag_check() {
	if (color_active[Red][Art] && color_active[Red][Mirror] && color_active[Red][Tea] && color_active[Red][Vase]
		&& color_active[Red][Bg] && color_active[Red][Frame]) {
		if (Card::card_timer == 0) watch_flag = true;
	}
}

/// <summary>
/// 時計の針を回転
/// </summary>
void Watch::rotate_needle()
{
	wx1 = 230.0 + sliding();
	radians = DX_PI * watch_num / 6.0;
	wx2 = length * cos(radians);
	wy2 = length * sin(radians);
}
