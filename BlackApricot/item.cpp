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
/// �G���`��
/// </summary>
void Item::drawing_art() {
	changing_card_color(art, Art);
	DrawGraph(670, 80, art, true);
}

/// <summary>
/// ����`��
/// </summary>
void Item::drawing_mirror() {
	changing_card_color(mirror, Mirror);
	DrawGraph(820, 135, mirror, true);
}

/// <summary>
/// �v���C���[������ɂ���Ƃ��ɑO���Ƀe�B�[�Z�b�g��`��
/// </summary>
void Item::drawing_tea_front() {
	if (Player::py < 200) {
		changing_card_color(tea, Tea);
		DrawGraph(300, 250, tea, true);
	}
}

/// <summary>
/// �v���C���[���O���ɂ���Ƃ��Ɍ���Ƀe�B�[�Z�b�g��`��
/// </summary>
void Item::drawing_tea_back() {
	if (Player::py >= 200) {
		changing_card_color(tea, Tea);
		DrawGraph(300, 250, tea, true);
	}
}

/// <summary>
/// ���`��
/// </summary>
void Item::drawing_vase() {
	changing_card_color(vase, Vase);
	DrawGraph(100, 475, vase, true);
}

/// <summary>
/// �A�C�e���X�V
/// </summary>
void Item::drawing_update() {
	drawing_art();
	drawing_mirror();
	drawing_tea_back();
}

/// <summary>
/// ����`��
/// </summary>
/// <param name="active">���</param>
void Item::drawing_light(double* lx, double* ly, bool& active) {
	if (lx == nullptr || ly == nullptr) { return; }

	if (active == true) {
		light_color = change_sign() == positive ? red : yellow;
		change_color_normal(light, light_color, 180);
		DrawGraph(static_cast<int>(*lx), static_cast<int>(*ly), light, true);
	}
}

/// <summary>
/// �����g�U
/// </summary>
/// <param name="dis">����</param>
/// <param name="active">���</param>
void Item::diffusion_light(double* lx, double* ly, double* lcx, double* lcy, double* dis, bool& active) {
	if (lx == nullptr || ly == nullptr) { return; }
	if (lcx == nullptr || lcy == nullptr || dis == nullptr) { return; }


	if (active == true) {
		*lx += cos(get_angle()) * UNIQUE_SPEED; //x�����̑��x; //x���W�ɑ��x�����Z
		*ly += sin(get_angle()) * UNIQUE_SPEED; //y�����̑��x; //y���W�ɑ��x�����Z
	}

	*dis = (*lcx - *lx) * (*lcx - *lx) + (*lcy - *ly) * (*lcy - *ly); //2�_�ԋ������v�Z
	if (*dis > max_range) active = false; //�����폜
}

/// <summary>
/// �����Z�b�g����
/// </summary>
/// <param name="active">���</param>
void Item::active_light(double* lx, double* ly, double* lcx, double* lcy, bool& active) {
	if (lx == nullptr || ly == nullptr) { return; }
	if (lcx == nullptr || lcy == nullptr) { return; }

	*lx = *lcx + set_position(); //x���W�̃|�W�V�����̃Z�b�g
	*ly = *lcy + set_position(); //y���W�̃|�W�V�����̃Z�b�g
	active = true; //�A�N�e�B�u���
}

/// <summary>
/// ���X�V
/// </summary>
/// <param name="num">�z�u</param>
void Item::light_update(const int& num) {
	active_light(&light_x[num], &light_y[num], &light_cx[num], &light_cy[num], light_active[num]);
}

/// <summary>
/// ������
/// </summary>
/// <param name="num">�z�u</param>
void Item::light_process(const int& num) {
	drawing_light(&light_x[num], &light_y[num], light_active[num]);
	diffusion_light(&light_x[num], &light_y[num], &light_cx[num], &light_cy[num], &distance[num], light_active[num]);
}
