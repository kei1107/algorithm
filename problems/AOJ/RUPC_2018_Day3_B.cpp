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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/B>
問題文============================================================
 N 個の 1 次式 y=aix (1≤i≤N) が与えられます。
 
 1,2,…,N の部分列 s1,s2,…,sk (i<j ならば si<sj) を考えます。
 まず式 s1 を x=1 として評価することから始め、
 式 si を評価した結果を式 si+1 に x として入力することを考えます。すなわち以下のようになります。
 
 x0=1
 xi=a_si*x_i−1 (1≤i≤k)
 
 このとき、xk が最大となるような部分列を求めてください。
 ただし、そのような部分列が複数考えられる場合は列の長さが最小のものを求めるとします。
 また、さらにそのような部分列が複数考えられる場合は辞書順最小のものを求めるとします。
 ただし、部分列 s1,s2,…,sm が t1,t2,…,tn より辞書順で小さいとは以下のいずれかの場合を指します。
 
 ある i が存在して s1=t1,s2=t2,…,si=ti かつ si+1<ti+1
 m<n で、s1=t1,s2=t2,…,sm=tm
 
=================================================================

解説=============================================================

 2 があれば全部とったほうが良い
 
 -2は偶数であれば、全部取る
     奇数であれば -1があれば全部と-1をとる
                -1がなければ最後の-2を諦める
 
================================================================
*/

void solve(){
    int N; cin >> N;
    vector<int> a(N); for(auto& in:a) cin >> in;
    
    // get 2
    vector<int> idx2;
    // get -2
    vector<int> idxn2;
    // exist -1
    bool n1 = false;
    int idxn1 = -1;
    
    for(int i = 0; i < N;i++){
        if(a[i] == 2) idx2.push_back(i);
        if(a[i] == -2) idxn2.push_back(i);
        if(!n1 && a[i] == -1) { n1 = true; idxn1 = i; }
    }
    
    vector<int> ans;
    for(auto v:idx2) ans.push_back(v);
    for(auto v:idxn2) ans.push_back(v);
    
    if(idxn2.size()%2==0){
        sort(ans.begin(),ans.end());
    }else{
        if(n1) ans.push_back(idxn1);
        else ans.pop_back();
        sort(ans.begin(),ans.end());
    }
    cout << ans.size() << endl;
    for(auto v:ans) cout << v+1 << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
