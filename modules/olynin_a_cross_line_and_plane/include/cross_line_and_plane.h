// Copyright Olynin Alexander

#ifndef MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_H_
#define MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_H_

class Line {
 private:
    double x_1, y_1, z_1;
    double a_x, a_y, a_z;

 public:
    explicit Line(double tx_1 = 0.0, double ty_1 = 0.0, double tz_1 = 0.0,
         double ta_x = 1.0, double ta_y = 1.0, double ta_z = 1.0):
        x_1(tx_1), y_1(ty_1), z_1(tz_1), a_x(ta_x), a_y(ta_y), a_z(ta_z) {}
    Line(const Line& Tmp) : x_1(Tmp.x_1), y_1(Tmp.y_1), z_1(Tmp.z_1),
        a_x(Tmp.a_x), a_y(Tmp.a_y), a_z(Tmp.a_z) {}
    Line& operator=(const Line& Tmp);
    double GetX_1() { return this->x_1; }
    double GetY_1() { return this->y_1; }
    double GetZ_1() { return this->z_1; }
    double GetA_x() { return this->a_x; }
    double GetA_y() { return this->a_y; }
    double GetA_z() { return this->a_z; }
    void SetX_1(double tx_1) { this->x_1 = tx_1; }
    void SetY_1(double ty_1) { this->y_1 = ty_1; }
    void SetZ_1(double tz_1) { this->z_1 = tz_1; }
    void SetA_x(double ta_x) { this->a_x = ta_x; }
    void SetA_y(double ta_y) { this->a_y = ta_y; }
    void SetA_z(double ta_z) { this->a_z = ta_z; }
};

class Plane {
 private:
    double a, b, c, d;

 public:
    explicit Plane(double ta = 1.0, double tb = 1.0,
                   double tc = 1.0, double td = 1.0):
          a(ta), b(tb), c(tc), d(td) {}
    Plane(const Plane& Tmp): a(Tmp.a), b(Tmp.b),
                             c(Tmp.c), d(Tmp.d) {}
    Plane& operator=(const Plane& Tmp);
    double GetA() { return this->a; }
    double GetB() { return this->b; }
    double GetC() { return this->c; }
    double GetD() { return this->d; }
    void SetA(double ta) { this->a = ta; }
    void SetB(double tb) { this->b = tb; }
    void SetC(double tc) { this->c = tc; }
    void SetD(double td) { this->d = td; }
};

class Space {
 protected:
    void calculate_params(Line Sline, Plane Splane,
                          double* numerator, double* denominator);

 public:
    int Relationship(Line Sline, Plane Splane);
    void GetPointOfIntersection(Line Sline, Plane Splane,
                                double* common_x,
                                double* common_y,
                                double* common_z);
    bool IsPerpendicular(Line Sline, Plane Splane);
    bool IsOblique(Line Sline, Plane Splane);
};

#endif  // MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_H_
