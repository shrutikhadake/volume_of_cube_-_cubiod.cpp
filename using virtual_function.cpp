//uisng virtual function
#include <iostream>

using namespace std;

class Shape {
public:
    virtual double calculateVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) {
        this->radius = radius;
        this->height = height;
    }

    double calculateVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) {
        this->sideLength = sideLength;
    }

    double calculateVolume() override {
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
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double calculateVolume() override {
        return length * width * height;
    }
};

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << cylinder.calculateVolume() << endl;
    cout << "Volume of cube: " << cube.calculateVolume() << endl;
    cout << "Volume of cuboid: " << cuboid.calculateVolume() << endl;

    return 0;
}

