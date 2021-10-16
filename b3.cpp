// C++ program to check if the given
// three traversals are of the same
// tree or not

#include <bits/stdc++.h>
using namespace std;

// Function to check if traversals are
// of the same tree
int checktree(int preorder[], int inorder[],
			int postorder[], int len)
{

	// if the array lengths are 0,
	// then all of them are obviously equal
	if (len == 0)
		return 1;

	// if array lengths are 1,
	// then check if all of them are equal
	if (len == 1)
		return (preorder[0] == inorder[0])
			&& (inorder[0] == postorder[0]);

	// search for first element of preorder
	// in inorder array
	int idx = -1, f = 0;
	for (int i = 0; i < len; ++i)
		if (inorder[i] == preorder[0]) {
			idx = i;
			break;
		}

	if(idx != -1){
	for(int i = 0; i < len; i++)
		if(preorder[0] == postorder[i]){f = 1; break;}
	}

	if (idx == -1 || f == 0)
		return 0;

	// check for the left subtree
	int ret1
		= checktree(preorder + 1, inorder, postorder, idx);

	// check for the right subtree
	int ret2
		= checktree(preorder + idx + 1, inorder + idx + 1,
					postorder + idx, len - idx - 1);

	// return 1 only if both of them are
	// correct else 0
	return (ret1 && ret2);
}

// Driver Code
int main()
{
	// Traversal Arrays
	int inorder[] = { 4, 2, 5, 1, 3 };
	int preorder[] = { 1, 2, 4, 5, 3 };
	int postorder[] = { 4, 5, 2, 3, 1 };
	int len1 = sizeof(inorder) / sizeof(inorder[0]);
	int len2 = sizeof(preorder) / sizeof(preorder[0]);
	int len3 = sizeof(postorder) / sizeof(postorder[0]);

	// Check if all the array lengths are equal
	if ((len1 == len2) && (len2 == len3)) {

		bool res
			= checktree(preorder, inorder, postorder, len1);

		(res) ? cout << "Yes" : cout << "No";
	}
	else
		cout << "No\n";

	return 0;
}

