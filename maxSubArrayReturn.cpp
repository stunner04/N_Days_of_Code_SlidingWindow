#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    deque<int> q;
    int i = 0, j = 0;
    vector<int> res;
    while (j < n)
    {
        while (!q.empty() && q.back() < arr[j])
            q.pop_back();
        q.push_back(arr[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            res.push_back(q.front());
            if (q.front() == arr[i])
                q.pop_front();
            i++;
            j++;
        }
    }
    return res;
}

vector<int> maximumInAllSubarraysOfSizeK(vector<int> arr, int n, int k)
{
    int i = 0, j = 0, maxi = INT_MIN;
    vector<int> ans;

    while (j < n)
    {
        maxi = max(maxi, arr[j]);
        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            ans.push_back(maxi);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v{-1, -1, -1, -1, -1};
    cout << "Maximum of all subarrays with size K: ";
    for (auto x : maximumInAllSubarraysOfSizeK(v, 3))
    {
        cout << x << " ";
    }
    return 0;
}

https://www.codingninjas.com/studio/problems/maximum-of-all-subarrays-of-size-k_1071161