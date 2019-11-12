#include <iostream>
using namespace std;
int data[11][11];
int dp[11][11][11][11];

int main() {
    int n;
    cin >> n;

    while (true) {
        int a, b, val;
        cin >> a >> b >> val;
        if (a == 0 && b == 0 && val == 0) break;
        data[a][b] = val;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int p = 1; p <= n; p++) {
                for (int q = 1; q <= n; q++) {
                    dp[i][j][p][q] = max(max(dp[i-1][j][p-1][q], dp[i-1][j][p][q-1]),
                                         max(dp[i][j-1][p-1][q], dp[i][j-1][p][q-1])) + data[i][j] + data[p][q];
                    if (i == p && j == q) {
                        dp[i][j][p][q] -= data[i][j];
                    }
                }
            }
        }
    }

    cout << dp[n][n][n][n]<< endl;
    return 0;
}
