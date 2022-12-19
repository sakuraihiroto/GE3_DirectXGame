#pragma once

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "WinApp.h"
#include <vector>
#include <chrono>

//DirectX���
class DirectXCommon
{
public://�����o�֐�
	//������
	void Initialize(WinApp* winApp);
	//�`��O����
	void PreDraw();
	//�`��㏈��
	void PostDraw();
	//Getter
	ID3D12Device* GetDevice() const { return device.Get(); }
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

private://�����o�֐�
	//�f�o�C�X�̏�����
	void InitializeDevice();
	//�R�}���h�֘A�̏�����
	void InitializeCommand();
	//�X���b�v�`�F�[���̏�����
	void InitializeSwapChain();
	//�����_�[�^�[�Q�b�g�r���[�̏�����
	void InitializeRenderTargetView();
	//�[�x�o�b�t�@�̏�����
	void InitializeDepthBuffer();
	//�t�F���X�̏�����
	void InitializeFence();

	//FPS�Œ菉����
	void InitializeFixFPS();
	//FPS�Œ�X�V
	void UpdateFixFPS();

	//�L�^����(FPS�Œ�)
	std::chrono::steady_clock::time_point reference_;

private://�����o�ϐ�
	//DirectX12�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	//DXGI�t�@�N�g��
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	//�R�}���h�A���P�[�^�[
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	//�R�}���h���X�g
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	//�R�}���h�L���[
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	//�X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	//WindowsAPI
	WinApp* winApp = nullptr;
	//�o�b�N�o�b�t�@
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	// �t�F���X�̐���
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	//�t�F���X�l
	UINT64 fenceVal = 0;
};