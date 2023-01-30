#pragma once
#include <DirectXMath.h>
#include <d3d12.h>
#include <wrl.h>
#include<array>
#include<string>
#include "DirextXCommon.h"

//�X�v���C�g���ʕ�
class SpriteCommon
{
public://�����o�֐�
	//������
	void Initialize(DirectXCommon* dxCommon);

	void LoadTexture(uint32_t index, const std::string& fileName);

	void SetTextureCommands(uint32_t index);
	//�`��O����
	void PreDraw();
	//�`��㏈��
	void PostDraw();
	//getter
	DirectXCommon* GetDirectXCommon() { return dxCommon_; }
	ID3D12Resource* GetTextureBuffer(uint32_t index)const { return texBuff[index].Get(); }

private://�ÓI�����o�ϐ�
	//SRV�̍ő��
	static const size_t kMaxSRVCount = 2056;
	//�f�t�H���g�e�N�X�`���i�[�f�B���N�g��
	static std::string kDefaultTextureDirectoryPath;
private:
	DirectXCommon* dxCommon_;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;

	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;

	//Microsoft::WRL::ComPtr<ID3D12Resource> texBuff;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap;

	//�e�N�X�`���o�b�t�@
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, kMaxSRVCount>texBuff;

};