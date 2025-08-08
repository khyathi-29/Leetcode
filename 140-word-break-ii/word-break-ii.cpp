struct Node {
    Node* list[26];
    bool End = false;
    Node() { // IMPORTANT: initialize child pointers
        for (int i = 0; i < 26; ++i) list[i] = nullptr;
    }
    void assignNode(char c, Node* node) { list[c - 'a'] = node; }
    Node* returnNode(char c) { return list[c - 'a']; }
    bool isEnd() { return End; }
    void setEnd() { End = true; }
};

class Trie {
    Node* root;
public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->returnNode(ch) == nullptr) {
                temp->assignNode(ch, new Node());
            }
            temp = temp->returnNode(ch);
        }
        temp->setEnd();
    }

    bool search(const string& word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->returnNode(ch) == nullptr) return false;
            temp = temp->returnNode(ch);
        }
        return temp->isEnd();
    }

    bool startsWith(const string& prefix) {
        Node* temp = root;
        for (char ch : prefix) {
            if (temp->returnNode(ch) == nullptr) return false;
            temp = temp->returnNode(ch);
        }
        return true;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         Trie trie;
        for (const string& w : wordDict) trie.insert(w);

        // memo[idx] -> all sentences that can be formed from s[idx:]
        unordered_map<int, vector<string>> memo;
        return dfs(0, s, trie, memo);
    }
    vector<string> dfs(int pos, const string& s, Trie& trie,
                       unordered_map<int, vector<string>>& memo) {
        if (pos == (int)s.size()) return {""}; // empty tail = valid termination
        if (memo.count(pos)) return memo[pos];

        vector<string> res;
        string prefix; // grow s[pos..i]
        for (int i = pos; i < (int)s.size(); ++i) {
            prefix.push_back(s[i]);

            // prune early: if no word starts with this prefix, stop extending
            if (!trie.startsWith(prefix)) break;

            if (trie.search(prefix)) {
                // get sentences from the rest
                vector<string> tails = dfs(i + 1, s, trie, memo);
                for (const string& tail : tails) {
                    // join current word + (optional) space + tail
                    if (tail.empty()) res.push_back(prefix);
                    else res.push_back(prefix + " " + tail);
                }
            }
        }
        memo[pos] = move(res);
        return memo[pos];
    }
};