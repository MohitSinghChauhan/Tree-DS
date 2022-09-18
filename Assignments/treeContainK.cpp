#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

bool treeContainK(TreeNode<int>* root, int k){
    bool ans = false;

    if(root->data == k ){
        return true;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        ans=max(ans,treeContainK(root->children[i],k));

    }
    return ans;
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

int main(){
    TreeNode<int>* root = inputTree2();
    printTree3(root);

    int k;
    cin>>k;

   bool isKPresent=treeContainK(root,k);
cout << (isKPresent ? "YES" : "NO") << endl;
}

// bool ans = 1;