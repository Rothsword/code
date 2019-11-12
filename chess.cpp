#include<iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll path_num(int a, int b, int x, int y){
    vector<vector<ll> > dp(a+1,vector<ll>(b+1));

    for(int i=a; i>=0; i--){
        for(int j=b; j>=0; j--){
            if(i+1 > a && j+1 >b) dp[i][j] = 1;
            else if(i+1 > a) dp[i][j] = dp[i][j+1];
            else if(j+1 > b) dp[i][j] = dp[i+1][j];
            else dp[i][j] = dp[i+1][j] + dp[i][j+1];

            if((abs(i-x)==1 && abs(j-y)==2) || (abs(i-x)==2 && abs(j-y)==1) || (i==x && j==y)){
                dp[i][j] = 0;
            }
        }
    }

    return dp[0][0];
}

int main(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<path_num(a,b,x,y)<<endl;
    //cout<<path_num(6,6,3,3)<<endl;
    return 0;
}