#pragma once
#include <d3d12.h>
#include <wrl.h>
#include "DirextXCommon.h"

//�X�v���C�g���ʕ�
class SpriteCommon
{
public://�����o�֐�
	//������
	void Initialize(DirectXCommon* dxCommon);

	void PreDraw();

	DirectXCommon* GetDirectXCommon() { return dxCommon_; }
private:
	DirectXCommon* dxCommon_;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;

	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
};