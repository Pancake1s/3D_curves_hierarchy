#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;

class Point
{
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
    ~Point() {};
    double x, y, z;
};

class Vector
{
public:
    Vector(double x = 0.0, double y = 0.0, double z = 0.0) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
    ~Vector() {};
    double x, y, z;
};

class Curve {
public:
    virtual Point Evaluate(double t) const = 0;
    virtual Vector Derivative(double t) const = 0;
    virtual void Print(double t) const = 0;
    virtual double GetRadius() const = 0;
};

class Circle : public Curve {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    Point Evaluate(double t) const override {
        double x = radius * cos(t);
        double y = radius * sin(t);
        double z = 0.0;
        return Point(x, y, z);
    }

    Vector Derivative(double t) const override {
        double dx_dt = -radius * sin(t);
        double dy_dt = radius * cos(t);
        double dz_dt = 0.0;
        return Vector(dx_dt, dy_dt, dz_dt);
    }

    void Print(double t) const override {
        Point P = this->Evaluate(t);
        Vector V = this->Derivative(t);
        cout << "<<Circle>>" << "\n";
        cout << "Radius = " << radius << "\n";
        cout << "Circle point at t = " << t << "\t: (" << P.x << ",\t" << P.y << ",\t" << P.z << ")\n";
        cout << "Circle deriv at t = " << t << "\t: (" << V.x << ",\t" << V.y << ",\t" << V.z << ")\n\n";
    }

    double GetRadius() const override { return radius; }
};

class Ellipse : public Curve {
private:
    double a;
    double b;
public:
    Ellipse(double majorAxis, double minorAxis) : a(majorAxis), b(minorAxis) {}

    Point Evaluate(double t) const override {
        double x = a * cos(t);
        double y = b * sin(t);
        double z = 0.0;
        return Point(x, y, z);
    }

    Vector Derivative(double t) const override {
        double dx_dt = -a * sin(t);
        double dy_dt = b * cos(t);
        double dz_dt = 0.0;
        return Vector(dx_dt, dy_dt, dz_dt);
    }

    void Print(double t) const override {
        Point P = this->Evaluate(t);
        Vector V = this->Derivative(t);
        cout << "<<Ellipse>>" << "\n";
        cout << "First Radius = " << a << "\n";
        cout << "Second Radius = " << b << "\n";
        cout << "Ellipse point at t = " << t << "\t: (" << P.x << ",\t" << P.y << ",\t" << P.z << ")\n";
        cout << "Ellipse deriv at t = " << t << "\t: (" << V.x << ",\t" << V.y << ",\t" << V.z << ")\n\n";
    }

    double GetRadius() const override { return a; }
};

class Spiral : public Curve {
private:
    double a;
    double b;
public:
    Spiral(double radius, double param) : a(radius), b(param) {}

    Point Evaluate(double t) const override {
        double x = a * cos(t);
        double y = a * sin(t);
        double z = b * t;
        return Point(x, y, z);
    }

    Vector Derivative(double t) const override {
        double dx_dt = -a * sin(t);
        double dy_dt = a * cos(t);
        double dz_dt = b;
        return Vector(dx_dt, dy_dt, dz_dt);
    }

    void Print(double t) const override {
        Point P = this->Evaluate(t);
        Vector V = this->Derivative(t);
        cout << "<<Spiral>>" << "\n";
        cout << "Radius = " << a << "\n";
        cout << "Param = " << b << "\n";
        cout << "Spiral point at t = " << t << "\t: (" << P.x << ",\t" << P.y << ",\t" << P.z << ")\n";
        cout << "Spiral deriv at t = " << t << "\t: (" << V.x << ",\t" << V.y << ",\t" << V.z << ")\n\n";
    }

    double GetRadius() const override { return a; }
};

Curve* Change(int num) {
    double random = 0.1 + (double)(rand()) / (double)(rand());
    switch (num)
    {
    case 1:
        return new Circle(random);
    case 2:
        return new Ellipse(random, random);
    case 3:
        return new Spiral(random, random);
    default:
        return 0;
        break;
    }
}

void Sort(vector<Curve*>& list)
{
    for (int i = 1; i < list.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && list[j]->GetRadius() > list[j + 1]->GetRadius())
        {
            swap(list[j], list[j + 1]);
            j--;
        }
    }
}