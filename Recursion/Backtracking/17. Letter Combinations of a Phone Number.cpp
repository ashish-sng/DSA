// 17. Letter Combinations of a Phone Number

class Solution {
public:
    vector<string> ans;
    string curr;

    vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int index) {
        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mapping[digit];

        for (char ch : letters) {
            curr.push_back(ch);
            backtrack(digits, index + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return ans;
        backtrack(digits, 0);
        return ans;
    }
};