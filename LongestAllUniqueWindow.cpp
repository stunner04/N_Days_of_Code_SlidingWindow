#include <bits/stdc++.h>
using namespace std;

// using the frame size (j-i+1)  // but TLE
int lengthOfLongestSubstring(string s)
{
    int i = 0, j = 0, maxWindowAllUnique = 1;
    map<char, int> freq;
    freq.clear();

    while (j < s.length())
    {
        freq[s[j]]++;
        if (freq.size() == j - 1 + 1)
        {
            maxWindowAllUnique = max(maxWindowAllUnique, j - i + 1);
            j++;
        }
        else if (freq.size() < j - i + 1)
        {
            while (freq.size() < j - i + 1)
            {
                freq[s[i]]--;
                if (freq[s[i]] == 0)
                {
                    freq.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxWindowAllUnique;
}

// using count variable
int lengthOfLongestSubstring(string s)
{
    int i = 0, j = 0, maxWindowAllUnique = 1, count = 0;
    map<char, int> freq;
    freq.clear();

    while (j < s.length())
    {
        freq[s[j]]++;
        count++;
        if (freq.size() == count)
        {
            maxWindowAllUnique = max(maxWindowAllUnique, j - i + 1);
            j++;
        }
        else if (freq.size() < count)
        {
            while (freq.size() < count)
            {
                freq[s[i]]--;
                count--;
                if (freq[s[i]] == 0)
                {
                    freq.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxWindowAllUnique;
}

int main()
{
    return 0;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

