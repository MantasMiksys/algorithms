#include <iostream>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void morris_inorder(TreeNode* root) {
    TreeNode* curNode = root;

    while(curNode) {
        if(curNode->left) {
            // find in-order predecessor of curNode
            TreeNode* predecessor = curNode->left;
            while(predecessor->right && predecessor->right != curNode)
                predecessor = predecessor->right;

            if(!predecessor->right) {
                predecessor->right = curNode;
                curNode = curNode->left;
            } else {
                predecessor->right = nullptr;
                // visiting
                std::cout << curNode->val << std::endl;
                curNode = curNode->right;
            }
        } else {
            // visiting
            std::cout << curNode->val << std::endl;
            curNode = curNode->right;
        }    
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5); 
    
    root->right->left= new TreeNode(6);
    root->right->right = new TreeNode(7);

    morris_inorder(root);
}   