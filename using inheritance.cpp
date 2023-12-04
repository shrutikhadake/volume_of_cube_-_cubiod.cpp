//uisng inheriantance

#include <iostream>

using namespace std;

class Shape {
public:
    virtual double getVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) : sideLength(sideLength) {}

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
    Cuboid(double length, double width, double height) : length(length), width(width), height(height) {}

    double getVolume() override {
        return length * width * height;
    }
};

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << cylinder.getVolume() << endl;
    cout << "Volume of cube: " << cube.getVolume() << endl;
    cout << "Volume of cuboid: " << cuboid.getVolume() << endl;

    return 0;
}
