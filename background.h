#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

void floor()
{

    ///back
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    glTranslatef(-20,-40,-50);
    glScalef(.5,120,130);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///top
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    glTranslatef(-20,80,-50);
    glScalef(150,.5,130);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///right
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    glTranslatef(-20,-40,-20);
    glScalef(130,130,.5);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///left
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    glTranslatef(-20,-40,50);
    glScalef(130,130,.5);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///bottom
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    glTranslatef(-20,-20,-50);
    glScalef(120,.5,130);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

#endif // BACKGROUND_H_INCLUDED
