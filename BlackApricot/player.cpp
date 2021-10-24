#include "player.h"
#include "DxLib.h"
#include "inputProcess.h"
#include "card.h"

int Player::px = 200;
int Player::py = 200;
int Player::graph = 1;
bool Player::reverse = false;

Player::Player() {
	width = 128;
	height = 256;
	graph1 = LoadGraph("Source/Charactor/apricot_pr1.png");
	graph2 = LoadGraph("Source/Charactor/apricot_pr2.png");
	graph3 = LoadGraph("Source/Charactor/apricot_pr3.png");
	graph4 = LoadGraph("Source/Charactor/apricot_pr4.png");
	player = graph1;
	x1 = px + width / 2;
	x2 = width / 2;
	y1 = py + height / 2;
	y2 = height / 2;
	ex = 1.0 - Input::mx;
	ey = 1.0 - Input::my;
	angle = 0.0;
}

Player::~Player() {
	DeleteGraph(graph1);
	DeleteGraph(graph2);
	DeleteGraph(graph3);
	DeleteGraph(graph4);
}

/// <summary>
/// プレイヤー更新
/// </summary>
void Player::player_update() {
	drawing_player();
}

/// <summary>
/// プレイヤーを描画
/// </summary>
void Player::drawing_player() {
	/* 歩くごとに次の画像に変更する */
	switch (graph) {
	case 1:
		player = graph1;
		break;
	case 2:
		player = graph2;
		break;
	case 3:
		player = graph3;
		break;
	case 4:
		player = graph4;
		break;
	default:
		graph = 1;
		break;
	}
	DrawRotaGraph3(x1, y1, x2, y2,
	               ex, ey, angle,
	               player, true, reverse);
}
