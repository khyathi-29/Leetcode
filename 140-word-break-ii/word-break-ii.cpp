class Node{
    public:
        Node* next[26];
        bool end = false;
    };
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string s)
    {
        Node* curr = root;
        for( char c : s)
        {
            int idx = c-'a';
            if(curr->next[idx]==NULL) curr->next[idx]= new Node();
            curr = curr->next[idx];
        }
        curr->end = true;
    }
};

class Solution {
public:

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for(string s: wordDict) trie->insert(s);
        unordered_map<int,vector<string>> memo;
        return dfs(0,trie,s,memo);
    }
    vector<string> dfs(int idx,Trie* trie, string s,unordered_map<int,vector<string>>& memo)
    {
        if(idx==s.size()) return {""};
        if(memo.find(idx)!=memo.end()) return memo[idx];
        Node* curr = trie->root;
        vector<string> res;
        for( int i = idx ; i<s.size();i++)
        {
            int j = s[i]-'a';
            curr = curr->next[j];
            if(curr==NULL) break;
            if(curr->end==true)
            {
                string word = s.substr(idx, i - idx + 1);
                auto tails = dfs(i + 1, trie ,s, memo);
                for (auto& tail : tails) {
                    res.push_back(tail.empty() ? word : word + " " + tail);
                }
            }

        }
        memo[idx] = res;
        return res;
    }
};