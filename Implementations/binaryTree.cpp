#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildBT(){
    int data;
    cout << "Enter data : " ;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Left of " << data << " -> ";
    root->left = buildBT();
    cout << "Right of " << data << " -> ";
    root->right = buildBT();
    return root;
}

void display(Node* root){
    if(root == NULL) return;
    
    if(root->left != NULL){
        cout << root->left->data;
    }
    else{
        cout << "--";
    }

    cout << " <- " << root->data << " -> " ;

    if(root->right != NULL){
        cout << root->right->data;
    }
    else{
        cout << "--";
    }
    cout << endl;

    display(root->left);
    display(root->right);
}

void inorder(Node* node){
    if(node == NULL) return;
    inorder(node->left);
    cout << node->data << "  ";
    inorder(node->right);
}

void preorder(Node* node){
    if(node == NULL) return;
    cout << node->data << "  ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << "  ";
}
 
int main(){
  
   Node* root = buildBT();
   
   cout << endl;
   cout << "Tree : " << endl;
   cout << "=================="<< endl;
   display(root);

   cout << endl;
   cout << "InOrder Traversal : "; 
   inorder(root);
   cout << endl;
   cout << "PreOrder Traversal : ";
   preorder(root);
   cout << endl;
   cout << "PostOrder Traversal : " ;
   postorder(root);
   cout << endl;

   return 0;
}