#include "Sprite.h"

Sprite::Sprite(){
	//Default the sprite to position (0, 0, 0)
	position.x = 0;
	position.y = 0;
	position.z = 0;

	//Default the sprite color
	color = D3DCOLOR_ARGB(255, 255, 255, 255);

	//We are not initialized yet
	initialized = false;
}

Sprite::Sprite(float x, float y){
	//Default the sprite to position (0, 0, 0)
	position.x = 0;
	position.y = 0;
	position.z = 0;

	//Default the sprite color
	color = D3DCOLOR_ARGB(255, 255, 255, 255);

	//Not initialized yet
	initialized = false;
}

bool Sprite::Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height){
	//Same funcionality as D3DXCreateTextureFromFile EXCEPT width and height are manually entered
	if(!SUCCEEDED(D3DXCreateTextureFromFileEx(device, file.c_str(), width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture))){
		std::string s = "There was a issue creating the texture for the sprite. Requested image: '" + file + "'";
		MessageBox(NULL, s.c_str(), "Error loading the game assets!", MB_ICONERROR | MB_OK);
		return false;
	}

	if(!SUCCEEDED(D3DXCreateSprite(device, &sprite))){
		MessageBox(NULL, "There was an issue creating the sprite.", NULL, MB_ICONERROR | MB_OK);
		return false;
	}

	initialized = true;

	return true;
}

bool Sprite::IsInitialized(){
	return initialized;
}

void Sprite::Update(float gameTime){

}

void Sprite::Draw(float gameTime){
	if(sprite && texture){
		sprite->Begin(D3DXSPRITE_ALPHABLEND);

		sprite->Draw(texture, NULL, NULL, &position, color);

		sprite->End();
	}
}

Sprite::~Sprite(){
	if(sprite){
		sprite->Release();
		sprite = 0;
	}

	if(texture){
		texture->Release();
		texture = 0;
	}
}