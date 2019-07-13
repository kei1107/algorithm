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
 <url:https://atcoder.jp/contests/abc127/tasks/abc127_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 更新クエリによって与えられるa,bを順番に a1,...,an  / b1,...bnとする
 
 この時、求値クエリの値は
 f(x) = |x-a1| + |x-a2| + .... + |x-an| + b1 + b2 + ... + bn
 の最小値となる。ここでb1+b2+...+bnは定数であるため、xによらず一定となる。
 そこで
  |x-a1| + |x-a2| + .... + |x-an|
 の最小値及びそのxを考える。
 これは、図などを書いて考えると分かりやすいが、最小の値をとるxは
 nが奇数の時は a1,...,anの中央値
 nが偶数の時は a1,...,anの中央値要素となる2値の小さい方となる。
 
 よって、priority_queueやmultisetなどを使って中央値以下の値の集合と中央値より大きい値の集合などを管理して計算すれば解ける
 
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    ll asum = 0,bsum = 0;
    using Item = tuple<ll,ll,ll>;
    int Q; cin >> Q;
    vector<Item> Qs(Q);
    for(int i = 0; i < Q;i++){
        ll mode; cin >> mode;
        if(mode == 1){
            ll a,b; cin >> a >> b;
            Qs[i] = Item(mode,a,b);
        }else{
            Qs[i] = Item(mode,-1,-1);
        }
    }
    
    priority_queue<ll> l;
    priority_queue<ll,vector<ll>,greater<ll>> r;
    
    ll lsum = 0, rsum = 0;
    for(int q = 0; q < Q; q++){
        ll mode,a,b; tie(mode,a,b) = Qs[q];
        if(q == 0){
            bsum += b;
            l.push(a);
            lsum = a;
            continue;
        }
        if(mode == 1){
            bsum += b;
            
            
            if(a <= l.top()){
                l.push(a);
                lsum += a;
            }else{
                r.push(a);
                rsum += a;
            }
            
            if(!l.empty() && l.size() > r.size() + 1){
                r.push(l.top());
                lsum -= l.top(); rsum += l.top();
                l.pop();
            }else if(!r.empty() && r.size() > l.size()){
                l.push(r.top());
                lsum += r.top(); rsum -= r.top();
                r.pop();
            }
        }else{
            if(l.size() == r.size() + 1){
                cout << l.top() << " " << l.top()-lsum + rsum + bsum << endl;
            }else{
                cout << l.top() << " " << -lsum + rsum + bsum << endl;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
