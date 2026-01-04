#include <bits/stdc++.h>
using namespace std;

struct IndexNode {
    int idx;                     // chỉ số mục
    string title;                // tên mục
    IndexNode* left;             // mục con trái
    IndexNode* right;            // mục con phải

    IndexNode(int i, string t) {
        idx = i;
        title = t;
        left = right = NULL;
    }
};
bool checkCopy(IndexNode* a, IndexNode* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    if (a->idx != b->idx) return false;
    if (a->title != b->title) return false;

    return checkCopy(a->left, b->left) &&
           checkCopy(a->right, b->right);
}
int main(){
    return 0;
}