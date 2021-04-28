//Description: https://www.interviewbit.com/problems/sliding-window-maximum/#

#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B)
{
    int i = 0, j = 0;
    list<int> max_list;
    vector<int> sol;

    while (j < A.size())
    {
        while (!max_list.empty() && max_list.back() < A[j])
            max_list.pop_back();
        max_list.push_back(A[j]);

        if (!(j - i < B - 1))
        {
            sol.push_back(max_list.front());
            if (max_list.front() == A[i])
                max_list.pop_front();
            i++;
        }
        j++;
    }

    if (A.size() < B)
        return vector<int>{max_list.front()};

    return sol;
}

int main()
{
    vector<int> A = {648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};
    int B = 9;

    vector<int> ans = slidingMaximum(A, B);
    cout << "Solution: ";
    for (int x : ans)
        cout << x << "\t";
}
