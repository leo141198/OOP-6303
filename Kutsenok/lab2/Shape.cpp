#include "Shape.h"


void Shape::move(Point* point) {
    float x_offset = point->x() - getCenterPoint()->x();
    float y_offset = point->y() - getCenterPoint()->y();
    for(Point* current : points) {
        current->x() += x_offset;
        current->y() += y_offset;
    }
}

void Shape::rotate(float angle) {
    Point* center = getCenterPoint();
    float x, y;
    for(Point* current : points) {
        current->x() -= center->x();
        current->y() -= center->y();
        x = current->x() * cos(angle) - current->y() * sin(angle) + center->x();
        y = current->x() * sin(angle) + current->y() * cos(angle) + center->y();
        current->x() = x;
        current->y() = y;
    }
}

void Shape::scale(float factor) {
    Point* center = getCenterPoint();
    for(Point* current : points) {
        current->x() = (current->x() - center->x()) * factor;
        current->y() = (current->y() - center->y()) * factor;
    }
}


Color* Shape::getColor() const {
    return color;
}
