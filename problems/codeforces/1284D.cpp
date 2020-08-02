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
 <url:https://codeforces.com/problemset/problem/1284/D>
 問題文============================================================
 D. New Year and Conference
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> sa(n),ea(n),sb(n),eb(n);
    for(int i = 0; i < n;i++){
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    
    auto check = [&](vector<int>& sa,vector<int>&ea,vector<int>& sb,vector<int>& eb){
        using Event = tuple<int,int,int>;
        vector<Event> event;
        for(int i = 0; i < n;i++){
            event.emplace_back(sa[i],0,i);
            event.emplace_back(ea[i],1,i);
        }
        sort(event.begin(),event.end());
        
        multiset<int> start_t,end_t;
        for(auto e:event){
            int status,id;
            tie(ignore,status,id) = e;
            
            if(status == 0){
                start_t.emplace(sb[id]);
                end_t.emplace(eb[id]);
            }else{
                
                start_t.erase(start_t.lower_bound(sb[id]));
                end_t.erase(end_t.lower_bound(eb[id]));
                
                if(end_t.size() && sb[id] > *end_t.begin()) return false;
                if(start_t.size() && eb[id] < *start_t.rbegin()) return false;
            }
        }
        return true;
    };
    
    if(check(sa,ea,sb,eb) && check(sb,eb,sa,ea)) return "YES";
    else return "NO";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
