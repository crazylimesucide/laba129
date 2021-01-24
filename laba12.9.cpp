#include <iostream>
using namespace std;
typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
};
Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}
int Find(Node* root, int k)

{
	if (root == NULL)
		return 0;
	if (root->info % k == 0)
		return root->info + Find(root->left, k);
	else if (root->info % k == 0)
		return root->info + Find(root->right, k);
	else if (root->info % k != 0)
		return Find(root->left, k);
	else
		return Find(root->right, k);
}
int main()
{
	int N, k, sum = 0;
	cout << "k = "; cin >> k;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	sum = Find(root, k);
	cout << sum;
	return 0;
}