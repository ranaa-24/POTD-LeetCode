class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<long, int> map[n]; // array of maps :)
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - nums[j];
                auto it = map[j].find(diff);
                int count_at_j;
                if (it == end(map[j]))
                    count_at_j = 0;
                else
                    count_at_j = it->second;

                map[i][diff] += count_at_j + 1;

                ans += count_at_j;
            }
        }

        return ans;
    }
};