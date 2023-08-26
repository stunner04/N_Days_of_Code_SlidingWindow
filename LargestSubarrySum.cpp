#include <bits/stdc++.h>
using namespace std;
// for positive array only
// for negative array we use hashmap with prefixSum
int largestWindowSumInSubarray(vector<int> &v, int givenSum)
{
    int i = 0, j = 0, currSum = 0, maxWindowSize = INT_MIN;

    while (j < v.size())
    {
        currSum += v[j];
        if (currSum < givenSum)
        {
            j++;
        }
        else if (currSum == givenSum)
        {
            maxWindowSize = max(maxWindowSize, j - i + 1);
            j++;
        }
        else if (currSum > givenSum)
        {
            while (currSum > givenSum)
            {
                currSum -= v[i];
                i++;
                if (currSum == givenSum)
                {
                    maxWindowSize = max(maxWindowSize, j - i + 1);
                }
            }
            j++;
        }
    }
    return maxWindowSize;
}

int main()
{
    vector<int> v{4, 1, 1, 1, 2, 3, 5};
    int sum = 5;
    cout << largestWindowSumInSubarray(v, sum);
    return 0;
}

// https : // www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505?leftPanelTab=0

// int countOfDivisiblePairs(int n, int m)
// {

//     // Variable to store the count of pairs.
//     int count = 0;

//     // X[i] stores the count of x such that x % 5 == i
//     int x = n / 5;
//     vector<int> X(5, x);
//     n %= 5;
//     int curX = 1;
//     while (n > 0)
//     {
//         X[curX]++;
//         curX++;
//         n--;
//     }

//     // Y[i] stores the count of y such that y % 5 == i
//     int y = m / 5;
//     vector<int> Y(5, y);
//     m %= 5;
//     int curY = 1;
//     while (m > 0)
//     {
//         Y[curY]++;
//         curY++;
//         m--;
//     }

//     count += X[0] * Y[0];

//     for (int i = 1; i < 5; i++)
//     {
//         count += X[i] * Y[5 - i];
//     }

//     return count;
// }
