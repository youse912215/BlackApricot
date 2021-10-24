#pragma once

#define PARTICLE_MAX 30 //エミッターの総数

const int WIN_WIDTH = 1000; //ウィンドウ横幅
const int WIN_HEIGHT = 600; //ウィンドウ縦幅

const int RANDOM_MIN = 0; //最小のランダム値
const int RANDOM_MAX = 360; //最大のランダム値
const int positive = 1; //プラス
const int negative = -1; //マイナス
const double UNIQUE_SPEED = 2.5; //固有速度

const int FONT_SIZE = 32; //フォントサイズ
const int CARD_WIDTH = 15; //カードの横幅
const int CARD_HEIGHT = 25; //カードの縦幅

/// <summary>
/// ライトの名称
/// </summary>
enum lights {
	front,
	//手前の灯
	back_left,
	//左奥の灯
	back_center,
	//中央奥の灯
	back_right
	//右奥の灯
};

/// <summary>
/// カードの色
/// </summary>
enum cards {
	Red,
	//赤
	Blue,
	//青
	Yellow,
	//黄色
	Green
	//緑
};

/// <summary>
/// アイテムなどの名称
/// </summary>
enum others {
	Art,
	//絵画
	Mirror,
	//鏡
	Tea,
	//ティーセット
	Vase,
	//壺
	Bg,
	//背景
	Frame,
	//フレーム
	_Char,
	//文字
	_Watch
	//ウォッチ
};
