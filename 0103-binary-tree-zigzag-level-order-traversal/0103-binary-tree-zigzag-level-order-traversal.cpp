/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
       queue<TreeNode*>q;
       if (root == NULL)
       {
        return {};
       }
       q.push(root);

        bool lefttoright = 1;

       while(!q.empty())
       {
        int lvlsize = q.size();
        vector<int>tmp(lvlsize);
        int first = 0;
        int last = lvlsize - 1;

        while(lvlsize--)
        {
            TreeNode* t = q.front();
            q.pop();
            
            if(lefttoright == 1){   
                tmp[first] = t->val;
                first++;
            }
            else{
                tmp[last] = t->val;
                last--;
            }

            if(t-> left != NULL)
            q.push(t->left);
            if(t-> right != NULL)
            q.push(t->right);
        }
        lefttoright = 1 - lefttoright;
        res.push_back(tmp);
       }
        return res;
    }
};