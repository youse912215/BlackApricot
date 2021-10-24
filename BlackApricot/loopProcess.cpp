#include "DxLib.h"
#include "windowPreference.h"
#include "inputProcess.h"
#include "player.h"
#include "background.h"
#include "item.h"
#include "constant.h"
#include "card.h"
#include "watch.h"
#include "char.h"
#include "roap.h"
#include "color.h"
#include <vector>

using namespace std;

void loop_process() {

	vector<Item> _light(PARTICLE_MAX); //パーティクル生成
	vector<int> l_quantity(sizeof(enum lights)); //灯の個数

	Color cr;
	Input input;
	Roap roap; //ロープ生成
	Player player; //プレイヤー生成
	Char _char; //文字生成
	Background _bg; //背景生成
	Card card; //カード生成
	Watch watch; //時計生成

	// ゲームループ
	while (true) {
		ClearDrawScreen(); //画面クリア

		/* 入力処理　*/
		input.input_info();
		input.update(cr);
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; //終了処理

		/* 更新処理　*/
		roap.roap_update(); //ロープ更新

		
		_bg.drawing_bg(); //背景描画

		
		watch.update(); //時計更新
		

		Item* item = new Item; //アイテム生成
		item->drawing_update(); //他アイテム更新

		//パーティクル更新
		for (unsigned int j = 0; j < l_quantity.size(); ++j) {
			if (Item::light_action_flag[j]) {
				for (auto& i : _light) {
					if (i.light_active[j] == false) {
						i.light_update(j); //後方の灯更新
						break;
					}
					i.light_process(j); //後方の灯描画
				}
			}
		}

		_char.char_update(); //文字更新	
		player.player_update(); //プレイヤー更新
		item->drawing_tea_front(); //ティーセット更新
		item->drawing_vase(); //壺更新
		delete item; //全アイテム削除

		
		card.card_update(); //カード更新
		

		_bg.update(); //背景更新

		//パーティクル更新
		if (Item::light_action_flag[front]) {
			for (auto& i : _light) {
				if (i.light_active[front] == false) {
					i.light_update(front); //前方の灯更新
					break;
				}
				i.light_process(front); //前方の灯描画
			}
		}

		_char.drawing_message(); //メッセージ表示

		if (Input::mx >= 0.60) break; //脱出して終了

		window_in_roop(); //ループ内ウィンドウ設定
		if (ProcessMessage() == -1) break; //Windowsシステムからくる情報を処理
	}
}
