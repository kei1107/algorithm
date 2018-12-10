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
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/359>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 気づきゲー。。。。
 
 門松行列になるか否かについての境は a_ij 近辺や L/2 付近になる。
 よって、近傍でなるかならないかを判定して、まとめて加算すればいい
 ================================================================
 */
bool kadomatsu(int a,int b,int c){
    if(a==b || a==c || b==c) return false;
    if(b>a&&b>c) return true;
    if(b<a&&b<c) return true;
    return false;
}
bool ok(vector<vector<int>>& a){
    for(int i = 0; i < 3;i++){
        if(!kadomatsu(a[i][0], a[i][1], a[i][2])) return false;
        if(!kadomatsu(a[0][i], a[1][i], a[2][i])) return false;
    }
    if(!kadomatsu(a[0][0], a[1][1], a[2][2])) return false;
    if(!kadomatsu(a[0][2], a[1][1], a[2][0])) return false;
    return true;
}
ll solve(){
    ll res = 0;
    int L; cin >> L;
    vector<vector<int>> a(3,vector<int>(3));
    for(auto& vec:a) for(auto& in:vec) cin >> in;
    vector<int> none,vs;
    for(int i = 0; i < 3;i++) for(int j = 0; j < 3;j++)
        if(!a[i][j]) none.push_back(i*3+j);
        else if(L-a[i][j]>0) {vs.push_back(a[i][j]); vs.push_back(L-a[i][j]);}
    
    for(int i = -1; i <= 1;i++) if(L/2+i>0) vs.push_back(L/2+i);
    vs.push_back(L/2);
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    vector<pii> sections;
    int n = (int)vs.size();
    if(vs.front() > 1) sections.emplace_back(1,vs.front()-1);
    for(int i = 0; i < n;i++){
        sections.emplace_back(vs[i],vs[i]);
        if(i < n-1 && vs[i]+1<vs[i+1]) sections.emplace_back(vs[i]+1,vs[i+1]-1);
    }
    if(vs.back()<L-1) sections.emplace_back(vs.back()+1,L-1);
    for(pii p:sections){
        a[none[0]/3][none[0]%3] = p.first;
        a[none[1]/3][none[1]%3] = L-p.first;
        if(ok(a)) res += p.second-p.first+1;
    }
    return res;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
