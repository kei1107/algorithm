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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2534>
 問題文============================================================
 =================================================================
 解説=============================================================
 永遠にバグらせた。解説見ればそれはそう
 http://lan496.hatenadiary.jp/entry/2016/02/23/100103
 ================================================================
 */

int n;
template<class Type>
Type solve(Type res = Type()){
    while(cin >> n,n){
        // preprocessing
        vector<string> s(n);
        for(auto& in:s) cin >> in;
        
        for(auto& each_s:s){
            each_s += string(10-each_s.length(),(char)('a'-1));
            for(auto& c:each_s) c -= 'a'-1;
        }
        // main processing
        bool ok = true;
        int dist[27][27] = {0};
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n; j++){
                int k = 0;
                while(k<10&&s[i][k]==s[j][k]) k++;
                if(k==10) continue;
                if(dist[s[j][k]][s[i][k]]) ok = false;
                dist[s[i][k]][s[j][k]] = 1;
            }
        }
        for(int i = 0; i < 27;i++) if(dist[i][0]) ok = false;
        
        if(!ok){
            cout << "no" << endl;
            continue;
        }
        
        function<bool(int,int)> rec = [&](int k,int cnt){
            if(cnt >= 27) return false;
            bool f = true;
            for(int i = 0; i < 27;i++){
                if(dist[k][i]) f = false;
            }
            if(f) return true;
            
            f = true;
            for(int i = 0; i < 27;i++){
                if(dist[k][i]){
                    f &= rec(i,cnt+1);
                }
            }
            return f;
        };
        
        if(rec(0,0)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
