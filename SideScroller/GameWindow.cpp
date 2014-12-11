

#include "GameWindow.h"

typedef struct  {
    
    GLfloat positionCoordinates [3];
    GLfloat textureCoordinates[2];
    
}VertexData;


VertexData vertices[] ={
    {{-Square_Size/2, -Square_Size/2, 0.0f}, {0.0f, 0.0f}},
    {{Square_Size/2, -Square_Size/2, 0.0f}, {1.0f, 0.0f}},
    {{Square_Size/2, Square_Size/2, 0.0f}, {1.0f, 1.0f}},
    {{-Square_Size/2, Square_Size/2, 0.0f}, {0.0f, 1.0f}}
    
};



GameWindow::GameWindow(bool isRunning) : _height(800), _width(800*16/9), _vertexBufferID(0)
{
    
    _running = isRunning;
    setup();
    //_rocketSound = Util::loadSoundEffects("laser.wav");
    _rocketSound= Mix_LoadWAV("sound.wav");

    _textureBufferID = Util::loadAndBUfferImage("rocket.tga");
    _ballTextureID = Util::loadAndBUfferImage("ball.tga");
    _rockTextureBufferID = Util::loadAndBUfferImage("rock.tga");
    
    balls = new std::vector<Sprite *>;
    balls->reserve(20);

    rocks = new std::vector<Sprite *>;
    rocks->reserve(20);
    
    _playerRocket = new PlayerSprite(_textureBufferID, makeVector2(_height/2, 300), 100, true);
    _playerRocket->setBoundingBox(makeBoundingBox(_height, 0, 0, _width));
    
         
    
    
}

GameWindow::~GameWindow()
{
    for (std::vector<Sprite *>::iterator it = balls->begin();
         it != balls->end(); it++) {
        delete (*it);
    }

    
    delete balls;
    delete _playerRocket;
    //Util::freeSounds(*_rocketSound);
    glDeleteBuffers(1,&_vertexBufferID);
    glDeleteTextures(1, &_textureBufferID);
    glDeleteTextures(1, &_textureBufferID);
    glDeleteTextures(1, &_ballTextureID);
    glDeleteTextures(1, &_rockTextureBufferID);
    
}

void GameWindow::setRunning(bool isRunning)
{
    _running = isRunning;
}

bool GameWindow::getRunning()
{
    return _running;
}


void GameWindow::setup()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glViewport(0.0f, 0.0f, _width, _height);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, _width, 0, _height);
    glMatrixMode(GL_MODELVIEW);
    
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *)offsetof(VertexData, positionCoordinates));
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *)offsetof(VertexData, textureCoordinates));
    
    
    
}


void GameWindow::mouseButtonPressed(int button, int action)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        Sprite *ball = new Sprite(_ballTextureID, makeVector2(_playerRocket->getPosition().x + Square_Size/2 , _playerRocket->getPosition().y));
        ball->setVelocity(makeVector2(8, 0));
        ball->setRotationVelocity(-1);
        balls->push_back(ball);
        Mix_PlayChannel( -1, _rocketSound, 0 );
        
    }
    
}

void GameWindow::addRock()
{
    int locationY = arc4random()%(unsigned int)_height;
    Sprite *newRock = new Sprite(_rockTextureBufferID, makeVector2(_width+Square_Size/2, locationY));
    newRock->setVelocity(makeVector2(-5, 0));
    newRock->setRotationVelocity(1);
    rocks->push_back(newRock);
    
}



bool GameWindow::update()
{
    
    std::vector<std::vector<Sprite *>::iterator> deleteArray;
    
    for (std::vector<Sprite *>::iterator iterRock = rocks->begin(); iterRock != rocks->end(); iterRock++) {
        
        if (Util::checkForCollision((*iterRock), _playerRocket)) {
            deleteArray.push_back(iterRock);
            _playerRocket->_health -= 25;
        }
        
        for (std::vector<Sprite *>::iterator iterBall = balls->begin(); iterBall != balls->end(); iterBall ++) {
            if (Util::checkForCollision(*iterRock, *iterBall)) {
                deleteArray.push_back(iterRock);
                deleteArray.push_back(iterBall);
            }
        }
    }
    
    for (std::vector<Sprite *>::iterator Iter = balls->begin(); Iter != balls->end(); Iter++) {
        if (((*Iter)->getPosition().x > _width+Square_Size)) {
            deleteArray.push_back(Iter);
        }
    
    }
    
    for (std::vector<Sprite *>::iterator Iter = rocks->begin(); Iter != rocks->end(); Iter++) {
        if (((*Iter)->getPosition().x < 0)) {
            deleteArray.push_back(Iter);
        }
        
    }
    
    for (std::vector<std::vector<Sprite *>::iterator>::iterator deleteIterator = deleteArray.begin();
         deleteIterator != deleteArray.end(); deleteIterator++) {
        if((**deleteIterator)->getVelocity().x >0) {
            balls->erase(*deleteIterator);
        } else {
            rocks->erase(*deleteIterator);
        }
    }
    
    static int updates;
    if (updates >= 60) {
        addRock();
        updates = 0;
    }
    ++updates;

    
    _playerRocket->update();
    
    for (std::vector<Sprite *>::iterator it = balls->begin();
         it != balls->end(); it++) {
        (*it)->update();
    }
    
    for (std::vector<Sprite *>::iterator it = rocks->begin();
         it != rocks->end(); it++) {
        (*it)->update();
    }

    return  _playerRocket->checkAlive();
    
    
}

void GameWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
   
   
    
    for (std::vector<Sprite *>::iterator it = rocks->begin();
         it != rocks->end(); it++) {
        (*it)->render();
    }
    
    for (std::vector<Sprite *>::iterator it = balls->begin();
         it != balls->end(); it++) {
        (*it)->render();
    }
    
    std::cout<< balls->size()<<" -- "<<rocks-> size()<<"--Health: "<<_playerRocket->_health<<"--Status: "<<_playerRocket->_isAlive<<std::endl;

    _playerRocket->render();
    
    glfwSwapBuffers();
}

