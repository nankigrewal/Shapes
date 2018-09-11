#include<iterator>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include<cmath>
#include<cstdlib>

//Prototype for string parsing function
vector<string> parseString(string);

const double pi = 3.14159;

struct Square {
	double side;
};
struct Rectangle {
	double length;
	double width;
};
struct Circle {
	double radius;
};
struct Triangle {
	double side;
};
struct Cube {
	double side;
};
struct Box {
	double length;
	double width;
	double height;
};
struct Cylinder {
	double radius;
	double height;
};
struct Prism {
	double side;
	double length;
};

void outputSquare(ostream&, const Square&);
void outputRectangle(ostream&, const Rectangle&);
void outputCircle(ostream&, const Circle&);
void outputTriangle(ostream&, const Triangle&);
void outputBox(ostream&, const Box&);
void outputCube(ostream&, const Cube&);
void outputCylinder(ostream&, const Cylinder&);
void outputPrism(ostream&, const Prism&);


int main() {

	//Programmer info
	cout << "Programmer : Nanki Grewal\nProgrammer ID: 1428278" << endl;
	cout << "File: " << __FILE__ << "\n\n";

	//Declaring input and output file
	ifstream fin;
	ofstream fout;
	//Declaring string to hold file input
	string input;
	//Declaring variables for given values
	double length, width, height, radius, side;
	//Declaring variables for calculated values
	double area, volume, surfaceArea, perimeter;

	//Open the input and output files
	fin.open("Shapes.input.txt");
	fout.open("Shapes.output.txt");

	//Check if the file is usable/locatable
	if (!fin.good()) throw "I/O error";

	//While loop for parsing through the open file
	while (fin.good()) {
		//Read the line
		getline(fin, input);

		//Parse the string using the parseString function, store in vector
		vector<string> tokens = parseString(input);

		//Check for whether the line is empty
		if (tokens.size() == 0)
			continue;

		//The following conditional tests for what type of object is specified, then it calculates and outputs desired values
		if (tokens.at(0) == "SQUARE") {

			Square* sq = new Square;

			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			sq->side = atof(tokens.at(1).c_str());

			//Calculate area and perimeter using geometric formulas
			area = sq->side * sq->side;
			perimeter = sq->side * 4.0;

		}
		else if (tokens.at(0) == "RECTANGLE") {

			Rectangle* rec = new Rectangle;

			//Length and width values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			rec->length = atof(tokens.at(1).c_str());
			rec->width = atof(tokens.at(2).c_str());

			//Calculate area and perimeter using geometric formulas
			area = rec->length * rec->width;
			perimeter = 2.0 * (rec->length + rec->width);

		}
		/**************************************create objects and add pointers*************************************/
		else if (tokens.at(0) == "TRIANGLE") {
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			side = atof(tokens.at(1).c_str());

			//Calculate area and perimeter using geometric formulas
			area = sqrt(3) / 4 * side * side;
			perimeter = length * 3.0;
		}
		else if (tokens.at(0) == "CIRCLE") {
			// Radius value needed
			tokens.resize(2, "0");
			//Convert string to double
			radius = atof(tokens.at(1).c_str());

			//Calculate area and perimeter using geometric formulas
			area = pi * radius * radius;
			perimeter = 2.0 * pi * radius;
		}
		else if (tokens.at(0) == "CUBE") {
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			side = atof(tokens.at(1).c_str());

			//Calculate surface area and volume using geometric formulas
			surfaceArea = 6.0 * side * side;
			volume = side * side * side;
		}
		else if (tokens.at(0) == "BOX") {
			//Length, width, and height values needed
			tokens.resize(4, "0");
			//Convert strings to doubles
			length = atof(tokens.at(1).c_str());
			width = atof(tokens.at(2).c_str());
			height = atof(tokens.at(3).c_str());

			//Calculate surface area and volume using geometric formulas
			surfaceArea = (2.0 * length * width) + (2.0 * width * height) + (2.0 * height * length);
			volume = length * width * height;
		}
		else if (tokens.at(0) == "CYLINDER") {
			//Radius and height values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			height = atof(tokens.at(1).c_str());
			radius = atof(tokens.at(2).c_str());

			//Calculate surface area and volume using geometric formulas
			surfaceArea = (2.0 * pi * radius * radius) + (2.0 * pi * radius * height);
			volume = pi * radius * radius * height;
		}
		else if (tokens.at(0) == "PRISM") {
			//Side and height values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			side = atof(tokens.at(1).c_str());
			height = atof(tokens.at(2).c_str());

			//Calculate surface area and volume using geometric formulas
			surfaceArea = (2.0 * sqrt(3) / 4.0 * side * side) + (3.0 * side * height);
			volume = sqrt(3) / 4 * side * side * height;
		}
		//Exit the file if EOF is encountered
		else if (tokens.at(0) == "EOF") {
			break;
		}
		//Check for whether shape type is valid and tell user if not valid
		else
			cout << tokens.at(0) << " -> invalid" << endl;
	}

	//CLose the files
	fin.close();
	fout.close();

	//Keep console open and return 0 to main function
	system("PAUSE");
	return 0;
}

vector<string> parseString(string str) {
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

void outputSquare(ostream& out, const Square& s) {
	//Output the data to the console and an output file
	out << "Square side = " << s.side << ", area = " << s.area << ", perimeter = " << s.perimeter << endl;
}
void outputRectangle(ostream& out, const Rectangle & r) {
	//Output the data to the console and an output file
	out << "Rectangle length = " << r.length << ", width = " << r.width << ", area = " << r.area << ", perimeter = " << r.perimeter << endl;
}
void outputCircle(ostream& out, const Circle& c) {
	//Output the data to the console and an output file
	out << "Circle radius = " << c.radius << ", area = " << c.area << ", perimeter = " << c.perimeter << endl;
}
void outputTriangle(ostream& out, const Triangle& t) {
	//Output the data to the console and an output file
	out << "Triangle side = " << t.side << ", area = " << t.area << ", perimeter = " << t.perimeter << endl;
}
void outputBox(ostream& out, const Box& b) {
	//Output the data to the console and an output file
	out << "Box length = " << b.length << ", width = " << b.width << ", height = " << b.height << ", surface area = " << b.surfaceArea << ", volume = " << b.volume << endl;
}
void outputCube(ostream& out, const Cube& c) {
	//Output the data to the console and an output file
	out << "Cube side = " << c.side << ", surface area = " << c.surfaceArea << ", volume = " << c.volume << endl;
}
void outputCylinder(ostream& out, const Cylinder& c) {
	//Output the data to the console and an output file
	out << "Cylinder radius = " << c.radius << ", height = " << c.height << ", surface area = " << c.surfaceArea << ", volume = " << c.volume << endl;
}
void outputPrism(ostream& out, const Prism& p) {
	//Output the data to the console and an output file
	out << "Prism side = " << p.side << ", height = " << p.height << ", surface area = " << p.surfaceArea << ", volume = " << p.volume << endl;
}