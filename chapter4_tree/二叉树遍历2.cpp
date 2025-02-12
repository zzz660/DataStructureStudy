#include<iostream>

struct BinTree
{
    int val;
    BinTree *Left, *Right;
    // 构��函敄1�7
    BinTree(int data): val(data), Left(nullptr), Right(nullptr) {}
};

// 二叉树插兄1�7 递归shixian
BinTree *Insert(BinTree *root, int val){
    if(!root){
        return new BinTree(val);    // 空节点则创建丢�个新节点
    }
    else{
        if(val > root->val) root->Right = Insert(root->Right, val);   // 大于根节点插入右栄1�7
        if(val < root->val) root->Left = Insert(root->Left, val);    // 小于根节点插入左栄1�7
    }
    return root;
}

BinTree *MakeTree(int* data, int length){
    BinTree *Tree = new BinTree(data[0]);
    for (int i = 1; i < length; ++i) Insert(Tree, data[i]);
    return Tree;
}

// 先序遍历
// 递归实现
void PreOrderTraversal(BinTree *root){
    if(root){
        std::cout << root->val << ' ';
        PreOrderTraversal(root->Left);
        PreOrderTraversal(root->Right);
    }
}

// 中序遍历
void InOrderTraversal(BinTree *root){
    if(root){
        InOrderTraversal(root->Left);
        std::cout << root->val << ' ';
        InOrderTraversal(root->Right);
    }
}

// 后序遍历
void PostOrderTraversal(BinTree *root){
    if(root){
        PostOrderTraversal(root->Left);
        PostOrderTraversal(root->Right);
        std::cout << root->val << ' ';
    }
}

int main(){
    int data[7] = {15, 12, 17, 10, 14, 16, 18};
    BinTree *Tree = MakeTree(data, (sizeof(data) / sizeof(data[0])));

    std::cout << "先序遍历:"; 
    PreOrderTraversal(Tree);
    std::cout << std::endl;

    std::cout << "中序遍历:"; 
    InOrderTraversal(Tree);
    std::cout << std::endl;

    std::cout << "后序遍历:"; 
    PostOrderTraversal(Tree);
    std::cout << std::endl;

    // std::cin.get();
    return 0;
}