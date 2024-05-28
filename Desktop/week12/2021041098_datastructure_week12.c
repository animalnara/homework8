/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("[-----[강태광] [2021041098]-----]\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr) {
    if(ptr != NULL) {
        inorderTraversal(ptr->left); // 왼쪽 서브트리 순회
        printf("%d ", ptr->key);     // 현재 노드 출력
        inorderTraversal(ptr->right); // 오른쪽 서브트리 순회
    }
}

void preorderTraversal(Node* ptr) {
    if(ptr != NULL) {
        printf("%d ", ptr->key);     // 현재 노드 출력
        preorderTraversal(ptr->left); // 왼쪽 서브트리 순회
        preorderTraversal(ptr->right); // 오른쪽 서브트리 순회
    }
}


void postorderTraversal(Node* ptr) {
    if(ptr != NULL) {
        postorderTraversal(ptr->left);  // 왼쪽 서브트리 순회
        postorderTraversal(ptr->right); // 오른쪽 서브트리 순회
        printf("%d ", ptr->key);        // 현재 노드 출력
    }
}



int insert(Node* head, int key) {
    Node *newNode, *current, *parent;

    // 새로운 노드 생성
    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    // 트리가 비어있는 경우
    if (head->left == NULL) {
        head->left = newNode;
        return 1;
    }

    // 삽입 위치 찾기
    parent = NULL;
    current = head->left;
    while (current != NULL) {
        parent = current;
        current = (key < current->key) ? current->left : current->right;
    }

    // 부모 노드와 연결
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return 1;
}

int deleteLeafNode(Node* head, int key) {
    Node *current, *parent, *target;

    // 삭제할 노드를 찾기
    parent = NULL;
    current = head->left;
    while (current != NULL) {
        if (key == current->key) {
            target = current;
            break;
        }
        parent = current;
        current = (key < current->key) ? current->left : current->right;
    }

    // 삭제할 노드가 없는 경우
    if (current == NULL) {
        printf("삭제할 노드를 찾을 수 없습니다.\n");
        return 0;
    }

    // 삭제할 노드가 리프 노드인지 확인
    if (target->left != NULL || target->right != NULL) {
        printf("리프 노드가 아닙니다.\n");
        return 0;
    }

    // 부모 노드와 연결 해제
    if (parent != NULL) {
        if (parent->left == target)
            parent->left = NULL;
        else
            parent->right = NULL;
    }

    // 노드 해제
    free(target);
    return 1;
}

Node* searchRecursive(Node* ptr, int key) {
    if (ptr == NULL || ptr->key == key) {
        return ptr;
    }
    if (key < ptr->key) {
        return searchRecursive(ptr->left, key);
    } else {
        return searchRecursive(ptr->right, key);
    }
}


Node* searchIterative(Node* head, int key) {
    Node* current = head->left;

    while (current != NULL) {
        if (key == current->key) {
            return current;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // 노드를 찾지 못한 경우
    return NULL;
}



int freeBST(Node* head) {
    if (head == NULL) {
        return 0;
    }

    // 왼쪽 서브트리 해제
    freeBST(head->left);

    // 오른쪽 서브트리 해제
    freeBST(head->right);

    // 노드 해제
    free(head);

    return 1;
}