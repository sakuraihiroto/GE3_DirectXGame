#pragma once

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "WinApp.h"

//DirectX基盤
class DirectXCommon
{
public://メンバ関数
    //初期化
    void Initialize(WinApp* winApp);

    void InitializeDevice();

    void InitializeComannd();

    void InitializeSwapchain();

    void InitializeRenderTargetView();

    void InitializeDepthBuffer();

    void InitializeFence();
    //描画前処理
    void PreDraw();
    //描画後処理
    void PostDraw();
private:
    //DirectX12デバイス
    Microsoft::WRL::ComPtr<ID3D12Device> device;
    //DXGIファクトリ
    Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

    Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;

    Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

    Microsoft::WRL::ComPtr<ID3D12Fence> fence;
    //バックバッファ
    std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
private:
    //WindowsAPI
    WinApp* winApp = nullptr;
public:
    //フェンス値
    UINT64 fenceVal = 0;

};