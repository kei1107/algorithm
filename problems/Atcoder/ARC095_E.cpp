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
 <url:https://beta.atcoder.jp/contests/arc095/tasks/arc095_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 どの行同士をペアにして交換するかをあらかじめ決めておけば最大 11!! の組み合わせで済む。
 
 あとは、実際に全通り試して、条件を満たすか調べれば良い。
 
 この時、行のペアを決めるときは、Hが奇数の時、ペアにならない行が一つ出るので、注意
 
 ================================================================
 */

ll H,W;
bool check(vector<vector<char>>& masu){
    vector<int> filled(W+1);
    bool center = false;
    for(int i = 1; i <= W;i++){
        if(filled[i]) continue;
        vector<char> T;
        for(ll j = H; j >= 1;j--){
            T.push_back(masu[j][i]);
        }
        bool update = false;
        for(int j = i + 1; j <= W;j++){
            if(filled[j]) continue;
            bool ok = true;
            for(int k = 1; k <= H;k++){
                if(T[k-1] != masu[k][j]) ok = false;
            }
            if(ok){
                filled[i] = filled[j] = 1;
                update = true;
                break;
            }
        }
        if(update) continue;
        if(W%2 == 0) return false;
        if(center) return false;
        for(int k = 0; k <= H/2; k++){
            if(T[k] != T[H-k-1]) return false;
        }
        center = true;
    }
    return true;
}
bool rec(vector<int>&flag,vector<vector<char>>& masu){
    ll S = accumulate(flag.begin(),flag.end(),0);
    if(S >= H){
        return check(masu);
    }else{
        if(S == 0 && H%2 == 1){
            for(int i = 1; i <= H;i++){
                flag[i] = 1;
                if(rec(flag,masu))return true;;
                flag[i] = 0;
            }
        }else{
            for(int i = 1; i<= H;i++){
                if(flag[i]) continue;
                for(int j = i+1; j <= H;j++){
                    if(flag[j]) continue;
                    flag[i] = flag[j] = 1;
                    if(rec(flag,masu)) return true;
                    swap(masu[i],masu[j]);
                    if(rec(flag,masu)) return true;
                    swap(masu[i],masu[j]);
                    flag[i] = flag[j] = 0;
                }
                break;
            }
        }
    }
    return false;
}
string solve(){
    cin >> H >> W;
    vector<vector<char>> masu(H+1,vector<char>(W+1));
    for(int i = 1; i <= H;i++) for(int j = 1; j <= W; j++) cin >> masu[i][j];
    vector<int> flag(H+1);
    if(rec(flag,masu)) return "YES";
    return "NO";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
