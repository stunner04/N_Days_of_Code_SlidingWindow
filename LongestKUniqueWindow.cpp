#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int kUniqueChar, string &s)
{
    int i = 0, j = 0, maxWindowUnique = INT_MIN;
    // int maxWindowUnique = 0;
    unordered_map<char, int> freq;
    freq.clear();

    while (j < s.length())
    {
        freq[s[j]]++;

        if (freq.size() < kUniqueChar)
        {
            j++;
        }
        else if (freq.size() == kUniqueChar)
        {
            maxWindowUnique = max(maxWindowUnique, j - i + 1);
            j++;
        }
        else if (freq.size() > kUniqueChar)
        {
            while (freq.size() > kUniqueChar)
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
    return maxWindowUnique;
}

int main()
{
    string s1 = "aabacbebebe";
    string s2 = "aaaaaaaa";
    string s3 = "uvtptxgtckttipjpnewpc";
    cout << kDistinctChars(3, s1) << "\n";  // 7
    cout << kDistinctChars(3, s2) << "\n";  // 8
    cout << kDistinctChars(17, s3) << "\n"; // 21
    return 0;
}

// TC = O(N) SC = O(N)
// https://www.codingninjas.com/studio/problems/distinct-characters_2221410?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1