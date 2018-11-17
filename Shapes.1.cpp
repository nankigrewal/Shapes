#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include<cmath>
#include<cstdlib>

#include "iShapes.h"


//Prototype for string parsing function
vector<string> parseString(string);

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
	vector<const Shape*> myBag;
	vector<int> myBagType;
	
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
			myBag.push_back(sq);
			myBagType.push_back(1);
		}
		else if (tokens.at(0) == "RECTANGLE") {
			const Rectangle* const rec = new Rectangle(tokens);
			myBag.push_back(rec);
			myBagType.push_back(2);
		}
		else if (tokens.at(0) == "TRIANGLE") {
			const Triangle* const tri = new Triangle(tokens);
			myBag.push_back(tri);
			myBagType.push_back(3);
		}
		else if (tokens.at(0) == "CIRCLE") {
			const Circle* const cir = new Circle(tokens);
			myBag.push_back(cir);
			myBagType.push_back(4);
		}
		else if (tokens.at(0) == "CUBE") {
			const Cube* const cube = new Cube(tokens);
			myBag.push_back(cube);
			myBagType.push_back(5);
		}
		else if (tokens.at(0) == "BOX") {
			const Box* const box = new Box(tokens);
			myBag.push_back(box);
			myBagType.push_back(6);
		}
		else if (tokens.at(0) == "CYLINDER") {
			const Cylinder* const cyl = new Cylinder(tokens);
			myBag.push_back(cyl);
			myBagType.push_back(7);
		}
		else if (tokens.at(0) == "PRISM") {
			const Prism* const pri = new Prism(tokens);
			myBag.push_back(pri);
			myBagType.push_back(8);
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
		if (myBagType[i] == 1) {
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			const Square& rSquare = *pSquare;
			pSquare->outputSquareCalculation(cout);
		}
		else if (myBagType[i] == 2) {
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			const Rectangle& rRectangle = *pRectangle;
			pRectangle->outputRectangleCalculation(cout);
		}
		else if (myBagType[i] == 3) {
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]); 
			const Triangle& rTriangle = *pTriangle;
			pTriangle->outputTriangleCalculation(cout);
		}
		else if (myBagType[i] == 4) {
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			const Circle& rCircle = *pCircle;
			pCircle->outputCircleCalculation(cout);
		}
		else if (myBagType[i] == 5) {
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]); 
			const Cube& rCube = *pCube;
			pCube->outputCubeCalculation(cout);
		}
		else if (myBagType[i] == 6) {
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]); 
			const Box& rBox = *pBox;
			pBox->outputBoxCalculation(cout);
		}
		else if (myBagType[i] == 7) {
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			const Cylinder& rCylinder = *pCylinder;
			pCylinder->outputCylinderCalculation(cout);
		}
		else if (myBagType[i] == 8) {
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			const Prism& rPrism = *pPrism;
			pPrism->outputPrismCalculation(cout);
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
		if (myBagType[i] == 1) {
			const Square* const s = reinterpret_cast<const Square*>(myBag[i]); 
			delete s; 
		}
		else if (myBagType[i] == 2) {
			const Rectangle* const r = reinterpret_cast<const Rectangle*>(myBag[i]); 
			delete r;
		}
		else if (myBagType[i] == 3) {
			const Triangle* const t = reinterpret_cast<const Triangle*>(myBag[i]); 
			delete t;
		}
		else if (myBagType[i] == 4) {
			const Circle* const e = reinterpret_cast<const Circle*>(myBag[i]); 
			delete e;
		}
		else if (myBagType[i] == 5) {
			const Cube* const c = reinterpret_cast<const Cube*>(myBag[i]); // restore its "Movie-ness"
			delete c;
		}
		else if (myBagType[i] == 6) {
			const Box* const b = reinterpret_cast<const Box*>(myBag[i]); 
			delete b;
		}
		else if (myBagType[i] == 7) {
			const Cylinder* const y = reinterpret_cast<const Cylinder*>(myBag[i]); 
			delete y;
		}
		else if (myBagType[i] == 8) {
			const Prism* const p = reinterpret_cast<const Prism*>(myBag[i]); 
			delete p;
		}
	}

	//Keep console open and return 0 to main function
	system("PAUSE");
	return 0;
}