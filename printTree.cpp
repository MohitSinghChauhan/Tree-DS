#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

// Vague O/P
void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    
}

// as tree becomes big the order gets jumbled up and down
void printTree2(TreeNode<int>* root){
    cout<<root->data<<": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<(root->children[i]->data)<<", ";
    }
    cout<<endl;
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

int main(){

    TreeNode<int>* root = new TreeNode<int> (1);
    TreeNode<int>* node1 = new TreeNode<int> (2);
    TreeNode<int>* node2 = new TreeNode<int> (3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    printTree2(root);
}