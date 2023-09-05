class Solution
{
public:
    int totalFruit(vector<int> &arr)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0, j = 0, maxi = 0;
        map<int, int> mp;
        mp.clear();

        while (j < arr.size())
        {
            mp[arr[j]]++;

            if (mp.size() == 2)
            {
                maxi = max(maxi, j - i + 1);
            }
            else if (mp.size() > 2)
            {
                while (mp.size() > 2)
                {
                    mp[arr[i]]--;
                    if (mp[arr[i]] == 0)
                    {
                        mp.erase(arr[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};

//https://leetcode.com/problems/fruit-into-baskets/