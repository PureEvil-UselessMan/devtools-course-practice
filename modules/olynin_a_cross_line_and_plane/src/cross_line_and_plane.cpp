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

void Space::calculate_params(Line Sline, Plane Splane,
                      double* numerator, double* denominator) {
        *numerator = Splane.GetD() + Splane.GetA() * Sline.GetX_1() +
                      Splane.GetB() * Sline.GetY_1() +
                      Splane.GetC() * Sline.GetZ_1();
        *denominator = Splane.GetA() * Sline.GetA_x() +
                      Splane.GetB() * Sline.GetA_y() +
                      Splane.GetC() * Sline.GetA_z();
}

int Space::Relationship(Line Sline, Plane Splane) {
    double numerator, denominator;
    calculate_params(Sline, Splane, &numerator, &denominator);
    if (denominator == 0) {
        if (numerator == 0) {
            return 2;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

void Space::GetPointOfIntersection(Line Sline, Plane Splane,
                                double* common_x,
                                double* common_y,
                                double* common_z) {
        int relation = Relationship(Sline, Splane);
        if (relation == 0) {
            const std::string error_type("Line doesn't intersect the Plane");
            throw error_type;
        } else if (relation == 2) {
            const std::string error_type("The Line lies on the Plane");
            throw error_type;
        }
        double numerator, denomirator;
        calculate_params(Sline, Splane, &numerator, &denomirator);
        double t = - numerator / denomirator;
        *common_x = Sline.GetX_1() + Sline.GetA_x() * t;
        *common_y = Sline.GetY_1() + Sline.GetA_y() * t;
        *common_z = Sline.GetZ_1() + Sline.GetA_z() * t;
}

bool Space::IsPerpendicular(Line Sline, Plane Splane) {
    double accuracy = 0.000001;
    if (Relationship(Sline, Splane) == 1) {
        if ((Sline.GetA_x() / Splane.GetA()) -
            (Sline.GetA_y() / Splane.GetB()) < accuracy &&
            (Sline.GetA_x() / Splane.GetA()) -
            (Sline.GetA_z() / Splane.GetC()) < accuracy) {
                return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Space::IsOblique(Line Sline, Plane Splane) {
    if (Relationship(Sline, Splane) == 1) {
        return !IsPerpendicular(Sline, Splane);
    } else {
        return false;
    }
}
