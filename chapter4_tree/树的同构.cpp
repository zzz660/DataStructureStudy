#include<iostream>
# define MaxTree 10

// 通过结构树组表示二叉树
struct BinTree{
    char element;
    int left, right;
}T1[MaxTree], T2[MaxTree];

// 返回值为树根
int BuildTree(BinTree T[]){
    int n; std::cin >> n;   // 节点个数
    int check[MaxTree];     // 用来寻找根节点的数组
    char left, right;       // 输入中有"-"，先用char接收输入，后续转数字
    int root = -1;
    if(n){
        for (int i = 0; i < n; ++i) check[i] = 0;
        for (int i = 0; i < n; ++i){
            std::cin >> T[i].element >> left >> right;
            // 判断左右子树是否为空节点，同时标记出现过的子树，没出现过的就是根节点
            if(left != '-'){
                T[i].left = left - '0';
                check[T[i].left] = 1;   // 出现过，标记为1
            }
            else if(left == '-') T[i].left = -1;

            if(right != '-'){
                T[i].right = right - '0';
                check[T[i].right] = 1;   // 出现过，标记为1
            }
            else if(right == '-') T[i].right = -1;

            // 寻找根节点，出现过的节点都会被标记1，没出过的就是0，即为根节点
            // 根节点不会被指向
            for (int i = 0; i < n; ++i){
                if (!check[i]){
                    root = i;
                    break;
                }
            }
        }
    }
    return root;
}

bool Isomorphic(int R1, int R2){
    if ( (R1==-1) && (R2==-1) ) return true;  // 都是空树，同构
    if ( ((R1!=-1) && (R2==-1)) || ((R1==-1) && (R2!=-1))) return false;    // 其中一个为空树
    if ( T1[R1].element != T2[R2].element) return false;    // 根节点不相同，不同构
    // 左子树均为空（这覆盖了右子树均为空的情况，对称性，第一种判断已经将其包含）
    if( (T1[R1].left==-1) && (T2[R2].left==-1) ) return Isomorphic(T1[R1].right, T2[R2].right);
    // 左子树不为空且值相等
    if( (T1[R1].left!=-1 && T2[R2].left!=-1) && (T1[T1[R1].left].element == T2[T2[R2].left].element))
        return (Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right));
    // 左子树不为空，但是值不相等，即需要交换
    else
        return (Isomorphic(T1[R1].left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].left));
}

int main(){
    int R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    std::cout << (Isomorphic(R1, R2) ? "Yes" : "No") << std::endl;
    return 0;
}