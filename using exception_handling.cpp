//uisng exception handling
#include <iostream>
#include <exception>

using namespace std;

class InvalidInputException : public exception {
public:
    InvalidInputException(const string& message) : message(message) {}

    const string& getMessage() const {
        return message;
    }

private:
    string message;
};

class Shape {
public:
    virtual double getVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) {
        if (radius <= 0) {
            throw InvalidInputException("Invalid input: Radius must be positive");
        }

        if (height <= 0) {
            throw InvalidInputException("Invalid input: Height must be positive");
        }

        this->radius = radius;
        this->height = height;
    }

    double getVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) {
        if (sideLength <= 0) {
            throw InvalidInputException("Invalid input: Side length must be positive");
        }

        this->sideLength = sideLength;
    }

    double getVolume() override {
        return sideLength * sideLength * sideLength;
    }
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) {
        if (length <= 0) {
            throw InvalidInputException("Invalid input: Length must be positive");
        }

        if (width <= 0) {
            throw InvalidInputException("Invalid input: Width must be positive");
        }

        if (height <= 0) {
            throw InvalidInputException("Invalid input: Height must be positive");
        }

        this->length = length;
        this->width = width;
        this->height = height;
    }

    double getVolume() override {
        return length * width * height;
    }
};

int main() {
    try {
        Cylinder cylinder(5.0, 10.0);
        Cube cube(6.0);
        Cuboid cuboid(8.0, 4.0, 3.0);

        cout << "Volume of cylinder: " << cylinder.getVolume() << endl;
        cout << "Volume of cube: " << cube.getVolume() << endl;
        cout << "Volume of cuboid: " << cuboid.getVolume() << endl;
    } catch (InvalidInputException& e) {
        cerr << "Error: " << e.getMessage() << endl;
    }

    return 0;
}
