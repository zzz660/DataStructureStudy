#include<iostream>

struct BinTree
{
    int val;
    BinTree *Left, *Right;
    // æ„ï¿½ï¿½å‡½æ•?1ï¿?7
    BinTree(int data): val(data), Left(nullptr), Right(nullptr) {}
};

// äºŒå‰æ ‘æ’å…?1ï¿?7 é€’å½’shixian
BinTree *Insert(BinTree *root, int val){
    if(!root){
        return new BinTree(val);    // ç©ºèŠ‚ç‚¹åˆ™åˆ›å»ºä¸?ï¿½ä¸ªæ–°èŠ‚ç‚?
    }
    else{
        if(val > root->val) root->Right = Insert(root->Right, val);   // å¤§äºæ ¹èŠ‚ç‚¹æ’å…¥å³æ ?1ï¿?7
        if(val < root->val) root->Left = Insert(root->Left, val);    // å°äºæ ¹èŠ‚ç‚¹æ’å…¥å·¦æ ?1ï¿?7
    }
    return root;
}

BinTree *MakeTree(int* data, int length){
    BinTree *Tree = new BinTree(data[0]);
    for (int i = 1; i < length; ++i) Insert(Tree, data[i]);
    return Tree;
}

// å…ˆåºéå†
// é€’å½’å®ç°
void PreOrderTraversal(BinTree *root){
    if(root){
        std::cout << root->val << ' ';
        PreOrderTraversal(root->Left);
        PreOrderTraversal(root->Right);
    }
}

// ä¸?åºéå?
void InOrderTraversal(BinTree *root){
    if(root){
        InOrderTraversal(root->Left);
        std::cout << root->val << ' ';
        InOrderTraversal(root->Right);
    }
}

// ååºéå†
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

    std::cout << "ÏÈĞò±éÀú:"; 
    PreOrderTraversal(Tree);
    std::cout << std::endl;

    std::cout << "ÖĞĞò±éÀú:"; 
    InOrderTraversal(Tree);
    std::cout << std::endl;

    std::cout << "ºóĞø±éÀú:"; 
    PostOrderTraversal(Tree);
    std::cout << std::endl;

    // std::cin.get();
    return 0;
}