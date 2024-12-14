// Root - Top most element;
// Parent/Internal Node - A node which has atleast one child or leaf node;
// Child Node - A node which extend or derive from other node;
// Leaf/External Node - A node which has no child or leaf node;
// Depth - Number of edges from root to the node;
// Height - Number of edges from root to the deepest leaf;
// Sibling - Node belongs to same parent node;
// Ancestors- Parent of parents;
// Descendends - Child of child;
// Degree - Number of child;
// n Nodes --> n-1 Edges;
// Types of Tree: Binary Tree, Binary Search Tree, B Tree, B+ Tree, B* Tree, AVL Tree, Red-Black Tree, Splay Tree, so on;
#include <stdio.h>
#include <stdlib.h>

struct Binary {
    int data;
    struct Binary* left;
    struct Binary* right;
};

struct Binary* createNode (int data) {
    struct Binary* cNode = (struct Binary*) malloc (sizeof(struct Binary)); // Memory allocate to data;
    cNode->data = data;
    cNode->left = NULL;
    cNode->right = NULL;
    return cNode;
}

void preOrderTraversal (struct Binary* bin) {
    if (bin != NULL){
        printf("%d  |  ", bin->data);
        preOrderTraversal (bin->left);
        preOrderTraversal (bin->right);
    }
}

void postOrderTraversal (struct Binary* bin) {
    if (bin != NULL){
        postOrderTraversal (bin->left);
        postOrderTraversal (bin->right);
        printf("%d  |  ", bin->data);
    }
}

void inOrderTraversal (struct Binary* bin) {
    if (bin != NULL){
        inOrderTraversal (bin->left);
        printf("%d  |  ", bin->data);
        inOrderTraversal (bin->right);
    }
}

int main (){
    struct Binary *bin;
    bin = createNode(4);

    struct Binary *node1 = createNode(1);
    struct Binary *node2 = createNode(6);
    struct Binary *node3 = createNode(5);
    struct Binary *node4 = createNode(2);
    bin->left = node1;
    bin->right = node2;
    node1->left = node3;
    node1->right = node4;

    // printf("value of %d\n", bin->data);
    // printf("value of %d\n", bin->left->data);
    // printf("value of %d\n", bin->right->data);
    // printf("value of %d\n", bin->left->right->data);
    // printf("value of %d\n", bin->left->left->data);

    preOrderTraversal(bin);
    printf("\n");
    postOrderTraversal(bin);
    printf("\n");
    inOrderTraversal(bin);
    
    return 0;
}