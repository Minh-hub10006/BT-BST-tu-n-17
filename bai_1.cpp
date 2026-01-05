// ---MỤC LỤC SÁCH---
#include <bits/stdc++.h>
using namespace std;
struct Node {
    string title;
    int page;
    vector<Node*> children;
};
Node*createNode(string title,int page){
    Node*n=new Node();
    n->title=title;
    n->page=page;
    return n;
}
// Xác định số chương trong sách
int countChapters(Node*root){
    if(root==NULL) return 0;
    int cnt=0;
    for(auto child:root->children){
        cnt++;
    }
    return cnt;
}
// Tổng số trang ( để phần sau áp dụng tính của 1 chương)
int totalPages(Node*chapter){
    if(chapter==NULL) return 0;
    int sum=chapter->page;
    for(auto child:chapter->children){
        sum+=totalPages(child);
    }
    return sum;
}
// Tìm số chương dài nhất (bằng số trang)
void maxChapter(Node*root){
    if(root==NULL) return ;
    map<string,int> chapterPages;
    for(auto chapter:root->children){
        chapterPages[chapter->title]=totalPages(chapter);
    }
    int x=0;
    string y;
    for(auto a:chapterPages){
        if(a.second>x){
            x=a.second;
            y=a.first;
        }
    }
    cout<<"Chương dài nhất là: "<<y<<", với số trang là: "<<x<<endl;
}
// Tìm mục bất kì và in ra đề mục
void find(Node*root,string x){
    if(root==NULL) return;
    if(root->title==x){
        cout<<"Đề mục:"<<root->title<<", Số trang: "<<root->page<<endl;
        return;
    }
    for(auto child:root->children){
        find(child,x);
    }
    return;
}
// In toàn bộ mục lục sách
void printAll(Node*root){
    if(root==NULL) return;
    cout<<"Đề mục: "<<root->title<<", Số trang: "<<root->page<<endl;
    for(auto child:root->children){
        printAll(child);
    }
    return;
}
// Xóa 1 mục bất kì và cập nhật lại số trang
bool deleteNode(Node*root,string x){
    if(root==NULL) return false;
    for(auto it=root->children.begin();it!=root->children.end();it++){
        if((*it)->title==x){
            root->page-=(*it)->page;
            root->children.erase(it);
            return true;
        }
    }
    for(auto child:root->children){
        if(deleteNode(child,x)){
            return true;
        }
    }
    return false;
}
int main(){
    return 0;
}
