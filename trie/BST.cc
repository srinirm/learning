#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <unordered_set>
using namespace std;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node * get_node(int data) {
    Node * temp = (Node *)malloc(sizeof(struct Node));
    if (temp == NULL) return NULL;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node * insert_node(Node *root, int data) {
    
    if (root == NULL) {
        Node * temp = get_node(data);
        return temp;
    } 

    if (root->data > data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
    
}

Node * minvalue (Node * root) {
    
    while (root->left != NULL)
        root = root->left;
    return root; 
}

Node * delete_node(Node *root, int data) {

    if (root == NULL) 
        return NULL;

    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        
        if (root->left == NULL) {
            Node * temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node * temp = root->left;
            free(root);
            return temp;
        } 

        Node * temp = minvalue(root->right);
        root->data = temp->data;

        root->right = delete_node(root->right, temp->data);

    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void level_order(Node *root) {
    if (root == NULL) return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty()) {
        Node *f = q.front();
        printf("%d ", f->data);
        q.pop();

        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
}


bool findpairinbst(Node *root, int sum){

    unordered_set <int> set;

    queue<Node *> q;
     q.push(root);

    while (!q.empty()) {
        Node *f = q.front();
        if(set.find(sum - f->data) != set.end()) {
            printf("pair %d + %d = %d\n", (sum - f->data), f->data, sum);
            return true;
        }
        q.pop();
        set.insert(f->data);
        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
    return false;
}


Node * search_node(Node *root, int data) {
    if (root == NULL) return NULL;
    
    if (root->data == data){
        return root;
    }
    if (root->data > data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }    
}

int main () {
    Node * root = NULL;

    root = insert_node(root, 30);
    insert_node(root, 5);
    insert_node(root, 10);
    insert_node(root, 50);
    insert_node(root, 44);
    insert_node(root, 55);
    insert_node(root, 8);
    printf("root %d\n", root->data);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    level_order(root);
     printf("\n");
    
    Node *t = minvalue(root);
    printf("min: %d\n", t->data);
    //root = delete_node(root, 5);
    level_order(root);
     printf("\n");
    findpairinbst(root, 55);
    return 0;
}
