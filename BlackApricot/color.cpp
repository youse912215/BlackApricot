#include "color.h"
#include "DxLib.h"
#include "card.h"

#include "roap.h"

bool Color::roap_active[6] = {false, false, false, false, false, false};
bool Color::color_active[3][6] = {
		{false, false, false, false, false, false},
		{false, false, false, false, false, false},
		{false, false, false, false, false, false}
	};

Color::Color() {
	red = LoadGraph("Source/Color/apricot_red.png");
	blue = LoadGraph("Source/Color/apricot_blue.png");
	yellow = LoadGraph("Source/Color/apricot_yellow.png");
	green = LoadGraph("Source/Color/apricot_green.png");
	black = LoadGraph("Source/Color/apricot_black.png");
}

Color::~Color() {
	DeleteGraph(red);
	DeleteGraph(blue);
	DeleteGraph(yellow);
	DeleteGraph(green);
	DeleteGraph(black);
}

/// <summary>
/// 画像Grに色Crのノーマルブレンド
/// </summary>
/// <param name="Gr">画像</param>
/// <param name="Cr">指定の色</param>
void Color::change_color_normal(const int& Gr, const int& Cr, const int& Br) {
	GraphBlend(Gr, Cr, Br, DX_GRAPH_BLEND_NORMAL);
}

/// <summary>
/// 画像Grに色Crの乗算ブレンド
/// </summary>
/// <param name="Gr">画像</param>
/// <param name="Cr">指定の色</param>
/// <param name="Br">ブレンド値</param>
void Color::change_color_multiple(const int& Gr, const int& Cr, const int& Br) {
	GraphBlend(Gr, Cr, Br, DX_GRAPH_BLEND_MULTIPLE);
}

/// <summary>
/// カードが挿入されているときに指定のカードの色のフラグが建っていれば、指定の色に変更する
/// </summary>
/// <param name="Gr">画像</param>
/// <param name="Cr">指定の色</param>
void Color::changing_card_color(const int& Gr, const int& Cr) {
	if (Card::card_timer == 0) {
		if (color_active[Red][Cr] && Card::card_flag[Red]) {
			change_color_normal(Gr, red, 255);
		}
		else if (color_active[Blue][Cr] && Card::card_flag[Blue]) {
			change_color_normal(Gr, blue, 255);
		}
		else if (color_active[Yellow][Cr] && Card::card_flag[Yellow]) {
			change_color_normal(Gr, yellow, 255);
		}
	}
}

/// <summary>
/// 色とロープのフラグを建てる
/// </summary>
/// <param name="count">ロープのカウント</param>
void Color::changing_color_flag(const int& count) {
	Roap::roap_flag = true; //ロープのフラグをtrue
	memset(roap_active, false, 6); //文字以外のアイテムをfalse
	roap_active[count] = true; //count番のロープの状態をtrue

	//count番のロープの状態がtrueかつカードが指定の色ののときcount番目の指定色の状態をtrueにする
	if (Card::card_flag[Red] && roap_active[count]) {
		color_active[Red][count] = true;
	}
	else if (Card::card_flag[Blue] && roap_active[count]) {
		color_active[Blue][count] = true;
	}
	else if (Card::card_flag[Yellow] && roap_active[count]) {
		color_active[Yellow][count] = true;
	}
}
