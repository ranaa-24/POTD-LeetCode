// YT - Nukhil Lohia
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int maxIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i] > dp[maxIdx])
            maxIdx = i;
    }

    return dp[maxIdx];
}