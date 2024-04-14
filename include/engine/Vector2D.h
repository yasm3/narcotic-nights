#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Vector2D {
    public:
    T x;
    T y;
    Vector2D() : x(0), y(0) {}
    Vector2D(T xValue, T yValue) : x(xValue), y(yValue) {}
    Vector2D(T value) : x(value), y(value) {}

    Vector2D& operator=(const Vector2D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(T scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(T scalar) const {
        if (scalar != 0) {
            return Vector2D(x / scalar, y / scalar);
        }
        else {
            throw std::invalid_argument("Division by zero");
        }
    }

    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector2D & other) const {
        return x < other.x && y < other.y;
    }

    bool operator>(const Vector2D& other) const {
        return x > other.x && y > other.y;
    }

    bool operator>=(const Vector2D& other) const {
        return *this == other || *this > other;
    }

    bool operator<=(const Vector2D& other) const {
        return *this == other || *this < other;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

#endif
