#include<iostream>
const int MaxTree = 10;
int a1[MaxTree], a2[MaxTree], a3[MaxTree];

struct BinTreeNode
{
    int data;
    BinTreeNode* left;
    BinTreeNode* right;
    int flag;
    // 构造函数 
    BinTreeNode(int val): data(val), flag(0), left(nullptr), right(nullptr){}
};

// 插入
BinTreeNode* Insert(int data, BinTreeNode* root)
{
    if(!root) return new BinTreeNode(data);
    else
    {
        if(data > root->data) root->right = Insert(data, root->right);
        if(data < root->data) root->left = Insert(data, root->left);
        // 相等不做操作
    }
    return root;
}

// 构建树
BinTreeNode* BuildTree(int N){
    int val;
    std::cin >> val;
    BinTreeNode* T = new BinTreeNode(val);
    for (int i = 1; i < N; ++i){
        std::cin >> val;
        T = Insert(val, T);
    }
    return T;
}

// 释放整棵树
void FreeTree(BinTreeNode* root) {
    if (!root) return;
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
}

//如何判别（已经访问过的结点要进行标记，使flag=1）
//在树T中按顺序搜索序列中的每个数，如果每次搜索所经过的结点在前面均出现过，则一致；
//                              否则如果某次搜索中遇到前面未出现的结点，则不一致。
int check(BinTreeNode* T, int val){
    if(T->flag){
        if(val > T->data) return check(T->right, val);
        else if(val < T->data) return check(T->left, val);
        else return 0;  //如果V == T->v，意味着这个序列中有两个元素出现了两次以上，即重复出现，认为不一致
    }
    else{
        if(val == T->data){
            T->flag = 1;    //如果未被访问过的结点刚好是所搜索的，使flag=1
            return 1;
        } 
        else return 0;  //否则未被访问过的结点不是所搜索的，即遇到前面未出现的结点，使flag=0
    }
}

int Judge(BinTreeNode* T, int N){
    int val, same = 1;  // same用于标记二叉树是否相等
    std::cin >> val;
    if(val != T->data) same = 0;    //序列第一个元素与T的根结点不一致，那就不是同一棵树
    else T->flag = 1;

    for (int i = 1; i < N; ++i){
        std::cin >> val;
        if( same && (!check(T, val)) ) same = 0;
    }

    if(!same) return 0;
    else return 1;
}

void ResetT(BinTreeNode* T){
    if(T->left) ResetT(T->left);
    if(T->right) ResetT(T->right);
    T->flag = 0;
}


int main(){
    BinTreeNode* T;
    int N, L;
    std::cin >> N;
    while(N){
        std::cin >> L;
        T = BuildTree(N);
        for (int i = 0; i < L; ++i){
            if (Judge(T, N)) std::cout << "Yes" << std::endl;
            else std::cout << "No" << std::endl;
            ResetT(T);
        }
        FreeTree(T);
        std::cin >> N;
    }
    return 0;
}