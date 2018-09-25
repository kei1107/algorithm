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
 <url:https://beta.atcoder.jp/contests/arc094/tasks/arc094_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 えー、こんなん成り立つの。。。
 
 -> <https://img.atcoder.jp/arc094/editorial.pdf>
 -> <http://kmjp.hatenablog.jp/entry/2018/04/07/1000>
 ================================================================
 */

const ll MOD = 998244353;
ll dp[200010][2][3][3];
ll solve(){
    ll res = 0;
    string S; cin >> S;
    for(auto& c:S) c -= 'a';
    if(count(S.begin(),S.end(),0) == S.length()) return 1;
    if(count(S.begin(),S.end(),1) == S.length()) return 1;
    if(count(S.begin(),S.end(),2) == S.length()) return 1;

    if(S.length() <= 3){
        set<string> T,R;
        T.insert(S);
        while(T.size()){
            set<string> U;
            for(auto& s:T){
                R.insert(s);
                for(int i = 0; i < S.length()-1;i++){
                    if(s[i] != s[i+1]){
                        string a = s;
                        a[i]=a[i+1]=0+1+2-a[i]-a[i+1];
                        if(R.count(a)==0){
                            U.insert(a);
                            R.insert(a);
                        }
                    }
                }
            }
            T = U;
        }
        return R.size();
    }
    
    int hash = accumulate(S.begin(),S.end(),0)%3;
    
    dp[1][0][0][0]=1;
    dp[1][0][1][1]=1;
    dp[1][0][2][2]=1;
    for(int i = 1; i < S.length();i++){
        for(int j = 0; j < 2;j++){
            for(int x = 0; x < 3;x++){
                for(int y = 0; y < 3;y++){
                    for(int z = 0; z < 3;z++){
                        (dp[i+1][j|(x==z)][z][(y+z)%3]+=dp[i][j][x][y])%=MOD;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 3;i++) res += dp[S.length()][1][i][hash];
    [&]{
        for(int i = 0; i < S.length()-1;i++){
            if(S[i]==S[i+1])return;
        }
        res++;
    }();
    res%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
