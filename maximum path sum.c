#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int ans = INT_MIN;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxPathSum(struct TreeNode* root)
{
    int left, right, path;

    if (root == NULL)
        return 0;

    left = maxPathSum(root->left);
    right = maxPathSum(root->right);

    if (left < 0)
        left = 0;

    if (right < 0)
        right = 0;

    path = root->val + left + right;

    if (path > ans)
        ans = path;

    return root->val + max(left, right);
}

struct TreeNode* newNode(int val)
{
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    struct TreeNode* root = newNode(-10);

    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Maximum Path Sum = %d\n", maxPathSum(root));

    return 0;
}