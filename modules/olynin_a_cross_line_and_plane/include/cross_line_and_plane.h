// Copyright Olynin Alexander

#ifndef MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_H_
#define MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_H_

class Line {
 private:
    float x_1, y_1, z_1;
    float a_x, a_y, a_z;

 public:
    Line(float tx_1, float ty_1, float tz_1,
         float ta_x, float ta_y, float ta_z):
        x_1(tx_1), y_1(ty_1), z_1(tz_1), a_x(ta_x), a_y(ta_y), a_z(ta_z) {}
    Line(const Line& Tmp) : x_1(Tmp.x_1), y_1(Tmp.y_1), z_1(Tmp.z_1),
        a_x(Tmp.a_x), a_y(Tmp.a_y), a_z(Tmp.a_z) {}
    Line& operator=(const Line& Tmp);
    float GetX_1() { return this->x_1; }
    float GetY_1() { return this->y_1; }
    float GetZ_1() { return this->z_1; }
    float GetA_x() { return this->a_x; }
    float GetA_y() { return this->a_y; }
    float GetA_z() { return this->a_z; }
};


#endif  // MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_H_

