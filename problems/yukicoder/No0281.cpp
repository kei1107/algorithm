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
 <url:https://yukicoder.me/problems/no/281>
 問題文============================================================
 =================================================================
 解説=============================================================
 真ん中が一番高いor低くなる場合を想定して、
 場合分けをがんばる
 ================================================================
 */
bool kadomatsu(vector<ll>& H){
    if(H[0] == H[1] || H[1] == H[2] || H[0] == H[2]) return false;
    if(H[0] > H[1] && H[2] > H[1]) return true;
    if(H[0] < H[1] && H[2] < H[1]) return true;
    return false;
}
ll solve(){
    ll res = LINF;
    ll d; cin >> d;
    vector<ll> H(3); for(auto& in:H) cin >> in;
    if(kadomatsu(H)) return 0;
    if(d == 0) return -1;
    
    auto T = H;
    {
        //真ん中が一番高い場合

        ll cnt = 0;
        if(H[0] >= H[1]){
            cnt += (H[0] - H[1] + d - 1)/d;
            H[0] -= (H[0] - H[1] + d - 1)/d*d;
            if(H[0] == H[1]){
                cnt++;
                H[0] -= d;
            }
            H[0] = max(0LL,H[0]);
        }
        if(H[2] >= H[1]){
            cnt += (H[2] - H[1] + d - 1)/d;
            H[2] -= (H[2] - H[1] + d - 1)/d*d;
            if(H[2] == H[1]){
                cnt++;
                H[2] -= d;
            }
            H[2] = max(0LL,H[2]);
        }
        if(H[0] != 0 || H[2] != 0){
            if(H[0] == H[2]){ cnt++; H[0]--;}
            if(kadomatsu(H)) res = min(res,cnt);
        }
    }
    H = T;

    {
        //真ん中が一番低い場合
        
        ll cnt = 0;
        if(H[0] == H[2]){
            cnt++;
            H[0] -= d;
            H[0] = max(0LL,H[0]);
        }
        if(H[0] != 0 && H[2] != 0){
            ll minH = min(H[0],H[2]);
            if(minH <= H[1]){
                cnt += (H[1] - minH + d - 1)/d;
                H[1] -= (H[1] - minH + d - 1)/d*d;
                if(H[1] == minH){
                    cnt++;
                    H[1] -= d;
                }
                H[1] = max(0LL,H[1]);
            }
        }
        
        if(kadomatsu(H)) res = min(res,cnt);
    }
    if(res == LINF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
