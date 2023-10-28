#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

using namespace std;


int main(int argc, char *argv[]) {

  if(SDL_Init(SDL_INIT_VIDEO) > 0)
    cout<<"SDL_Init Failed"<<SDL_GetError()<<endl;

  if(!(IMG_Init(IMG_INIT_PNG)))
    cout<<"SDL_Image Failed"<<SDL_GetError()<<endl;

  RenderWindow window("GAME v1.0", 1280, 720);

  SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

  bool gameRunning = true;
  SDL_Event event;
  while(gameRunning){
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT)
        gameRunning = false;
    }
    window.clear();
    window.render(grassTexture);
    window.display();
  }

  window.cleanUp();
  SDL_Quit();
  return 0;
}
