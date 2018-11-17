#include "iShapes.h"

#include<iostream>
#include<fstream>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

const double PI = 3.14159;

ostream& roundingTwo(ostream& out) {
	out.setf(ios::fixed);
	out.precision(2);
	return out;
}
ostream& roundingOff(ostream& out) {
	out.unsetf(ios::fixed);
	out.precision(6);
	return out;
}

void Square::outputSquareCalculation(ostream& out) const {
	double area, perimeter;
	area = this->length * this->length;
	perimeter = 4.0 * this->length;
	out << "Square side = " << roundingOff << this->length << roundingTwo << ", area = " << area << ", perimeter = " << perimeter << endl;
}

void Rectangle::outputRectangleCalculation(ostream& out) const {
	double area, perimeter;
	
	area = this->length * this->width;
	perimeter = 2.0 * (this->length + this->width);
	out << "Rectangle length = " << roundingOff << this->length << ", width= " << this->width << roundingTwo << ", area = " << area << ", perimeter = " << perimeter << endl;
}

void Triangle::outputTriangleCalculation(ostream& out) const {
	double area, perimeter;

	area = (1.732 * this->length *this->length) / 4.0;
	perimeter = 3.0 * this->length;
	out << "Triangle side = " << roundingOff << this->length << roundingTwo << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void Cube::outputCubeCalculation(ostream& out) const {
	double area, perimeter, volume;

	area = 6 * this->length *this->length;
	volume = this->length * this->length * this->length;
	perimeter = 2.0 * (this->length + this->height);
	out << "Cube side = " << roundingOff << this->length << roundingTwo << ", area = " << area << ", perimeter = " << perimeter << endl;;
}
void Circle::outputCircleCalculation(ostream& out) const {
	double area, perimeter;

	area = PI * this->radius * this->radius;
	perimeter = 2 * PI * this->radius;
	out << "Circle radius = " << roundingOff << this->radius <<	roundingTwo << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void Cylinder::outputCylinderCalculation(ostream& out) const {
	double area, volume;
	
	area = 2.0 * PI * this->radius * (this->radius + this->height);
	volume = PI * this->radius * this->radius * this->height;
	out << roundingOff << "Cylinder radius = " << this->radius << ", height = " << this->height << roundingTwo << ", surface area = " << area << ", volume = " << volume << endl;
}
void Box::outputBoxCalculation(ostream& out) const {
	double area, volume;

	area = 2.0 * ((this->length * this->width) + (this->length * this->height) + (this->width * this->height));
	volume = this->length * this->width * this->height;
	out << "Box length = " << roundingOff << this->length << ", widht = " << this->width << ", height = " << this->height << roundingTwo << ", surface area = " << area << ", volume = " << volume << endl;

}
void Prism::outputPrismCalculation(ostream& out) const {
	double area, volume;

	area = 3.0 * (this->length * this->height) + (1.732 * this->length * this->length) / 2.0;
	volume = (1.732 * this->length * this->length *this->height) / 4.0;
	out << "Prism side = " << roundingOff << this->length << ", height = " << this->height << roundingTwo << ", surface area = " << area << ", volume = " << volume << endl;
}

Square& Square::operator = (const Square& copyThis) {
	Square& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.length) = copyThis.length;
	}
	return host;
}
Rectangle& Rectangle::operator = (const Rectangle& copyThis) {
	Rectangle& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
	}
	return host;
}
Triangle& Triangle::operator = (const Triangle& copyThis) {
	Triangle& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.length) = copyThis.length;
	}
	return host;
}
Circle& Circle::operator = (const Circle& copyThis) {
	Circle& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.radius) = copyThis.radius;
	}
	return host;
}
Cube& Cube::operator = (const Cube& copyThis) {
	Cube& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.length) = copyThis.length;
	}
	return host;
}

Prism& Prism::operator = (const Prism& copyThis) {
	Prism& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host;
}
Cylinder& Cylinder::operator = (const Cylinder& copyThis) {
	Cylinder& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.radius) = copyThis.radius;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host;
}

Box& Box::operator = (const Box& copyThis) {
	Box& host = *this;
	if (this != &copyThis)
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host;
}

vector<string> parseString(string str) {
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}