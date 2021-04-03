#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/arc112/tasks/arc112_c>
 問題文============================================================
 C - DFS Game 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<vector<int>> T(n);
    for(int i = 1; i < n;i++){
        int p; cin >> p; p--;
        T[p].emplace_back(i);
    }
    vector<int> tree_num(n);
    auto calc_tree_num = [&](auto self,int u = 0) -> int{
        tree_num[u] = 1;
        for(auto v:T[u]) tree_num[u] += self(self,v);
        return tree_num[u];
    };
    calc_tree_num(calc_tree_num);

    vector<int> get_coins(n);
    auto calc_coins = [&](auto self,int u = 0) -> void {
        get_coins[u] = 1;

        vector<pii> sub_coins;
        for(auto v:T[u]){
            self(self,v);
            if(tree_num[v]%2 == 0){
                if(get_coins[v] < 0){
                    sub_coins.emplace_back(0,get_coins[v]);
                }else{
                    sub_coins.emplace_back(2,get_coins[v]);
                }
            }else{
                sub_coins.emplace_back(1,get_coins[v]);
            }
        }

        sort(sub_coins.begin(),sub_coins.end());
        int turn = 0;

        for(auto [state,coins] : sub_coins){
            if(state == 1){
                if(turn == 0){
                    get_coins[u] += coins;
                }else{
                    get_coins[u] -= coins;
                }
                turn = !turn;
            }else{
                if(turn == 0){
                    get_coins[u] += coins;
                }else{
                    get_coins[u] -= coins;
                }
            }
        }
    };
    calc_coins(calc_coins);

    cerr << get_coins << endl;

    res = (n+get_coins[0])/2;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}