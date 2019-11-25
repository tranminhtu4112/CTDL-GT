#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *pNext;	
};
struct List {
	Node *pHead;
	Node *pTail;
};
void initList(List &list){
	list.pHead = NULL;
	list.pTail = NULL;
}
Node *creNode(int val){
	Node *node = new Node; // cap phap bo nho
	node->data = val;
	node->pNext = NULL;
	return node;
}
void insertHeadList(List &list, Node *node){
	if(list.pHead == NULL){
		list.pHead = list.pTail = node;
	}else{
		node->pNext = list.pHead;
		list.pHead = node;
	}
}
void insertTailList(List &list, Node *node){
	if(list.pHead == NULL){
		list.pHead = list.pTail = node;
	}else{
		list.pTail->pNext = node;
		list.pTail = node;
	}
}
void insertIntoList(List &list, int val, int local){
	if(local < 0){
		printf("\nVi tri khong hop le!");
		return;
	}
	if(list.pHead != NULL && local != 0){
		int count = 0;
		Node *temp = list.pHead;
		while(temp != NULL){
			count++;
			if(local == count)	
				break;
			temp = temp->pNext;
			
		}
		if(local > count){
			printf("\nVuot qua gioi han, List co %d phan tu", count);
			return;
		}	
		Node *nodeOfVal = creNode(val);
		nodeOfVal->pNext = temp->pNext;
		temp->pNext = nodeOfVal;
	}else if(list.pHead == NULL || local == 0){ // bang NULL
		Node *nodeOfVal = creNode(val);
		insertHeadList(list, nodeOfVal);
	}
}
void inputList(List &list, int count){
	initList(list);
	for(int i = 0; i < count; i++){
		int val;
		printf("Nhap gia tri: ");
		scanf("%d", &val);
		Node *node = creNode(val);
		insertTailList(list, node);
	}
}
int getCountNodeList(List list){
	int count = 0;
		Node *temp = list.pHead;
	while(temp != NULL){
		count++;
		temp = temp->pNext;
	}
	return count;
}
void deleteNode(List &list, int local){
	
	if(list.pHead == NULL){
		printf("\nKhong co phan tu de xoa!");
		return;
	}
	Node *temp = list.pHead;
	int count = 0;
	while(temp->pNext != NULL){
		count++;
		if(local == count)
			break;
		temp = temp->pNext;
	}
}
void outputList(List list){
	for(Node *k = list.pHead; k != NULL; k = k->pNext){
		printf("%d\t", k->data);
	}
}
int findMaxList(List list){
	int max = list.pHead->data;
	for(Node *k = list.pHead->pNext; k != NULL; k = k->pNext){
		if(k->data > max)
			max = k->data;
	}
	return max;
}
int main(){
	int count, local, val;
	List list;
	printf("Nhap so luong: ");
	scanf("%d", &count);
	inputList(list, count);
	outputList(list);
	printf("\nGia tri max: %d", findMaxList(list));
	printf("\nNhap vi local: ");
	scanf("%d", &local);
	printf("Nhap val: ");
	scanf("%d", &val);
	insertIntoList(list, val, local);
	outputList(list);
	printf("\nSo luong Node: %d", getCountNodeList(list));
	
	
	
	
	
	
	
	
}
