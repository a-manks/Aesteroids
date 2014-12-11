
#ifndef __SideScroller__Sprite__
#define __SideScroller__Sprite__
#include <GL/glfw.h>
#include "Vector2.h"

#define Square_Size 100

class Sprite
{
private:
    
    GLuint _textureBUfferID;
    Vector2 _velocity;
    GLfloat _rotation;
    GLfloat _rotationVelocity;
    
protected:
     Vector2 _position;
    
public:
    
    void setPosition(Vector2 newPosition);
    Vector2 getPosition();
    
    void setRotationVelocity(GLfloat rotationVelocity);
    GLfloat getRotationVelocity();
    
    void setRotation(GLfloat newRotation);
    GLfloat getRotation();
    
    void setVelocity(Vector2 newVelocity);
    Vector2 getVelocity();
    
    Sprite(GLuint textureBufferId, Vector2 position);
    void render();
    virtual void update();
    
};

#endif /* defined(__SideScroller__Sprite__) */
