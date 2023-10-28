#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"

using namespace std;
RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h):window(NULL), renderer(NULL){
  window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
  if(window == NULL)
    cout<<"Window failed to init. Error:"<<SDL_GetError()<<endl;

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp(){
  SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(const char *texturePath){
  SDL_Texture* texture = NULL;
  texture = IMG_LoadTexture(renderer, texturePath);
  if(texture == NULL){
     cout<<"Failed to load texture. Error:"<<SDL_GetError()<<endl;
  }
  return texture;
}

void RenderWindow::clear(){
  SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture *p_texture){
  SDL_Rect *src = new SDL_Rect();
  src->x = 0;
  src->y = 0;
  src->w = 32;
  src->h = 32;

  SDL_Rect *dest = new SDL_Rect();
  dest->x = 0;
  dest->y = 0;
  dest->w = 32;
  dest->h = 32;
  SDL_RenderCopy(renderer, p_texture, src, dest);
}

void RenderWindow::display(){
  SDL_RenderPresent(renderer);
}