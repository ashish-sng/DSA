// 179. Largest Number

string largestNumber(vector<int>& nums) {
    vector<string> res;
    for (int i : nums) {
        res.push_back(to_string(i));
    }

    // Custom comparator
    sort(res.begin(), res.end(),
            [](const string& a, const string& b) { return a + b > b + a; });

    // Handle edge case: if largest number is "0"
    if (res[0] == "0")
        return "0";

    string ans = "";
    for (string s : res) {
        ans += s;
    }

    return ans;
}