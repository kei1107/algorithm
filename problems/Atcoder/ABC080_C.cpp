#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc080.contest.atcoder.jp/tasks/abc080_c>
問題文============================================================
 joisinoお姉ちゃんは、ある商店街に店を開こうとしています。
 
 その商店街の店は、月曜日から金曜日の 5 つの曜日を午前と午後の 2 つの時間帯に分けて、これら 10 個の時間帯それぞれについて店を営業するか否かを決めることとなっています。ただし、1 つ以上の時間帯で店を営業しなければなりません。
 
 商店街には既に N 個の店があり、1 から N までの番号がついています。
 
 これらの店の営業時間の情報として Fi,j,k が与えられ、月曜日 = 曜日 1、火曜日 = 曜日 2、水曜日 = 曜日 3、木曜日 = 曜日 4、金曜日 = 曜日 5、 午前 = 時間帯 1、午後 = 時間帯 2 と対応させたとき、Fi,j,k=1 なら曜日 j の時間帯 k に店 i が営業しており、Fi,j,k=0 なら営業していないことを意味します。
 
 店 i とjoisinoお姉ちゃんの開く店の両方が営業している時間帯の個数を ci としたとき、joisinoお姉ちゃんの店の利益は P1,c1+P2,c2+…+PN,cN となります。ただし、利益は負にもなりうることに注意してください。
 
 1 つ以上の時間帯で店を営業しなければならないことに注意しつつ、10 個の時間帯それぞれについて店を営業するか否かを決めるとき、joisinoお姉ちゃんの店の利益のあり得る最大値を求めてください。
 

=================================================================

解説=============================================================

 bitでの貪欲全探索
 
================================================================
*/
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<vector<ll>> F(N,vector<ll>(10));
    for(int i = 0; i < N;i++)for(int j = 0; j < 10;j++) cin >> F[i][j];
    vector<vector<ll>> P(N,vector<ll>(11));
    for(int i = 0; i < N;i++) for(int j = 0; j < 11;j++) cin >> P[i][j];

    ll ans = -LINF;
    for(int i = 1; i < (1<<10);i++){
        ll T = 0;
        vector<int> cnt(N,0);
        for(int j = 0; j < 10;j++){
            if(!((i>>j)&1))continue;
            for(int k = 0; k < N;k++){
                if(F[k][j] == 1){ cnt[k]++; }
            }
        }
        for(int j = 0; j < N;j++){
            T += P[j][cnt[j]];
        }
        ans = max(ans,T);
    }
    cout << ans << endl;
    return 0;
}
