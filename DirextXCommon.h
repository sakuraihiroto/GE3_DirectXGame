#pragma once
#include <cassert>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "WinApp.h"

//DirectX���
class DirectXCommon
{
public://�����o�֐�
    //������
    void Initialize(WinApp* winApp);

    void InitializeDevice();

    void InitializeComannd();

    void InitializeSwapchain();

    void InitializeRenderTargetView();

    void InitializeDepthBuffer();

    void InitializeFence();
    //�`��O����
    void PreDraw();
    //�`��㏈��
    void PostDraw();
private:
    //DirectX12�f�o�C�X
    Microsoft::WRL::ComPtr<ID3D12Device> device;
    //DXGI�t�@�N�g��
    Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

    Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;

    Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
    //�o�b�N�o�b�t�@
    std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
private:
    //WindowsAPI
    WinApp* winApp = nullptr;

};