

#include "PlayerSprite.h"

PlayerSprite::PlayerSprite(GLuint textureBufferID, Vector2 position,  int health, bool isAlive) : Sprite(textureBufferID, position)
{
    _health = health;
    _isAlive = isAlive;
}

void PlayerSprite::setBoundingBox(BoundingBox boundingBox)
{
    _boundingBox = boundingBox;
}

bool PlayerSprite::checkAlive()
{
    if(_health <= 0)
    {
        _isAlive = false;
    }
    return _isAlive;
}

void PlayerSprite::update()
{
    if(glfwGetKey(GLFW_KEY_UP) && _position.y <= _boundingBox.top) {
        _position = addVector2(_position, makeVector2(0.0f, 2.0f));
    }
    
    if(glfwGetKey(GLFW_KEY_DOWN) && _position.y >= _boundingBox.bottom) {
        _position = addVector2(_position, makeVector2(0.0f, -2.0f));
    }
    if(glfwGetKey(GLFW_KEY_LEFT) && _position.x >= _boundingBox.left) {
        _position = addVector2(_position, makeVector2(-2.0f, 0.0f));
    }
    if(glfwGetKey(GLFW_KEY_RIGHT)&& _position.x <= _boundingBox.right) {
        _position = addVector2(_position, makeVector2(2.0f, 0.0f));
    }
    
    checkAlive();

}

