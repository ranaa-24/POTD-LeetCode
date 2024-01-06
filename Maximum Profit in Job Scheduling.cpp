class Solution
{
public:
    int dp[50001];
    int n;
    int nextJobIdx(vector<vector<int>> &jobs, int start, int target)
    {
        int end = n - 1;
        int res = n + 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (jobs[mid][0] >= target)
            {
                res = mid;
                end = mid - 1; // go left, we have to find the left most
            }
            else
            {
                start = mid + 1;
            }
        }

        return res;
    }

    int solve(vector<vector<int>> &jobs, int i)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        // take the job, so, add the profit and find nextJob to be get
        int take = jobs[i][2] + solve(jobs, nextJobIdx(jobs, i + 1, jobs[i][1]));
        int notTake = solve(jobs, i + 1);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = startTime.size();
        vector<vector<int>> jobs; //{s, e, p};

        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // sort acording to startTime.
        // comparator, by defalut its 0th idx we dont need to write a comparator
        auto comp = [&](auto &vec1, auto &vec2)
        {
            return vec1[0] <= vec2[0];
        };

        sort(jobs.begin(), jobs.end(), comp);

        return solve(jobs, 0);
    }
};