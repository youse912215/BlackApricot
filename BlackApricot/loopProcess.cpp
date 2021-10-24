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
#include <vector>

using namespace std;

void loop_process() {

	vector<Item> _light(PARTICLE_MAX); //パーティクル生成
	vector<int> l_quantity(sizeof(enum lights)); //灯の個数

	// ゲームループ
	while (true) {
		ClearDrawScreen(); //画面クリア

		/* 入力処理　*/
		Input* input = new Input;
		input->input_info();
		input->update();
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; //終了処理
		delete input;

		/* 更新処理　*/
		/* 描画処理 */
		Roap* roap = new Roap; //ロープ生成
		roap->roap_update(); //ロープ更新
		delete roap; //ロープ削除

		Background* _bg = new Background; //背景生成
		_bg->drawing_bg(); //背景描画

		Watch* watch = new Watch; //時計生成
		watch->watch_update(); //時計更新
		delete watch; //時計削除

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

		Char* _char = new Char; //文字生成
		_char->char_update(); //文字更新

		Player* player = new Player; //プレイヤー生成
		player->player_update(); //プレイヤー更新
		delete player; //プレイヤー描画

		item->drawing_tea_front(); //ティーセット更新
		item->drawing_vase(); //壺更新
		delete item; //全アイテム削除

		Card* card = new Card; //カード生成
		card->card_update(); //カード更新
		delete card; //カード削除

		_bg->update(); //背景更新
		delete _bg; //背景削除

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

		_char->drawing_message(); //メッセージ表示
		delete _char; //文字削除

		if (Input::mx >= 0.60) break; //脱出して終了

		window_in_roop(); //ループ内ウィンドウ設定
		if (ProcessMessage() == -1) break; //Windowsシステムからくる情報を処理
	}
}
