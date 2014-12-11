#define GLFW_INCLUDE_GLU

#include <GL/glfw.h>
#include "GameWindow.h"

#define Updates_Per_Second 60

GameWindow *gameWindow;
void GLFWCALL mouseButtonPressed(int button, int action)
{
    gameWindow->mouseButtonPressed(button, action);
}


int main()
{
    glfwInit();
    
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    glfwOpenWindow(800*16/9, 800, 8, 8, 8, 8, 0, 0, GLFW_WINDOW);
    glfwSetWindowTitle("Side Scroller");
    glfwSwapInterval(0);
    glfwSetMouseButtonCallback(mouseButtonPressed);
    
    
    gameWindow = new GameWindow(true);
    
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;
    
    bool running = true;
    
    while (running) {
        gameWindow->render();
        deltaTime += (glfwGetTime() - lastTime)*Updates_Per_Second;
        lastTime = glfwGetTime();
        while (deltaTime >= 1.0f) {
            running = gameWindow->update();
            --deltaTime;
        }
        
        gameWindow->setRunning(glfwGetWindowParam(GLFW_OPENED));

    }
    
    delete gameWindow;
    
    glfwTerminate();
    
}