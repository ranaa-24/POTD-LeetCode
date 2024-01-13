int minSteps(string s, string t)
{
    unordered_map<char, int> mp;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        mp[t[i]]--;
    }

    // we will take the difference of the element,we only care which element in t has more number of element to change
    for (auto it : mp)
    {
        if (it.second > 0)
            ans += it.second;
    }
    return ans;
}