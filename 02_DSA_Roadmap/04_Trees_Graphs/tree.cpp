#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node (int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node * insert(Node * root , int val){
    if (root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right= insert(root->right,val);
    }
    return root;
}
Node *search(Node * root, int target){
    if (root == NULL) {
        return NULL;
    }
    if(target==root->data) return root;
    if(target<root->data){
        return search(root->left,target);
    }
    else {
        return search(root->right,target);
    }
}
void inorder(Node * root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}
int main(){
    Node * root =NULL;
    root=insert(root,11);
    insert(root,12);
    insert(root,2);
    insert(root,67);
    insert(root,6);
    insert(root,10);
    insert(root,76);
    insert(root,1);
    inorder(root);
    cout<<endl;
    int target = 2;
    Node * result = search(root, target);
    if(result!=NULL){
        cout<<target<<" is on this ADDRESS "<<result<<endl;
    }
    else{
        cout<<"target not found"<<endl;
    }
    return 0 ;

}