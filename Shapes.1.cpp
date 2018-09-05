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

int main() {

	//Programmer info
	cout << "Programmer : Nanki Grewal\nProgrammer ID: 1428278" << endl;
	cout << "File: " << __FILE__ << endl;

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
		//Check for whether the line is empty
		if (input == "")
			continue;

		//Parse the string using the parseString function, store in vector
		vector<string> tokens = parseString(input);

		//The following conditional tests for what type of object is specified, then it calculates and outputs desired values
		if (tokens.at(0) == "SQUARE") {
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			side = atof(tokens.at(1).c_str());

			//Calculate area and perimeter using geometric formulas
			area = side * side;
			perimeter = side * 4.0;

			//Output the data to the console and an output file
			cout << tokens.at(0) << " side = " << side << ", area = " << area << ", perimeter = " << perimeter << endl;
			fout << tokens.at(0) << " side = " << side << ", area = " << area << ", perimeter = " << perimeter << endl;
		}
		else if (tokens.at(0) == "RECTANGLE") {
			//Length and width values needed
			tokens.resize(3, "0");
			//Convert strings to doubles
			length = atof(tokens.at(1).c_str());
			width = atof(tokens.at(2).c_str());

			//Calculate area and perimeter using geometric formulas
			area = length * width;
			perimeter = 2.0 * (length + width);

			//Output the data to the console and an output file
			cout << tokens.at(0) << " length = " << length << ", width = " << width << ", area = " << area << ", perimeter = " << perimeter << endl;
			fout << tokens.at(0) << " length = " << length << ", width = " << width << ", area = " << area << ", perimeter = " << perimeter << endl;
		}
		else if (tokens.at(0) == "TRIANGLE") {
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			side = atof(tokens.at(1).c_str());

			//Calculate area and perimeter using geometric formulas
			area = sqrt(3) / 4 * side * side;
			perimeter = length * 3.0;

			//Output the data to the console and an output file
			cout << tokens.at(0) << " side = " << side << ", area = " << area << ", perimeter = " << perimeter << endl;
			fout << tokens.at(0) << " side = " << side << ", area = " << area << ", perimeter = " << perimeter << endl;
		}
		else if (tokens.at(0) == "CIRCLE") {
			// Radius value needed
			tokens.resize(2, "0");
			//Convert string to double
			radius = atof(tokens.at(1).c_str());

			//Calculate area and perimeter using geometric formulas
			area = pi * radius * radius;
			perimeter = 2.0 * pi * radius;

			//Output the data to the console and an output file
			cout << tokens.at(0) << " radius = " << radius << ", area = " << area << ", perimeter = " << perimeter << endl;
			fout << tokens.at(0) << " radius = " << radius << ", area = " << area << ", perimeter = " << perimeter << endl;
		}
		else if (tokens.at(0) == "CUBE") {
			//Side value needed
			tokens.resize(2, "0");
			//Convert string to double
			side = atof(tokens.at(1).c_str());

			//Calculate surface area and volume using geometric formulas
			surfaceArea = 6.0 * side * side;
			volume = side * side * side;

			//Output the data to the console and an output file
			cout << tokens.at(0) << " Side = " << side << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
			fout << tokens.at(0) << " Side = " << side << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
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

			//Output the data to the console and an output file
			cout << tokens.at(0) << " length = " << length << ", width = " << width << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
			fout << tokens.at(0) << " length = " << length << ", width = " << width << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
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

			//Output the data to the console and an output file
			cout << tokens.at(0) << " radius = " << radius << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
			fout << tokens.at(0) << " radius = " << radius << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
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

			//Output the data to the console and an output file
			cout << tokens.at(0) << " side = " << side << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
			fout << tokens.at(0) << " side = " << side << ", height = " << height << ", surface area = " << surfaceArea << ", volume = " << volume << endl;
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