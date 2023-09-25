#include "FileIOExamples.h"
#include <iostream>
#include <string>
#include <fstream> //This is the module needed to read and write to files 
//ifstream(ussed for reading data from a file stream) >>
//and ofstream << (for writing data from a file stream)
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void FileIOExamples::readData()
{



	ifstream inputFile; //file handling object

	string fileName; //name of the file desired to search

	int numValues;

	double value, total = 0.0;

	//prompt the user for enter the name of the file they wish to use 
	cout << "This Program Reads the sums of the values in the data file\nEnter The Name of the file to read from: ";
	cin >> fileName;


	//open the file 
	//****ENSURE THE FILE IS ON THE SAME LEVEL AND AREA THAT YOU WANT TO OPEN, EVEN IF YOU CLICK AND ADD IT THROUGH EXISTING ITEMS AND DOWNLOADS 
	//*** THEY MUST BE IN THE SAME LOCATION 
	inputFile.open(fileName);
	//check if the input file is valid and exists 
	if (!inputFile) { //stream inputfile has an error condition

		cout << endl << "File Handling Error: " << fileName << " File Not Found\n";
		exit(-1); //give the exit function a exit code, The error code number can be whatever you decide

	}

	cout << "How Many Values are stored in the file?: ";

	cin >> numValues;

	cout << "\n";
	for (int count = 1; count <= numValues; count++) {

		inputFile >> value;

		cout << "Current Value: " << value << endl;


		total += value;
	}

	cout << "\nThe Total of the " << numValues << " Values is " << total << endl;

	//Close the File
	inputFile.close();

}





void FileIOExamples::writeData()
{
	


	ofstream outputFile;

	string fileName; //name of the file desired to search

	int i = 0;

	cout << "Enter the name of the file you wish to write to: ";

	cin >> fileName;

	outputFile.open(fileName); //open the file the user has said they want to open

	//error Handling
	if (!outputFile) {

		cout << endl << "File Handling Error: " << fileName << " File Not Found\n";
		exit(-1); //give the exit function a exit code, The error code number can be whatever you decide

	}

	//get input from the user
	string outputText;

	
	while (i < 10) {

		

		cout << "What Would You Like To Type?: ";

		cin >> outputText;

		outputFile << outputText << endl;

		i++;

	}

	outputFile.close();


}





void FileIOExamples::writeRandomDataArray()
{
	//Random Number Generator Variables 

	int maxValue, minValue;


	ofstream outputFile;

	string fileName; //name of the file desired to search

	int i = 0, rNumber;

	cout << "Enter the name of the file you wish to write to: ";

	cin >> fileName;

	outputFile.open(fileName); //open the file the user has said they want to open

	//error Handling
	if (!outputFile) {

		cout << endl << "File Handling Error: " << fileName << " File Not Found\n";
		exit(-1); //give the exit function a exit code, The error code number can be whatever you decide

	}

	//get input from the user
	string outputText;
	
	srand(time(0));

	while (i < 10) {

		//Generate A Random Number
		rNumber = rand();
		
		outputFile << rNumber << endl;

		i++;

	}

	outputFile.close();


}






void FileIOExamples::calcTotal()
{

	ifstream inputFile;

	string fileName = "myNumbers.txt";

	inputFile.open(fileName);

	//Error Checking 
	if (!inputFile) {

		cout << endl << "File Handling Error:" << fileName <<  "File Not Found\n";
		exit(-1); //give the exit function a exit code, The error code number can be whatever you decide

	}

	int i = 0,total = 0;

	//Array For Integers
	int numbersRead[10];
	while (i < 10) {

		//Generate A Random Number

		//Assign the current index of numbers read to the generated random number in the text file, according to the index
		inputFile >> numbersRead[i];

		//Add to the running total the current index value of the random numbers 
		total += numbersRead[i];

		i++;

	}

	cout << "\nTotal Of the Random Numbers is: " << total << endl;

	inputFile.close();
}
