#pragma once
#include <Windows.h>

class WinApp
{
public: //�ÓI�����o�ϐ�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	// �E�B���h�E�T�C�Y
	static const int window_width = 1280;  // ����
	static const int window_height = 720;  // �c��

public:

	//������
	void Initialize();
	//�X�V
	void Update();

	//�I��
	void Finalize();

	//���b�Z�[�W�̏���
	bool ProcessMessage();

	//getter
	HWND GetHwnd() const { return hwnd; }

	HINSTANCE GetHInstance()const { return w.hInstance; }
private:
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
};

