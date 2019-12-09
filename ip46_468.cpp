#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {

        if(IP.find(".")!=string::npos){
            if(check_ipv4(IP)) return "IPv4";
        }

        if(IP.find(":")!=string::npos){
            if(check_ipv6(IP)) return "IPv6";
        }

        return "Neither";
    }
private:
    bool check_ipv4(string s){
        if(s[s.length()-1] == '.') return 0;
        int count = 0;
        for(int i=0, j=0; j<s.length();j++){
            if(s[j] == '.' || j==s.length()-1){
                if(j==s.length()-1) j = s.length();
                if(j-i > 3) return 0;
                if(!validate_4(s.substr(i, j-i))){
                    return 0;
                }
                i = j+1;
                count +=1;
            }
        }

        if(count != 4) return 0;

        return 1;
    }

    bool check_ipv6(string s){
        if(s[s.length()-1] == ':') return 0;
        int count = 0;
        for(int i=0, j=0; j<s.length();j++){
            if(s[j] == ':' || j==s.length()-1){
                if(j==s.length()-1) j = s.length();
                if(j-i > 4) return 0;
                if(!validate_6(s.substr(i, j-i))){
                    return 0;
                }
                i = j+1;
                count +=1;
            }
        }

        if(count != 8) return 0;

        return 1;
    }

    bool validate_4(string s){
        if(s.length()==0) return 0;
        if(s[0] == '0' && s.length()>1){
            return 0;
        }
        int num = 0;
        for(int i=0; i<s.length(); i++){
            num = num*10+(s[i] - '0');
        }
        if(num<=255 && num>=0) return 1;
        return 0;
    }

    bool validate_6(string s){
        if(s.length()==0) return 0;
        if(s.length() > 4) return 0;
        string k = "0123456789ABCDEF";
        for(int i=0; i<s.length(); i++){
            if(k.find(toupper(s[i]))==string::npos) return 0;
        }

        return 1;

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
        string IP = stringToString(line);

        string ret = Solution().validIPAddress(IP);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}