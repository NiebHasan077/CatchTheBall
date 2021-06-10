#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

bool l0=1,l1=1,l2=1,l0a=1,l0s=1,l0d=1,l1a=1,l1s=1,l1d=1,l2a=1,l2s=1,l2d=1;

void light(int flag=0)
{

    ///light1


    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {.30, .30, .30, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 20.0, 38.0, 1.0 };

    if(l0==false)
    {
        glDisable(GL_LIGHT0);

    }
    else
    {
        glEnable(GL_LIGHT0);


        if(flag==1)
        {
            if(l0a==true)
            {
                glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
                l0a=false;
            }
            else
            {
                glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
                l0a=true;
            }
        }
        else if(flag==2)
        {
            if(l0s==true)
            {
                glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
                l0s=false;
            }
            else
            {
                glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
                l0s=true;
            }
        }
        else if(flag==3)
        {
            if(l0d==true)
            {
                glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);;
                l0d=false;
            }
            else
            {
                glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
                l0d=true;
            }
        }
        else
        {
            if(l0a==true)
            {

                glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);

            }
            else
            {
                glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);

            }

            if(l0s==true)
            {

                glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);

            }
            else
            {
                glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);

            }
            if(l0d==true)
            {

                glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);

            }
            else
            {

                glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
            }
        }
    }

    glLightfv( GL_LIGHT0, GL_POSITION, light_position);



    ///light2





    light_position[0] = 1;
    light_position[1] = 20;
    light_position[2] = 0;
    light_position[3] = 1;

    if(l1==false)
    {
        glDisable(GL_LIGHT1);

    }
    else
    {
        glEnable(GL_LIGHT1);


        if(flag==1)
        {
            if(l1a==true)
            {
                glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
                l1a=false;
            }
            else
            {
                glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
                l1a=true;
            }
        }
        else if(flag==2)
        {
            if(l1s==true)
            {
                glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);
                l1s=false;
            }
            else
            {
                glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
                l1s=true;
            }
        }
        else if(flag==3)
        {
            if(l1d==true)
            {
                glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);;
                l1d=false;
            }
            else
            {
                glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
                l1d=true;
            }
        }
        else
        {
            if(l1a==true)
            {

                glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);

            }
            else
            {
                glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);

            }

            if(l1s==true)
            {

                glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);

            }
            else
            {
                glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);

            }
            if(l1d==true)
            {

                glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);

            }
            else
            {

                glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
            }
        }
    }

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);


    light_position[0] = 0;
    light_position[1] = 48;
    light_position[2] = 20;
    light_position[3] = 1;

    if(l2==false)
    {
        glDisable(GL_LIGHT2);

    }
    else
    {
        glEnable(GL_LIGHT2);


        if(flag==1)
        {
            if(l2a==true)
            {
                glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
                l2a=false;
            }
            else
            {
                glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);
                l2a=true;
            }
        }
        else if(flag==2)
        {
            if(l2s==true)
            {
                glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);
                l2s=false;
            }
            else
            {
                glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular);
                l2s=true;
            }
        }
        else if(flag==3)
        {
            if(l2d==true)
            {
                glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);;
                l2d=false;
            }
            else
            {
                glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);
                l2d=true;
            }
        }
        else
        {
            if(l2a==true)
            {

                glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);

            }
            else
            {
                glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);

            }

            if(l2s==true)
            {

                glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular);

            }
            else
            {
                glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);

            }
            if(l2d==true)
            {

                glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);

            }
            else
            {

                glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);
            }
        }
    }

    glLightfv( GL_LIGHT2, GL_POSITION, light_position);

    //GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    //glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    //glLightf( GL_LIGHT2, GL_SPOT_CUTOFF, 18.0);

}

#endif // LIGHT_H_INCLUDED
