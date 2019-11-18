#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len,vector<int>(len+1,0)));
        for(int i = 0;i<len;i++){
            for(int k = i+1;k<=len;k++){
                dp[i][i][len-k] = (len-k+1)*(len-k+1);
            }
        }
        for(int p = 1; p<=len-1; p++){
            for(int i=0; i+p<len; i++){
                for(int k=0; k<=len-p-i; k++){
                    if(boxes[p+i] == boxes[p+i-1]){
                        dp[i][p+i][k] = dp[i][i+p-1][k+1];
                    }
                    else{
                        dp[i][i+p][k] = dp[i][i+p-1][0]+(k+1)*(k+1);
                        for(int m=i;m<i+p-1;m++){
                            if(boxes[m] == boxes[i+p]){
                                dp[i][i+p][k] = max(dp[i][i+p][k],dp[i][m][k+1]+dp[m+1][i+p-1][0]);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][len-1][0];
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
        vector<int> boxes = stringToIntegerVector(line);

        int ret = Solution().removeBoxes(boxes);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
