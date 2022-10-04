#include "ScreenMannager.h"


void screenMannager()
{

}

/*

using namespace Asteroids;
using namespace Gameplay;
using namespace intext;


namespace Asteroids {
	namespace Game_Asteroids {


		static void Change();


		GameScreen Screens;

		int screenWidth = 900;
		int screenHeight = 600;



		int ScreenManager()
		{
			InitWindow(screenWidth, screenHeight, "Asteroids");

			intext::LoadTexture();
			Gameplay::Gameplay();
			Menu::Menu();
			Controls::Controls();
			Credits::Credits();
			Gameplay::UpdateGame();

			while (!WindowShouldClose())
			{
				Change();
			}

        CloseAudioDevice();
        CloseWindow();
        return 0;
		} 
		
		// SCreen MANAGER

		static void Change() {
			switch (Screens) {
			case Menu: {
				Menu::Menu();

			} break;
			case Game: {
				Gameplay:Game();
			} break;
			case Controls: {
				Controls::Controls();
			} break;
			case Credits: {
				Credits::Credits();
			}
			}

		} // CHANGE END


	}// namespace GAME_PONG
} // namespace PONG



*/

/*

llamado
			if (CheckCollisionPointRec(mousePoint, rec1)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					Game_Asteroids::Screens = Game_Asteroids::Game;
				}
			}
			if (CheckCollisionPointRec(mousePoint, rec2)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					Game_Asteroids::Screens = Game_Asteroids::Controls;
				}
			}
			if (CheckCollisionPointRec(mousePoint, rec3)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					Game_Asteroids::Screens = Game_Asteroids::Credits;
				}

*/