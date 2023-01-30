#pragma once
#include <DirectXMath.h>
#include "SpriteCommon.h"


//�X�v���C�g
class Sprite
{
public:
	//�萔�o�b�t�@�f�[�^�\����(�}�e���A��)
	struct ConstBufferDataMaterial {
		DirectX::XMFLOAT4 color;
	};

	//�萔�o�b�t�@�f�[�^�\����(3D�ϊ��s��)
	struct ConstBufferDataTransform {
		DirectX::XMMATRIX mat;//3D�ϊ��s��
	};

	//���_�f�[�^
	struct Vertex {
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT2 uv;
	};

	//���_�ԍ�
	enum VertexNumber {
		LB,//����
		LT,//����
		RB,//�E��
		RT,//�E��
	};

public://�����o�֐�
	//������
	void Initialize(SpriteCommon* spriteCommon, uint32_t textureIndex = UINT32_MAX);

	void Update();

	void Draw();
public:
	//setter
	void SetPosition(const DirectX::XMFLOAT2& position) { position_ = position; }
	void SetRotation(float rotation) { rotationZ = rotation; }
	void SetColor(DirectX::XMFLOAT4 color) { color_ = color; }
	void SetSize(const DirectX::XMFLOAT2& size) { size_ = size; }
	void SetAnchorPoint(const DirectX::XMFLOAT2& anchorPoint) { anchorPoint_ = anchorPoint; }
	void SetIsFlipX(const bool& isFlipX) { isFlipX_ = isFlipX; }
	void SetIsFlipY(const bool& isFlipY) { isFlipY_ = isFlipY; }
	void SetIsInvisible(const bool& isInvisible) { isInvisible_ = isInvisible; }
	void SetTextureIndex(uint32_t index) { this->textureIndex_ = index; }
	void SetTextureLeftTop(const DirectX::XMFLOAT2& textureLeftTop) { this->textureLeftTop_ = textureLeftTop; }
	void SetTextureSize(const DirectX::XMFLOAT2& textureSize) { this->textureSize_ = textureSize; }

	//getter
	const DirectX::XMFLOAT2& GetPosition() const { return position_; }
	float GetRotation() const { return rotationZ; }
	const DirectX::XMFLOAT4 GetColor()const { return color_; }
	const DirectX::XMFLOAT2& GetSize() const { return size_; }
	const DirectX::XMFLOAT2& GetAnchorPoint()const { return anchorPoint_; }
	const bool GetIsFlipX()const { return isFlipX_; }
	const bool GetIsFlipY()const { return isFlipY_; }
	const bool GetIsInvisible()const { return isInvisible_; }
	const uint32_t GetTextureIndex()const { return textureIndex_; }
	const DirectX::XMFLOAT2& GetTextureLeftTop()const { return textureLeftTop_; }
	const DirectX::XMFLOAT2& GetTextureSize()const { return textureSize_; }
private://�����o�֐�
	//�e�N�X�`���T�C�Y���C���[�W�ɍ��킹��
	void AdjustTextureSize();

private:
	//�X�v���C�g���
	DirectX::XMFLOAT4 color_ = { 1,1,1,1 };
	float rotationZ = 0.0f;
	DirectX::XMFLOAT2 position_ = { 0.0f,0.0f };
	DirectX::XMFLOAT2 size_ = { 100.0f,100.0f };
	//�A���J�[�|�C���g
	DirectX::XMFLOAT2 anchorPoint_ = { 0.0f,0.0f };
	//�e�N�X�`�����
	//�e�N�X�`��������W
	DirectX::XMFLOAT2 textureLeftTop_ = { 0.0f,0.0f };
	//�e�N�X�`���؂�o���T�C�Y
	DirectX::XMFLOAT2 textureSize_ = { 100.0f,100.0f };

	//�e�N�X�`���ԍ�
	uint32_t textureIndex_ = 0;

	//���E�t���b�v
	bool isFlipX_ = false;
	//�㉺�t���b�v
	bool isFlipY_ = false;
	//��\���t���O
	bool isInvisible_ = false;

	SpriteCommon* spriteCommon_;

	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;

	D3D12_VERTEX_BUFFER_VIEW vbView{};

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffMaterial;
	ConstBufferDataMaterial* constMapMaterial = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffTransform;
	ConstBufferDataTransform* constMapTransform = nullptr;

	Vertex vertices[4];

};