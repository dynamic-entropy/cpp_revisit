//Description: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> inArr = {12, -1, -7, 8, -15, 30, 16, 28}, solArr;
    int k = 3, neg_pos = -1;

    for (int i = inArr.size() - k; i < inArr.size(); i++)
    {
        if (inArr[i] < 0)
        {
            neg_pos = i;
            solArr.push_back(inArr[neg_pos]);
            break;
        }
    }

    if (neg_pos == -1)
        solArr.push_back(0);

    for (int i = inArr.size() - k - 1; i >= 0; i--)
    {
        if (inArr[i] < 0)
            neg_pos = i;

        if (neg_pos >= i && neg_pos < i + k)
            solArr.push_back(inArr[neg_pos]);

        else
            solArr.push_back(0);
    }

    reverse(solArr.begin(), solArr.end());
    for (int x : solArr)
        cout << x << " ";

    return 0;
}