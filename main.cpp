#include <windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<GL/glut.h>
#include "game.h"
#include<iostream>
#define COLUMNS 40
#define ROWS 40
#define FPS 10
using namespace std;
extern short sDirection;
bool gameOver = false;

int score = 0;

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    initGrid(COLUMNS,ROWS);
}
void display_callback();
void keyboard_callback(int,int,int);
void reshape_callback(int,int);
void timer_callback(int);
int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE);
    glutInitWindowPosition(0,300);
    glutInitWindowSize(500,500);
    glutCreateWindow("snake game");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();
    return 0;
}
int index=0;
void display_callback(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if (gameOver) {
    string sc = "Your score: " + to_string(score);
    MessageBox(NULL, sc.c_str(), "Game Over", MB_OK | MB_ICONINFORMATION);
    exit(0);
}


}
void reshape_callback(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
void timer_callback(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);

}
void keyboard_callback(int key,int,int){
    switch(key){
        case GLUT_KEY_UP:
            if(sDirection!=DOWN){
                sDirection=UP;
            }
            break;

        case GLUT_KEY_DOWN:
            if(sDirection!=UP){
                sDirection=DOWN;
            }
            break;

        case GLUT_KEY_RIGHT:
            if(sDirection!=LEFT){
                sDirection=RIGHT;
            }
            break;

        case GLUT_KEY_LEFT:
            if(sDirection!=RIGHT){
                sDirection=LEFT;
            }
            break;


    }
}
