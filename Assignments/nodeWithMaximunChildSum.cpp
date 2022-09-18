#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *findNodeWithMaxChildSum(TreeNode<int> *root)
{

    int sum = root->data;
    int maxSum = -1;
    TreeNode<int> *maxSumChildAddress = NULL;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
        TreeNode<int> *x = findNodeWithMaxChildSum(root->children[i]);
        int childSum = x->data;
        for (int j = 0; j < x->children.size(); j++)
        {
            childSum+=x->children[j]->data;
        }
        if (maxSum < childSum)
            {
                maxSum = childSum;
                maxSumChildAddress = x;
            }
    }

    if (sum > maxSum)
        return root;

    return maxSumChildAddress;
}
int findMaxChildSum(TreeNode<int> *root)
{

    int sum = 0;
    int maxSum = -1;
    TreeNode<int> *maxSumChildAddress = NULL;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
        int x = findMaxChildSum(root->children[i]);
        if (maxSum < x)
        {
            maxSum = x;
            maxSumChildAddress = root->children[i];
        }
    }

    return max(sum, maxSum);
    // if(sum>maxSum) return root->data;

    // return maxSumChild->data;
}

void printTree3(TreeNode<int> *root)
{
    // cout<<root->data<<endl;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }

        cout << "\n";
    }
}

TreeNode<int> *inputTree2()
{
    cout << "Enter root data\n";
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter number " << i + 1 << " child of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root = inputTree2();
    printTree3(root);

    int maxChildSum = findMaxChildSum(root);

    // Node With max sum of chjildren including node itself
    TreeNode<int> *nodeWithMaxChildSum = findNodeWithMaxChildSum(root);

    cout << nodeWithMaxChildSum->data;
}