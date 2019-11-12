#include <iostream>
#include <vector>

using std::vector;

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n<=0) return 0;
        if(n==1) return nums[0];
        int max_val = 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n += 2;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int size=2; size<n; size++){
            for(int i=0; i+size<n; i++){
                int j = i + size;
                for(int k=i+1; k<j; k++){
                    dp[i][j] = max(dp[i][j],nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];

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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().maxCoins(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}