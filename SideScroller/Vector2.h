
#ifndef __SideScroller__Vector2__
#define __SideScroller__Vector2__

#include <stdio.h>
#include <GL/glfw.h>

typedef struct {
    GLfloat x;
    GLfloat y;
    
}Vector2;

Vector2 makeVector2(GLfloat x, GLfloat y);
Vector2 addVector2(Vector2 first, Vector2 second);

#endif /* defined(__SideScroller__Vector2__) */
