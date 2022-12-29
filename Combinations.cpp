#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5};
const int k = 2;
vector<vector<int>> allPossibleCom;
const int N = arr.size();

void combination(int i, vector<int> &com) {
    if (com.size() == k) {
        allPossibleCom.push_back(com);
        return;
    }

    if (i >= N) return;

    com.push_back(arr[i]);
    combination(i+1, com);

    com.pop_back();
    combination(i+1, com);
}

int main()
{
    vector<int> com;
    combination(0, com);

    for (int i = 0; i < allPossibleCom.size(); i++) {
        for (auto &u : allPossibleCom[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
}