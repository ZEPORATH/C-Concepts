#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node(int data):key(data){}
    int key;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* root = new Node(data);
    return root;
}

Node* insert(Node* root, int data)
{
    if (root == nullptr) 
        return newNode(data);
    if (root->key < data)
        root->right = insert(root->right, data);
    if (root->key > data)
        root->left = insert(root->left, data);
    return root;
}

int distanceFromRoot(Node* root, int key)
{
    if (root->key == key)
        return 0;
    else if (root->key > key)
        return 1 + distanceFromRoot(root->left, key);
    return 1 + distanceFromRoot(root->right, key);
}

int distanceBetween2(Node* root, int a, int b)
{
    if (!root)
        return 0;

    if (root->key > a && root->key > b)
        return distanceBetween2(root->left, a, b);
    
    if (root->key < a && root->key < b)
        return distanceBetween2(root->right, a, b);
    
    if (root->key >= a && root->key <= b)
        return distanceFromRoot(root, a) + distanceFromRoot(root, b);
};

int distance(vector<int> arr, int node1, int node2)
{
    Node* root = newNode(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        insert(root, arr[i]);
    }

    if (node1 > node2)
        swap(node1, node2);

    return distanceBetween2(root, node1, node2);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {15, 123, 5, 6, 32, 7, 23, 12};
    cout << distance(arr, 12, 6) << endl;
    return 0;
}
