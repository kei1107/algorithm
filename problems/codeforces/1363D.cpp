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
 <url:https://codeforces.com/problemset/problem/1363/D>
 問題文============================================================
 D. Guess The Maximums
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,k; cin >> n >> k;
    vector<set<int>> S(k);
    for(int i = 0; i < k; i++){
        int c; cin >> c;
        while(c--){
            int x; cin >> x;
            S[i].insert(x);
        }
    }
    
    int counter = 0;
    auto ask1 = [&](int l,int r){
        if(counter == 12) return -1;
        if(l > r) return -INF;
        counter++;
        
        vector<int> ask_list;
        for(int x = l; x <= r; x++) for(auto v:S[x]) ask_list.emplace_back(v);
        
        cout << "? " << ask_list.size()<< " " << ask_list << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    auto ask2 = [&](vector<int> ask_list){
        if(counter == 12) return -1;
        counter++;
                
        cout << "? " << ask_list.size()<< " " << ask_list << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    
    int l = 0, r = k-1;
    int max_v = -1;
    {
        vector<int> ask_list(n);
        iota(ask_list.begin(),ask_list.end(),1);
        max_v = ask2(ask_list);
    }
    while(l < r){
        int m = (l+r)/2;
        
        int ret_v = ask1(0,m);
        assert(ret_v >= 0);
        if(ret_v == max_v){
            r = m;
        }else{
            l = m+1;
        }
    }
    vector<int> A(k,-1);
    {
        vector<int> ask_list;
        for(int i = 1; i <= n;i++){
            if(S[l].find(i) == S[l].end()) ask_list.emplace_back(i);
        }
        fill(A.begin(),A.end(),max_v);
        A[l] = ask2(ask_list);
    }
    cout << "! " << A << endl;
    string result; cin >> result;
    assert(result == "Correct");
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t; cin >> t; while(t--) solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
