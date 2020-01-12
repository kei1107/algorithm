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
 <url:https://codeforces.com/contest/1287/problem/D>
 問題文============================================================
 D. Numbers on Tree
 =================================================================
 解説=============================================================
 
 これは、最初から1,...,1e9までの整数から条件を満たす値を探す必要はない
 
 ある頂点nを見た時、その子孫達の値の配列が
 [x1,x2,x3,...,xm]として、
 c[n]が2、すなわち,a[n]がx2とx3の間となるべき値のときは
 a[n] = (x2 + x3)/2として値を当てはめてやればいい。
 また、
 c[n]が0のときは a[n]=x1-1
 c[n]がmのときは a[n]=xm+1
 などなど、
 
 この方針のもと、あとで値が重複しないように葉に初期値を割り当てて、他の頂点の値を決める。
 その後、条件を満たす自然数値となるように値を割り当ててやればいい
 
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<vector<int>> G(n);
    vector<int> C(n);
    int root = -1;
    for(int i = 0; i < n;i++){
        int p,c; cin >> p >> c;
        if(p>=1){
            G[p-1].push_back(i);
        }else{
            root = i;
        }
        C[i] = c;
    }
    vector<double> vals(n);
    
    double base_value = 0;
    function<vector<double>(int)> dfs = [&](int n){
        vector<double> ret;
        for(const int& next:G[n]){
            auto vs = dfs(next);
            if(vs == vector<double>{-1}) return vs;
            for(auto v:vs) ret.push_back(v);
        }
        if(C[n] > (int)ret.size()) return vector<double>{-1};
        sort(ret.begin(),ret.end());
        if(ret.empty()){
            vals[n] = base_value;
            ret.push_back(base_value);
            base_value += 1e4;
        }else{
            if(C[n]==0){
                vals[n] = (*ret.begin())-1;
                ret.push_back((*ret.begin())-1);
            }else if(C[n] == (int)ret.size()){
                vals[n] = (*ret.rbegin())+1;

                ret.push_back((*ret.rbegin())+1);
            }else{
                vals[n] = (ret[C[n]]+ret[C[n]-1])/2.0;
                ret.push_back((ret[C[n]]+ret[C[n]-1])/2.0);
            }
        }
        return ret;
    };
    auto vs = dfs(root);
    if(vs == vector<double>{-1}){
        cout << "NO" << endl;
        return res;
    }
    
    cout << "YES" << endl;
    sort(vs.begin(),vs.end());
    for(int i = 0; i < n;i++){
        cout << (lower_bound(vs.begin(),vs.end(),vals[i])-vs.begin()+1) << " \n"[i==n-1];
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
