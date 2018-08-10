#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
template <typename T>
struct node{
	T data;
	node<T> *left;
	node<T> *right;
};

typedef node<int> Node;// 需要等到确定之后才能替换的
// 递归方法
// 前序遍历
template <typename T>
void preordertravel1(Node* root, vector<T>& path) {
	if (root == NULL)
		return;
	else {
		path.push_back(root->data);
		preordertravel1(root->left, path);
		preordertravel1(root->right, path);
	}	
}

// 中序遍历
template <typename T>
void inordertravel1(Node* root, vector<T>& path) {
	if (root == NULL)
		return;
	else {
		inordertravel1(root->left, path);
		path.push_back(root->data);
		inordertravel1(root->right, path);
	}	
}

// 后序遍历
template <typename T>
void posordertravel1(Node* root, vector<T>& path) {
	if (root == NULL)
		return;
	else {
		posordertravel1(root->left, path);
		posordertravel1(root->right, path);
		path.push_back(root->data);
	}	
}
// 非递归方法:
// 前序遍历
template <typename T>
void preordertravel2(Node* root, vector<T>& path) {
	stack< pair<Node*, bool> > s;
	s.push(make_pair(root, false));
	bool visited = false;
	while (!s.empty()) {
		root = s.top().first;
		visited = s.top().second;
		s.pop();
		if (root == NULL)
			continue;
		else if (visited == true)
			path.push_back(root->data);
		else {
			s.push(make_pair(root->right, false));
			s.push(make_pair(root->left, false));
			s.push(make_pair(root, true));
		}
	}
}

// 中序遍历
template <typename T>
void inordertravel2(Node* root, vector<T>& path) {
	stack< pair< Node*, bool > > s;
	s.push(make_pair(root, false));
	bool visited = false;
	while (!s.empty()) {
		root = s.top().first;
		visited = s.top().second;
		s.pop();
		if (root == NULL)
			continue;
		else if (visited == true)
			path.push_back(root->data);
		else {
			s.push(make_pair(root->right, false));
			s.push(make_pair(root, true));
			s.push(make_pair(root->left, false));
		}
		
	} 
}

// 后序遍历
template <typename T>
void posordertravel2(Node* root, vector<T>& path) {
	stack< pair<Node*, bool> > s;
	s.push(make_pair(root, false));
	bool visited = false;
	while(!s.empty()) {
		root = s.top().first;
		visited = s.top().second; // 是否已经访问过，如果访问过则可以打印
		s.pop();
		if(root == NULL)
			continue;
		else if(visited == 1) {
			path.push_back(root->data);
		}
		else {
			s.push(make_pair(root, true));
			s.push(make_pair(root->right, false));
			s.push(make_pair(root->left, false));
		}
			
	} 
}

// 层次遍历
template <typename T>
void leveltravel(Node* root, vector<T>& path) {
	queue<Node*> Q;
	if (root == NULL) // 如果根节点为空
		return; // 直接返回
	Q.push(root); // 否则的话压入队列
	while (!Q.empty()) { // 当队列不为空
		Node* x = Q.front(); // 取出队列的首元素,但是该元素还在队列中
		path.push_back(x->data); // 访问该元素
		Q.pop(); // 弹出该元素
		if (x->left != NULL) Q.push(x->left); // 如果其左节点不为空则压入队列中
		if (x->right != NULL) Q.push(x->right); // 如果其右节点不为空则压入队列中
	}
}

// 树的深度
int BinaryTreeHeight(Node *node)
{
    int treeHeight = 0;
    if (node != NULL)
    {
        int leftHeight = BinaryTreeHeight(node->left);
        int rightHeight = BinaryTreeHeight(node->right);
        treeHeight = leftHeight >= rightHeight? leftHeight + 1:rightHeight + 1;
    }
 
    return treeHeight;
}

// 统计叶节点的数目
int leafcount(Node* node) {
	int count;
	if (node == NULL)
		count = 0;
	else if (node->left==NULL && node->right==NULL)
		count = 1;
	else
		count = leafcount(node->left) + leafcount(node->right);
	return count;
}

int main(int argc, char* argv[]) {
	Node n1,n2,n3,n4,n5,n6; // 定义二叉树节点
	n1.data = 4; // 构建二叉树
	n2.data = 5;
	n3.data = 6;
	n4.data = 7;
	n5.data = 8;
	n6.data = 9;
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = NULL;
	n3.left = &n5;
	n3.right = &n6;
	n4.left = NULL;
	n4.right = NULL;
	n5.left = NULL;
	n5.right = NULL;
	n6.left = NULL;
	n6.right = NULL;
	
	// 非递归前序遍历
	cout << "非递归版本的前序遍历:" << endl;
	vector<int> path1;
	preordertravel2(&n1, path1);
	for (vector<int>::iterator it = path1.begin(); it != path1.end(); it++)
		cout << *it << "\t";
	cout << endl;

	cout << "非递归版本的中序遍历:" << endl;
	vector<int> path2;
	inordertravel2(&n1, path2);
	for (vector<int>::iterator it = path2.begin(); it != path2.end(); it++)
		cout << *it << "\t";
	cout << endl;
	
	cout << "非递归版本的后序遍历:" << endl;
	vector<int> path3;
	posordertravel2(&n1, path3);
	for (vector<int>::iterator it = path3.begin(); it != path3.end(); it++)
		cout << *it << "\t";
	cout << endl;

	cout << "递归版本的前序遍历:" << endl;
	vector<int> path4;
	preordertravel1(&n1, path4);
	for (vector<int>::iterator it = path4.begin(); it != path4.end(); it++)
		cout << *it << "\t";
	cout << endl;

	cout << "递归版本的中序遍历:" << endl;
	vector<int> path5;
	inordertravel2(&n1, path5);
	for (vector<int>::iterator it = path5.begin(); it != path5.end(); it++)
		cout << *it << "\t";
	cout << endl;

	cout << "递归版本的后续遍历:" << endl;
	vector<int> path6;
	posordertravel2(&n1, path6);
	for (vector<int>::iterator it = path6.begin(); it != path6.end(); it++)
		cout << *it << "\t";
	cout << endl;

	cout << "层次遍历:" << endl;
	vector<int> path7;
	leveltravel(NULL, path7);
	for (vector<int>::iterator it = path7.begin(); it != path7.end(); it++)
		cout << *it << "\t";
	cout << endl;

	cout << "二叉树的高度:" << endl;
	int height = BinaryTreeHeight(&n1);
	cout << "The height of tree is " << height << endl;

	cout << "二叉树叶节点的数目:" << endl;
	int num = leafcount(&n1);
	cout << "The number of leaf is " << num << endl;
	
	return 0;
}
