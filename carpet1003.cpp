//
// Created by SF on 2019/11/11.
//
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n, x, y;
    cin>>n;
    vector<vector<int>> carpet(n, vector<int>(4));
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >> carpet[i][j];
        }
    }
    cin>>x>>y;

    for(int i=n-1; i>=0; i--){
        int a = carpet[i][0];
        int b = carpet[i][1];
        int w = carpet[i][2];
        int h = carpet[i][3];
        if((x-a) >=0 && (y-b) >=0 && (a+w) >= x && (b+h) >= y){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}

