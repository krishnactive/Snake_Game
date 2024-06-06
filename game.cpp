
#include<GL/gl.h>
#include<GL/glu.h>

#include<GL/glut.h>
#include "game.h"


int GridX,GridY;
int PosX=20;
int PosY=20;
short sDirection= RIGHT;
void initGrid(int x,int y){
    GridX=x;
    GridY=y;

}
void drawGrid(){
    //unit(20.0,20.0);
    for(int x=0;x<GridX;x++){
        for(int y=0;y<GridY;y++){
            unit(x,y);
        }
    }

}
void unit(int x,int y){
    if(x==0||y==0||x==GridX-1||y==GridY-1){
        glLineWidth(3.0);
        glColor3f(1.0,0.0,0.0);

    }
    else{
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);

    }

    //glLineWidth(1.0);
    //glColor3f(1.0,1.0,1.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+1,y);
    glVertex2f(x+1,y+1);
    glVertex2f(x,y+1);
    glEnd();





}
void drawSnake(){
    if(sDirection==UP){
        PosY++;
    }
    else if(sDirection==DOWN){
        PosY--;
    }
    else if(sDirection==LEFT){
        PosX--;
    }
    else if(sDirection==RIGHT){
        PosX++;
    }
    glRectd(PosX,PosY,PosX+1,PosY+1);
}
