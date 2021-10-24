#include "roap.h"
#include "DxLib.h"

bool Roap::roap_flag = false;
int Roap::roap_timer = 0;

Roap::Roap() {
	rx = 450;
	ry = 35 - moving_roap();
}

Roap::~Roap() {
}

/// <summary>
/// ロープを描画
/// </summary>
void Roap::drawing_roap() {
	DrawGraph(rx, ry, roap, true);
}

/// <summary>
/// ロープを引っ張り、戻す処理
/// </summary>
/// <returns>時間による出力値</returns>
int Roap::moving_roap() {
	if (roap_flag && roap_timer < 40) roap_timer++;
	if (roap_timer >= 40) {
		roap_timer = 0;
		roap_flag = false;
	}

	return ((roap_timer - 20) * (roap_timer - 20) - 400) / 10; //放物線を描く運動
}

/// <summary>
/// ロープを更新
/// </summary>
void Roap::roap_update() {
	moving_roap();
	drawing_roap();
}
