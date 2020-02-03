#pragma once

//===== ===== Extern ===== =====
#include <dxgi.h>
#include <d3d11.h>

//===== ===== Intern ===== =====
#include "Window.h"


class Renderer {
public:

	bool Initialize(const Window& myWindow, bool enalbeVSync, bool enableFullscreen);
	void ShutDown(void);
private:

	void BeginRender(void) const;
	void RenderQuad(void) const;
	void EndRender(void) const;

	bool CreateBuffer(void);
	bool CreateShader(void);

	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;
	IDXGISwapChain* swapChan = nullptr;
	ID3D11RenderTargetView* renderTargetView = nullptr;
	ID3D11Texture2D* depthStencilBuffer = nullptr;
	ID3D11DepthStencilState* depthStencilState = nullptr;
	ID3D11DepthStencilView* depthStencilView = nullptr;
	ID3D11RasterizerState* rasterState = nullptr;

	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;

	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	int indexBufferCount;

	ID3D11Buffer* constBuffer;

	int vRAM;
	char* vDesc;

	bool isVSync;
};