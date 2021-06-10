#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

static GLfloat cube_pts[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};



static GLubyte cube_sur[6][4] =
{
    {3,1,5,7},  //front
    {6,4,0,2},  //back
    {2,3,7,6},  //top
    {1,0,4,5},  //bottom
    {7,5,4,6},  //right
    {2,0,1,3}   //left
};


static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float colR=0.5, float colG=0.5, float colB=0.5, GLfloat sh=128.0,float em=0)
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { colR, colG, colB, 1.0 };
    GLfloat mat_diffuse[] = { colR, colG, colB, 1.0 };
    GLfloat mat_specular[] = { colR,colG,colB, 1.0 };
    GLfloat mat_shininess[] = {sh};
    //GLfloat mat_emission[] = {colR,colG,colB,1};

    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);


    for (GLint i = 0; i <6; i++)
    {
        glBegin(GL_QUADS);


        getNormal3p(cube_pts[cube_sur[i][0]][0], cube_pts[cube_sur[i][0]][1], cube_pts[cube_sur[i][0]][2],
                    cube_pts[cube_sur[i][1]][0], cube_pts[cube_sur[i][1]][1], cube_pts[cube_sur[i][1]][2],
                    cube_pts[cube_sur[i][2]][0], cube_pts[cube_sur[i][2]][1], cube_pts[cube_sur[i][2]][2]);


        glTexCoord2f(0,4);
        glVertex3fv(&cube_pts[cube_sur[i][0]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&cube_pts[cube_sur[i][1]][0]);
        glTexCoord2f(4,0);
        glVertex3fv(&cube_pts[cube_sur[i][2]][0]);
        glTexCoord2f(4,4);
        glVertex3fv(&cube_pts[cube_sur[i][3]][0]);


        /*glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(1,1);
        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,1);*/

        glEnd();
    }

}

#endif // CUBE_H_INCLUDED
