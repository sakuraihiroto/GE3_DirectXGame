#pragma once
#include <Windows.h>

class WinApp
{
public: //�ÓI�����o�ϐ�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:

	//������
	void Initialize();
	//�X�V
	void Update();
};

