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
 <url:https://yukicoder.me/problems/no/61>
 問題文============================================================
 2人の魔法少女MamiとHomuraは幅 W メートル、奥行き H メートルの密室で銃撃戦を繰り広げていた。
 
 Homuraは時間を止め、同時に最後の一発を発射した。
 時間停止した世界ではHomuraと弾丸しか動くことができず、
 弾丸は壁にあたると入射角と同じ角度で反射し速度を落とすことなく無限に飛び続ける。
 
 Mamiがいる位置を (Mx,My)、Homuraが発砲した位置を (Hx,Hy)、
 弾丸の発射時の速度ベクトルを (Vx,Vy) とし D 秒間時間を止めるとき、
 D 秒以内に弾丸がMamiに当たることはあるか判定せよ。
 
 ただしMamiと弾丸の大きさは無視できるものとし、Homuraが弾丸に当たることはないとする。
 =================================================================
 解説=============================================================
 
 制約が小さいので実際にシミュレーションしてやればいい。
 
 また、空間について、W、Hが高々15以下なので格子点に関しても16^2しか存在せず、十分余裕をもっても
 1000パターンほどシミュレーションしてやればいい
 
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

string solve(){
    ll W,H,D,Mx,My,Hx,Hy,Vx,Vy;
    cin >> W >> H >> D >> Mx >> My >> Hx >> Hy >> Vx >> Vy;
    ll GCD = gcd(abs(Vx),abs(Vy));
    Vx /= GCD; Vy /= GCD;
    D = min(D*GCD,17LL*17);
    while((Hx != Mx || Hy != My)&&(D != 0)){
        D--;
        Hx += Vx; Hy += Vy;
        while(true){
            if(Hx < 0){ Hx = -Hx; Vx = -Vx; continue; }
            if(Hx > W){ Hx = 2*W-Hx; Vx = -Vx; continue; }
            if(Hy < 0){ Hy = -Hy; Vy = -Vy; continue; }
            if(Hy > H){ Hy = 2*H-Hy; Vy = -Vy; continue; }
            break;
        }
    }
    if(Hx == Mx & Hy == My) return "Hit";
    return "Miss";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll Q; cin >> Q;
    while(Q--){
        cout << solve() << endl;
    }
    return 0;
}
