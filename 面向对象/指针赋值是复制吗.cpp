#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int width, val;
		Node(int _width, int _val);
}; 

Node::Node(int _width, int _val):width(_width), val(_val){}

int main()
{
	Node * n;
	Node a = Node(1, 2);
	n = &a;
	a.width = 3;
	cout << a.width << a.val << endl;
	cout << n->width << n->val << endl;
}


