

#include "Util.h"


GLuint Util::loadAndBUfferImage(const char *filename)
{
    GLFWimage imageData;
    glfwReadImage(filename, &imageData, NULL);
    
    GLuint textureBufferID;
    glGenTextures(1, &textureBufferID);
    glBindTexture(GL_TEXTURE_2D, textureBufferID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageData.Width, imageData.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.Data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glfwFreeImage(&imageData);
    
    
    
    return textureBufferID;
}

bool Util::checkForCollision(Sprite *a, Sprite *b)
{
    return !(a->getPosition().x + Square_Size/2 <= b->getPosition().x - Square_Size/2 ||
             a->getPosition().x - Square_Size/2 >= b->getPosition().x + Square_Size/2 ||
             a->getPosition().y + Square_Size/2 <= b->getPosition().y - Square_Size/2 ||
             a->getPosition().y - Square_Size/2 >= b->getPosition().y + Square_Size/2);
}

bool Util::init()
{
    bool success = true;
    
    
    if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    return success;
}


Mix_Chunk Util::loadSoundEffects(std::string filename)
{
    
    return *Mix_LoadWAV("filename");
    
    
    
}

void Util::freeSounds(Mix_Chunk sound)
{
    Mix_FreeChunk( &sound );
}

