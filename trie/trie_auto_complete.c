// Recursive function to print auto-suggestions for given 
// node. 
void suggestionsRec(struct TrieNode* root, string currPrefix) 
{ 
    // found a string in Trie with the given prefix 
    if (root->isWordEnd) 
    { 
        cout << currPrefix; 
        cout << endl; 
    } 
  
    // All children struct node pointers are NULL 
    if (isLastNode(root)) 
        return; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    { 
        if (root->children[i]) 
        { 
            // append current character to currPrefix string 
            currPrefix.push_back(97 + i); 
  
            // recur over the rest 
            suggestionsRec(root->children[i], currPrefix); 
            // remove last character 
            currPrefix.pop_back(); 
        } 
    } 
} 
  
// print suggestions for given query prefix. 
int printAutoSuggestions(TrieNode* root, const string query) 
{ 
    struct TrieNode* pCrawl = root; 
  
    // Check if prefix is present and find the 
    // the node (of last level) with last character 
    // of given string. 
    int level; 
    int n = query.length(); 
    for (level = 0; level < n; level++) 
    { 
        int index = CHAR_TO_INDEX(query[level]); 
  
        // no string in the Trie has this prefix 
        if (!pCrawl->children[index]) 
            return 0; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // If prefix is present as a word. 
    bool isWord = (pCrawl->isWordEnd == true); 
  
    // If prefix is last node of tree (has no 
    // children) 
    bool isLast = isLastNode(pCrawl); 
  
    // If prefix is present as a word, but 
    // there is no subtree below the last 
    // matching node. 
    if (isWord && isLast) 
    { 
        cout << query << endl; 
        return -1; 
    } 
  
    // If there are are nodes below last 
    // matching character. 
    if (!isLast) 
    { 
        string prefix = query; 
        suggestionsRec(pCrawl, prefix); 
        return 1; 
    } 
} 
