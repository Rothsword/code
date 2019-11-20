#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restoreIpAddresses(s, res, 4, "");
        return res;
    }

private:
    void restoreIpAddresses(string s, vector<string>& res, int len, string new_s){
        if(len == 0 && s.length()==0){
            res.push_back(new_s);
        }
        else if(len == 0 && s.length() != 0) return;
        for(int i=1; i<=3; i++){
            string t = new_s;
            if(i<=s.length() && check_valid(s.substr(0,i))){
                t.append(s.substr(0,i));
                if(len > 1){
                    t.append(".");
                }
                restoreIpAddresses(s.substr(i, s.length()-i), res, len-1, t);
            }
        }
    }

private:
    bool check_valid(string s){
        if(s[0] != '0' || s.length()==1){
            int sum = 0;
            for(int i=0; i<s.length(); i++){
                sum = sum*10 + s[i]-'0';
            }
            if(sum >=0 && sum <=255){
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<string> res = solution->restoreIpAddresses("25525511135");
    for(auto item : res){
        cout<<item<<endl;
    }
    return 0;
}
