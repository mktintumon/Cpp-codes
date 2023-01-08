#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int key;
    node *left, *right;
};

node *newNode(int key){
    node *Node = new node();
    Node->key = key;
    Node->left = Node->right = NULL;
    return (Node);
}

node *rightRotate(node *x){
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node *leftRotate(node *x){
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node *splay(node *root, int key){
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key){
        // Key is not in tree
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key){
            root->left->left = splay(root->left->left, key);


            root = rightRotate(root);
        }
        else if (root->left->key < key) 
        // Zig-Zag (Left Right)
        {
            root->left->right = splay(root->left->right, key);

            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else 
    // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL)
            return root;

        // Zig-Zag (Right Left)
        if (root->right->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);

            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key) // Zag-Zag (Right Right)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do second rotation for root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

node *insert(node *root, int k){
    if (root == NULL)
        return newNode(k);

    root = splay(root, k);

    if (root->key == k)
        return root;

    node *newnode = newNode(k);

    if (root->key > k){
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }

    else{
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }

    return newnode; // newnode becomes new root
}

void inOrder(node *root){
    if (root != NULL){
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

node *delete_key(node *root, int key){
    node *temp;
    if (!root)
        return NULL;

    // Splay the given key
    root = splay(root, key);

    if (key != root->key)
        return root;

    // make root->right as root
    if (!root->left){
        temp = root;
        root = root->right;
    }

    // Else if left child exits
    else{
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    delete(temp);
    return root;
}


int main(){
    node *root = newNode(90);
    root->left = newNode(45);
    root->right = newNode(180);
    root->left->left = newNode(35);
    root->left->left->left = newNode(25);
    root->left->left->left->left = newNode(15);

    cout << "Splay tree CREATION " << endl;
    cout << "Inorder view ---> ";
    inOrder(root);
    cout << endl;
    cout << endl;

    int data; // 10
    cout << "Enter data to insert : ";
    cin >> data;
    root = insert(root, data);
    cout << "Data " << data << " INSERTED into splay tree." << endl;
    cout << "Inorder view ---> ";
    inOrder(root);
    cout << endl;
    cout << endl;

    int key; // 35
    cout << "Enter data to Delete : ";
    cin >> key;
    root = delete_key(root, key);
    cout << "Data " << key << " DELETED from splay tree." << endl;
    cout << "Inorder view ---> ";
    inOrder(root);
    return 0;
}

