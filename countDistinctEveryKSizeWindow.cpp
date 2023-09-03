#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    vector<int> ans;
    int i = 0, j = 0;
    unordered_map<int, int> freq;
    freq.clear();

    while (j < arr.size())
    {
        freq[arr[j]]++;

        if (j - i + 1 == k)
        {
            ans.push_back(freq.size());
            freq[arr[i]]--;
            if (freq[arr[i]] == 0)
            {
                freq.erase(arr[i]);
            }
            i++;
        }
        j++;
    }
    return ans;
}

//https://www.codingninjas.com/studio/problems/count-distinct-element-in-every-k-size-window_920336?leftPanelTab=0