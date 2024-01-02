vector<vector<int>> findMatrix(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int freq = mp[nums[i]]; // curr freq of the element
        if (freq == ans.size())
        {                      // if freq is same as row numbers then we need add a bew row to add this elemnt
            ans.push_back({}); // an empty row is added
        }
        ans[freq].push_back(nums[i]); // push it in the freq'th row
        mp[nums[i]]++;                // update freq of the element
    }
    return ans;
}