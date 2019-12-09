#include <iostream>

using namespace std;

int count(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
    return 0;
}

int main(){
    string s = "12345678";
    cout<<s.substr(6,1)<<endl;

}
