// AVL Tree is next of BST Tree;
// AVL tree helps to main tain balanced tree and make less time complexity;
// It balanced tree with the helps of balanced factor of node;
// According to Balanced factor we decide to rotation like: LL, RR, LR, RL;

#include <stdio.h>
#include <stdlib.h>

struct AVLTree {
    int data;
    struct AVLTree* left;
    struct AVLTree* right;
    int height;
};

struct AVLTree* createNode (int data) {
    struct AVLTree* cNode = (struct AVLTree*) malloc (sizeof(struct AVLTree)); // Memory allocate to data;
    cNode->data = data;
    cNode->left = NULL;
    cNode->right = NULL;
    return cNode;
}

int max (int a, int b) {
    return (a > b? a : b);
}

int getHeight (struct AVLTree* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor (struct AVLTree* node) {
    if (node == NULL)
        return 0;
    return (getHeight(node->left) - getHeight(node->right));
}

struct AVLTree* rightRotate (struct AVLTree* node){
    struct AVLTree* lNode = node->left;
    struct AVLTree* lrNode = lNode->right;

    lNode->right = node;
    node->left = lrNode;

    node->height = max(getHeight(node->right), getHeight(node->right)) + 1;
    lNode->height = max(getHeight(lNode->right), getHeight(lNode->right)) + 1;
    return lNode;
}

struct AVLTree* leftRotate (struct AVLTree* node){
    struct AVLTree* lNode = node->right;
    struct AVLTree* lrNode = lNode->left;

    lNode->left = node;
    node->right = lrNode;

    node->height = max(getHeight(node->right), getHeight(node->right)) + 1;
    lNode->height = max(getHeight(lNode->right), getHeight(lNode->right)) + 1;
    return lNode;
}

struct AVLTree* insertAVL (struct AVLTree* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insertAVL (root->left, data);
    else if (data > root->data)
        root->right = insertAVL (root->right, data);
    
    return root;
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor (root);

    // Case I: LL Rotation;
    if (bf > 1 && data > root->left->data)
        return rightRotate(root);

    // Case II: RR Rotation;
    if (bf < -1 && data > root->right->data)
        return leftRotate(root);

    // Case III: LR Rotation;
    if (bf > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case IV: RL Rotation;
    if (bf < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}

void inOrderTraversal (struct AVLTree* bin) {
    if (bin != NULL){
        inOrderTraversal (bin->left);
        printf("%d  |  ", bin->data);
        inOrderTraversal (bin->right);
    }
}

int main (){
    struct AVLTree* avl = createNode(5);
    avl = insertAVL(avl, 34);
    avl = insertAVL(avl, 35);
    avl = insertAVL(avl, 3);
    avl = insertAVL(avl, 10);
    avl = insertAVL(avl, 20);
    inOrderTraversal(avl);
    
    return 0;
}