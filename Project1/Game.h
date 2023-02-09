#ifndef GAME_H
#define GAME_H

#include "GraphicsDevice.h"
#include "Sprite.h"

class Game
{
public:
	Game();
	~Game();

	//Game Function
	bool Initialize(HWND hWnd);
	void Run();
	void Update(float gameTime);
	void Draw(float gameTime);
private:
	GraphicsDevice *gDevice;
	Sprite *player;

};

#endif // !GAME_H
