// BST is like same as Binary Tree;
// But some condition is there:
//  * All node of left subtree is lesser than root;
//  * All node of right subtree is greater than root;
//  * Tree has no duplicates node;
//  * Left and right subtree also follow bst condition;
//  * Inorder traversal of BST is gives ascending order;

#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* createNode (int data) {
    struct BST* cNode = (struct BST*) malloc (sizeof(struct BST));
    cNode->data = data;
    cNode->left = NULL;
    cNode->right = NULL;
    return cNode;
}

int isBST (struct BST* root) {
    static struct BST* prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left))
            return 0;
        
        if ((prev != NULL) && (root->data <= prev->data))
            return 0;

        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

void insertBST (struct BST* root, int data) {
    struct BST* cNode = createNode(data);
    struct BST* prev = NULL;
    while (root != NULL){
        prev = root;
        if (data == root->data){
            printf("\nWe cant insert, element is already inserted.\n");
            return;
        }
        else if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    
    if (data < prev->data)
        prev->left = cNode;
    else
        prev->right = cNode;
        
}

struct BST* inOrderPredecessor (struct BST* root) {
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    
    return root;
}

struct BST* deleteBST (struct BST* root, int data) {
    struct BST* iPre = NULL;
    if (root == NULL)
        return NULL;
    
    if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    // Search node to be deleted;
    if (data < root->data)
        root->left = deleteBST (root->left, data);
    else if (data > root->data)
        root->right = deleteBST (root->right, data);
    else{
        // Building deleting logic here when the node is found;
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteBST(root->left, iPre->data);
    }
    return root;
}

struct BST* searchBST (struct BST* root, int data) {
    if (root == NULL)
        return NULL;

    if (data == root->data)
        return root;
    else if (data > root->data)
        return searchBST(root->right, data);
    else
        return searchBST(root->left, data);
}

void inOrderTraversal (struct BST* bin) {
    if (bin != NULL){
        inOrderTraversal (bin->left);
        printf("%d  |  ", bin->data);
        inOrderTraversal (bin->right);
    }
}

int main (){
    struct BST *bin = createNode(5);
    struct BST *node1 = createNode(2);
    struct BST *node2 = createNode(6);
    struct BST *node3 = createNode(1);
    struct BST *node4 = createNode(4);
    bin->left = node1;
    bin->right = node2;
    node1->left = node3;
    node1->right = node4;
    printf("\n");
    // printf("%d", isBST(bin));

    // Searching check;
    insertBST(bin, 8);
    inOrderTraversal(bin);
    // struct BST* n = searchBST(bin, 2);
    // if (n != NULL)
    //     printf("Element is found !!!");
    // else
    //     printf("Element is not found !!!");
    
    deleteBST(bin, 2);
    inOrderTraversal(bin);

    return 0;
}