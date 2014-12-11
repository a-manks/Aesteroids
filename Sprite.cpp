
#include "Sprite.h"

void Sprite::setPosition(Vector2 newPosition)
{
    _position = newPosition;
}

Vector2 Sprite::getPosition()
{
    return _position;
}

void Sprite::setRotation(GLfloat newRotation)
{
    _rotation = newRotation;
}

GLfloat Sprite::getRotation()
{
    return _rotation;
}


void Sprite::setRotationVelocity(GLfloat rotationVelocity)
{
    _rotationVelocity = rotationVelocity;
}

GLfloat Sprite::getRotationVelocity()
{
    return _rotationVelocity;
}


void Sprite::setVelocity(Vector2 newVelocity)
{
    _velocity = newVelocity;
}

Vector2 Sprite::getVelocity()
{
    return _velocity;
}


Sprite::Sprite(GLuint textureBufferId, Vector2 position) : _textureBUfferID(textureBufferId), _position(position)
{
    
}

void Sprite::render()
{
    glBindTexture(GL_TEXTURE_2D, _textureBUfferID);
    
    glLoadIdentity();
    
    glTranslatef(_position.x, _position.y, 0);
    glRotatef(_rotation, 0, 0, 1.0f);
    
    
    glDrawArrays(GL_QUADS, 0, 4);
}

void Sprite::update()
{
    _position = addVector2(_position, _velocity);
    _rotation += _rotationVelocity;
}
