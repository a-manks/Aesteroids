

#ifndef __SideScroller__PlayerSprite__
#define __SideScroller__PlayerSprite__

#include <stdio.h>
#include "BoundingBox.h"

#include "Sprite.h"

class PlayerSprite : public Sprite
{
    
private:
    BoundingBox _boundingBox;
    
    
public:
    void setBoundingBox(BoundingBox boundingBox);
    int _health;
    bool _isAlive;
    bool checkAlive();

    PlayerSprite(GLuint textureBufferID, Vector2 position, int health, bool isAlive);
    void update();
};

#endif /* defined(__SideScroller__PlayerSprite__) */
