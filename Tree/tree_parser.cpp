#include <iostream>
using namespace std;
typedef struct Node{
	char key;
	Node *left=NULL;
	Node *right=NULL;
} Node;
typedef Node* pNode; 

void preorder(pNode n){
	cout<<n->key;
	if(n->left) preorder(n->left);
	if(n->right) preorder(n->right);
}
void inorder(pNode n){
	if(n->left) inorder(n->left);
	cout<<n->key;
	if(n->right) inorder(n->right);
}
void postorder(pNode n){
	if(n->left) postorder(n->left);
	if(n->right) postorder(n->right);
	cout<<n->key;
}

int main(int argc, char** argv) {
	pNode s;
	int num;
	char a,b,c;
	Node node[26];
	int j;
	
	cin>>num;
	while(num--){
		cin>>a>>b>>c;
		j=a-'A';
		node[j].key=a;
		if(b!='.')node[j].left=&node[b-'A'];
		if(c!='.')node[j].right=&node[c-'A'];
	}
	s=&node[0];
	
	preorder(s);
	cout<<endl;
	
	inorder(s);
	cout<<endl;
	
	postorder(s);
	
	return 0;
}
