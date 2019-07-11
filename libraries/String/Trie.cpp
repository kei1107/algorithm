#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

// Trie
/*-----------------------------*/
// Map[{l,k}] := cnt of a group of k strings such that they a common prefix of lenght l
map<pii,int> Map;
/*-------Trie Setting---------*/
const int Alphabets = 26;
const int AlphabetBase = 'a'; // '0'
/*------------------------------------*/
class Trie {
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

void test(){
#define debug(x) cerr << #x << ": " << x << endl
    /* TEST !! */
    string s[8] = { "a","to","tea","ted","ten","i","in","inn" };
    Trie T;
    for (int i = 0; i < 8; i++) T.insert(s[i]);
    string m = "to";
    cout << T.exists(m) << endl;
    string del = "tea";
    debug(T.remove(del));
    cout << T.exists(del) << endl;
    debug(T.getnodesize()); // 10 + 1(root)
}

/* verify : https://www.codechef.com/problems/NPLFLF */
void NPLFLF(){
    int Q,q,L,K,X;
    cin>>Q;
    Trie T;
    vector<string> vs(Q);
    vector<int> insr(Q);
    for(int i = 0; i < Q;i++){
        cin>>q;
        if(q==1){
            cin>>vs[i];
            reverse(vs[i].begin(),vs[i].end());
            T.insert(vs[i]);
            insr[i]++;
        }else if(q==2){
            cin>>K>>L;
            if(Map[pii(L,K)]>0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else {
            cin>>X; X--;
            if(insr[X]){
                insr[X]--;
                T.remove(vs[X]);
            }
        }
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
 //   test();
    NPLFLF();
    return 0;
}
