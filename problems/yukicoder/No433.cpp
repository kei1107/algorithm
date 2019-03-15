#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/433>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 問題より優先度は
 
 解いた問題数 > 学内順位 > ペナルティ
 
 となる。
 
 よって、それぞれ求めてor確認してpriority_queueで出力すればいい
 ================================================================
 */

struct team{
    int S,P,U,id;
    team(int S = 0,int P = 0,int U = 0,int id = 0):S(S),P(P),U(U),id(id){}
    bool operator < (const team& c1) const{
        if(S != c1.S) return S < c1.S;
        return P > c1.P;
    }
};
template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    vector<team> T(N);
    for(int i = 0; i < N;i++){
        int S,P,U; cin >> S >> P >> U;
        T[i] = team(S,P,U,i);
    }
    sort(T.rbegin(),T.rend());
    map<int,int> ranking;
    using Item = tuple<int,int,int,int>;
    priority_queue<Item> pq;
    for(int i = 0; i < N;i++){
        pq.push(Item(T[i].S,-ranking[T[i].U],-T[i].P,T[i].id));
        ranking[T[i].U]++;
    }
    while(K--){
        cout << get<3>(pq.top()) << endl;
        pq.pop();
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
