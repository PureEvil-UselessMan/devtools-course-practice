// Copyright Olynin Alexander

#include <math.h>
#include <string>
#include "include/cross_line_and_plane.h"

Line& Line::operator=(const Line& Tmp) {
    this->x_1 = Tmp.x_1;
    this->y_1 = Tmp.y_1;
    this->z_1 = Tmp.z_1;
    this->a_x = Tmp.a_x;
    this->a_y = Tmp.a_y;
    this->a_z = Tmp.a_z;
    return *this;
}

Plane& Plane::operator=(const Plane& Tmp) {
    this->a = Tmp.a;
    this->b = Tmp.b;
    this->c = Tmp.c;
    this->d = Tmp.d;
    return *this;
}
