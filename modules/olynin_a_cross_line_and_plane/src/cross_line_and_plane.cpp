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
    /* The function for calculating t = - (D + A*x_1 + B*y_1 + C*z_1) / (A*a_x + B*a_y + C*a_z).
    * Returns the numerator and denominator, that are calculated separately.
    * If they are both equal to zero, then the line lies in the plane.
    * If the denominator is zero and the numerator is not, then the line is parallel to the plane.
    * If they are both nonzero, then the straight line intersects the plane.
    */
    *numerator = Splane.GetD() + Splane.GetA() * Sline.GetX_1() +
                    Splane.GetB() * Sline.GetY_1() +
                    Splane.GetC() * Sline.GetZ_1();
    *denominator = Splane.GetA() * Sline.GetA_x() +
                    Splane.GetB() * Sline.GetA_y() +
                    Splane.GetC() * Sline.GetA_z();
}

int Space::Relationship(Line Sline, Plane Splane) {
    /* Returns one of the following values:
    *    0 - Line doesn't intersect the Plane
    *    1 - Line intersects the Plane and has the one common point with the Plane
    *    2 - Line is contained in the Plane and has lots common points with the Plane
    */
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
    /* Returns following values:
    * In the case of line intersects the plane, returns the coordinates
    * of the common point.
    * In the case line doesn't intersect the plane throws an error.
    */
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
    /* Returns one of the following values:
    *    0 - Line isn't perpendicular to the Plane
    *    1 - Line is perpendicular to the Plane
    */
    if ((Sline.GetA_x() == 0 && Sline.GetA_y() == 0 && Sline.GetA_z() == 0) ||
        (Splane.GetA() == 0 && Splane.GetB() == 0 && Splane.GetC() == 0)) {
        const std::string
            error_type("The perpendicularity can't be determined");
        throw error_type;
    }
    if (Relationship(Sline, Splane) == 1) {
        double accuracy = 0.000001;
        if (Splane.GetA() == 0 || Splane.GetB() == 0 || Splane.GetC() == 0) {
            if (Splane.GetA() == 0 && Splane.GetB() == 0) {
                if (Sline.GetA_x() == 0 && Sline.GetA_y() == 0) {
                    return true;
                } else {
                    return false;
                }
            }
            if (Splane.GetA() == 0 && Splane.GetC() == 0) {
                if (Sline.GetA_x() == 0 && Sline.GetA_z() == 0) {
                    return true;
                } else {
                    return false;
                }
            }
            if (Splane.GetB() == 0 && Splane.GetC() == 0) {
                if (Sline.GetA_y() == 0 && Sline.GetA_z() == 0) {
                    return true;
                } else {
                    return false;
                }
            }
            if (Splane.GetA() == 0) {
                if (Sline.GetA_x() == 0 &&
                (Sline.GetA_y() / Splane.GetB()) -
                (Sline.GetA_z() / Splane.GetC()) < accuracy) {
                    return true;
                } else {
                    return false;
                }
            }
            if (Splane.GetB() == 0) {
                if (Sline.GetA_y() == 0 &&
                (Sline.GetA_x() / Splane.GetA()) -
                (Sline.GetA_z() / Splane.GetC()) < accuracy) {
                    return true;
                } else {
                    return false;
                }
            }
            if (Splane.GetC() == 0) {
                if (Sline.GetA_z() == 0 &&
                (Sline.GetA_x() / Splane.GetA()) -
                (Sline.GetA_y() / Splane.GetB()) < accuracy) {
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            if ((Sline.GetA_x() / Splane.GetA()) -
                (Sline.GetA_y() / Splane.GetB()) < accuracy &&
                (Sline.GetA_x() / Splane.GetA()) -
                (Sline.GetA_z() / Splane.GetC()) < accuracy) {
                    return true;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return false;
}

bool Space::IsOblique(Line Sline, Plane Splane) {
    /* Returns one of the following values:
    *    0 - Line isn't oblique to the Plane
    *    1 - Line is oblique to the Plane
    */
    if (Relationship(Sline, Splane) == 1) {
        return !IsPerpendicular(Sline, Splane);
    } else {
        return false;
    }
}
