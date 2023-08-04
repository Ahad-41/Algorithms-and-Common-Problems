#include <bits/stdc++.h>
using namespace std;

vector <int> createFailureTable (string pattern) {
    int M = pattern.size();
    vector <int> failureTable(M);
    int index = 0;
    for (int i = 1; i < M; ) {
        if (pattern[index] == pattern[i]) {
            failureTable[i] = index + 1;
            index++;
            i++;
        }
        else {
            if (index != 0) index = failureTable[index - 1];
            else {
                failureTable[i] = index;
                i++;
            }
        }
    }
    return failureTable;
}

bool kmp (string text, string pattern) {
    int N = text.size(), M = pattern.size();
    vector<int> failureTable = createFailureTable(pattern);

    int i = 0, j = 0;
    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if (j != 0) j = failureTable[j-1];
            else i++;
        }
        if (j == M) return true;
    } 
    return false; 
}

int main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    cout << (kmp(text, pattern) ? "Found" : "Not Found") << endl;
}
