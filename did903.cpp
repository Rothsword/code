#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int numPermsDISequence(string S) {
        int len = S.length();
        if(len <= 1) return len;
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=len; i++){
            for(int j=0; j<=i; j++){
                if(S[i-1] == 'I'){
                    for(int k=j; k<i; k++) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= 1000000007;
                    }
                }
                else {
                    for (int k = 0; k<j; k++) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= 1000000007;
                    }
                }
            }
        }
        int ans = 0;
        for(auto val : dp[len]){
            ans += val;
            ans %= 1000000007;
        }

        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);

        int ret = Solution().numPermsDISequence(S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}