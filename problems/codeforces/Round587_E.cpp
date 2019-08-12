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
 <url:https://codeforces.com/contest/1200/problem/E>
 問題文============================================================
 =================================================================
 解説=============================================================
 ローリングハッシュで比較していけば間に合う
 ================================================================
 */

/*
 Rolling hash
 */
struct RH {
public:
    vector<unsigned long long> p,hash;
    int n;
    unsigned long long base,m,q;
    // m : 1000000007, 1000000009, 1000000021...
    RH(){
        base=10007;
        m=1000000007;
    }
    void init(const string s) {
        q=1;
        n=(int)s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){
            if(m == 0){p[i+1]=p[i]*base; hash[i+1]=s[i]+hash[i]*base;}
            else {p[i+1]=p[i]*base%m; hash[i+1]=(s[i]+hash[i]*base)%m;}
        }
    }
    void apply(const char c){
        if(m == 0){
            p.push_back(p[n]*base);
            hash.push_back(c+hash[n]*base);
        }else{
            p.push_back(p[n]*base%m);
            hash.push_back((c+hash[n]*base)%m);
        }
        n++;
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{
        if(m==0) return h(j)-h(i)*p[j-i];
        else return (h(j)-h(i)*p[j-i]%m+m)%m;
    }
    unsigned long long bach_h(int i)const { return h(n-i,n); }
};

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<string> words(n);
    for(auto& in:words) cin >> in;

    res += words.front();
    RH rh; rh.init(words.front());

    for(int i = 1; i < n;i++){
        int len = min(rh.n,(int)words[i].length());

        RH rh2; rh2.init(words[i]);

        int M = -1;
        for(int j = 0; j < len;j++){
            if(rh.bach_h(j+1) == rh2.h(j+1)){
                M = j;
            }
        }

        for(int j = M+1; j < words[i].length();j++){
            res += words[i][j];
            rh.apply(words[i][j]);
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
