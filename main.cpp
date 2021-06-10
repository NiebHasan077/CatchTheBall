#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include <iostream>
#include <random>
#include "printtext.h"
#include "light.h"
#include "sphere.h"
#include "bmploader.h"
#include "cube.h"
#include "background.h"
#include<fstream>
using namespace std;


const int width = 850;
const int height = 600;


float posy=45,posz=20,poszb=20;
long long int score = 0, hscore,bsize=8;
double speed = 1.0;
SimpleDrawText sdt;
int vw=1;
int go;


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(0, 20);
std::uniform_int_distribution<> type(4, 11);

int balltype=4,direction;

GLfloat eyeX = 20;
GLfloat eyeY = 20;
GLfloat eyeZ = 20;

GLfloat lookX = -20;
GLfloat lookY =20;
GLfloat lookZ =20;


int func(int score)
{
    fstream ff("score.txt");
    int temp=0;
    ff>>temp;
    if(score==0)
    {
        ff.close();
        return temp;
    }
    else
    {
        score = max(temp,score);
        ff<<score;
        ff.close();
        return score;
    }

}


static void resize(int height,int width)
{
    glViewport(0,0,height,width);
}


void globe()
{
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(-1,posy,posz);
    DisplaySphere(6, balltype);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void busket()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    glPushMatrix();
    glTranslatef(-2.2,-6,poszb);
    glScalef(3, 6, bsize);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void gameover()
{
    eyeX = 20;
    eyeY = 20;
    eyeZ = 20;

    lookX = -20;
    lookY =20;
    lookZ =20;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,12);
    glPushMatrix();
    glTranslatef(-20,-40,-50);
    glScalef(.5,120,130);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    string hscr = to_string(hscore);
    string yscr = to_string(score);
    sdt.drawText("-----------------------Press Y/y to play again------------------------", 0, 160, 1, 0, 0);
    sdt.drawText("Highest Score:  " + hscr, 330, 330, 1, 0, 0);
    sdt.drawText("Your Score:  " + yscr, 330, 280, 1, 0, 0);

    sdt.render();
    //PlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\breakout.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);

    if(go)
    {
        gameover();
    }
    else
    {
        floor();
        light();
        busket();
        globe();

//    glDrawArrays(GL_QUADS, 0, sizeof(vertices) / (sizeof(float) * 3));
        string scr = to_string(score);
        sdt.drawText("Score: " + scr, 650, 550, 1, 0, 0);
        sdt.render();

        string dir;
        //cout<<direction<<endl;
        if(direction>0)
        {
            dir = "<<-- LEFT";
        }
        else if(direction==0)
        {
            dir = "On point";
        }
        else
        {
            dir = "RIGHT -->>";
        }

        //string scra = to_string(score);
        sdt.drawText(dir, 640, 500, 1, 0, 0);
        sdt.render();
    }




    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    if(go)
    {
        switch(key)
        {
        case 'y':
            go = 1-go;
            score=0;
            break;
        case 'Y':
            go = 1-go;
            score=0;
            break;
        default:
            glutDestroyWindow(0);
        }

    }
    else
    {
        switch (key)
        {
        ///eye point setup
        case 'f':
            eyeZ++;
            break;

        case 'h':
            eyeZ--;
            break;


        case 't':
            eyeY++;
            break;

        case 'g':
            eyeY--;
            break;

        case 'r':
            eyeX--;
            break;

        case 'y':
            eyeX++;
            break;


        ///lookat point setup
        case 'k':
            lookZ++;
            break;

        case ';':
            lookZ--;
            break;


        case 'o':
            lookY++;
            break;

        case 'l':
            lookY--;
            break;

        case 'i':
            lookX--;
            break;

        case 'p':
            lookX++;
            break;

        case '1':
            if(l0==true)
            {
                l0=false;
            }
            else
            {
                l0=true;
            }

            break;
        case '2':
            if(l1==true)
            {
                l1=false;
            }
            else
            {
                l1=true;
            }
            break;
        case '3':
            if(l2==true)
            {
                l2=false;
            }
            else
            {
                l2=true;
            }
            break;

        case 'a':
            light(1);
            break;
        case 's':
            light(2);
            break;
        case 'd':
            light(3);
            break;
        case 'n':
            if(poszb<(48-bsize))
                poszb+=4;
            break;
        case 'm':
            if(poszb>-4)
                poszb-=4;
            break;
        case 'c':
            vw= 1- vw;
            break;


        case 27:
            exit(1);
        }

    }

    glutPostRedisplay();
}

