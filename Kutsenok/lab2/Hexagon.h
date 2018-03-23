#ifndef LAB_OOP_2_HEXAGON_H
#define LAB_OOP_2_HEXAGON_H

#include "Shape.h"

class Hexagon : public Shape {
public:
    Hexagon(Point* center, float R, Color* color, int id);

    Point* getCenterPoint() override;

    friend ostream& operator<<(ostream& stream, const Hexagon& figure) {
        stream << fixed << setprecision(3);
        stream << "Фигура: правильный шестиугольник" << endl;
        stream << "Идентификационный номер объекта: " << figure.id << endl;
        stream << "Цвет фигуры: " << figure.color->getRed() << " " << figure.color->getGreen() << " " << figure.color->getBlue() << endl;
        stream << "Координаты, задающие фигуру:" << endl;
        for(Point* point : figure.points) {
            stream << "(" <<point->x() << ";"<< point->y() << ")" << endl;
        }
    }
};


#endif //LAB_OOP_2_HEXAGON_H
