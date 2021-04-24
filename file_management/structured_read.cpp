#include <fstream>
#include <iostream>
#include <vector>

void read_input_file(std::ifstream &inFile)
{
    inFile.open("structured_input.txt");
    if (!inFile)
    {
        std::cout << "File not found";
        exit(1);
    }
}

int main()
{
    std::ifstream inFile;
    read_input_file(inFile);
    struct Student
    {
        int id;
        int age;
        std::string fullname;
    } st;

    std::vector<Student> v;
    while (inFile >> st.id)
    {
        inFile >> st.age;
        inFile.ignore(256, ' ');
        std::getline(inFile, st.fullname);
        v.push_back(st);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].age > 20)
        {
            std::cout << "Age:" << v[i].age << "  Name:" << v[i].fullname << std::endl;
        }
    }
    return 0;
}