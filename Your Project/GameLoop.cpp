#include "GameLoop.h"
#include <Math.h>
#include <ctime>
float currentTime = clock();
float previousTime = currentTime;
int deltaTime;
int Onemoveup;
int Onemovedown;
int Twomoveup;
int Twomovedown;
float yeet = 50;
float yeet2 = 1500;
float PlayOne = 300;
float PlayTwo = 300;
	int dx = 800;
	int dy = 450;
	int dv = 200;
	int dg = 50;
	float p = 200.0f;
	int f;
				
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
			Graphics::DrawLine({ 100, 0 }, { 100, 800 }, { 0, 255 , 255, 255 });
			Graphics::DrawLine({ 100, 800 }, { 1500, 800 }, { 0, 255 , 255, 255 });
			//verticle lines
			for (float x = 100; x <= 1500; x = x + 25)
			{
				Graphics::DrawLine({ x, 0 }, { x, 1000 }, { 0, 255 , 255, 255 });
			}
			
			//horizontal lines
			for (float y = 0; y <= 1025; y = y + 25)
			{
				Graphics::DrawLine({ 100, y }, { 1500, y }, { 0, 255 , 255, 255 });
			}
			////line function
			//float g = 800;
			//float end = 300;
			//float p = 1400;
			//float o = 0;
			//		for (end = 300; end <= 1600; end++)
			//		{  
			//			
			//			int stuff = 0;
			//			stuff = end;
			//			if (stuff % 25 == 0)
			//			{
			//				end = stuff;
			//			Graphics::DrawLine({ end, g }, { p, o }, { 255, 0 , 0, 255 });
			//		g = g - 25;
			//		p = p - 25;
			//		o = o - 25;
			//			}	
			//	}

			/*int CurrentTime = 0;
			int PreviousTime;
			PreviousTime = CurrentTime;
			int DeltaTime;
			DeltaTime = CurrentTime - PreviousTime;
			PreviousTime = CurrentTime;
			
			std::cout << CurrentTime;
			std::cout << PreviousTime;*/

			currentTime = clock();
			deltaTime = (currentTime - previousTime) / 2;

			
				//PLAYER ONE
				Graphics::DrawRect({ yeet, PlayOne }, { 50, 300 }, { 251, 241, 244, 255 });
				//... stuff to update using deltaTime

				//PLAYER TWO
				Graphics::DrawRect({ yeet2, PlayTwo }, { 50, 300 }, { 251, 241, 244, 255 });

				std::cout << f << " ";
				//BALL
				
				
					
				f = (dx + deltaTime);

				if ( f <= yeet)
				{
					f = dx + (deltaTime);
				}
				if (f >= yeet2)
				{
					f = dx - (deltaTime);
				}
				
				Graphics::DrawCircle({ f, dy }, 50, 50, { 0, 255, 255, 250 });
				
				
				//COLLISION DETECTION
				
				//boolian checks that make the panels move
			



			if (Onemoveup == 1)
			{
			if (PlayOne <= 0)
			{
				PlayOne = 0;
			}
				PlayOne -= 20;
			}
		if (Onemovedown == 1)
		{
			if (PlayOne >= 600)
			{
				PlayOne = 600;
			}
			PlayOne += 20;
		}
		if (Twomoveup == 1)
		{
			if (PlayTwo <= 0)
			{
				PlayTwo = 0;
			}
			PlayTwo -= 20;
		}
		if (Twomovedown == 1)
		{
			if (PlayTwo >= 600)
			{
				PlayTwo = 600;
			}
			PlayTwo += 20;
		}

			//Graphics::DrawCircle({ dx, dy }, dv, dg, { 0, 255, 255, 150 });
			//Graphics::DrawCircle({ p, 540 }, 200, 4, { 0, 255, 255, 150 });
			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	
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
		
	case SDLK_w:  Onemoveup = 1; break;
	case SDLK_s:  Onemovedown = 1; break;
	case SDLK_o:  Twomoveup = 1; break;
	case SDLK_l:  Twomovedown = 1; break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_w:  Onemoveup = 0; break;
	case SDLK_s:  Onemovedown = 0; break;
	case SDLK_o:  Twomoveup = 0; break;
	case SDLK_l:  Twomovedown = 0; break;
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


