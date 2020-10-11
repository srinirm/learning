Youtube link: https://www.youtube.com/watch?v=xqsaAhQC6c8&list=PLEJXowNB4kPyO3prfyAh8ms7VltG5o47M&index=8&ab_channel=TECHDOSE

insert: O(keylenth)
delete: O (lenght)
search: O(length)

space: O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
    
#define SIZE 26
#define INDEX(x) ((int)x - (int)'a')

typedef struct TrieNode {
    TrieNode *child[SIZE];
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool is_end;
    int count;
}TrieNode;

TrieNode * getNode () {
    TrieNode * temp = (TrieNode *)malloc(sizeof(TrieNode));
    if (temp) {
        temp->is_end = false;
        temp->count = 0;
        for(int i =0; i < SIZE; i++ ) {
            temp->child[i] = NULL;
        }
        return temp;        
    }
    return NULL;
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node
void insert (TrieNode *root, const char *str) {
    
    int index, depth;
    int len = strlen(str);
    TrieNode *tmp = root;
    
    for (depth = 0 ; depth < len; depth++) {
        index = INDEX(str[depth]);

        if (!tmp->child[index]) {
            tmp->child[index] = getNode();

        }   
        tmp->count += 1; 
        // mark last node as leaf 
        tmp = tmp->child[index];
    }
    tmp->is_end = true;
}


// Returns true if key presents in trie, else 
// false 
bool search (TrieNode *root, const char *str) {

    int index, depth;
    int len = strlen(str);
    TrieNode *tmp = root;
        
    for (depth = 0 ; depth < len; depth++) {
        index = INDEX(str[depth]);  

        if (!tmp->child[index]) {
            return false;
        }
        tmp = tmp->child[index];
    }
    return ((tmp != NULL) && (tmp->is_end == true));
}

bool isEmpty (TrieNode *root) {
    for (int i =0; i< SIZE; i++) {
        if (root->child[i])
            return false;
    }
    return true;
}

// Recursive function to delete a key from given Trie 
TrieNode* deleteNode (TrieNode *root, const char *str, int depth = 0) {

    if (!root) return NULL;

     // If last character of key is being processed 
    if (depth == strlen(str)) {
        if(root->is_end) {
            root->is_end = false;
        }
        root->count -= 1;
        if (isEmpty(root)) {
            free(root);
            root = NULL;
        }
        return root;
    }

    // If not last character, recur for the child 
    // obtained using ASCII value
    int index = INDEX(str[depth]);
    root->child[index] = deleteNode(root->child[index], str, depth+1);

    root->count -= 1;
    // If root does not have any child (its only child got  
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->is_end == false) {
        free(root);
        root = NULL;
    }
    return root;
}
//iterative delete
void  Delete_iter (TrieNode * root, const char* str) {

    stack<TrieNode *> s;
    TrieNode * tmp = root;
    int len = strlen(str);
    int depth = 0;
    int index;

    for (depth = 0; depth < len; depth++) {
        index = INDEX(str[depth]);        
        if (tmp->child[index]) {
            s.push(root);
        } else {
            printf("no match");
            return;
        }
        tmp = tmp->child[index];
    }
    
    if (tmp->is_end == false) { 
        printf("not match\n");
        return;
    }
    tmp->is_end = false;

    while(!s.empty()) {
        tmp = s.top();
        s.pop();
        if (isEmpty(tmp) && tmp->is_end == false) {
            free(root);
            tmp = NULL;
        }
    }
    return;
}




int main () {

    char *keys[] = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane" }; 
    int n = sizeof(keys) / sizeof(keys[0]); 
  
    struct TrieNode* root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++){ 
        insert(root, keys[i]); 
        printf("%s\n", keys[i]);
    }
  
    // Search for different keys 
    search(root, "the") == true ? printf( "Yes\n") : printf("No\n"); 
    search(root, "these") == true ? printf( "Yes\n") : printf("No\n"); 
  
    deleteNode(root, "heroplane"); 
    search(root, "hero") ? printf( "Yes\n") : printf("No\n");
   
    return 0;
}
