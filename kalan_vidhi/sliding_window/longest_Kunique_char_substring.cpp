//Description: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int i = 0, j = 0, max = -1;
    map<char, int> unique_map;
    string s = "aaaa";
    int k = 2;

    while (j < s.size())
    {
        while (unique_map.size() > k)
        {
            if (unique_map[s[i]] == 1)
                unique_map.erase(s[i]);
            else
                unique_map[s[i]]--;
            i++;
        }

        unique_map[s[j]]++;
        if (unique_map.size() == k && (j - i + 1) > max)
            max = j - i + 1;
        j++;
    }
    cout << max;
}