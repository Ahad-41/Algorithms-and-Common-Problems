#include <iostream>
using namespace std;

const int N = 1e5+5;
int arr[N], tree[N*3];

// create segment tree ->
void segmentTree(int currNode, int left, int right) {
    if (left == right) {
        tree[currNode] = arr[left];
        return;
    } 
    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);
    tree[currNode] = tree[leftNode] + tree[rightNode];
}

// return the sum of i-th index to j-th index ->
int query(int currNode, int left, int right, int i, int j) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) return tree[currNode];
    
    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;
    int leftSum = query(leftNode, left, mid, i, j);
    int rightSum = query(rightNode, mid+1, right, i, j);

    return leftSum + rightSum;
}

// update in the i-th index with new value -> 
void update(int currNode, int left, int right, int i, int newValue) {
    if (i > right || i < left) return;
    if (left == right) {
        tree[currNode] = newValue;
        return;
    }

    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;

    update(leftNode, left, mid, i, newValue);
    update(rightNode, mid+1, right, i, newValue);
    tree[currNode] = tree[leftNode] + tree[rightNode];
}

int main()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    segmentTree(1, 1, n);

    while (q--) {
        int i, j; cin >> i >> j;
        cout << query(1, 1, n, i, j) << endl;
    }
}
