// 实现功能
// 二叉树的搜索
// 二叉树的插入
// 二叉树的删除

#include<iostream>

struct BinTreeNode
{
    int data;
    BinTreeNode* left;
    BinTreeNode* right;
    // 构造函数 
    BinTreeNode(int val): data(val), left(nullptr), right(nullptr){}
};

// 查找递归实现
BinTreeNode* InterFind(int data, BinTreeNode* root)
{
    if(!root)
    {
        return nullptr;
    }
    if(data > root->data)
    {
        return InterFind(data, root->right);
    }
    else if(data < root->data)
    {
        return InterFind(data, root->left);
    }
    else
    {
        return root;
    }
}

// 查找非递归实现
BinTreeNode* Find(int data, BinTreeNode* root)
{
    while (root)
    {
        if(data > root->data)
        {
            root = root->right; // 比根节点大，往右子树查找
        }
        else if(data < root->data)
        {
            root = root->left; // 比根节点小，往左子树查找
        }
        else
        {
            return root;   // 找到了，返回对应的指针
        }
    }
    return nullptr; // 没找到，返回空指针
}

// 查找最小值
BinTreeNode* FindMin(BinTreeNode* root)
{
    if(!root)
    {
        return nullptr; // 空树
    }
    while (root->left)
    {
        root = root->left; // 左子树比根节点小，一直往左子树查找就可以找到最小值
    }
    return root;
}

// 查找最大值
BinTreeNode* FindMax(BinTreeNode* root)
{
    if(!root) return nullptr;
    while(root->right) root = root->right;
    return root;
}

// 插入
BinTreeNode* Insert(int data, BinTreeNode* root)
{
    if(!root) // 空树，初始化节点
    {
        return new BinTreeNode(data);
    }
    else
    {
        if(data > root->data) root->right = Insert(data, root->right);
        if(data < root->data) root->left = Insert(data, root->left);
        // 相等不做操作
    }
    return root;
}

// 删除
BinTreeNode* Delete(int data, BinTreeNode* root)
{
    BinTreeNode* tmp;
    if(!root){
        std::cout<<"未找到要删除的元素.";
        return nullptr;
    }
    else if(data > root->data) root->right = Delete(data, root->right);
    else if(data < root->data) root->left = Delete(data, root->left);
    else{ // 找到要删除的节点
        // 要删除的节点有两个子节点
        if(root->left && root->right){
            tmp = FindMin(root->right);    // 找到右子树最小的节点
            root->data = tmp->data;         // 节点覆盖
            root->right = Delete(tmp->data, root->right);// 需要删除用来替换的节点
        }
        // 只有一个子节点或没有子节点
        else{
            tmp = root;
            // if(root->left) root = root->left;
            // else if(root->right) root = root->right;
            // else root = nullptr;
            root = (root->left) ? root->left : root->right;
            delete tmp; // 叶子节点则直接删除节点
        }
    }
    return root;
}

// 释放整棵树
void FreeTree(BinTreeNode* root) {
    if (!root) return;
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
}

// **中序遍历 (递归)**
void InOrder(BinTreeNode* root) {
    if (!root) return;
    InOrder(root->left);
    std::cout << root->data << " ";
    InOrder(root->right);
}

int main(){
    BinTreeNode* root = nullptr;
    // 插入元素
    root = Insert(10, root);
    root = Insert(5, root);
    root = Insert(15, root);
    root = Insert(2, root);
    root = Insert(7, root);
    root = Insert(12, root);
    root = Insert(18, root);

    std::cout << "中序遍历:";
    InOrder(root);
    std::cout << std::endl;

    std::cout << "查找结点:" << 10 << ":" << (Find(10, root) ? "找到" : "未找到") << std::endl;
    std::cout << "查找结点:" << 11 << ":" << (Find(11, root) ? "找到" : "未找到") << std::endl;

    // 删除节点
    root = Delete(10, root);
    InOrder(root);
    std::cout << std::endl;

    FreeTree(root);
    return 0;
}