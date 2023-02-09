#include "Game.h"

Game::Game(){

}

bool Game::Initialize(HWND hWnd){

	gDevice = new GraphicsDevice();

	if(!gDevice->Initialize(hWnd, true))
		return false;

	player = new Sprite(19, 40);
	if(!player->Initialize(gDevice->device, "test.png", 58, 86))
		return false;

	return true;
}

void Game::Run(){
	//Get game time and update + draw
	float gameTime = 0;

	Update(gameTime);
	Draw(gameTime);
}

void Game::Update(float gameTime){
	//Update our sprites and other game logic
}

void Game::Draw(float gameTime){
	gDevice->Clear(D3DCOLOR_XRGB(0,100,100));
	gDevice->Begin();

	if (player && player->IsInitialized()) player->Draw(gameTime);

	gDevice->End();
	gDevice->Present();
}

Game::~Game(){
	if (player) { delete player; player = 0; }
	if (gDevice) { delete gDevice; gDevice = 0; }
}