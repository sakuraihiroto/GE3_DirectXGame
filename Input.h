#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION  0x0800
#include <dinput.h>
#include "WinApp.h"

class Input
{

public:
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //メンバ関数

	//初期化
	void Initialize(WinApp*winApp);
	//更新
	void Update();

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:
	//WindowsAPI
	WinApp* winApp = nullptr;

	// キーボードデバイスの生成
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	//全キーの状態
	BYTE key[256] = {};

	//前回の全キーの状態
	BYTE keyPre[256] = {};

};
