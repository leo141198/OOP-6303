#ifndef OOP_PARALLELOGRAM_H
#define OOP_PARALLELOGRAM_H

#include "Shape.h"

class Parallelogram : public Shape {
public:
    Parallelogram(Point* p1, Point* p2, Point* p3, Color* color, int id);

    Point* getCenterPoint() override;

    friend ostream& operator<<(ostream& stream, const Parallelogram& figure) {
        stream << fixed << setprecision(3);
        stream << "Фигура: параллелограмм" << endl;
        stream << "Идентификационный номер объекта: " << figure.id << endl;
        stream << "Цвет фигуры: " << figure.color->getRed() << " " << figure.color->getGreen() << " " << figure.color->getBlue() << endl;
        stream << "Координаты, задающие фигуру:" << endl;
        for(Point* point : figure.points) {
            stream << "(" <<point->x() << ";"<< point->y() << ")" << endl;
        }
    }
};


#endif //OOP_PARALLELOGRAM_H
