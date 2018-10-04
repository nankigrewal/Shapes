#include<iterator>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;

#include<cmath>
#include<cstdlib>

const double pi = 3.14159;

class Square {
	const double side;
public:
	Square(const vector<string>&);
	Square& operator = (const Square&);
	void output(ostream&) const;

	double getSide() const { return side; };
};

class Rectangle {
	const double length;
	const double width;
public:
	Rectangle(const vector<string>&);
	Rectangle& operator = (const Rectangle&);
	void output(ostream&) const;
	double getLength() const { return length; };
	double getWidth() const { return width; };
};

class Circle {
	const double radius;
public:
	Circle(const vector<string>&);
	Circle& operator = (const Circle&);
	void output(ostream&) const;

	double getRadius() const { return radius; };
};

class Triangle {
	const double side;
public:
	Triangle(const vector<string>&);
	Triangle& operator = (const Triangle&);
	void output(ostream&) const;

	double getSide() const { return side; };
};

class Cube {
	const double side;
public:
	Cube(const vector<string>&);
	Cube& operator = (const Cube&);
	void output(ostream&) const;

	double getSide() const { return side; };
};

class Box {
	const double length;
	const double width;
	const double height;
public:
	Box(const vector<string>&);
	Box& operator = (const Box&);
	void output(ostream&) const;

	double getLength() const { return length; };
	double getWidth() const { return width; };
	double getHeight() const { return height; };
};

class Cylinder {
	const double radius;
	const double height;
public:
	Cylinder(const vector<string>&);
	Cylinder& operator = (const Cylinder&);
	void output(ostream&) const;
	double getRadius() const { return radius; };
	double getHeight() const { return height; };
};

class Prism {
	const double side;
	const double height;
public:
	Prism(const vector<string>&);
	Prism& operator = (const Prism&);
	void output(ostream&) const;
	double getSide() const { return side; };
	double getHeight() const { return height; };
};

