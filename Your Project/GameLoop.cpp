#include "GameLoop.h"
#include <Math.h>
#include <ctime>

	int dx = 800;
	int dy = 450;
	int dv = 200;
	int dg = 50;
	int p = 200;
	int y = 1;
void GameLoop::Loop()
{
	while (m_bRunning)
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed


			// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
			// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
			// 'SDL_PollEvent' returns 0 when there are no more events to parse
			while (SDL_PollEvent(&sdlEvent))
			{
				// Calls the redefined event function for the EventHandler class
				// Refer to its header file and cpp for more information on what each inherited function is capable of
				// and its syntax
				OnEvent(sdlEvent);
			}


			Draw();
			//Graphics::DrawRect({ 1000, 100 }, { 450, 400 }, { 251, 241, 244, 255 });


			//outline
			Graphics::DrawLine({ 300, 0 }, { 300, 800 }, { 0, 255 , 255, 255 });
			Graphics::DrawLine({ 300, 800 }, { 1400, 800 }, { 0, 255 , 255, 255 });
			//verticle lines
			for (float x = 300; x <= 1400; x = x + 25)
			{
				Graphics::DrawLine({ x, 0 }, { x, 800 }, { 0, 255 , 255, 255 });
			}
			
			//horizontal lines
			for (float y = 0; y <= 800; y = y + 25)
			{
				Graphics::DrawLine({ 300, y }, { 1400, y }, { 0, 255 , 255, 255 });
			}




			//line function
			
			float end = 300;

					for (end = 300; end <= 1600; end++)
					{
						
						int stuff = 0;
						stuff = end;


						if (stuff % 25 == 0)
						{
							end = stuff;
							
							float g = 800;
							float r = 300;
					
						Graphics::DrawLine({ r, g }, { 1400, 0 }, { 0, 255 , 255, 255 });

						g = g - 25;
						r = r - 25;
							
							}
				}

			




			//Graphics::DrawCircle({ dx, dy }, dv, dg, { 0, 255, 255, 150 });
			//Graphics::DrawCircle({ p, 540 }, 200, 4, { 0, 255, 255, 150 });
			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	
}

void GameLoop::Update()
{
	
}
void GameLoop::LateUpdate()
{

}

	
	
void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas
	

	
	
	
}

					
void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	/*if (keystate[SDLK_w])
	{
		y += 10;
	}*/
	
	switch (ac_sdlSym)
	{
	case SDLK_w: dy -= 20; break;
	case SDLK_a: dx -= 20; break;
	case SDLK_s: dy += 20; break;
	case SDLK_d: dx += 20; break;
	case SDLK_v: dv += 20; break;
	case SDLK_b: dv -= 20; break;
	case SDLK_y: dg += 1; break;
	case SDLK_t: dg -= 1; break;
	case SDLK_p: 
		
		
			{
				auto currentTime = SDL_GetTicks();
				float deltaTime = 0.f, lastTime = 0.f;

				deltaTime = (currentTime - lastTime) / 1000.f;
				lastTime = currentTime;
				float go = 1;
				go*lastTime/10;
						p = go;
			};
		 break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
