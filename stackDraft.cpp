#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
  void recur(TreeNode* root, vector<int> &res) {
    if (root == NULL)
      return;
    recur(root->left, res);
    res.push_back(root->val);
    recur(root->right, res);
  }

  vector<int> inorderTravesal(TreeNode* root) {
    vector<int> res;
    recur(root, res);
    return res;
  }
};

class Solution1 {
public:
  vector<int> inorderTravesal(TreeNode* root) {
    vector<int> res;
    vector<TreeNode*> stack;
    TreeNode* curr = root;
    while (curr != NULL || stack.size() != 0)
    {
      while (curr != NULL)
      {
        stack.push_back(curr);
        curr = curr->left;
      }
      curr = stack[stack.size()-1];
      stack.pop_back();
      res.push_back(curr->val);
      curr = curr->right;
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  TreeNode* pval3 = new TreeNode(3);
  TreeNode* pval2 = new TreeNode(2, pval3, nullptr);
  TreeNode* pval1 = new TreeNode(1, nullptr, pval2);

  Solution sol;
  Solution1 sol1;
  vector<int> res = sol.inorderTravesal(pval1);
  vector<int> res1 = sol1.inorderTravesal(pval1);

  for (int i=0; i<res.size(); i++)
  {
    cout << res[i] << endl;
  }
  for (int i=0; i<res1.size(); i++)
  {
    cout << res1[i] << endl;
  }

  delete pval3;
  delete pval2;
  delete pval1;
}











// end
