#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://beta.atcoder.jp/contests/arc087/tasks/arc087_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 grundy数使うまでは、それはそうだろなって思ったらが、
 具体的にどう行った形に落とし込むのかがわからなかった。
 
 んで、解説みた -> https://img.atcoder.jp/arc087/editorial.pdf
 
 こう行った考察はもっとしっかりせんとあかんな
 ================================================================
 */

/*-----------------------------*/
// Map[{l,k}] := cnt of a group of k strings such that they a common prefix of lenght l
map<pii,int> Map;
/*-------Trie Setting---------*/
const int Alphabets = 2;
const int AlphabetBase = '0'; // '0'
/*------------------------------------*/
class Trie {
public:
    struct node {
        bool isleaf;
        node *children[Alphabets];
        int id;
        int cnt;
        node() :cnt(0),isleaf(0), id(nodesize++) { memset(children, 0, sizeof children); }
    } *root;
    static int nodesize;
    
    // check children
    static bool is_free_node(node *n) {
        for (int i = 0; i < Alphabets; i++) {
            if (n->children[i] != NULL)return true;
        }
        return false;
    }
    
    bool _remove(const string& s, node *n, int level) {
        if (level == (int)s.size()) return 1;
        else {
            int idx = s[level] - AlphabetBase;
            if (_remove(s, n->children[idx], level + 1)) {
                Map[pii(level+1,n->children[idx]->cnt)]--;
                n->children[idx]->cnt--;
                return 1;
            }
        }
        return 1;
    }
    
    void DEL(const string& s, node *n,int level){
        if(level == (int)s.size()) return ;
        int idx = s[level] - AlphabetBase;
        n = n->children[idx];
        Map[pii(level+1, n->cnt)]--;
        n->cnt--;
        DEL(s,n,level+1);
    }

    static void clean_up(node *n) {
        if (n == 0 || n->isleaf) return;
        for (int i = 0; i < Alphabets; i++) clean_up(n->children[i]);
        delete n;
    }
    
public:
    Trie() { root = new node(); }
    ~Trie() { clean_up(root); }
    
    int getnodesize() { return nodesize; }
    void insert(string &s) {
        node *n = root;
        for (int level = 0; level < (int)s.size(); level++) {
            int idx = s[level] - AlphabetBase;
            if (n->children[idx] != NULL) n = n->children[idx];
            else {
                n->children[idx] = new node();
                n = n->children[idx];
            }
            n->cnt++;
            Map[pii(level+1,n->cnt)]++;
        }
        n->isleaf = 1;
    }
    bool exists(string &s) {
        node *n = root;
        for (int level = 0; level < (int)s.size(); level++) {
            int idx = s[level] - AlphabetBase;
            if (n->children[idx] == NULL) return 0;
            n = n->children[idx];
        }
        return (n != 0 && n->isleaf); //
    }
    bool remove(string &s) {
        return _remove(s, root, 0);
    }
    void DEL(string &s){
        DEL(s,root,0);
    }
};
int Trie::nodesize = 0;


ll calc(ll H){
    ll ret = 1;
    while(H%2==0){ ret *= 2; H/=2;}
    return ret;
}
ll dfs(Trie::node *n,ll H){
    ll ret = 0;
    if(n == NULL) return calc(H);
    if(n != 0 && n->isleaf) return 0;
    ret ^= dfs(n->children[0],H-1);
    ret ^= dfs(n->children[1],H-1);
    return ret;
}
string solve(){
    ll N,L; cin >> N >> L;
    vector<string> s(N); for(auto& in:s) cin >> in;
    Trie T;
    for(int i = 0; i < N;i++) T.insert(s[i]);
    Trie::node *root = T.root;
    if(dfs(root,L+1)) return "Alice";
    else return "Bob";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
