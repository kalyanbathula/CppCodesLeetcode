class trie{
    public:
      bool wordCount;
      trie* links[26];
    trie(){
        wordCount=0;
        for (int index =0; index < 26; index++){
            links[index]=NULL;
        }
    }
};

trie *head = new trie();

void addWord(string word){
    int size = word.length();
    trie *ptr = head;
    for (int pos = 0; pos < size; pos++){
        int index = word[pos] - 97;
        if(ptr->links[index]){
            ptr = ptr->links[index];
        }
        else{
            trie *temp = new trie();
            ptr->links[index] = temp;
            ptr = temp;
        }
    }
    ptr->wordCount+= 1; 
}

void dfs(trie *ptr,vector<string> &v,string str){
    
    if(ptr->wordCount>=1){
        v.push_back(str);
    }
    for (int index = 0; index < 26; index++){
        if (ptr->links[index]){
            char u = 97 + index;
            dfs(ptr->links[index],v,str+u);
        }
    }
}
vector<string> autocomplete(string word){
    trie *ptr = head;
    int size = word.length();
    for (int pos = 0; pos < size; pos++){
        int index = word[pos] - 97;
        if(ptr->links[index])
            ptr = ptr->links[index];
        else break;
    }
    vector<string> v;
    dfs(ptr,v,word);
    return v;
}
int main() {
    addWord("abcd");
    addWord("abc");
    addWord("ef");
    vector<string> v = autocomplete("e");
    for(auto it : v){
        cout<<it<<endl;
    }
}