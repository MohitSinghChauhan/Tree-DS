#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

int findNextLarger(TreeNode<int> *root, int k)
{
    int nextlarger= root->data;
    int minDiff=10e6;
    if(root->data-k < minDiff and root->data-k > 0){
        minDiff = root->data - k;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        minDiff= min(minDiff,findNextLarger(root->children[i],k));       
    }

    return minDiff;
}

int findNextLarger2(TreeNode<int> *root, int k)
{
    int nextlarger=10e7;
    if(root->data-k > 0){
        nextlarger=root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
       nextlarger = min(nextlarger,findNextLarger2(root->children[i],k));       
    }

    return nextlarger;
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
    int k;
    cin>>k;
    printTree3(root);
    // int minDiff = findNextLarger(root,k);
    int nextLarger = findNextLarger2(root,k);
    // cout<<k+minDiff<<endl;
    cout<<nextLarger<<endl;
}