//
// Created by DAWEI LI on 2019/11/14.
//
#include <iostream>
#include <vector>
using namespace std;

typedef

class Solution {
private: int mod = 1000000000 + 7;
public:
    int checkRecord(int n) {
        if(n<=0) return 0;
        if(n==1) return 3;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        dp[3] = 7;
        for(int i=4; i<=n; i++){
            dp[i] = (2*dp[i-1] - dp[i-4]) % mod;
        }
        int sum = dp[n];
        for(int i=1; i<=n; i++){
            sum += (dp[i-1] * dp[n-i]) % mod;
        }

        return sum % mod;
    }
};

int stringToInteger(string input) {
        return stoi(input);
}

int main() {
        string line;
        while (getline(cin, line)) {
                int n = stringToInteger(line);

                int ret = Solution().checkRecord(n);

                string out = to_string(ret);
                cout << out << endl;
        }
        return 0;
}