#define _USE_MATH_DEFINES

#include "Pod.h"

#include <iostream>
#include <cmath>

using namespace std;

Pod::Pod(float x, float y, int id, float r, float vx, float vy, float angle, int nextCheckPointid, int checked, int timeout):
    Unit(x, y, id, r, vx, vy),
    m_angle(angle), m_nextCheckPointid(nextCheckPointid), m_checked(checked), m_timeout(timeout), m_shield(false) {

    cout << "Constructeur de Pod" << endl;
}

void Pod::debug(){
    cout << "Petit Test depuis pod" << endl;
}
float Pod::getAngle(Point p) {
    float d = this->distance1(p);
    float dx = (p.getX() - this->m_x) / d;
    float dy = (p.getY() - this->m_y) / d;

    // Trigonométrie simple. On multiplie par 180.0 / PI pour convertir en degré.
    float a = acos(dx) * 180.0 / M_PI;

    // Si le point qu'on veut est en dessus de nous, il faut décaler l'angle pour qu'il soit correct.
    if (dy < 0) {
        a = 360.0 - a;
    }

    return a;
}

float Pod::diffAngle(Point p) {
    float a = this->getAngle(p);

    // Pour connaitre le sens le plus proche, il suffit de regarder dans les 2 sens et on garde le plus petit
    // Les opérateurs ternaires sont la uniquement pour éviter l'utilisation d'un operateur % qui serait plus lent
    float right = this->m_angle <= a ? a - this->m_angle : 360.0 - this->m_angle + a;
    float left = this->m_angle >= a ? this->m_angle - a : this->m_angle + 360.0 - a;

    if (right < left) {
        return right;
    }
    else {
        // On donne un m_angle négatif s'il faut tourner à gauche
        return -left;
    }
}
void Pod::rotate(Point p) {
    float a = this->diffAngle(p);

    // On ne peut pas tourner de plus de 18° en un seul tour
    if (a > 18.0) {
        a = 18.0;
    }
    else if (a < -18.0) {
        a = -18.0;
    }

    this->m_angle += a;

    // L'opérateur % est lent. Si on peut l'éviter, c'est mieux.
    if (this->m_angle >= 360.0) {
        this->m_angle = this->m_angle - 360.0;
    }
    else if (this->m_angle < 0.0) {
        this->m_angle += 360.0;
    }
}
void Pod::boost(int thrust) {
    // N'oubliez pas qu'un pod qui a activé un m_m_shield ne peut pas accélérer pendant 3 tours
    if (this->m_shield) {
        return;
    }

    // Conversion de l'm_angle en radian
    float ra = this->m_angle * M_PI / 180.0;

    // Trigonométrie
    this->m_vx += cos(ra) * thrust;
    this->m_vx += sin(ra) * thrust;
}
void Pod::move(float t) {
    this->m_x += this->m_vx * t;
    this->m_y += this->m_vx * t;
}
void Pod::end() {
    this->m_x = round(this->m_x);
    this->m_y = round(this->m_y);
    //this->m_vx = truncate(this->m_vx * 0.85); // ATTETION RAJOUTER UN CAST d'entier ici
    //this->m_vx = truncate(this->m_vx * 0.85);

    // N'oubliez pas que le timeout descend de 1 chaque tour. Il revient à 100 quand on passe par un checkpoint
    this->m_timeout -= 1;
}
void Pod::play(Point p, int thrust) {
    this->rotate(p);
    this->boost(thrust);
    this->move(1.0);
    this->end();
}
void Pod::bounce(Unit u) {}
//void output(Move move) {}

