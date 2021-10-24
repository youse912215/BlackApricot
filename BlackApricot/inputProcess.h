#pragma once
#include "color.h"

class Input {

public:
	char keys[256] = {0}; //�ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = {0}; //1���[�v(�t���[��)�O�̃L�[�{�[�h���
	static double mx; //��������
	static double my; //�c������
	static bool timer_flag; //���͂̃^�C�}�[�t���O
	static int count; //���[�v�̓��̓J�E���g

	Input();
	void input_info();
	void update(Color& cr);

private:
	int m_distance; //�ړ���
	double m_rate; //�g�嗦

	void moving_player();
	void tips();
	void light_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max, const int& num);
	void card_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max);
	void watch_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max);
	void roap_action(const int& x_min, const int& x_max, const int& y_min, const int& y_max, Color& cr);
	void roap_count();
	void reset();
};
