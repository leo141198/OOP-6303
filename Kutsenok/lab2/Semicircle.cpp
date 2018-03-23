
#include "Semicircle.h"

Semicircle::Semicircle(Point* center, float R, float start_angle, Color* color, int id) : Shape(color, id) {
    points.push_back(new Point(center->x() + R * cos(start_angle), center->y() + R * sin(start_angle)));
    points.push_back(
            new Point(center->x() + R * cos(start_angle + M_PI / 2), center->y() + R * sin(start_angle + M_PI / 2)));
    points.push_back(new Point(center->x() + R * cos(start_angle + M_PI), center->y() + R * sin(start_angle + M_PI)));
}

Point* Semicircle::getCenterPoint() {
    return new Point((points[0]->x() + points[2]->x()) / 2, (points[0]->y() + points[2]->y()) / 2);
}