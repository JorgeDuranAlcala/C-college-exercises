#include <iostream>
#include "myqueue.cpp"
#include "Array.cpp"
#include <math.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int key);
    ~TreeNode();
};

TreeNode::TreeNode(int key)
{
    data = key;
    left = nullptr;
    right = nullptr;
}

TreeNode::~TreeNode()
{
    free(left);
    free(right);
}

class Tree
{
private:
    TreeNode *root;
    TreeNode *insertNodeHelper(TreeNode *root, int key);
    void inorderHelper(TreeNode *root);
    TreeNode *reverseTreeHelper(TreeNode *root);
    int *depthFirstValuesHelper(TreeNode *root, int *arr, int counter);
    Array<int> *brethFirstValuesHelper(TreeNode *root);
    bool includesNodeHelper(TreeNode *root, int key);
    int MSHelper(TreeNode *root);
    int SumLeafsHelper(TreeNode *root);
    void pllHelper(TreeNode *root);

public:
    Tree();
    ~Tree();
    void insert(int key);
    void inorder();
    void reverseTree();
    int *depthFirstValues();
    Array<int> *brethFirstValues();
    bool includesNode(int key);
    int MaxSumPath();
    int sumLeafs();
    void printAllLeftNodes();
};

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    free(root);
}

void Tree::pllHelper(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left)
    {
        cout << root->left->data << ", ";
    }
    pllHelper(root->left);
    pllHelper(root->right);
}

void Tree::printAllLeftNodes()
{
    pllHelper(root);
}

int Tree::SumLeafsHelper(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return abs(root->data) + SumLeafsHelper(root->left) + SumLeafsHelper(root->right);
}

int Tree::sumLeafs()
{
    return SumLeafsHelper(root);
}

int Tree::MSHelper(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int sumLeft = abs(root->data) + SumLeafsHelper(root->left);
    int sumRight = abs(root->data) + SumLeafsHelper(root->right);
    return max(sumLeft, sumRight);
}

int Tree::MaxSumPath()
{
    return MSHelper(root);
}

TreeNode *Tree::insertNodeHelper(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        TreeNode *temp = new TreeNode(key);
        return temp;
    }

    if (key > root->data)
    {
        root->right = insertNodeHelper(root->right, key);
    }
    else
    {
        root->left = insertNodeHelper(root->left, key);
    }

    return root;
}

void Tree::insert(int key)
{
    root = insertNodeHelper(root, key);
}

void Tree::inorderHelper(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << ", ";

    inorderHelper(root->left);
    inorderHelper(root->right);
}

void Tree::inorder()
{
    inorderHelper(root);
    cout << "\n";
}

TreeNode *Tree::reverseTreeHelper(TreeNode *root)
{
    if (root == nullptr)
        return root;
    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = temp;

    root->left = reverseTreeHelper(root->left);
    root->right = reverseTreeHelper(root->right);

    return root;
}

void Tree::reverseTree()
{
    root = reverseTreeHelper(root);
}

int *Tree::depthFirstValuesHelper(TreeNode *root, int *arr, int counter)
{
    if (root != nullptr)
    {
        arr[counter++] = root->data;
        depthFirstValuesHelper(root->left, arr, counter);
        depthFirstValuesHelper(root->right, arr, counter);
    }

    return arr;
}

int *Tree::depthFirstValues()
{
    int arr[] = {};
    return depthFirstValuesHelper(root, arr, 0);
}

Array<int> *Tree::brethFirstValuesHelper(TreeNode *root)
{
    if (root == nullptr)
        return {};
    Queue<TreeNode *> *q = new Queue<TreeNode *>();
    Array<int> *nodes = new Array<int>();
    q->enqueue(root);
    while (!q->isEmpty())
    {
        TreeNode *currentNode = q->dequeue();
        nodes->push(currentNode->data);
        if (currentNode->left != nullptr)
            q->enqueue(currentNode->left);
        if (currentNode->right != nullptr)
            q->enqueue(currentNode->right);
    }
    return nodes;
}

Array<int> *Tree::brethFirstValues()
{
    return brethFirstValuesHelper(root);
}

bool Tree::includesNodeHelper(TreeNode *root, int key)
{
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;

    return includesNodeHelper(root->left, key) || includesNodeHelper(root->right, key);
}

bool Tree::includesNode(int target)
{
    return includesNodeHelper(root, target);
}

Tree *treesFactory(int *arr, int n)
{
    Tree *tree = new Tree();
    for (int i = 0; i < n; i++)
    {
        tree->insert(arr[i]);
    }
    return tree;
}

void printArr(int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main()
{
    int values[] = {10, 40, 25, 2, 1, 3, 45};
    /* 
         10
       /    \
      2      40
    /   \    / \
   1     3  25  45
*/
    Tree *myTree = treesFactory(values, sizeof(values) / sizeof(values[0]));
    /* Array<int> *nodes = myTree->brethFirstValues();
    nodes->print(); // expected output: [10,2,40,1,3,25,45]
    int msp = myTree->MaxSumPath();
    cout << "max sum path is: " << msp << "\n";
    cout << "print all left node values"
         << "\n"; */
    myTree->printAllLeftNodes();
    /* Array<int> *slicedArr = nodes->slice(0, 3);
    slicedArr->print(); 120

    cout << slicedArr->size(); */
    return 0;
}
