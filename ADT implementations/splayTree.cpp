#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
};

node *newNode(int key)
{
    node *Node = new node();
    Node->key = key;
    Node->left = Node->right = NULL;
    return (Node);
}

node *rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node *splay(node *root, int key)
{
    // Base cases: root is NULL or
    // key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            // First recursively bring the
            // key as root of left-left
            root->left->left = splay(root->left->left, key);

            // Do first rotation for root,
            // second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            // First recursively bring
            // the key as root of left-right
            root->left->right = splay(root->left->right, key);

            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Do second rotation for root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    else // Key lies in right subtree
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
            // Bring the key as root of
            // right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do second rotation for root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

node *insert(node *root, int k)
{

    if (root == NULL)
        return newNode(k);

    root = splay(root, k);

    if (root->key == k)
        return root;

    node *newnode = newNode(k);

    if (root->key > k)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }

    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }

    return newnode; // newnode becomes new root
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

node *delete_key(struct node *root, int key)
{
    struct node *temp;
    if (!root)
        return NULL;

    // Splay the given key
    root = splay(root, key);

    if (key != root->key)
        return root;

    // make root->right as root
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }

    // Else if left child exits
    else
    {
        temp = root;

        root = splay(root->left, key);

        root->right = temp->right;
    }

    free(temp);

    // return root of the new Splay Tree
    return root;
}

/* Driver code*/
int main()
{
    node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);
    cout << "Splay tree Inorder representation" << endl;
    inOrder(root);
    cout << endl;
    cout << endl;

    int data; // 25
    cout << "Enter data to insert into Splay tree :";
    cin >> data;
    root = insert(root, data);
    cout << "inOrder traversal after insertion" << endl;
    inOrder(root);
    cout << endl;
    cout << endl;

    int key; // 40
    cout << "Enter data to Delete from Splay tree :";
    cin >> key;
    root = delete_key(root, key);
    cout << "inOrder traversal After deletion" << endl;
    inOrder(root);
    return 0;
}

// This code is contributed by rathbhupendra
