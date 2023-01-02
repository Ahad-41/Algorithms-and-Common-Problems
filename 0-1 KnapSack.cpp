#include <iostream>
using namespace std;

int main()
{
    int items, weightOfBag; cin >> items >> weightOfBag;
    
    int weight[items+1], cost[items+1], dp[items+1][weightOfBag+1];
    for (int i = 1; i <= items; i++) cin >> weight[i];
    for (int i = 1; i <= items; i++) cin >> cost[i];

    for (int i = 0; i <= items; i++) {
        for (int j = 0; j <= weightOfBag; j++) {
            if (!i || !j) dp[i][j] = 0;
            else if (weight[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-weight[i]]+cost[i], dp[i-1][j]);
        }
    }
    
    cout << dp[items][weightOfBag] << endl;
    return 0; 
}