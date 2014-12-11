

#ifndef __SideScroller__BoundingBox__
#define __SideScroller__BoundingBox__

#include <stdio.h>

typedef struct{
    int top;
    int bottom;
    int left;
    int right;
    
}BoundingBox;

BoundingBox makeBoundingBox(int top, int bottom, int left, int right);

#endif /* defined(__SideScroller__BoundingBox__) */
