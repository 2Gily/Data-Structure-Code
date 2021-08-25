#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a,b) ((a>b)?a:b)

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* LL_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treeNode* RR_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode* LR_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

treeNode* RL_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

// 서브 트리의 높이를 구하는 연산
int getHeight(treeNode* p) {
	int height = 0;
	if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

// 서브 트리의 높이를 이용해 균형 인수 BF를 구하는 연산
int getBF(treeNode* p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// BF를 검사하여 불균형이 발생한 경우, 회전 연산 호출
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);
	if (BF > 1) {
		if (getBF((*p)->left) > 0)
			     *p = LL_rotate(*p);
		else    *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			 *p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}

// AVL 트리에 노드를 삽입하는 연산: 이진 탐색 연산처럼 삽입한 후에, rebalance() 호출 
treeNode* insert_AVL_Node(treeNode** root, element x) {	
	if (*root == NULL) {
		*root = (treeNode*)malloc(sizeof(treeNode));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;		
	}
	else if (x < (*root)->key) {
		(*root)->left = insert_AVL_Node(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x >(*root)->key) {
		(*root)->right = insert_AVL_Node(&((*root)->right), x);
		*root = rebalance(root);
	}
	else {
		printf("\n 이미 같은 키가 있습니다! \n");
		exit(1);
	}
	return *root;
}

// 이진 탐색 트리에 노드를 삽입하는 연산 : [예제 7-4]의 25~39행
treeNode* insert_BST_Node(treeNode *p, element x) {
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)  p->left = insert_BST_Node(p->left, x);
	else if (x > p->key)  p->right = insert_BST_Node(p->right, x);
	else  printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

// 이진 탐색 트리와 AVL 트리에서 키값 x를 탐색하는 연산 : [예제 7-4]의 12~22행 수정
treeNode* searchTree(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->key) p = p->left;
		else if (x == p->key) {
			printf("%3d번째에 탐색 성공", count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("%3d번째에 탐색 실패! 찾는 키가 없습니다!", count);
	return p;
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산 : [예제 7-4]의 098~104행
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("_%d ", root->key);
		displayInorder(root->right);
	}
}

int main() {
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;

	//////////////////////////////////////////////////////////////////
	root_AVL = insert_AVL_Node(&root_AVL, 50); // AVL 트리 만들기
	insert_AVL_Node(&root_AVL, 60);
	insert_AVL_Node(&root_AVL, 70);
	insert_AVL_Node(&root_AVL, 90);
	insert_AVL_Node(&root_AVL, 80);
	insert_AVL_Node(&root_AVL, 75);
	insert_AVL_Node(&root_AVL, 73);
	insert_AVL_Node(&root_AVL, 72);
	insert_AVL_Node(&root_AVL, 78);

	printf("\n ******* AVL 트리 출력 ****************** \n\n");
	displayInorder(root_AVL);

	printf("\n\n AVL 트리에서 70 탐색 : ");
	searchTree(root_AVL, 70);
	
	printf("\n\n AVL 트리에서 72 탐색 : ");
	searchTree(root_AVL, 72);

	printf("\n\n AVL 트리에서 76 탐색 : ");
	searchTree(root_AVL, 76);

	/////////////////////////////////////////////////////////////////////////////
	root_BST = insert_BST_Node(root_BST, 50); //BST 만들기
	insert_BST_Node(root_BST, 60);
	insert_BST_Node(root_BST, 70);
	insert_BST_Node(root_BST, 90);
	insert_BST_Node(root_BST, 80);
	insert_BST_Node(root_BST, 75);
	insert_BST_Node(root_BST, 73);
	insert_BST_Node(root_BST, 72);
	insert_BST_Node(root_BST, 78);

	printf("\n\n\n ******* BST 출력 ************************ \n\n");
	displayInorder(root_BST);

	printf("\n\n BST에서 70 탐색 : ");
	searchTree(root_BST, 70);

	printf("\n\n BST에서 72 탐색 : ");
	searchTree(root_BST, 72);

	printf("\n\n BST에서 76 탐색 : ");
	searchTree(root_BST, 76);

	getchar();
}