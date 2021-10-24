#pragma once

#define PARTICLE_MAX 30 //�G�~�b�^�[�̑���

const int WIN_WIDTH = 1000; //�E�B���h�E����
const int WIN_HEIGHT = 600; //�E�B���h�E�c��

const int RANDOM_MIN = 0; //�ŏ��̃����_���l
const int RANDOM_MAX = 360; //�ő�̃����_���l
const int positive = 1; //�v���X
const int negative = -1; //�}�C�i�X
const double UNIQUE_SPEED = 2.5; //�ŗL���x

const int FONT_SIZE = 32; //�t�H���g�T�C�Y
const int CARD_WIDTH = 15; //�J�[�h�̉���
const int CARD_HEIGHT = 25; //�J�[�h�̏c��

/// <summary>
/// ���C�g�̖���
/// </summary>
enum lights {
	front,
	//��O�̓�
	back_left,
	//�����̓�
	back_center,
	//�������̓�
	back_right
	//�E���̓�
};

/// <summary>
/// �J�[�h�̐F
/// </summary>
enum cards {
	Red,
	//��
	Blue,
	//��
	Yellow,
	//���F
	Green
	//��
};

/// <summary>
/// �A�C�e���Ȃǂ̖���
/// </summary>
enum others {
	Art,
	//�G��
	Mirror,
	//��
	Tea,
	//�e�B�[�Z�b�g
	Vase,
	//��
	Bg,
	//�w�i
	Frame,
	//�t���[��
	_Char,
	//����
	_Watch
	//�E�H�b�`
};
