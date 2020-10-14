Inoder:

void inOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */
} 

Preorder:
*****************************************************


void iterativePreorder(node* root) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // Create an empty stack and push root to it 
    stack<node*> nodeStack; 
    nodeStack.push(root); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) { 
        // Pop the top item from stack and print it 
        struct node* node = nodeStack.top(); 
        printf("%d ", node->data); 
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (node->right) 
            nodeStack.push(node->right); 
        if (node->left) 
            nodeStack.push(node->left); 
    } 
} 

Postorder using 2 stacks:
************************************************************************************
// An iterative function to do post order 
// traversal of a given binary tree 
void postOrderIterative(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    // Create two stacks 
    stack<Node *> s1, s2; 
  
    // push root to first stack 
    s1.push(root); 
    Node* node; 
  
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
  
    // Print all elements of second stack 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
    } 
} 


postordet using single stack
******************************************************************

void postOrder(Node * root) {
  
  if (root == NULL) return ;
  
  stack <int>s;
  
  do {
      while (root) {
        if (roo->right)
          s.push(root->right);
        s.push(root);
        root = root->left;
      }
      
      root = s.top();
      s.pop();
      
      if (root->right && root->right == s.top) {
          Node *temp = s.top;
          s.pop();
          s.push(root);
          root = temp;
      } else {
        printf ("%d", root->data);
        root = NULL;
      }
  } while (s.empty() != true);
}
