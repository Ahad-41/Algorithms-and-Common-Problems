#include <bits/stdc++.h>
using namespace std;

vector<int> lps(string s) {
    int n = s.size();
    vector<int> lpsArray(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 and s[j] != s[i]) j = lpsArray[j-1];
        if (s[j] == s[i]) j++;
        lpsArray[i] = j;
    }   

    return lpsArray;
}

bool kmp (string text, string pattern) {
    int N = text.size(), M = pattern.size();
    vector<int> lpsArray = lps(pattern);

    int i = 0, j = 0;
    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if (j != 0) j = lpsArray[j-1];
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
