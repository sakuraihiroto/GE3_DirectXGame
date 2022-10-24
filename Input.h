#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION  0x0800
#include <dinput.h>

class Input
{

public:
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //�����o�֐�

	//������
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//�X�V
	void Update();

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:

	// �L�[�{�[�h�f�o�C�X�̐���
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	//�S�L�[�̏��
	BYTE key[256] = {};

	//�O��̑S�L�[�̏��
	BYTE keyPre[256] = {};

};
