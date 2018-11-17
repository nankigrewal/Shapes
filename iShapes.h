#pragma once
#ifndef iShapes_h
#define iShapes_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Shape {};
ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

class Square : public Shape {
protected:
	const double length;
public:
	Square(const vector<string>&tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {};
	Square& operator = (const Square&);
	void outputSquareCalculation(ostream&)const;
};

class Rectangle : public Shape {
protected:
	const double length;
	const double width;
public:
	Rectangle(const vector <string> &tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};
	Rectangle& operator = (const Rectangle&);
	void outputRectangleCalculation(ostream&)const;
};

class Triangle : public Shape {
protected:
	const double length;
public:
	Triangle(const vector <string> &tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {};
	Triangle& operator = (const Triangle&);
	void outputTriangleCalculation(ostream&)const;
};

class Circle : public Shape {
protected:
	const double radius;
public:
	Circle(const vector <string> &tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {};
	Circle& operator = (const Circle&);
	void outputCircleCalculation(ostream&)const;
};

class Cube : public Square {
protected:
	const double height;
public:
	Cube(const vector <string> &tokens) : Square(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};
	Cube& operator = (const Cube&);
	void outputCubeCalculation(ostream&)const;
};

class Prism : public Triangle {
protected:
	const double height;
public:
	Prism(const vector <string> &tokens) : Triangle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};
	Prism& operator = (const Prism&);
	void outputPrismCalculation(ostream&)const;
};

class Cylinder : public Circle {
protected:
	const double height;
public:
	Cylinder(const vector <string> &tokens) : Circle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};
	Cylinder& operator = (const Cylinder&);
	void outputCylinderCalculation(ostream&)const;
};

class Box : public Rectangle {
protected:
	const double height;
public:
	Box(const vector <string> &tokens) :Rectangle(tokens), height(tokens.size() >  3 ? atof(tokens[3].c_str()) : 0) {};
	Box& operator = (const Box&);
	void outputBoxCalculation(ostream&)const;
};

#endif