#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i] = nums[i];
        }
        for(int size=1; size<n; size++){
            for(int i=0; i+size<n; i++){
                int j = i+size;
                dp[i][j] = max((nums[j] - dp[i][j-1]), (nums[i] - dp[i+1][j]));
            }
        }

        return dp[0][n-1]>=0;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().PredictTheWinner(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}