// Question Link - https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1

// #Solution
class Solution {
  public:
    string encode(vector<string>& arr) {
        // write your logic to encode the strings
        string encodedString = "";
        for(auto& str : arr){
            encodedString += to_string(str.size()) + "/:" + str;
        }

        return encodedString;
    }

    vector<string> decode(string& s) {
        // write your logic to decode the string
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int delimiterIndex = s.find("/:", i);
            
            string lenStr = s.substr(i, delimiterIndex - i);
            int len = stoi(lenStr);
            string str = s.substr(delimiterIndex + 2, len);
            res.push_back(str);
            i = delimiterIndex + 2 + len;
        }
        
        return res;
    }
};