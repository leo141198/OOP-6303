#ifndef LAB_OOP_2_SEMICIRCLE_H
#define LAB_OOP_2_SEMICIRCLE_H

#include "Shape.h"

class Semicircle : public Shape {
public:
    Semicircle(Point* center, float R, float start_angle, Color* color, int id);

    Point* getCenterPoint() override;

    friend ostream& operator<<(ostream& stream, const Semicircle& figure) {
        stream << fixed << setprecision(3);
        stream << "Фигура: полуокружность" << endl;
        stream << "Идентификационный номер объекта: " << figure.id << endl;
        stream << "Цвет фигуры: " << figure.color->getRed() << " " << figure.color->getGreen() << " " << figure.color->getBlue() << endl;
        stream << "Координаты, задающие фигуру:" << endl;
        for(Point* point : figure.points) {
            stream << "(" <<point->x() << ";"<< point->y() << ")" << endl;
        }
    }
};


#endif //LAB_OOP_2_SEMICIRCLE_H
