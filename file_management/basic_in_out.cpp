/*
C++ has internal representation for a file
    We have objects that represent conections
    The datatype of these objects depends on the type of action that needs to be performed

    Input Files => ifstream object type
    OUtput Files => ofstream object type
*/

#include <iostream>
#include <fstream> //import classes for these objects

//Function to open a connection to input file stream
void openInputFile(std::ifstream &inFile)
{
    std::string filename;
    std::cout << " Enter Filename: ";
    std::cin >> filename;
    inFile.open(filename);
    while (!inFile) //Loop until unable to open file
    {
        inFile.clear(); //Clear flags from previous unsucceful attempts to open file
        std::cout << " File does not exist, renter file name: ";
        std::cin >> filename;
        inFile.open(filename);
    }
}

int main()
{
    //Lets write to a file
    std::ofstream outFile;          //1. We create an output file stream object for this purpose
    outFile.open("file.txt");       //2. We open a connection to a file on the storage system
    outFile << "This is a outfile"; //3. Write to the file
    outFile.close();                //4. We close the file, so that the lock can be released and other parts of the program can access the file

    //Lets read from the same file
    std::ifstream inFile;  //1. We create an input file stream object
    openInputFile(inFile); //2. We open a connection to this file via the ifstream object
    std::string data, word;
    while (inFile >> data) //3. We read a single word until EOF
    {
        std::cout << data << " ";
    }
    inFile.close();
}
