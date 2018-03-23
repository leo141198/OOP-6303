#include "Hexagon.h"

Hexagon::Hexagon(Point* center, float R, Color* color, int id) : Shape(color, id) {
    for(int i = 0; i < 6; i++) {
        points.push_back(new Point(center->x() + R * cos(i * M_PI / 3), center->y() + R * sin(i * M_PI / 3)));
    }
}

Point* Hexagon::getCenterPoint() {
    return new Point((points[0]->x() + points[5]->x()) / 2, (points[0]->y() + points[0]->x()) / 2);
}