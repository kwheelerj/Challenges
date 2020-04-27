#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root) {
		// swap left and right
		// call invertTree on left
		// call invertTree on right
		if (root == NULL) return NULL;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		if (root->left!= NULL)
			invertTree(root->left);
		if (root ->right != NULL)
			invertTree(root->right);

		return root;
	}
};

int main()
{
	TreeNode root = TreeNode(4);
	std::cout << root.val << std::endl;

	root.left = new TreeNode(2);
	root.right =  new TreeNode(7);

	std::cout << root.left->val << std::endl;
	std::cout << root.right->val << std::endl;


	std::cout << "---" << std::endl;

	Solution solution;
	solution.invertTree(&root);

	std::cout << root.val << std::endl;
	std::cout << root.left->val << std::endl;
	std::cout << root.right->val << std::endl;


	return 0;
}