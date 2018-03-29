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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/G>
問題文============================================================
 文字列 S と、 N 個の文字列 p1,p2,…,pN からなる文字列の集合 P が与えられる。
 文字列 S に対して、次の操作を考える。
 
 文字列 S 中のどれか 1 文字を ‘*’ に変える
 S 中の i 文字目の文字を si とする。
 S 中の任意の連続した部分文字列 Sij=sisi+1…sj と P 中の任意の要素 pk の組に対して、
 Sij≠pk を満たすようにするための最小の操作回数を求めよ。
 

=================================================================

解説=============================================================

 アホコラ使った、区間スケジューリング
================================================================
*/


/*-------Aho Corasick Setting---------*/
const int Alphabets = 26;
const int AlphabetBase = 'a' ; // '0'
/*------------------------------------*/
class Aho_Corasick{
public:
    struct PMA{
        PMA *fail;
        PMA *next[Alphabets];
        vector<int> accepts; // accepts id
        PMA():fail(NULL){memset(next,0,sizeof next);}
        ~PMA() { delete fail; for(int i = 0; i < Alphabets ; i++) delete next[i];}
    };
    
    PMA *Root;
    int PatternSize;
    
    // O( Σ]|p[i]| Alphabets )
    void buildMPA(vector<string>& pattern){
        PatternSize = (int)pattern.size();
        PMA *root = new PMA, *now;
        root->fail = root;
        for(int i = 0 ; i < (int)pattern.size(); i++){
            now = root;
            for(int j = 0 ; j < (int)pattern[i].size(); j++){
                int c = pattern[i][j] - AlphabetBase;
                if(now->next[c]==NULL)now->next[c] = new PMA;
                now = now->next[c];
            }
            now->accepts.push_back(i);
        }// Trie
        
        queue<PMA*> Q;
        for(int i = 0; i < Alphabets; i++){
            if(root -> next[i] == NULL){
                root -> next[i] = root;
            }else {
                root->next[i] -> fail = root;
                Q.push(root->next[i]);
            }
        }
        while(!Q.empty()){
            now = Q.front(); Q.pop();
            for(int i = 0; i < Alphabets; i++){
                if(now->next[i]){
                    PMA *nxt = now->fail;
                    while(nxt->next[i] == NULL)nxt = nxt -> fail;
                    now-> next[i]->fail = nxt -> next[i];
                    now->next[i]->accepts = mergev(now->next[i]->accepts, nxt->next[i]->accepts );
                    Q.push(now->next[i]);
                }
            }
        }
        Root = root;
    }
    
    // target S , res:include id (exist or times). O( |S| + Σ|p[i]| )
    PMA* match(PMA* pma, string &S, vector<vector<int>> &res){
        res.resize(PatternSize);
        for(int i = 0; i < (int)S.size(); i++){
            int c = S[i] - AlphabetBase;
            while(pma -> next[c] == NULL){
                pma = pma -> fail;
            }
            pma = pma -> next[c];
            for(int j = 0; j < (int)pma->accepts.size(); j++ ){
                res[pma->accepts[j]].push_back(i);// ++; //not sum if sum, vec++
            }
        }
        return pma;
    }
    
    PMA* NextStep(PMA* pma, char cc){
        int c = cc- AlphabetBase;
        while(pma->next[c] == NULL )pma = pma->fail;
        pma = pma-> next[c];
        return pma;
    }
private:
    // unique and merge
    vector<int> mergev(vector<int> &a, vector<int> &b){
        vector<int> target;
        set_union(a.begin(),a.end(),b.begin(),b.end(), back_inserter(target));
        return target;
    }
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    
    string s; cin >> s;
    ll N; cin >> N;
    vector<string> vs(N);
    for(auto& in:vs) cin >> in;
    
    Aho_Corasick Aho; Aho.buildMPA(vs);
    Aho_Corasick::PMA *saveroot;
    saveroot = Aho.Root;
    
    int ans = 0;
    for(char c:s){
        saveroot = Aho.NextStep(saveroot, c);
        if(saveroot->accepts.size()){
            ans++;
            saveroot = Aho.Root;
        }
    }
    cout << ans << endl;
	return 0;
}
