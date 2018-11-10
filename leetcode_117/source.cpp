#include <stdio.h>
#include <iostream>
#include <queue>
#include <Windows.h>

/*
最方便就是用队列，速度也不慢
不嫌麻烦的话，因为上一层是天然的队列，由上一层挨个生成下一层即可
*/

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	std::queue<struct TreeLinkNode *> *one, *two;

    void connect(TreeLinkNode *root) {
		if(root == NULL){
			return;
		}
		else{
			root->next = NULL;
		}
		one = new std::queue<struct TreeLinkNode *>;
		two = new std::queue<struct TreeLinkNode *>;
        one->push(root);
		while(1){
			struct TreeLinkNode *temp;
			while(!one->empty()){
				temp = one->front();
				one->pop();
				if(temp->left) two->push(temp->left);
				if(temp->right) two->push(temp->right);
			}
			if(two->empty()){
				break;
			}
			while(!two->empty()){
				temp = two->front();
				one->push(temp);
				two->pop();
				if(two->empty()){
					temp->next = NULL;
					break;
				}
				temp->next = two->front();
			}
		}
		delete one;
		delete two;
    }
};