#pragma once

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "WinApp.h"
#include <vector>

//DirectX���
class DirectXCommon
{
public://�����o�֐�
	//������
	void Initialize(WinApp* winApp);

private:
	void InitializeDevice();

	void InitializeCommand();

	void InitializeSwapChain();

	void InitializeRenderTargetView();

	void InitializeDepthBuffer();

	void InitializeFence();

private:
	//DirectX12�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	//DXGI�t�@�N�g��
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;

	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

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
};