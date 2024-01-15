class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> mp;
        vector<vector<int>> ans(2); // ans[0] -> 0 losses        ans[1] -> 1 lose

        // populate the map according to losers
        for (int i = 0; i < matches.size(); i++)
        {
            mp[matches[i][1]]++;
        }

        for (int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            // check is winner never lose
            if (mp.find(winner) == mp.end())
            {
                ans[0].push_back(winner);
                mp[winner] = 2; // to ignoring the duplicate, 2 val cos, if we put 1 then it may come in ocne lose list
            }

            // check if loser one lost only once
            if (mp[loser] == 1)
                ans[1].push_back(loser);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};