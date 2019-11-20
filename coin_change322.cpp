#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include "limits.h"
using namespace std;

class Solution {
private:
    int coinChange(vector<int>& coins, int amount, vector<int>& dict) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dict[amount-1] != 0) return dict[amount-1];
        int min_num = INT32_MAX;
        for(int i=0; i<coins.size(); i++){
            int remain = amount-coins[i];
            int number = coinChange(coins, remain, dict);
            if(number == -1) continue;
            else{
                number += 1;
                if(number < min_num) min_num = number;
            }
        }

        if(min_num == INT32_MAX) min_num = -1;
        dict[amount-1] = min_num;
        return min_num;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dict(amount, 0);
        int n = coins.size();
        if(n <=0) return -1;
        return coinChange(coins, amount, dict);
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);

        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}