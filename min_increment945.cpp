#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int index = 0;
        int count = 0;
        for(int i=1; i<A.size(); i++){
            if(A[i] >= A[index] + (i-index)){
                if(A[i] != A[index] + (i-index)){
                    index = i;
                }
            }
            else{
                count += A[index] + (i-index) - A[i];
            }
        }

        return count;
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().minIncrementForUnique(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
