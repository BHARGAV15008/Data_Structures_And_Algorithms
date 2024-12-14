#include <stdio.h>
#include <stdlib.h>

struct AVLTree{
	int data;
	struct AVLTree *left;
	struct AVLTree *right;
};

struct AVLTree* createNode(int value){
	struct AVLTree* cNode = (struct AVLTree*)malloc(sizeof(struct AVLTree));
	cNode->data = value;
	cNode->left = NULL;
	cNode->right = NULL;
	return cNode;
}

int max(int left, int right){ return (left>right?left:right);}

void addNodeToTree(struct AVLTree* head, int value){
	struct AVLTree* cNode = createNode(value);
	while(1){
		if(head->data < value){
			if(head->right == NULL){
				head->right = cNode; 
				break;
			}
			else head = head->right;
		}
		else{
			if(head->left == NULL){
				head->left = cNode; 
				break;
			}
			else head = head->left;
		}
	}
}

int heightOfNode(struct AVLTree* head){
	int h = 0, r = 0, l = 0;
	if(head->left == NULL){
		l = 0;
		if (head->right == NULL) r = 0;
		else r = heightOfNode(head->right) + 1;
	}
	else{
		l = heightOfNode(head->left) + 1;
		if (head->right == NULL) r = 0;
		else r = heightOfNode(head->right) + 1;
	}
	return max(r,l);
}

int balanceFactorOfNode(struct AVLTree* head){
	int h = 0, r = 0, l = 0;
	if(head->left == NULL){
		l = 0;
		if (head->right == NULL) r = 0;
		else r = heightOfNode(head->right) + 1;
	}
	else{
		l = heightOfNode(head->left) + 1;
		if (head->right == NULL) r = 0;
		else r = heightOfNode(head->right) + 1;
	}
	return (l-r);
}

void inOrderTraversal(struct AVLTree* head){
	if(head == NULL) return;
	inOrderTraversal(head->left);
	printf("--> %d ",head->data);
	inOrderTraversal(head->right);
}


int main(){
	struct AVLTree* head = createNode(5);
	int h, bf;
	addNodeToTree(head, 3);
	addNodeToTree(head, 4);
	addNodeToTree(head, 8);
	addNodeToTree(head, 2);
	addNodeToTree(head, 6);
	addNodeToTree(head, 9);
	addNodeToTree(head, 1);
	addNodeToTree(head, 7);
	addNodeToTree(head, 11);
	addNodeToTree(head, 12);
	h = heightOfNode(head);
	bf = balanceFactorOfNode(head);
	printf("%d-->%d", h,bf);
	rrRotation(head->right);
	h = heightOfNode(head);
	bf = balanceFactorOfNode(head);
	printf("\n%d-->%d", h,bf);
	return 0;
}



// int main(){
// 	struct AVLTree* head = createNode(5);
// 	int val, choice;

// 	do{
// 		printf("\n------- AVL Tree Data Structure -------");
// 		printf("\n1. Add element to AVL Tree.");
// 		printf("\n2. Remove element from AVL Tree.");
// 		printf("\n3. Traversal of AVL Tree.");
// 		printf("\n4. Exit...");
// 		printf("\n\nEnter your choice...");
// 		scanf("%d", &choice);
// 		switch(choice){
// 			case 1:
// 				printf("\nEnter the value which is add to the tree.");
// 				scanf("\n%d", &val);
// 				addNodeToTree(head, val);
// 				break;
// 			case 2:
// 				printf("\nEnter the value which is remove from the tree.");
// 				scanf("\n%d", &val);
// 				// removeNodeFromTree(head, val);
// 				break;
// 			case 3:
// 				printf("\nTraversal of AVL Tree.: ");
// 				inOrderTraversal(head);
// 				break;
// 			case 4:
// 				printf("\nExit...");
// 		}
// 	}while(choice != 4);
// 	return 0;
// }