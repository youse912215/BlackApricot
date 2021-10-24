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

	vector<Item> _light(PARTICLE_MAX); //�p�[�e�B�N������
	vector<int> l_quantity(sizeof(enum lights)); //���̌�

	Color cr;
	Input input;
	Roap roap; //���[�v����
	Player player; //�v���C���[����
	Char _char; //��������
	Background _bg; //�w�i����
	Card card; //�J�[�h����
	Watch watch; //���v����

	// �Q�[�����[�v
	while (true) {
		ClearDrawScreen(); //��ʃN���A

		/* ���͏����@*/
		input.input_info();
		input.update(cr);
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; //�I������

		/* �X�V�����@*/
		roap.roap_update(); //���[�v�X�V

		
		_bg.drawing_bg(); //�w�i�`��

		
		watch.update(); //���v�X�V
		

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

		_char.char_update(); //�����X�V	
		player.player_update(); //�v���C���[�X�V
		item->drawing_tea_front(); //�e�B�[�Z�b�g�X�V
		item->drawing_vase(); //��X�V
		delete item; //�S�A�C�e���폜

		
		card.card_update(); //�J�[�h�X�V
		

		_bg.update(); //�w�i�X�V

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

		_char.drawing_message(); //���b�Z�[�W�\��

		if (Input::mx >= 0.60) break; //�E�o���ďI��

		window_in_roop(); //���[�v���E�B���h�E�ݒ�
		if (ProcessMessage() == -1) break; //Windows�V�X�e�����炭���������
	}
}
