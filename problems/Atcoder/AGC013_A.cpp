#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc013.contest.atcoder.jp/tasks/agc013_a>
問題文============================================================
長さ N の配列 A が与えられます。
 A を何箇所かで切って、A の連続した部分であるようないくつかの数列に分けます。
 この時、分けられたあとの数列は全て、単調非減少または単調非増加な列になっている必要があります。
 最小で何個の数列に分ければ良いかを求めて下さい。
=================================================================

解説=============================================================

 先に、隣り合う値が等しい部分に関しては、処理を簡単にするために、unique等で
 削除しておくと楽
 
 あとは、順番に現在 単調増加なのか減少なのか、または確定できないのか
 といったフラグを持っておき、実際にシミュレーションしていく
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    A.erase(unique(A.begin(),A.end()),A.end());
    int mode = 0;
    int ans = 1;
    for(int i = 0 ; i < (int)A.size()-1;i++){
        if(mode == 0){
            if(A[i] < A[i+1]) mode = 1;
            else mode = -1;
        }else{
            if(mode == 1){
                if(A[i] > A[i+1]){
                    ans++;
                    mode = 0;
                }
            }else{
                if(A[i] < A[i+1]){
                    ans++;
                    mode = 0;
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}
