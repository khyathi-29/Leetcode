
struct Node {
    Node* next[26] = {nullptr};
    bool end = false;
};

class Trie {
public:
    Node* root = new Node();
    void insert(const string& w) {
        Node* cur = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!cur->next[idx]) cur->next[idx] = new Node();
            cur = cur->next[idx];
        }
        cur->end = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& w : wordDict) trie.insert(w);
        unordered_map<int, vector<string>> memo;  // start idx -> sentences from s[start:]
        return dfs(0, s, trie.root, memo);
    }

private:
    vector<string> dfs(int start, const string& s, Node* root,
                       unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) return memo[start];
        if (start == (int)s.size()) return memo[start] = {""}; // base: empty tail

        vector<string> res;
        Node* cur = root;
        // extend one char at a time; stop as soon as trie path breaks
        for (int i = start; i < (int)s.size(); ++i) {
            int idx = s[i] - 'a';
            cur = cur->next[idx];
            if (!cur) break;                  // no prefix continues → prune
            if (cur->end) {                   // s[start..i] is a word
                string word = s.substr(start, i - start + 1);
                auto tails = dfs(i + 1, s, root, memo);
                for (auto& tail : tails) {
                    res.push_back(tail.empty() ? word : word + " " + tail);
                }
            }
        }
        return memo[start] = res;
    }
};