#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *inputTree()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = inputTree();
        root->children.push_back(child);
    }
    return root;
}

// Order isn't very correct for nodes
// TODO: to solve this we use Queue DS
void printTree2(TreeNode<int> *root)
{
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << (root->children[i]->data) << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree2(root->children[i]);
    }
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
        cout << front->data <<": ";
        for (int i = 0; i < front->children.size(); i++)
        {
           cout<<front->children[i]->data<<" ";
           pendingNodes.push(front->children[i]);
        }

        cout<<"\n";
        
    }
}

// Better Wat to input LEVEL BY LEVEL
//! NOT A RECURSIVE SOLUTION
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
}