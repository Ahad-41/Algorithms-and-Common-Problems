#include <bits/stdc++.h>
using namespace std;

vector <int> arr = {1, 2, 3};
vector <vector<int>> allPossiblePer;
const int N = arr.size();
bool taken[100005];

void permutation(vector<int> &per) {
    if (per.size() == N) {
        allPossiblePer.push_back(per); 
        return;
    }

    for (int i = 0; i < N; i++) {
        int currNum = arr[i];
        if (taken[currNum] == false) {
            per.push_back(currNum);
            taken[currNum] = true;

            permutation(per);

            per.pop_back();
            taken[currNum] = false;
        }
    }
}

int main()
{
    vector <int> per;
    permutation(per);

    for (int i = 0; i < allPossiblePer.size(); i++) {
        for (auto &u : allPossiblePer[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
}