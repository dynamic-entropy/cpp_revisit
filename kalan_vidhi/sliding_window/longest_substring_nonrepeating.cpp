#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int j = 0, i = 0, maxx = 0;
    unordered_set<char> char_set;
    string s = "abcabcbb";

    while (j < s.size())
    {
        if (char_set.find(s[j]) == char_set.end())
        {
            char_set.insert(s[j++]);
            maxx = maxx > char_set.size() ? maxx : char_set.size();
        }

        else
            char_set.erase(s[i++]);
    }
    cout << maxx;
    return 0;
}