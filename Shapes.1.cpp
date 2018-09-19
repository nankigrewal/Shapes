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

const double pi = 3.14159;

struct Square {
	double side;
	void output(ostream&) const;
};
struct Rectangle {
	double length;
	double width;
	void output(ostream&) const;
};
struct Circle {
	double radius;
	void output(ostream&) const;
};
struct Triangle {
	double side;
	void output(ostream&) const;
};
struct Cube {
	double side;
	void output(ostream&) const;
};
struct Box {
	double length;
	double width;
	double height;
	void output(ostream&) const;
};
struct Cylinder {
	double radius;
	double height;
	void output(ostream&) const;
};
struct Prism {
	double side;
	double height;
	void output(ostream&) const;
};
//Prototype for string parsing function
vector<string> parseString(string);
//Prototypes for shapes property calc functions
void outputSquare(ostream&, const Square&);
void outputRectangle(ostream&, const Rectangle&);
void outputCircle(ostream&, const Circle&);
void outputTriangle(ostream&, const Triangle&);
void outputBox(ostream&, const Box&);
void outputCube(ostream&, const Cube&);
void outputCylinder(ostream&, const Cylinder&);
void outputPrism(ostream&, const Prism&);
//Stream manipulator prototype
ostream& roundingTwo(ostream&);

int main() {

	//Declaring input and output file
	ifstream fin;
	ofstream fout;
	//Open the input and output files
	fin.open("Shapes.input.txt");
	fout.open("Shapes.output.txt");
	//Declaring string to hold file input
	string input;

	//Programmer info
	cout << "Programmer : Nanki Grewal\nProgrammer ID: 1428278" << endl;
	cout << "File: " << __FILE__ << "\n\n";
	fout << "Programmer : Nanki Grewal\nProgrammer ID: 1428278" << endl;
	fout << "File: " << __FILE__ << "\n\n";

	//Check if the file is usable/locatable
	if (!fin.good()) throw "I/O error";

	//Create an empty bag and its companion array
	vector<void*> myBag; 
	vector<char> myBagType;
	
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
			sq->side = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			//Convert string to double
			myBag.push_back(sq);
			myBagType.push_back('S');
		}
		else if (tokens.at(0) == "RECTANGLE") {
			Rectangle* rec = new Rectangle;
			//Convert strings to doubles
			rec->length = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			rec->width = (tokens.size() > 2 ? atof(tokens.at(2).c_str()) : 0);
			myBag.push_back(rec);
			myBagType.push_back('R');
		}
		else if (tokens.at(0) == "TRIANGLE") {
			Triangle* tri = new Triangle;
			//Convert string to double
			tri->side = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			myBag.push_back(tri);
			myBagType.push_back('T');
		}
		else if (tokens.at(0) == "CIRCLE") {
			Circle* cir = new Circle;
			//Convert string to double
			cir->radius = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			myBag.push_back(cir);
			myBagType.push_back('C');
		}
		else if (tokens.at(0) == "CUBE") {
			Cube* cube = new Cube;
			//Convert string to double
			cube->side = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			myBag.push_back(cube);
			myBagType.push_back('U');
		}
		else if (tokens.at(0) == "BOX") {
			Box* box = new Box;
			//Convert strings to doubles
			box->length = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			box->width = (tokens.size() > 2 ? atof(tokens.at(2).c_str()) : 0);
			box->height = (tokens.size() > 3 ? atof(tokens.at(3).c_str()) : 0);
			myBag.push_back(box);
			myBagType.push_back('B');
		}
		else if (tokens.at(0) == "CYLINDER") {
			Cylinder* cyl = new Cylinder;
			//Convert strings to doubles
			cyl->height = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			cyl->radius = (tokens.size() > 2 ? atof(tokens.at(2).c_str()) : 0);
			myBag.push_back(cyl);
			myBagType.push_back('Y');
		}
		else if (tokens.at(0) == "PRISM") {
			Prism* pri = new Prism;
			//Side and height values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			pri->side = (tokens.size() > 1 ? atof(tokens.at(1).c_str()) : 0);
			pri->height = (tokens.size() > 2 ? atof(tokens.at(2).c_str()) : 0);
			myBag.push_back(pri);
			myBagType.push_back('P');
		}
		//Exit the file if EOF is encountered
		else if (tokens.at(0) == "EOF") {
			break;
		}
		//Check for whether shape type is valid and tell user if not valid
		else
			cout << tokens.at(0) << " -> invalid" << endl;
	}

	//This loop outputs appropriate calculations to console and to output file 
	for (unsigned int i = 0; i < myBag.size(); i++)
	{
		if (myBagType[i] == 'S') {
			Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
			Square& rSquare = *pSquare;
			rSquare.output(cout);
			rSquare.output(fout);
		}
		else if (myBagType[i] == 'R') {
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
			Rectangle& rRectangle = *pRectangle;
			rRectangle.output(cout);
			rRectangle.output(fout);
		}
		else if (myBagType[i] == 'T') {
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			Triangle& rTriangle = *pTriangle;
			rTriangle.output(cout);
			rTriangle.output(fout);
		}
		else if (myBagType[i] == 'C') {
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
			Circle& rCircle = *pCircle;
			rCircle.output(cout);
			rCircle.output(fout);
		}
		else if (myBagType[i] == 'U') {
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			Cube& rCube = *pCube;
			rCube.output(cout);
			rCube.output(fout);
		}
		else if (myBagType[i] == 'B') {
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			Box& rBox = *pBox;
			rBox.output(cout);
			rBox.output(fout);
		}
		else if (myBagType[i] == 'Y') {
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
			Cylinder& rCylinder = *pCylinder;
			rCylinder.output(cout);
			rCylinder.output(fout);
		}
		else if (myBagType[i] == 'P') {
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
			Prism& rPrism = *pPrism;
			rPrism.output(cout);
			rPrism.output(fout);
		}
		else {
			cout << "Type not recognized." << endl;
			fout << "Type not recognized." << endl;
		}
	}

	//CLose the files
	fin.close();
	fout.close();

	//This for loop will delete/deallocate objects
	for (unsigned int i = 0; i < myBag.size(); i++)
	{
		if (myBagType[i] == 'S') {
			Square* s = reinterpret_cast<Square*>(myBag[i]); // restore its "Movie-ness"
			delete s; // deallocate the Movie object at memory location myBag[i]
		}
		else if (myBagType[i] == 'R') {
			Rectangle* r = reinterpret_cast<Rectangle*>(myBag[i]); // restore its "Movie-ness"
			delete r;
		}
		else if (myBagType[i] == 'T') {
			Triangle* t = reinterpret_cast<Triangle*>(myBag[i]); // restore its "Movie-ness"
			delete t;
		}
		else if (myBagType[i] == 'C') {
			Circle* e = reinterpret_cast<Circle*>(myBag[i]); // restore its "Movie-ness"
			delete e;
		}
		else if (myBagType[i] == 'U') {
			Cube* c = reinterpret_cast<Cube*>(myBag[i]); // restore its "Movie-ness"
			delete c;
		}
		else if (myBagType[i] == 'B') {
			Box* b = reinterpret_cast<Box*>(myBag[i]); // restore its "Movie-ness"
			delete b;
		}
		else if (myBagType[i] == 'Y') {
			Cylinder* y = reinterpret_cast<Cylinder*>(myBag[i]); // restore its "Movie-ness"
			delete y;
		}
		else if (myBagType[i] == 'P') {
			Prism* p = reinterpret_cast<Prism*>(myBag[i]); // restore its "Movie-ness"
			delete p;
		}
	}

	//Keep console open and return 0 to main function
	system("PAUSE");
	return 0;
}

