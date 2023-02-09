#ifndef SPRITE_H
#define SPRITE_H

#include <d3dx9.h>
#include <string>

class Sprite{
	public:
		Sprite();
		Sprite(float x, float y);
		~Sprite();

		bool Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height);
		bool IsInitialized();
		virtual void Update(float gameTime);
		virtual void Draw(float gameTime);
	private:
		LPDIRECT3DTEXTURE9 texture;
		LPD3DXSPRITE sprite;

		D3DXVECTOR3 position;
		D3DCOLOR color;
		bool initialized;
};

#endif