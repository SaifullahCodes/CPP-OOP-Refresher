#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *search(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (target == root->data)
        return root;
    if (target < root->data)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *findMax(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Node * deleteN(Node * root,int val){
    if(root==NULL){
        return root;
    }
    if(val<root->data){
        root->left= deleteN(root->left,val);
    }
    else if(val>root->data){
        root->right= deleteN(root->right,val);
    }
    else{
        if(root->left==NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        Node * temp = findMin(root->right);
        root->data=temp->data;
        root->right=deleteN(root->right,temp->data);

    }
    return root;

}

int main()
{
    Node *root = NULL;
    root = insert(root, 11);
    insert(root, 12);
    insert(root, 2);
    insert(root, 67);
    insert(root, 6);
    insert(root, 10);
    insert(root, 76);
    insert(root, 1);
    inorder(root);
    cout << endl;
    cout << "Deleting 2 (Node with children)..." << endl;
    root = deleteN(root, 2);
    int target = 2;
    Node *result = search(root, target);
    if (result != NULL)
    {
        cout << target << " is on this ADDRESS " << result << endl;
    }
    else
    {
        cout << "target not found" << endl;
    }
    Node * result1 =findMin(root) ;
     Node * result2 =findMax(root);

    cout << result1 << " Miniumum value is " << result1->data << endl;
    cout << result2 << " Maximum value is " << result2->data << endl;
    inorder(root);
    return 0;
}