vector<string> parseString(string str) {
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

void Square::output(ostream& out) const {
	double area, perimeter;
	double side;

	side = this->side;
	area = side * side;
	perimeter = 4.0 * side;
	//Output the data to the console and an output file
	out << roundingTwo << "Square side = " << side << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void Rectangle::output(ostream& out) const {
	
	double area, perimeter;
	double length, width;

	length = this->length;
	width = this->width;
	area = length * width;
	perimeter = (2.0 * length) + (2.0 * width);
	//Output the data to the console and an output file
	out << roundingTwo << "Rectangle length = " << length << ", width = " << width << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void Circle::output(ostream& out) const {
	double area, perimeter;
	double radius;
	radius = this->radius;
	area = pi * radius * radius;
	perimeter = 2.0 * pi * radius;
	//Output the data to the console and an output file
	out << roundingTwo << "Circle radius = " << radius << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void Triangle::output(ostream& out) const {
	double area, perimeter;
	double side;
	side = this->side;
	area = sqrt(3) / 4.0 * side * side;
	perimeter = side * 3.0;
	//Output the data to the console and an output file
	out << roundingTwo << "Triangle side = " << side << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void Box::output(ostream& out) const {
	double surfaceArea, volume;
	double length, width, height;
	length = this->length;
	width = this->width;
	height = this->height;
	surfaceArea = (2.0 * length * width) + (2.0 * width * height) + (2.0 * height * length);
	volume = length * width * height;
	//Output the data to the console and an output file
	out << roundingTwo << "Box length = " << length << ", width = " << width << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
void Cube::output(ostream& out) const {
	double surfaceArea, volume;
	double side;
	side = this->side;
	//Calculate surface area and volume using geometric formulas
	surfaceArea = 6.0 * side * side;
	volume = side * side * side;
	//Output the data to the console and an output file
	out << roundingTwo << "Cube side = " << side << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
void Cylinder::output(ostream& out) const {
	double surfaceArea, volume;
	double radius, height;
	radius = this->radius;
	height = this->height;
	//Calculate surface area and volume using geometric formulas
	surfaceArea = (2.0 * pi * radius * radius) + (2.0 * pi * radius * height);
	volume = pi * radius * radius * height;
	//Output the data to the console and an output file
	out << roundingTwo << "Cylinder radius = " << radius << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
void Prism::output(ostream& out) const {
	double surfaceArea, volume;
	double side, height;
	side = this->side;
	height = this->height;
	//Calculate surface area and volume using geometric formulas
	surfaceArea = (2.0 * sqrt(3) / 4.0 * side * side) + (3.0 * side * height);
	volume = sqrt(3) / 4.0 * side * side * height;
	//Output the data to the console and an output file
	out << roundingTwo << "Prism side = " << side << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
ostream& roundingTwo(ostream& out)
{
	out.setf(ios::fixed);
	out.precision(2); // 2 decimal digits
	return out;
}