static void idle(void)
{
    if(go)
    {

    }
    else
    {
        if(posy>-4)
        {
            posy-=speed;
        }
        else
        {
            if(abs(posz-(poszb+(bsize/2))) < (bsize/2) )
            {
                if(balltype==8)
                {

                    hscore = func(0);
                    hscore = max( score, hscore);
                    func(hscore);
                    //score = 0;
                    go=1;
                    PlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\breakout.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
                }
                else
                {
                    if(balltype==6)
                    {
                        bsize = min(12LL,bsize+2);
                    }
                    else if(balltype==7)
                    {
                        bsize = max(6LL,bsize-2);
                    }

                    score++;
                }

                PlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\case-closed-531.wav", NULL, SND_ASYNC);
                //sndPlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\case-closed-531.wav",  SND_ASYNC);

            }
            else
            {
                if(balltype!=8)
                {

                    PlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\get-outta-here-505.wav", NULL, SND_SYNC);
                    //sndPlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\get-outta-here-505.wav",  SND_ASYNC);
                    hscore = func(0);
                    hscore = max( score, hscore);
                    func(hscore);
                    go=1;
                    PlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\breakout.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
                    //score=0;
                }


            }

            if(score && score%10==0)
            {
                speed += .3;
            }
            posz = distr(gen)*2;
            balltype = type(gen);
            posy=45;

        }

        if(vw==1)
        {
            eyeX = 0;
            eyeY = 4;
            eyeZ = poszb+4;

            lookX = -1;
            lookY =posy;
            lookZ =posz;
            //vw=0;
        }
        else
        {
            //vw=1;
            eyeX = 20;
            eyeY = 20;
            eyeZ = 20;

            lookX = -20;
            lookY =20;
            lookZ =20;
        }



        direction = posz-(poszb+(bsize/2));
    }

    glutPostRedisplay();
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Display-1607077");



    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutReshapeFunc(resize);

//    glClearColor(1,1,1,1);

    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glEnable(GL_LIGHTING);

    CreateSphere(30,0,0,0);

    //PlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\breakout.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //sndPlaySound("C:\\Users\\HP\\Desktop\\pro\\glproject\\breakout.wav",  SND_ASYNC|SND_FILENAME|SND_LOOP);
    //string fl = "C:\\Users\\HP\\Desktop\\pro\\glproject\\breakout.wav";
    //mciSendString(fl.c_str(), NULL, 0, NULL);

    //mciSendString("breakout.mp3", NULL, 0, NULL);


    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\brick.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\background.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\busket1.bmp");
    //LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\images (1).bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball1.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball2.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball3.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball4.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball5.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball6.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball7.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\ball8.bmp");
    LoadTexture("C:\\Users\\HP\\Desktop\\pro\\glproject\\gameover1.bmp");
    //cout<<ID<<endl;
    printf("######################################################################################\n");
    printf("########################################################################################\n");
    printf("####### Keys 'f','g','h','r','t','y' will change eye point              ################\n");
    printf("#######                                                                 ################\n");
    printf("####### Keys 'k','l',';','i','o','p' will change lookat point.          ################\n");
    printf("#######                                                                 ################\n");
    printf("####### Use keys 1 to 2 to switch on/off lights.                        ################\n");
    printf("#######                                                                 ################\n");
    printf("####### Keys 'a','s','d' will   change the light properties.            ################\n");
    printf("#######                                                                 ################\n");
    printf("########################################################################################\n");
    printf("########################################################################################\n\n\n");


    glutMainLoop();

    return EXIT_SUCCESS;
}
