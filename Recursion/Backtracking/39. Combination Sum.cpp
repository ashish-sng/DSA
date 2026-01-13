// 39. Combination Sum

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> currPath;
    void backtrack(vector<int>& candidates, int target, int index,
                   int sum = 0) {
        if (sum > target || index >= candidates.size())
            return;

        if (sum == target) {
            ans.push_back(currPath);
            return;
        }

        currPath.push_back(candidates[index]);
        backtrack(candidates, target, index, sum + candidates[index]);
        currPath.pop_back();

        backtrack(candidates, target, index + 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, 0);
        return ans;
    }
};