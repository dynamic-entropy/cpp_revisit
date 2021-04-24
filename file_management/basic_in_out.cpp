/*
C++ has internal representation for a file
    We have objects that represent conections
    The datatype of these objects depends on the type of action that needs to be performed

    Input Files => ifstream object type
    OUtput Files => ofstream object type
*/

#include <fstream> //import classes for these objects

int main()
{
    //Lets write to a file
    std::ofstream outFile;          //1. We create an output file stream object for this purpose
    outFile.open("output.txt");     //2. We open a connection to a file on the storage system
    outFile << "This is a outfile"; //3. Write to the file
    outFile.close();                //4. We close the file, so that the lock can be released and other parts of the program can access the file
}
