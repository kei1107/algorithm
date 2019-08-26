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
 <url:https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 問題は
 
 2枚のカードに書かれた整数が同じである。(イ)
 2枚のカードに書かれた整数の和がMの倍数である。(ロ)
 のいずれかの条件を満たすことができる組の個数の最大を求めること。
 
 ここで、条件(イ)・(ロ)をそれぞれ独立に考える。
 
 条件(イ)を満たす組は単純で同じ値の整数の個数を見ればいい。
 
 条件(ロ)を満たす組はXiをMで割った時の余りと他のXjをMで割った時の余りの和 が0またはMとなるようなXi,Xjをペアにすることができる。
 
 ここで、各XiをMで割った値についてのみ考える。事前に、
 
 s[i]=余りがiとなるような値の個数 p[i]=余りがiとなるような値の中で同じ整数同士での最大ペア数
 と求めておく。(後者は単純に同じ整数の個数/2の値を該当するp[i]に加算していけば求まる)
 
 s[i],p[i]を求めておけば、各iについて見たときs[i],p[i]とs[M−i],p[M−i]の値を用いて、 余りiと余りM−iを用いた最大ペア数を求めることができる。
 
 具体的には自分は次のようにペア数を求めた。
 
 p[i]のうちp′個のペアをそのまま用いると決め打った時、 残ったs[i]−p′∗2個とs[M−i]のうち余りp[M−i]の値が小さくならないように ペアに出来るだけペアにする、その後p[M−i]のうち残った値をペアとして加算する。
 
 以上の処理を全てのp′に対して行った時の最大値を余りiと余りM−iを用いた最大ペア数とする。 （例外としてi=0　若しくは i==M−iの時はどのような組み合わせでも条件を満たす為s[i]/2が最大ペア数となる)
 

 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    vector<ll> X(N); for(auto& in:X) cin >> in;
    map<ll,ll> Xcnt;
    for(auto& v:X) Xcnt[v]++;
    
    map<ll,ll> SameGroup;
    for(auto& v:X) SameGroup[v%M]++;
    map<ll,ll> PairCnt;
    for(auto& p:Xcnt) PairCnt[p.first%M] += p.second/2;
    
    ll T1 = 0; // 重複しない個数
    ll T2 = 0; // 重複する個数
    for(ll x = 0; x < M; x++){
        ll y = M-x;
        if(x == 0 || x == y){ // この場合はどんな組み合わせでも条件を満たす
            T1 += SameGroup[x]/2;
            continue;
        }
        
        ll s1 = SameGroup[x], s2 = SameGroup[y];
        ll p1 = PairCnt[x],p2 = PairCnt[y];
        
        ll add_T2 = 0;
        for(ll p = 0; p <= p1; p++){
            ll T = 0;
            // p1のうちp個のペアを使う
            T += p;
            
            // s1 - p*2 個をs2とのペア候補
            ll left_x = s1 - p*2;
            
            // y側は
            // ペアが最大p2個、 s2 - p2*2個が余り
            ll left_y = s2 - p2*2;
            
            
            ll min_left = min(left_x,left_y);
            T += min_left;
            
            left_x -= min_left;
            left_y -= min_left;
            
            if(left_x == 0){ // xの残りがなくなるようであれば
                T += p2; // p2は全て選ぶ
            }else{ // xのまだ残っているようであれば
                // left_x と p2の個数を見て
                
                // left_xのうち何個をp2*2の個数からペアにすれば最大となるのかを計算
                // よくよく考えると
                // left_xとペアにできる分だけペアにした方がいい
                // p2の1ペアで left_xを使えば最大2ペアできる為
                
                ll p_left_p2 = min(left_x,p2*2);
                T += p_left_p2;
                
                // 後は、残ったp2の個数を加算
                T += (p2*2 - p_left_p2)/2;
            }
            
            
            add_T2 = max(add_T2,T);
        }
        
        T2 += add_T2;
    }
    
    res = T1 + T2/2;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
