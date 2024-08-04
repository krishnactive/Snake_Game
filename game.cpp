#include <stdio.h>
#include <stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<ctime>
#include<GL/glut.h>
#include "game.h"
#include <time.h>

int snake_length = 5;//initial length
extern bool gameOver;
int GridX,GridY;
bool food = true;
int foodx,foody;
extern int score;
//snake body
int PosX[60] = {20,20,20,20,20};
int PosY[60] = {20,19,18,17,16};

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

void drawFood(){
    if(food){
        random(foodx, foody);
    }
    food = false;
    glColor3f(1,0,0);
    glRectf(foodx, foody, foodx+1, foody+1) ;
}




void drawSnake(){
    for(int i = snake_length-1;i>0;i--)
    {
        PosX[i] = PosX[i-1];
        PosY[i] = PosY[i-1];
    }
    if(sDirection==UP){
        PosY[0]++;
    }
    else if(sDirection==DOWN){
        PosY[0]--;
    }
    else if(sDirection==LEFT){
        PosX[0]--;
    }
    else if(sDirection==RIGHT){
        PosX[0]++;
    }
    for(int i =0;i<snake_length;i++){
        if(i == 0){
            glColor3f(0,1,0);
        }
        else{
            glColor3f(0,0,1);
        }
        glRectd(PosX[i],PosY[i],PosX[i]+1,PosY[i]+1);
    }
    /*glColor3f(0,1,0);
    glRectd(PosX,PosY,PosX+1,PosY+1);
    */
    if (PosX[0]==0||PosY[0]==0||PosX[0]==GridX-1||PosY[0] == GridY){
        gameOver = true;
    }
    if(PosX[0]==foodx&&PosY[0]==foody)
    {
        snake_length++;
        score++;
        if(snake_length>MAX){
            snake_length = MAX;
        }
        food = true;
    }

}

void random(int &x, int &y){
    int _maxX = GridX-2;
    int _maxY = GridY-2;
    int _min = 1;
    srand(time(NULL));
    x = _min+rand()%(_maxX-_min);
    y = _min+rand()%(_maxY-_min);
}
