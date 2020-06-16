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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc170/tasks/abc170_e>
 問題文============================================================
 E - Smart Infants
 =================================================================
 解説=============================================================

 次の3つのデータを用意する。
    各園児のレート・幼稚園の番号(vector)
    各幼稚園に所属する幼児のレート集合(multiset)
    全幼稚園の最大レートの集合(multiset)

 一つのクエリに対して
 上記データを用いて、消去・更新を行っていくことで高速に実現できる。

 https://atcoder.jp/contests/abc170/submissions/14418259
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;
    multiset<int> st[200010];
    vector<pii> childs(N);
    for(int i = 0; i < N;i++){
        int A,B; cin >> A >> B;
        st[B].emplace(A);
        childs[i] = make_pair(A,B);
    }
    multiset<int> val;
    for(int i = 1; i <= 2*100000; i++){
        if(st[i].size()){
            val.emplace(*st[i].rbegin());
        }
    }
    while(Q--){
        int C,D; cin >> C >> D;
        C--;

        int rate,belong;
        tie(rate,belong) = childs[C];
        { // delete
            auto it1 = val.lower_bound(*st[belong].rbegin());
            val.erase(it1);

            auto it2 = st[belong].lower_bound(rate);
            st[belong].erase(it2);

            if(st[belong].size()) val.emplace(*st[belong].rbegin());
        }
        { // move
            if(st[D].size()){
                auto it1 = val.lower_bound(*st[D].rbegin());
                val.erase(it1);
            }

            st[D].emplace(rate);

            val.emplace(*st[D].rbegin());
        }
        childs[C] = make_pair(rate,D);

        cout << *val.begin() << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
