#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <assert.h>  

int COUNT;

struct Node{
	Node *left;
	Node *rght;
	char name[100];
};

Node* new_node(){
	printf("malloc\n");
	Node* node = (Node*)calloc(1, sizeof(Node));
	return node;
}

Node* node_try_go(Node* thiz, char dir){
	if(dir == '0'){
		return thiz->left ? thiz->left : thiz->left = new_node();
	}else if(dir == '1')
		return thiz->rght ? thiz->rght : thiz->rght = new_node();
	else
		assert(false);
}

void node_go_thrghs(Node* thiz, char* buf){
	Node *iter = thiz;
	char tmp[100];
	strcpy(tmp, buf);
	while(*buf){
		iter = node_try_go(iter, *buf);
		buf++;
	}
	strcpy(iter->name, tmp);
}

void node_count_total(Node *thiz, int prob=100){
	//printf("%s %d\n", thiz->name, prob);
	assert(thiz != NULL);
	if(thiz->left == NULL && thiz->rght == NULL){
		++COUNT;
	}else{
		int mid = prob >> 1;
		for (int i = 1; i <= mid; ++i){
			node_count_total(thiz->left, i);
			node_count_total(thiz->rght, prob-i);
			--COUNT;
		}
	}
}

int main(){
	int n;
	while(scanf("%d\n", &n) && n){
		Node* head = new_node();
		strcpy(head->name, "name");
		COUNT = 0;
		while(n--){
			char buf[30];
			scanf("%s", buf);
			node_go_thrghs(head, buf);
		}
		printf("succ\n");
		node_count_total(head);
		printf("%d\n", COUNT);
	}
	return 0;
	
}
