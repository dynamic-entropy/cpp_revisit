#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Aim - find if the list/vector contains a odd and even number

//find_if searches for an element for which predicate p returns true
//it returns iterator to first element that satisfies the predicate
//it returns iterator to last if no element satisfies the given predicate

int main()
{
    vector<int> vec = {5, 13, 3, 5, 21, 21};

    //we use lambas as predicates where each returns true when value is even and odd respectively
    auto even_num_present = find_if(vec.begin(), vec.end(), [](int val) { return val % 2 == 0; });
    auto odd_num_present = find_if(vec.begin(), vec.end(), [](int val) { return val % 2 == 1; });

    //we check if the value returned is not the end iterator and print accordingly
    if (even_num_present != vec.end())
        cout << "Even number present = " << *even_num_present << endl;
    if (odd_num_present != vec.end())
        cout << "Odd number present = " << *odd_num_present << endl;
}