Square::Square(const vector<string>& tokens) : side((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0) {}
Rectangle::Rectangle(const vector<string>& tokens) : length((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0), width((tokens.size() > 3) ? atof(tokens[2].c_str()) : 0) {}
Circle::Circle(const vector<string>& tokens) : radius((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0) {}
Triangle::Triangle(const vector<string>& tokens) : side((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0) {}
Box::Box(const vector<string>& tokens) : length((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0), width((tokens.size() > 3) ? atof(tokens[2].c_str()) : 0), height((tokens.size() > 4) ? atof(tokens[3].c_str()) : 0) {}
Cube::Cube(const vector<string>& tokens) : side((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0) {}
Cylinder::Cylinder(const vector<string>& tokens) : radius((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0), height((tokens.size() > 3) ? atof(tokens[2].c_str()) : 0) {}
Prism::Prism(const vector<string>& tokens) : side((tokens.size() > 2) ? atof(tokens[1].c_str()) : 0), height((tokens.size() > 3) ? atof(tokens[2].c_str()) : 0) {}

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
	vector<const void*> myBag;
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
			const Square* const sq = new Square(tokens);
			double side = sq->getSide();
			//Convert string to double
			myBag.push_back(sq);
			myBagType.push_back('S');
		}
		else if (tokens.at(0) == "RECTANGLE") {
			const Rectangle* const rec = new Rectangle(tokens);
			double length = rec->getLength();
			double width = rec->getWidth();
			myBag.push_back(rec);
			myBagType.push_back('R');
		}
		else if (tokens.at(0) == "TRIANGLE") {
			const Triangle* const tri = new Triangle(tokens);
			double side = tri->getSide();
			//Convert string to double
			myBag.push_back(tri);
			myBagType.push_back('T');
		}
		else if (tokens.at(0) == "CIRCLE") {
			const Circle* const cir = new Circle(tokens);
			double radius = cir->getRadius();
			myBag.push_back(cir);
			myBagType.push_back('C');
		}
		else if (tokens.at(0) == "CUBE") {
			const Cube* const cube = new Cube(tokens);
			double side = cube->getSide();
			myBag.push_back(cube);
			myBagType.push_back('U');
		}
		else if (tokens.at(0) == "BOX") {
			const Box* const box = new Box(tokens);
			double length = box->getLength();
			double height = box->getHeight();
			double width = box->getWidth();
			myBag.push_back(box);
			myBagType.push_back('B');
		}
		else if (tokens.at(0) == "CYLINDER") {
			const Cylinder* const cyl = new Cylinder(tokens);
			double height = cyl->getHeight();
			double radius = cyl->getRadius();
			myBag.push_back(cyl);
			myBagType.push_back('Y');
		}
		else if (tokens.at(0) == "PRISM") {
			const Prism* const pri = new Prism(tokens);
			double side = pri->getSide();
			double height = pri->getHeight();
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

	for (int i = 0; i < myBag.size(); i++) {
		for (int j = i + 1; j < myBag.size(); j++) {
			if (myBagType[j] < myBagType[i]) {
				swap(myBagType[i], myBagType[j]);
				swap(myBag[i], myBag[j]);
			}
		}
	}

	//This loop outputs appropriate calculations to console and to output file 
	for (unsigned int i = 0; i < myBag.size(); i++)
	{
		if (myBagType[i] == 'S') {
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			const Square& rSquare = *pSquare;
			rSquare.output(cout);
			rSquare.output(fout);
		}
		else if (myBagType[i] == 'R') {
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			const Rectangle& rRectangle = *pRectangle;
			rRectangle.output(cout);
			rRectangle.output(fout);
		}
		else if (myBagType[i] == 'T') {
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]); 
			const Triangle& rTriangle = *pTriangle;
			rTriangle.output(cout);
			rTriangle.output(fout);
		}
		else if (myBagType[i] == 'C') {
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			const Circle& rCircle = *pCircle;
			rCircle.output(cout);
			rCircle.output(fout);
		}
		else if (myBagType[i] == 'U') {
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]); 
			const Cube& rCube = *pCube;
			rCube.output(cout);
			rCube.output(fout);
		}
		else if (myBagType[i] == 'B') {
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]); 
			const Box& rBox = *pBox;
			rBox.output(cout);
			rBox.output(fout);
		}
		else if (myBagType[i] == 'Y') {
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			const Cylinder& rCylinder = *pCylinder;
			rCylinder.output(cout);
			rCylinder.output(fout);
		}
		else if (myBagType[i] == 'P') {
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			const Prism& rPrism = *pPrism;
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
			const Square* const s = reinterpret_cast<const Square*>(myBag[i]); // restore its "Movie-ness"
			delete s; // deallocate the Movie object at memory location myBag[i]
		}
		else if (myBagType[i] == 'R') {
			const Rectangle* const r = reinterpret_cast<const Rectangle*>(myBag[i]); // restore its "Movie-ness"
			delete r;
		}
		else if (myBagType[i] == 'T') {
			const Triangle* const t = reinterpret_cast<const Triangle*>(myBag[i]); // restore its "Movie-ness"
			delete t;
		}
		else if (myBagType[i] == 'C') {
			const Circle* const e = reinterpret_cast<const Circle*>(myBag[i]); // restore its "Movie-ness"
			delete e;
		}
		else if (myBagType[i] == 'U') {
			const Cube* const c = reinterpret_cast<const Cube*>(myBag[i]); // restore its "Movie-ness"
			delete c;
		}
		else if (myBagType[i] == 'B') {
			const Box* const b = reinterpret_cast<const Box*>(myBag[i]); // restore its "Movie-ness"
			delete b;
		}
		else if (myBagType[i] == 'Y') {
			const Cylinder* const y = reinterpret_cast<const Cylinder*>(myBag[i]); // restore its "Movie-ness"
			delete y;
		}
		else if (myBagType[i] == 'P') {
			const Prism* const p = reinterpret_cast<const Prism*>(myBag[i]); // restore its "Movie-ness"
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