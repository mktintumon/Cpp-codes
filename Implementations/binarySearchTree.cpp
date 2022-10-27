#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

class BSTree{
    public:
        Node* root;

        BST();

        // invoking internal functions
        Node* insert(Node* node, int data);
        Node* search(Node* node , int data);
        Node* remove(Node* node , int data);
        int max(Node* node);
        int min(Node* node);
        void display(Node* node);
        void inorder(Node* node);
        void preorder(Node* node);
        void postorder(Node* node);

        // user functions
        void insert(int key);
        bool search(int data);
        void remove(int data);
        int max();
        int min();
        void display();
        void inorder();
        void preorder();
        void postorder();
};

Node* BSTree::insert(Node* node, int data) {
    if(node == NULL){
        node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if(data > node->data){
        node->right = insert(node->right , data);
    }
    else{
        // data < node->data
        node->left = insert(node->left , data);
    }

    return node;
}

void BSTree::insert(int data){
    root = insert(root , data);
}

void BSTree::inorder(Node* node){
    if(node == NULL) return;
    inorder(node->left);
    cout << node->data << "  ";
    inorder(node->right);
}

void BSTree::inorder(){
    inorder(root);
    cout << endl ;
}

void BSTree::preorder(Node* node){
    if(node == NULL) return;
    cout << node->data << "  ";
    preorder(node->left);
    preorder(node->right);
}

void BSTree::preorder(){
    preorder(root);
    cout << endl ;
}

void BSTree::postorder(Node* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << "  ";
}

void BSTree::postorder(){
    postorder(root);
    cout << endl ;
}

void BSTree::display(Node* root){
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

void BSTree::display(){
    display(root);
    cout << "================\n";
}

Node* BSTree::search(Node* node, int data){
    if (node == NULL) return NULL;
    else if(node->data == data) 
        return node;
    else if(node->data < data) 
        return search(node->right, data);
    else 
        // node->data > data
        return search(node->left, data);
}

bool BSTree::search(int data){
    Node * result = search(root, data);
    return result == NULL ? false : true;
    cout << endl;
}


// REMOVE FUNCTION NOT WORKING
Node* BSTree::remove(Node* node , int data){
    if(root  == NULL){
        return NULL;
    }
    
    if(data > node->data){
        root->right = remove(node->right, data);
    }
    else if(data < node->data){
        node->left = remove(node->left, data);
    }
    else{
        //0 child  OR  1 child
        if(node->left == NULL || node->right == NULL ){
            return node->left != NULL ? node->left : node->right;
        }
        
        // 2  child
        int maxEle = max(node->left);
        node->data = maxEle;
        node->left = remove(node->left, maxEle);
        
    }
    return node;
}

void BSTree::remove(int data){
    root = remove(root, data);
}

int BSTree::max(Node * node){
    if(node == NULL)
        return -1;
    else if(node->right == NULL)
        return node->data;
    else
        return max(node->right);
}

int BSTree::max(){
    return max(root);
    cout << endl;
}

int BSTree::min(Node * node){
    if(node == NULL)
        return -1;
    else if(node->left == NULL)
        return node->data;
    else
        return min(node->left);
}

int BSTree::min(){
    return min(root);
    cout << endl;
}

int main(){
    BSTree* tree = new BSTree();

    int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53};

    for(int &data : keys)
        tree->insert(data);

    cout << "Tree data: \n";
    cout << "================\n";
    tree->display();
    cout << endl;

    cout << "InOrder Traversal   : " ;
    tree->inorder();

    cout << "Preorder Traversal  : " ;
    tree->preorder();

    cout << "postorder Traversal : " ;
    tree->postorder();

    cout << "Search data : ";
    bool found = tree->search(18);
    if(found) cout << "Found";
    else cout << "Not Found";
    cout<< endl;

    // Retrieving minimum and maximum data
    cout << "Max. data : " << tree->max();
    cout << endl;
    cout << "Min. data : " << tree->min();
    cout << endl;

    // cout << "Removing key 15" << endl;
    // tree->remove(23);

    cout << endl;
    return 0;
}
