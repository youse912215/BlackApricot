#pragma once

class Player {
private:
	int player; //�v���C���[�̉摜
	int graph1; //�v���C���[1
	int graph2; //�v���C���[2
	int graph3; //�v���C���[3
	int graph4; //�v���C���[4
	int width; //����
	int height; //�c��
	int x1; //x���W
	int x2; //x���W
	int y1; //y���W
	int y2; //y���W
	double ex; //x�̊g�嗦
	double ey; //y�̊g�嗦
	double angle; //�p�x

	void drawing_player();

public:
	static int px; //�v���C���[x���W
	static int py; //�v���C���[y���W
	static int graph; //�v���C���[�̕ύX��̉摜
	static bool reverse; //���]

	Player();
	~Player();
	void player_update();
};
