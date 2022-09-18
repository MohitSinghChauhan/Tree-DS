#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

bool checkStructurallyIdentical(TreeNode<int> *tree1, TreeNode<int> *tree2)
{

    if (tree1->data != tree2->data)
        return false;
    if (tree1->children.size() != tree2->children.size())
        return false;

    for (int i = 0; i < tree1->children.size(); i++)
    {
        if (!checkStructurallyIdentical(tree1->children[i], tree2->children[i]))
        {
            return false;
        }
    }

    return true;
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
    TreeNode<int> *tree1= inputTree2();
    TreeNode<int> *tree2= inputTree2();
    printTree3(tree1);
    printTree3(tree2);

    bool isStructurallyIdentical = checkStructurallyIdentical(tree1,tree2);

    isStructurallyIdentical?cout<<"YES":cout<<"NO"<<endl;
}