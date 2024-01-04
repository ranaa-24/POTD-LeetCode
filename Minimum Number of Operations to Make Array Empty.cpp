int minOperations(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[i]++;
    }
    int ans = 0;
    for (auto &it : mp)
    {
        int freq = it.second;
        if (freq == 1)
            return -1;
        ans += (freq / 3); // take some exaple and observe
        if (freq % 3)
            ans++
    }
    return ans;
}