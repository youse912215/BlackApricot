#include "DxLib.h"
#include "background.h"
#include "item.h"
#include "constant.h"
#include "random.h"

Background::Background() {
	x = 0;
	y = 0;
	bg = LoadGraph("Source/Other/apricot_bg.png");
	frame = LoadGraph("Source/Other/apricot_frame.png");
	circle = LoadGraph("Source/Other/apricot_circle.png");
	r_min = 0;
}

Background::~Background() {
	DeleteGraph(frame);
	DeleteGraph(circle);
	DeleteGraph(bg);
}

/// <summary>
/// 背景更新
/// </summary>
void Background::update() {
	if (!Item::light_action_flag[back_left]) drawing_circle(-100, -100, 700, black, 255);
	if (!Item::light_action_flag[back_center] || !Item::light_action_flag[back_right]) drawing_circle(
		200, -100, 700, black, 255);
	if (!Item::light_action_flag[front]) drawing_circle(500, -100, 700, black, 255);
	drawing_frame();
}

/// <summary>
/// 背景描画
/// </summary>
void Background::drawing_bg() {
	/* 灯の色を変える */
	if (Item::light_action_flag[back_left]) drawing_circle(130, 140, 60, yellow, 128);
	if (Item::light_action_flag[back_center]) drawing_circle(515, 140, 60, yellow, 128);
	if (Item::light_action_flag[back_right]) drawing_circle(615, 140, 60, yellow, 128);
	if (Item::light_action_flag[front]) drawing_circle(885, 195, 60, yellow, 128);
	changing_card_color(bg, Bg); //色変更
	DrawGraph(x, y, bg, true);
	DrawBox(825, 185, 890, 215, GetColor(255, 255, 255), true); //鏡の裏を隠すボックス
}

/// <summary>
/// フレームを描画
/// </summary>
void Background::drawing_frame() {
	changing_card_color(frame, Frame);
	DrawGraph(x, y, frame, true);
}

/// <summary>
/// 灯のバックライトを描画
/// </summary>
void Background::drawing_circle(const int& x1, const int& y1, const int& size, const int& Cr, const int& Br) {
	/*ランダム値によって、赤と黄を入れ替える*/
	r_max = Cr == yellow ? 15 : 0;
	change_color_multiple(circle, Cr, Br - get_random(0, r_max * 10));
	DrawExtendGraph(x1 + get_random(r_min, r_max),
	                y1 + get_random(r_min, r_max),
	                x1 + size, y1 + size,
	                circle, true);
}
