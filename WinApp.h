#pragma once
#include <Windows.h>

//WindowsAPI
class WinApp
{
public://�ÓI�����o�֐�
	//�E�B���h�E�v���V�[�W��
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�
	//������
	void Initialize();
	//�X�V
	void Update();
	//getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }
	//�I��
	void Finalize();
	//���b�Z�[�W�̏���
	bool ProcessMessage();

private:
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;
	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
public://�萔
	//�E�B���h�E����
	static const int window_width = 1280;
	//�E�B���h�E�c��
	static const int window_height = 720;
};