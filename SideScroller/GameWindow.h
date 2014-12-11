

#ifndef __SideScroller__GameWindow__
#define __SideScroller__GameWindow__

#include <stdio.h>
#include "Sprite.h"
#include "PlayerSprite.h"
#include <GL/glfw.h>
#include <Vector>
#include <stdlib.h>
#include "Vector2.h"
#include <iostream>
#include "Util.h"
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2/SDL.h>


class GameWindow
{
private:
    bool _running;
    GLfloat _height;
    GLfloat _width;
    GLuint _vertexBufferID;
    GLuint _textureBufferID;
    GLuint _ballTextureID;
    GLuint loadAndBUfferImage(const char * filename);
    GLuint _rockTextureBufferID;
    std::vector<Sprite *> *balls;
    std::vector<Sprite *> *rocks;
    Mix_Chunk *_rocketSound;
    PlayerSprite *_playerRocket;
    void setup();
    void addRock();
    
    
public:
    
    void setRunning(bool isRunning);
    bool getRunning();
    
    GameWindow(bool isRunning);
    ~GameWindow();
    
    void mouseButtonPressed(int button, int action);
    void render();
    bool update();
    
};
#endif /* defined(__SideScroller__GameWindow__) */
  