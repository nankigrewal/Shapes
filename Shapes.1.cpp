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
	double height;
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

int main() {

	//Programmer info
	cout << "Programmer : Nanki Grewal\nProgrammer ID: 1428278" << endl;
	cout << "File: " << __FILE__ << "\n\n";

	//Declaring input and output file
	ifstream fin;
	ofstream fout;
	//Declaring string to hold file input
	string input;
	
	//Open the input and output files
	fin.open("Shapes.input.txt");
	fout.open("Shapes.output.txt");

	//Check if the file is usable/locatable
	if (!fin.good()) throw "I/O error";

	//Create an empty bag and its companion array
	vector<void*> myBag; 
	vector<char> myBagType;

	//Setting console and file output to two decimal points precision
	cout.setf(ios::fixed);
	cout.precision(2);
	fout.setf(ios::fixed);
	fout.precision(2);

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
			myBag.push_back(sq);
			myBagType.push_back('S');
		}
		else if (tokens.at(0) == "RECTANGLE") {
			Rectangle* rec = new Rectangle;
			//Length and width values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			rec->length = atof(tokens.at(1).c_str());
			rec->width = atof(tokens.at(2).c_str());
			myBag.push_back(rec);
			myBagType.push_back('R');
		}
		else if (tokens.at(0) == "TRIANGLE") {
			Triangle* tri = new Triangle;
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			tri->side = atof(tokens.at(1).c_str());
			myBag.push_back(tri);
			myBagType.push_back('T');
		}
		else if (tokens.at(0) == "CIRCLE") {
			Circle* cir = new Circle;
			// Radius value needed
			tokens.resize(2, "0");
			//Convert string to double
			cir->radius = atof(tokens.at(1).c_str());
			myBag.push_back(cir);
			myBagType.push_back('C');
		}
		else if (tokens.at(0) == "CUBE") {
			Cube* cube = new Cube;
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			cube->side = atof(tokens.at(1).c_str());
			myBag.push_back(cube);
			myBagType.push_back('U');
		}
		else if (tokens.at(0) == "BOX") {
			Box* box = new Box;
			//Length, width, and height values needed
			tokens.resize(4, "0");
			//Convert strings to doubles
			box->length = atof(tokens.at(1).c_str());
			box->width = atof(tokens.at(2).c_str());
			box->height = atof(tokens.at(3).c_str());
			myBag.push_back(box);
			myBagType.push_back('B');
		}
		else if (tokens.at(0) == "CYLINDER") {
			Cylinder* cyl = new Cylinder;
			//Radius and height values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			cyl->height = atof(tokens.at(1).c_str());
			cyl->radius = atof(tokens.at(2).c_str());
			myBag.push_back(cyl);
			myBagType.push_back('Y');
		}
		else if (tokens.at(0) == "PRISM") {
			Prism* pri = new Prism;
			//Side and height values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			pri->side = atof(tokens.at(1).c_str());
			pri->height = atof(tokens.at(2).c_str());
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
			outputSquare(cout, rSquare);
			outputSquare(fout, rSquare);
		}
		else if (myBagType[i] == 'R') {
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
			Rectangle& rRectangle = *pRectangle;
			outputRectangle(cout, rRectangle);
			outputRectangle(fout, rRectangle);
		}
		else if (myBagType[i] == 'T') {
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			Triangle& rTriangle = *pTriangle;
			outputTriangle(cout, rTriangle);
			outputTriangle(fout, rTriangle);
		}
		else if (myBagType[i] == 'C') {
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
			Circle& rCircle = *pCircle;
			outputCircle(cout, rCircle);
			outputCircle(fout, rCircle);
		}
		else if (myBagType[i] == 'U') {
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			Cube& rCube = *pCube;
			outputCube(cout, rCube);
			outputCube(fout, rCube);
		}
		else if (myBagType[i] == 'B') {
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			Box& rBox = *pBox;
			outputBox(cout, rBox);
			outputBox(fout, rBox);
		}
		else if (myBagType[i] == 'Y') {
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
			Cylinder& rCylinder = *pCylinder;
			outputCylinder(cout, rCylinder);
			outputCylinder(fout, rCylinder);
		}
		else if (myBagType[i] == 'P') {
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
			Prism& rPrism = *pPrism;
			outputPrism(cout, rPrism);
			outputPrism(fout, rPrism);
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

void outputSquare(ostream& out, const Square& s) {
	double area = s.side * s.side;
	double perimeter = s.side * 4.0;
	//Output the data to the console and an output file
	out << "Square side = " << s.side << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void outputRectangle(ostream& out, const Rectangle& r) {
	//Calculate area and perimeter using geometric formulas
	double area = r.length * r.width;
	double perimeter = 2.0 * (r.length + r.width);
	//Output the data to the console and an output file
	out << "Rectangle length = " << r.length << ", width = " << r.width << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void outputCircle(ostream& out, const Circle& c) {
	//Calculate area and perimeter using geometric formulas
	double area = pi * c.radius * c.radius;
	double perimeter = 2.0 * pi * c.radius;
	//Output the data to the console and an output file
	out << "Circle radius = " << c.radius << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void outputTriangle(ostream& out, const Triangle& t) {
	//Calculate area and perimeter using geometric formulas
	double area = sqrt(3) / 4.0 * t.side * t.side;
	double perimeter = t.side * 3.0;
	//Output the data to the console and an output file
	out << "Triangle side = " << t.side << ", area = " << area << ", perimeter = " << perimeter << endl;
}
void outputBox(ostream& out, const Box& b) {
	//Calculate surface area and volume using geometric formulas
	double surfaceArea = (2.0 * b.length * b.width) + (2.0 * b.width * b.height) + (2.0 * b.height * b.length);
	double volume = b.length * b.width * b.height;
	//Output the data to the console and an output file
	out << "Box length = " << b.length << ", width = " << b.width << ", height = " << b.height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
void outputCube(ostream& out, const Cube& c) {
	//Calculate surface area and volume using geometric formulas
	double surfaceArea = 6.0 * c.side * c.side;
	double volume = c.side * c.side * c.side;
	//Output the data to the console and an output file
	out << "Cube side = " << c.side << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
void outputCylinder(ostream& out, const Cylinder& c) {
	//Calculate surface area and volume using geometric formulas
	double surfaceArea = (2.0 * pi * c.radius * c.radius) + (2.0 * pi * c.radius * c.height);
	double volume = pi * c.radius * c.radius * c.height;
	//Output the data to the console and an output file
	out << "Cylinder radius = " << c.radius << ", height = " << c.height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}
void outputPrism(ostream& out, const Prism& p) {
	//Calculate surface area and volume using geometric formulas
	double surfaceArea = (2.0 * sqrt(3) / 4.0 * p.side * p.side) + (3.0 * p.side * p.height);
	double volume = sqrt(3) / 4.0 * p.side * p.side * p.height;
	//Output the data to the console and an output file
	out << "Prism side = " << p.side << ", height = " << p.height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
}