//Problem Description: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> ia;
    if (s.size() < p.size())
        return ia;

    unordered_map<char, int> pmap, smap;
    for (char c : p)
        pmap[c]++;

    for (int i = 0; i < p.size(); i++)
    {
        if (pmap.find(s[i]) != smap.end())
            smap[s[i]]++;
        if (smap == pmap)
        {
            ia.push_back(0);
        }
    }

    for (int i = p.size(); i < s.size(); i++)
    {
        //rempve first element
        if (pmap.find(s[i - p.size()]) != smap.end())
            smap[s[i - p.size()]]--;

        //add last element
        if (pmap.find(s[i]) != smap.end())
            smap[s[i]]++;

        if (smap == pmap)
            ia.push_back(i - p.size() + 1);
    }
    return ia;
}

int main()
{
    string s = "abab", p = "ab";
    vector<int> v = findAnagrams(s, p);
    for (int x : v)
        cout << x << "  ";

    return 0;
}