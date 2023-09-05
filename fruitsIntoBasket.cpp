class Solution
{
public:
    int totalFruit(vector<int> &arr) // either basket 1 or basket 2 will get filled.
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (arr.size() == 1) // size of arr is 1 return 1
        {
            return 1;
        }

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
        if (mp.size() == 1) // if arr have same elements then return arr size
        {
            return arr.size();
        }
        return maxi;
    }
};
// https://leetcode.com/problems/fruit-into-baskets/