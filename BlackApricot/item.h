#pragma once
#include "color.h"

class Item : public Color {
protected:
	int x; //x���W
	int y; //y���W
	int art; //�G��̉摜
	int mirror; //���̉摜
	int roap; //���[�v�̉摜
	int tea; //�e�B�[�Z�b�g�̉摜
	int watch; //�E�H�b�`�̉摜
	int vase; //��̉摜

private:
	int light; //���̉摜
	int light_color; //���̐F
	double light_x[4] = {light_cx[0], light_cx[1], light_cx[2], light_cx[3]}; //����x���W
	double light_cx[4] = {905, 150, 540, 635}; //���̌��݂�x���W
	double light_y[4] = {light_cy[0], light_cy[1], light_cy[2], light_cy[3]}; //����y���W
	double light_cy[4] = {215, 155, 155, 155}; //���̌��݂�y���W
	double distance[4] = {0.0, 0.0, 0.0, 0.0}; //����
	double max_range; //������������͈�

	void drawing_art();
	void drawing_mirror();
	void drawing_tea_back();
	void drawing_light(double* lx, double* ly, bool& active);
	void diffusion_light(double* lx, double* ly, double* lcx, double* lcy, double* dis, bool& active);
	void active_light(double* lx, double* ly, double* lcx, double* lcy, bool& active);

public:
	bool light_active[4] = {false, false, false, false}; //���̏��
	static bool light_action_flag[4]; //���̃A�N�V�����t���O

	void drawing_tea_front();
	void drawing_vase();
	void drawing_update();
	void light_update(const int& num);
	void light_process(const int& num);
	Item();
	~Item();
};
