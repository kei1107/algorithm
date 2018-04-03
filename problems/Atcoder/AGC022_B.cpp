#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://agc022.contest.atcoder.jp/tasks/agc022_b>
 問題文============================================================
 ナガセは高校の優等生です。ある日のこと、
 ナガセは正の整数からなる特別な集合のとある性質を分析しています。
 
 ナガセの考えでは、異なる 正の整数の集合 S={a1,a2,…,aN} は、
 以下の条件を満たす場合に 特別 であると呼ばれます。
 条件：どの 1≤i≤N についても、ai と、S のその他の要素の和の最大公約数は 1 ではない。
 
 ナガセは、要素数 N の 特別 な集合を求めたいです。ところがこれは簡単すぎるので、
 難易度を上げることにしました。
 要素数 N の 特別 な集合であって、すべての要素の最大公約数が 1 であり、
 どの要素も 30000 以下であるものを求めてみよ、とのことです。
 
 制約
 3≤N≤20000
 =================================================================
 解説=============================================================
 
 ど根性探索
 
 2,3,5を使って作る
 
 この時、Nが奇数であれば、30000などの公倍数を一つ入れておき、偶に調整すれば良い
 
 2,5で作る場合、 10の倍数ずつ挿入すると嬉しい
 また、よって２の倍数では下一桁が 2 + 8 や 4 + 6 などの組み合わせを入れれる
 また５の倍数を使うときも 15 + 25 などで同等のことができる
 
 ここで都合よく合計が3の倍数になる時があるので、
 その時は 2,3,5の最小公倍数　=> 30ずつ挿入すると嬉しくなる
 ３の倍数に関しても 3 + 27 , 9 + 21 などのこれまでに用いていない数字を入れることができる
 
 ================================================================
 */

/*
 gcd : 最大公約数
 lcm : 最小公倍数
 */
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

vector<ll> solve(ll N){
    vector<ll> res(N);
    if(N == 3){
        res[0] = 2; res[1] = 5; res[2] = 63;
        return res;
    }
    if(N == 4){
        res = {2,5,20,63};
        return res;
    }
    int idx = 0;
    ll sum = 0;
    res[idx++] = 2; res[idx++] = 5; res[idx++] = 8; res[idx++] = 15;
    sum += (2 + 5 + 8 + 15);
    if(N%2 == 1) {res[idx++] = 30000; sum += 30000;}
    if(N == idx) return res;
    
    
    res[idx++] = 4; res[idx++] = 6;
    sum += 4 + 6;
    
    int base = 10;
    for(int i = 1; i < 3000; i++){ // 10*x + 2 , 10*x + 8
        if(idx == N) break;
        res[idx++] = base*i + 2;
        res[idx++] = base*i + 8;
        
        sum += base*i + 2;
        sum += base*i + 8;
    }
    if(idx == N) return res;
    
    for(int i = 1; i < 3000; i++){ // 10*x + 4 , 10*x + 6
        if(idx == N) break;
        res[idx++] = base*i + 4;
        res[idx++] = base*i + 6;
        
        sum += base*i + 4;
        sum += base*i + 6;
    }
    if(idx == N) return res;
    
    for(int i = 1; i < 2999; i++){ // 10 * x
        if(idx == N) break;
        res[idx++] = base*i;
 
        sum += base*i;
    }
    
   // cout << idx << endl;
    
    for(int i = 2; i < 2998; i++){ // n*10 + 5
        if(idx == N) break;
        res[idx++] = base*i + 5;
        sum += base*i + 5;
    }
    if(idx == N) return res;

    base = 30;
    for(int i = 0; i < 1000; i++){ // n*30 + 3  n*30 + 27
        if(idx == N) break;
        res[idx++] = base*i + 3;
        res[idx++] = base*i + 27;
        
        sum += base*i + 3;
        sum += base*i + 27;
    }

    if(idx == N) return res;
    for(int i = 0; i < 1000; i++){ // n*30 + 9  n*30 + 21
        if(idx == N) break;
        res[idx++] = base*i + 9;
        res[idx++] = base*i + 21;
    }
    return res;
}

bool check(vector<ll>& A){
    ll sum = accumulate(A.begin(),A.end(),0LL);
    
    ll Max = *max_element(A.begin(), A.end());
    if(Max > 30000) return false;
    for(int i = 0; i < A.size();i++){
        if(gcd(A[i],sum-A[i]) == 1){
            cout << sum << endl;
            cout << A[i] << endl;
            return false;
        }
    }
    ll X = A[0];
    for(int i = 1; i < A.size();i++){
        X = gcd(X,A[i]);
    }
    if(X != 1) return false;
    return true;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll N; cin >> N;
    auto ret = solve(N);
    sort(ret.begin(),ret.end());
    
    cout << ret << endl;
    return 0;
}
