int findContentChildren(vector<int> &g, vector<int> &s)
{
    // sort both array so that max sixe cookie can be given to max greedy child
    sort(g.begin(), g.end(), greater<int>()); // children
    sort(s.begin(), s.end(), greater<int>()); // cookies

    int child = 0, cookie = 0;
    int ans = 0;
    while (cookie < s.size() && child < g.size())
    {
        if (g[child] <= s[cookie])
        { // can be given
            ans++;
            child++;
            cookie++;
        }
        else
        {
            child++; // cant be given check for other children
        }
    }

    return ans;
}