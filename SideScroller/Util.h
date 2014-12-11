

#ifndef __SideScroller__TextureLoader__
#define __SideScroller__TextureLoader__

#include <stdio.h>
#include <GL/glfw.h>
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <string>

class Util
{
  
public:
        
    static GLuint loadAndBUfferImage(const char *filename);
    static bool checkForCollision(Sprite *a, Sprite *b);
    static bool init();
    static Mix_Chunk loadSoundEffects(std::string filename);
    static void freeSounds(Mix_Chunk sound);
    
};
#endif /* defined(__SideScroller__TextureLoader__) */
