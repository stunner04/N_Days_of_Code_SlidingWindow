#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{2, 5, 1, 8, 2, 9, 1};
    int k = 3;
    int i = 0, j = 0, sum = 0, maxi = INT_MIN;

    while (j < v.size())
    {
        sum += v[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            sum -= v[i];
            i++;
            j++;
        }
    }

    cout << " Max value" << maxi << endl;

    return 0;
}
