#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {1, 2, 3};
vector<vector<int>> allPossibleSubset;
const int N = arr.size();

void subsetGenerator(int i, vector<int> &subset) {
    if (i >= N) {
        allPossibleSubset.push_back(subset);
        return;
    }

    subset.push_back(arr[i]);
    subsetGenerator(i + 1, subset);

    subset.pop_back();
    subsetGenerator(i + 1, subset);
}

int main()
{
    vector<int> subset;
    subsetGenerator(0, subset);

    for (int i = 0; i < allPossibleSubset.size(); i++) {
        for (auto &u : allPossibleSubset[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
}