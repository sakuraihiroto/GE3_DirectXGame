#pragma once
#include <Windows.h>

class WinApp
{
public: //静的メンバ変数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:

	//初期化
	void Initialize();
	//更新
	void Update();
};

