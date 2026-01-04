#include <bits/stdc++.h>
using namespace std;

struct BookNode {
    int id;                        // mã mục
    string name;                   // tên mục
    int pageCount;                 // số trang
    vector<BookNode*> sub;         // các mục con

    BookNode(int i, string n, int p) {
        id = i;
        name = n;
        pageCount = p;
    }
};
int getChapterCount(BookNode* root) {
    return root->sub.size();
}
BookNode* getLongestChapter(BookNode* root) {
    if (root->sub.empty()) return NULL;

    BookNode* res = root->sub[0];
    for (BookNode* x : root->sub)
        if (x->pageCount > res->pageCount)
            res = x;
    return res;
}
bool removeItem(BookNode* cur, int target) {
    for (int i = 0; i < cur->sub.size(); i++) {
        BookNode* child = cur->sub[i];

        if (child->id == target) {
            cur->pageCount -= child->pageCount;
            delete child;
            cur->sub.erase(cur->sub.begin() + i);
            return true;
        }

        if (removeItem(child, target)) {
            cur->pageCount -= child->pageCount;
            return true;
        }
    }
    return false;
}
BookNode* findChapterById(BookNode* root, int id) {
    for (BookNode* ch : root->sub)
        if (ch->id == id)
            return ch;
    return NULL;
}

void showChapterContent(BookNode* ch) {
    if (!ch) return;
    cout << ch->name << endl;
    for (BookNode* x : ch->sub)
        cout << "  + " << x->name << endl;
}
int main(){
    return 0;
}