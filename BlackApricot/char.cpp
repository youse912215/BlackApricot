#include "char.h"
#include "DxLib.h"
#include "card.h"
#include "constant.h"
#include "inputProcess.h"
#include "watch.h"

bool Char::tips_flag = false;

Char::Char() {
	R = LoadGraph("Source/Char/apricot_R.png");
	B = LoadGraph("Source/Char/apricot_B.png");
	Y = LoadGraph("Source/Char/apricot_Y.png");
	G = LoadGraph("Source/Char/apricot_G.png");
	Num = LoadGraph("Source/Char/apricot_Num.png");
	tips = LoadGraph("Source/Char/apricot_tips.png");
	tips_q = LoadGraph("Source/Char/apricot_tips_q.png");
	n_size = 32;
	char_x = 840;
	char_y = 185;
}

Char::~Char() {
	DeleteGraph(R);
	DeleteGraph(B);
	DeleteGraph(Y);
	DeleteGraph(G);
	DeleteGraph(Num);
	DeleteGraph(tips);
	DeleteGraph(tips_q);
}

/// <summary>
/// 文字の色変更
/// </summary>
void Char::changing_char() {
	if (Card::card_flag[Red]) drawing_char(R);
	else if (Card::card_flag[Blue]) drawing_char(B);
	else if (Card::card_flag[Yellow]) drawing_char(Y);
	else if (Card::card_flag[Green]) drawing_char(G);
}

/// <summary>
/// Grの色の文字を描画
/// </summary>
/// <param name="Gr">色</param>
void Char::drawing_char(const int& Gr) {
	DrawGraph(char_x, char_y, Gr, true);
}

/// <summary>
/// 緑の文字を描画し、フラグの有無で緑色に変更
/// </summary>
/// <param name="Gr"></param>
void Char::drawing_green(const int& Gr) {
	if (Card::card_flag[Green] && Card::card_timer == 0)
		change_color_normal(Gr, green, 255); //緑に変更
	if (!Watch::watch_flag) DrawGraph(275, 200, Gr, true); //ウォッチフラグが建っていないときのみ描画
}

/// <summary>
/// Gnの数字をロープの上方に描画
/// </summary>
/// <param name="Gn">ロープのカウント</param>
void Char::drawing_number(const int& Gn) {
	DrawRectGraph(442, 25, n_size * Gn, 0, n_size, n_size, Num, true, false);
}

/// <summary>
/// 文字更新
/// </summary>
void Char::char_update() {
	changing_char();
	drawing_green(G);
}

/// <summary>
/// メッセージを描画
/// </summary>
void Char::drawing_message() {
	drawing_number(Input::count);
	if (tips_flag) DrawGraph(0, 0, tips, true);
	else DrawGraph(5, 545, tips_q, true);
}
