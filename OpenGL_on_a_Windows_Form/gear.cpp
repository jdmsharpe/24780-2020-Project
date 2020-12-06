#include "gear.h"
#include "ViewManager.h"

const double Pi = 3.142;

#ifndef M_PI
#define M_PI 3.14159265
#endif
float rad(int i) {//radians

    return (i * M_PI / 180);

}

gear::gear() : N(0), R(0) {}

gear::gear(const std::string& aLabel, double xCoord, double yCoord, double zCoord, double rad, double irad, int T, double TD)
{
    label = aLabel;
    x = xCoord;
    y = yCoord;
    R = irad;
    OR = rad;
    teeth = T;
    tooth_depth = TD;
}

//gear::gear(int Ni, double Ri)
//{
//    N = Ni;
//    R = Ri;
//}


void gear::setN(int Ni)
{
    N = Ni;
    R = N * 10 / Pi;
}

void gear::setColor(int ri, int gi, int bi)
{
    r = ri;
    g = gi;
    b = bi;
}

void gear::setPosition(double xi, double yi, double thetai)
{
    x = xi;
    y = yi;
    theta = thetai;
}


int gear::getN() const
{
    return N;
}



void gear::draw(float inner_radius, float outer_radius,
    int teeth, float tooth_depth)
{
    int i;
    float r0, r1, r2;
    float angle, da;
    float u, v, len;

    r0 = inner_radius;
    r1 = outer_radius - tooth_depth / 2.0;
    r2 = outer_radius + tooth_depth / 2.0;

    da = 2.0 * M_PI / teeth / 4.0;

    //glShadeModel(GL_FLAT);

    glNormal3f(0.0, 0.0, 1.0);

    /* draw front face */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        angle = i * 2.0 * M_PI / teeth;
        glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
        glVertex3f(x + r1 * cos(angle), y + r1 * sin(angle), 0);
        if (i < teeth) {
            glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
            glVertex3f(x + r1 * cos(angle + 3 * da), y + r1 * sin(angle + 3 * da), 0);
        }
    }
    glEnd();

    /* draw front sides of teeth */
    glBegin(GL_QUADS);
    da = 2.0 * M_PI / teeth / 4.0;
    for (i = 0; i < teeth; i++) {
        angle = i * 2.0 * M_PI / teeth;

        glVertex3f(x + r1 * cos(angle), y + r1 * sin(angle), 0);
        glVertex3f(x + r2 * cos(angle + da), y + r2 * sin(angle + da), 0);
        glVertex3f(x + r2 * cos(angle + 2 * da), y + r2 * sin(angle + 2 * da), 0);
        glVertex3f(x + r1 * cos(angle + 3 * da), y + r1 * sin(angle + 3 * da), 0);
        /* for (int i = 0; i < 100; ++i) {
             glVertex3f(outer_radius * (cos(rad(i)) + (rad(i) * sin(rad(i)))), outer_radius * (sin(rad(i)) - (rad(i) * cos(rad(i)))), 0);
         }*/
    }
    glEnd();

    glNormal3f(0.0, 0.0, -1.0);


    /* draw outward faces of teeth */
   /* glBegin(GL_QUAD_STRIP);
    for (i = 0; i < teeth; i++) {
        angle = i * 2.0 * M_PI / teeth;

        glVertex3f(x + r1 * cos(angle), y + r1 * sin(angle),  0);
        glVertex3f(x + r1 * cos(angle), y + r1 * sin(angle), 0);
        u = r2 * cos(angle + da) - r1 * cos(angle);
        v = r2 * sin(angle + da) - r1 * sin(angle);
        len = sqrt(u * u + v * v);
        u /= len;
        v /= len;
        glNormal3f(v, -u, 0.0);
        glVertex3f(x + r2 * cos(angle + da), y + r2 * sin(angle + da), 0);
        glVertex3f(x + r2 * cos(angle + da), y + r2 * sin(angle + da), 0);
        glNormal3f(cos(angle), sin(angle), 0.0);
        glVertex3f(x + r2 * cos(angle + 2 * da), y + r2 * sin(angle + 2 * da), 0);
        glVertex3f(x + r2 * cos(angle + 2 * da), y + r2 * sin(angle + 2 * da), 0);
        u = r1 * cos(angle + 3 * da) - r2 * cos(angle + 2 * da);
        v = r1 * sin(angle + 3 * da) - r2 * sin(angle + 2 * da);
        glNormal3f(v, -u, 0.0);
        glVertex3f(x + r1 * cos(angle + 3 * da), y + r1 * sin(angle + 3 * da), 0);
        glVertex3f(x + r1 * cos(angle + 3 * da), y + r1 * sin(angle + 3 * da), 0);
        glNormal3f(cos(angle), sin(angle), 0.0);
    }

    glVertex3f(x + r1 * cos(0), y + r1 * sin(0), 0);
    glVertex3f(x + r1 * cos(0), y + r1 * sin(0), 0);

    glEnd();*/

    //glShadeModel(GL_SMOOTH);

    /* draw inside radius cylinder */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        angle = i * 2.0 * M_PI / teeth;
        glNormal3f(-cos(angle), -sin(angle), 0.0);
        glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
        glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
    }
    glEnd();

}