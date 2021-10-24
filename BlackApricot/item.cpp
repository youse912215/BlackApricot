#include "DxLib.h"
#include "item.h"
#include "player.h"
#include "random.h"
#include "constant.h"
#include <cmath>

using namespace std;

bool Item::light_action_flag[sizeof(enum lights)] = {};

Item::Item() {
	x = 0;
	y = 0;
	art = LoadGraph("Source/Other/apricot_art.png");
	mirror = LoadGraph("Source/Other/apricot_mirror.png");
	roap = LoadGraph("Source/Other/apricot_roap.png");
	tea = LoadGraph("Source/Other/apricot_tea.png");
	watch = LoadGraph("Source/Other/apricot_watch.png");
	light = LoadGraph("Source/Other/apricot_light.png");
	vase = LoadGraph("Source/Other/apricot_vase.png");
	max_range = 100.0;
}

Item::~Item() {
	DeleteGraph(art);
	DeleteGraph(mirror);
	DeleteGraph(roap);
	DeleteGraph(tea);
	DeleteGraph(watch);
	DeleteGraph(light);
	DeleteGraph(vase);
}

/// <summary>
/// 絵画を描画
/// </summary>
void Item::drawing_art() {
	changing_card_color(art, Art);
	DrawGraph(670, 80, art, true);
}

/// <summary>
/// 鏡を描画
/// </summary>
void Item::drawing_mirror() {
	changing_card_color(mirror, Mirror);
	DrawGraph(820, 135, mirror, true);
}

/// <summary>
/// プレイヤーが後方にいるときに前方にティーセットを描画
/// </summary>
void Item::drawing_tea_front() {
	if (Player::py < 200) {
		changing_card_color(tea, Tea);
		DrawGraph(300, 250, tea, true);
	}
}

/// <summary>
/// プレイヤーが前方にいるときに後方にティーセットを描画
/// </summary>
void Item::drawing_tea_back() {
	if (Player::py >= 200) {
		changing_card_color(tea, Tea);
		DrawGraph(300, 250, tea, true);
	}
}

/// <summary>
/// 壺を描画
/// </summary>
void Item::drawing_vase() {
	changing_card_color(vase, Vase);
	DrawGraph(100, 475, vase, true);
}

/// <summary>
/// アイテム更新
/// </summary>
void Item::drawing_update() {
	drawing_art();
	drawing_mirror();
	drawing_tea_back();
}

/// <summary>
/// 灯を描画
/// </summary>
/// <param name="active">状態</param>
void Item::drawing_light(double* lx, double* ly, bool& active) {
	if (lx == nullptr || ly == nullptr) { return; }

	if (active == true) {
		light_color = change_sign() == positive ? red : yellow;
		change_color_normal(light, light_color, 180);
		DrawGraph(static_cast<int>(*lx), static_cast<int>(*ly), light, true);
	}
}

/// <summary>
/// 灯を拡散
/// </summary>
/// <param name="dis">距離</param>
/// <param name="active">状態</param>
void Item::diffusion_light(double* lx, double* ly, double* lcx, double* lcy, double* dis, bool& active) {
	if (lx == nullptr || ly == nullptr) { return; }
	if (lcx == nullptr || lcy == nullptr || dis == nullptr) { return; }


	if (active == true) {
		*lx += cos(get_angle()) * UNIQUE_SPEED; //x方向の速度; //x座標に速度を加算
		*ly += sin(get_angle()) * UNIQUE_SPEED; //y方向の速度; //y座標に速度を加算
	}

	*dis = (*lcx - *lx) * (*lcx - *lx) + (*lcy - *ly) * (*lcy - *ly); //2点間距離を計算
	if (*dis > max_range) active = false; //灯を削除
}

/// <summary>
/// 灯をセットする
/// </summary>
/// <param name="active">状態</param>
void Item::active_light(double* lx, double* ly, double* lcx, double* lcy, bool& active) {
	if (lx == nullptr || ly == nullptr) { return; }
	if (lcx == nullptr || lcy == nullptr) { return; }

	*lx = *lcx + set_position(); //x座標のポジションのセット
	*ly = *lcy + set_position(); //y座標のポジションのセット
	active = true; //アクティブ状態
}

/// <summary>
/// 灯更新
/// </summary>
/// <param name="num">配置</param>
void Item::light_update(const int& num) {
	active_light(&light_x[num], &light_y[num], &light_cx[num], &light_cy[num], light_active[num]);
}

/// <summary>
/// 灯処理
/// </summary>
/// <param name="num">配置</param>
void Item::light_process(const int& num) {
	drawing_light(&light_x[num], &light_y[num], light_active[num]);
	diffusion_light(&light_x[num], &light_y[num], &light_cx[num], &light_cy[num], &distance[num], light_active[num]);
}
