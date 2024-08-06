class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> mp;
        for (auto c : word)
        {
            mp[c]++;
        }
        vector<int> v;
        for (auto p : mp)
        {
            v.push_back(p.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        int cnt = 0;
        for (auto p : v)
        {
            cnt++;
            if (cnt <= 8)
            {
                ans += 1 * p;
            }
            else if (cnt <= 16)
            {
                ans += 2 * p;
            }
            else if (cnt <= 24)
            {
                ans += 3 * p;
            }
            else
            {
                ans += 4 * p;
            }
        }
        return ans;
    }
};