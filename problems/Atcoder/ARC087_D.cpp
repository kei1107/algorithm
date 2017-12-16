#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://beta.atcoder.jp/contests/arc087/tasks/arc087_b>
 問題文============================================================
 二次元平面の原点にロボットが置かれています。 最初、ロボットは x 軸の正の向きを向いています。
 
 このロボットに命令列s が与えられます。s は次の2 文字のみからなり、先頭から末尾まで順に実行されます。
 F : 今向いている向きに長さ1 だけ移動する。
 T : 時計回りまたは反時計回りの好きな方向に90 度だけ向きを変える。
 ロボットの目標は、命令列をすべて実行し終わった後に座標(x,y) にいることです。
 この目標が達成可能か判定してください。
 
 s  は F, T のみからなる。
 1≤|s|≤8 000
 x,y は整数である。
 |x|,|y|≤|s|
 =================================================================
 
 解説=============================================================
 Tを区切りとして文字を分割して考えると、
 偶数番目(x軸側)と奇数番目(y軸側)は各々独立して考えることができることに気づく
 
 そして、道の選びかたは各区切り間のFの数をCとすると
 x軸に関しては
 一番最初は
     C
 二番目以降は
     pre_C + C or pre_C - C
 
 yに関しては一番最初の条件がなくなっただけで同様のことが言える
 
 
 となるのでハッシュなりとって計算してやればはい
 ================================================================
 */
bool dp1[4050][16001];
bool dp2[4050][16001];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    ll x,y; cin >> x >> y;
    vector<int> ax,ay;
    int t = 0;
    int cnt = 0;
    for(int i = 0; i < s.length();i++){
        if(s[i] == 'F'){
            cnt++;
        }else{
            if(t%2 == 0){
                ax.push_back(cnt);
            }else{
                ay.push_back(cnt);
            }
            t++; cnt = 0;
        }
    }
    if(cnt != 0){
        if(t%2 == 0){
            ax.push_back(cnt);
        }else{
            ay.push_back(cnt);
        }
    }
    dp1[0][8000] = true;
    for(int i = 0; i < (int)ax.size();i++){
        for(int j = 0; j <= 16000;j++){
            if(dp1[i][j]){
                dp1[i+1][j + ax[i]] = true;
                if(i == 0) continue;
                dp1[i+1][j - ax[i]] = true;
            }
        }
    }
    dp2[0][8000] = true;
    for(int i = 0; i < (int)ay.size();i++){
        for(int j = 0; j <= 16000;j++){
            if(dp2[i][j]){
                dp2[i+1][j + ay[i]] = true;
                dp2[i+1][j - ay[i]] = true;
            }
        }
    }
    if(dp1[ax.size()][8000+x] && dp2[ay.size()][8000+y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
