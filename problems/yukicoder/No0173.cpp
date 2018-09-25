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
 <url:https://yukicoder.me/problems/no/173>
 問題文============================================================
 =================================================================
 解説=============================================================
 実際にシミュレーションを行い
 モンテカルロ法で確率を出す。（制約が小さいので)
 ================================================================
 */

typedef long double ld;

vector<int> get(vector<int> V,ld P){
    vector<int> ret;
    size_t sz = V.size();
    for(int i = 0; i < sz-1;i++){
        int nowsz = (int)V.size();
        ld p = rand()*1.0/RAND_MAX;
        if(p < P){
            ret.push_back(*V.begin());
            V.erase(V.begin());
        }else{
            int idx = rand()%(V.size()-1);
            ret.push_back(V[idx+1]);
            V.erase(V.begin()+idx+1);
        }
    }
    ret.push_back(*V.begin());
    return ret;
}
ld solve(){
    srand((unsigned int)time(NULL));
    ld res = 0;
    int N; cin >> N;
    ld Pa,Pb; cin >> Pa >> Pb;
    vector<int> A(N),B(N);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    ld win = 0;
    ld sum = 0;
    for(int kassa = 0; kassa < 500000; kassa++){
        auto tA = get(A,Pa),tB = get(B,Pb);
        
        int score = 0;
        for(int i = 0; i < N;i++){
            if(tA[i] > tB[i]) score += tA[i] + tB[i];
            if(tA[i] < tB[i]) score -= tA[i] + tB[i];
        }
        sum+=1;
        if(score>0)win+=1;
    }
    res = win/sum;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
