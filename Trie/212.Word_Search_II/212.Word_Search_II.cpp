class TrieNode {
public:
    TrieNode() {
        isword = false;
    }
    ~TrieNode() {
        for (auto p: children) {
            if (p.second) delete p.second;
        }
    }
    bool isword;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string str) {
        TrieNode *p = root;
        for (auto ch: str) {
            if (!p->children[ch]) p->children[ch] = new TrieNode();
            p = p->children[ch];
        }
        p->isword = true;
    }
    TrieNode *root;
};

class Solution {
public:
    int t[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_set<string> used;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto str: words) trie.insert(str);
        
        vector<string> res;
        string start;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                for (auto a: trie.root->children) {
                    DFS(board, a.second, start + a.first, res, i, j);
                }
            }
        }
        
        return res;
    }
    
    void DFS(vector<vector<char>> &board, TrieNode *p, string cur, vector<string> &res, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') return;
        if (board[i][j] != cur.back()) return;
        if (p->isword && !used.count(cur)) {
            res.push_back(cur);
            used.insert(cur);
        }
        char temp = board[i][j];
        board[i][j] = '#';
        for (auto a: p->children) {
            for (int k = 0; k < 4; k++) {
                DFS(board, a.second, cur + a.first, res, i + t[k][0], j + t[k][1]);
            }
        }
        board[i][j] = temp;
    }
};