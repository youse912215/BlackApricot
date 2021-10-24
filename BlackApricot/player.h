#pragma once

class Player {
private:
	int player; //プレイヤーの画像
	int graph1; //プレイヤー1
	int graph2; //プレイヤー2
	int graph3; //プレイヤー3
	int graph4; //プレイヤー4
	int width; //横幅
	int height; //縦幅
	int x1; //x座標
	int x2; //x座標
	int y1; //y座標
	int y2; //y座標
	double ex; //xの拡大率
	double ey; //yの拡大率
	double angle; //角度

	void drawing_player();

public:
	static int px; //プレイヤーx座標
	static int py; //プレイヤーy座標
	static int graph; //プレイヤーの変更先の画像
	static bool reverse; //反転

	Player();
	~Player();
	void player_update();
};
