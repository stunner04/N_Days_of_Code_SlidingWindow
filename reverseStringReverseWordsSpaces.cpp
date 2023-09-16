#include <bits/stdc++.h>

string trim(string s)
{
    int left = 0, right = s.length() - 1;

    // Trim leading spaces
    while (left <= right && s[left] == ' ')
    {
        left++;
    }

    // Trim trailing spaces
    while (right >= left && s[right] == ' ')
    {
        right--;
    }

    // Construct the trimmed string
    return s.substr(left, right - left + 1);
}

string reverseString(string &str)
{

    reverse(str.begin(), str.end());

    int i = 0, j = 0;

    while (j < str.length())
    {
        if (str[j] == ' ')
        {
            reverse(str.begin() + i, str.begin() + j);
            j++;
            i = j;
        }
        else
        {
            j++;
        }
    }
    reverse(str.begin() + i, str.begin() + j); // last word

    return trim(str);
}