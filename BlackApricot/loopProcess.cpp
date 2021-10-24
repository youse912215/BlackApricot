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

	vector<Item> _light(PARTICLE_MAX); //�p�[�e�B�N������
	vector<int> l_quantity(sizeof(enum lights)); //���̌�

	// �Q�[�����[�v
	while (true) {
		ClearDrawScreen(); //��ʃN���A

		/* ���͏����@*/
		Input* input = new Input;
		input->input_info();
		input->update();
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; //�I������
		delete input;

		/* �X�V�����@*/
		/* �`�揈�� */
		Roap* roap = new Roap; //���[�v����
		roap->roap_update(); //���[�v�X�V
		delete roap; //���[�v�폜

		Background* _bg = new Background; //�w�i����
		_bg->drawing_bg(); //�w�i�`��

		Watch* watch = new Watch; //���v����
		watch->watch_update(); //���v�X�V
		delete watch; //���v�폜

		Item* item = new Item; //�A�C�e������
		item->drawing_update(); //���A�C�e���X�V

		//�p�[�e�B�N���X�V
		for (unsigned int j = 0; j < l_quantity.size(); ++j) {
			if (Item::light_action_flag[j]) {
				for (auto& i : _light) {
					if (i.light_active[j] == false) {
						i.light_update(j); //����̓��X�V
						break;
					}
					i.light_process(j); //����̓��`��
				}
			}
		}

		Char* _char = new Char; //��������
		_char->char_update(); //�����X�V

		Player* player = new Player; //�v���C���[����
		player->player_update(); //�v���C���[�X�V
		delete player; //�v���C���[�`��

		item->drawing_tea_front(); //�e�B�[�Z�b�g�X�V
		item->drawing_vase(); //��X�V
		delete item; //�S�A�C�e���폜

		Card* card = new Card; //�J�[�h����
		card->card_update(); //�J�[�h�X�V
		delete card; //�J�[�h�폜

		_bg->update(); //�w�i�X�V
		delete _bg; //�w�i�폜

		//�p�[�e�B�N���X�V
		if (Item::light_action_flag[front]) {
			for (auto& i : _light) {
				if (i.light_active[front] == false) {
					i.light_update(front); //�O���̓��X�V
					break;
				}
				i.light_process(front); //�O���̓��`��
			}
		}

		_char->drawing_message(); //���b�Z�[�W�\��
		delete _char; //�����폜

		if (Input::mx >= 0.60) break; //�E�o���ďI��

		window_in_roop(); //���[�v���E�B���h�E�ݒ�
		if (ProcessMessage() == -1) break; //Windows�V�X�e�����炭���������
	}
}
