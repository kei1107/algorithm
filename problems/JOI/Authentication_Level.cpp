#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0542>
 問題文============================================================
 あなたは Just Odd Inventions 社を知っているだろうか?
 この会社の業務は「ただ奇妙な発明 (just odd inventions)」をすることである．ここでは略して JOI 社と呼ぶ．
 JOI 社には 2 つの事務所があり，それぞれ同じ大きさの正方形の部屋がマス目状に並んでできている．
 辺で接しているすべての部屋の間に，身分証による認証機能の付いた扉がある．
 JOI 社では様々なレベルの機密情報を扱っているため，部屋ごとに機密レベルという正の整数が設定されており，
 身分証の事務所ごとに定められた非負整数の認証レベルが，
 機密レベル以上でないとその部屋に入室することができない．
 各事務所の出入り口は唯一あるエレベーターホールのみで，エレベーターホールの部屋の機密レベルは最低の 1 である．
 その事務所についての認証レベルが 0 のときはエレベーターホールに入ることさえできない．
 JOI 社では，社長の突発的な提案で，一般の人に社内を見学してもらうツアーを実施することになった．
 あなたは見学者に渡す身分証の認証レベルの組み合わせを決める必要がある．
 見学者は開けられる扉を見つけると必ず開けて中に入る (同じ部屋を何度も訪れることも可能である)．
 そのため，必要以上に見学者の身分証の認証レベルを高くしたくはない．
 しかし，
 ツアーに魅力を持たせるため，ツアーではエレベーターホールの部屋を含め 2 つの事務所であわせて
 R 個以上の部屋を訪れることができるようにする必要がある．
 身分証の認証レベルを低くしすぎると，この条件を満たすことができないかもしれない．
 JOI 社には事務所が 2 個あり，第 k 事務所 (k = 1, 2) の部屋は東西方向に Wk 個，
 南北方向に Hk 個並んでおり，全部で Wk × Hk 個ある．
 西から i 番目，北から j 番目の部屋を (i, j)k で表すことにする．
 Wk と Hk と R の値，エレベーターホールの位置 (Xk, Yk)k ，各部屋の機密レベルが与えられたとき，
 見学者が 2 つの事務所であわせて R 個以上の部屋を訪れることができるための，
 見学者の身分証の認証レベルの和の最小値を求めるプログラムを作成せよ．
 なお，JOI 社が「ただ奇妙な発明」をすることでどうやって利益を得ているかは，
 社内でも最高機密であり社長以外の誰も知らない．
 =================================================================
 解説=============================================================
 
 問題文がややこしいが、簡単
 
 半分全列挙みたいな考え方
 
 先に、ある認証レベルの時、どの部屋まで見学できるかどうかの情報を求めておく（priority-queueを使うと楽)
 その後、部屋１の情報をもとに、
 条件を満たす最小の認証レベルの部屋2の情報と照らし合わせれば良い( O(log))
 ================================================================
 */

struct room{
    int x,y;
    int level;
    room(){}
    room(int x,int y,int l):x(x),y(y),level(l){}
    bool operator < (const room& o) const{
        return level < o.level;
    }
    bool operator > (const room& o) const{
        return level > o.level;
    }
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pii> calc_cnt_level(){
    vector<pii> ret;
    
    int W,H,X,Y; cin >> W >> H >> X >> Y; X--; Y--;
    vector<vector<int>> masu(H,vector<int>(W,0));
    vector<vector<int>> f(H,vector<int>(W,0));
    for(int i = 0; i < H;i++) for(int j = 0; j < W; j++) cin >> masu[i][j];
    
    priority_queue<room,vector<room>,greater<room>> pq;
    int cnt = 0,MaxLevel = 0;
    pq.push(room(X,Y,masu[Y][X]));
    while(!pq.empty()){
        auto r = pq.top(); pq.pop();
        if(f[r.y][r.x] == 1) continue;
        if(r.level > MaxLevel){
            ret.push_back(pii(cnt,MaxLevel));
            MaxLevel = r.level;
        }
        f[r.y][r.x] = 1;
        cnt++;
        for(int i = 0; i < 4;i++){
            int ny = r.y + dy[i], nx = r.x + dx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(f[ny][nx] == 1) continue;
            pq.push(room(nx,ny,masu[ny][nx]));
        }
    }
    ret.push_back(pii(cnt,MaxLevel));
    return ret;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int R; cin >> R;
    auto r1 = calc_cnt_level(); // { cnt , level }
    auto r2 = calc_cnt_level();
    
    sort(r1.begin(),r1.end());
    sort(r2.begin(),r2.end());
    
    ll ans = LINF;
    for(int i = 0; i < (int)r1.size();i++){
        if(r1[i].first >= R){
            ans = min(ans,(ll)r1[i].second);
        }else{
            int rR = R - r1[i].first;
            auto it = lower_bound(r2.begin(),r2.end(),pii(rR,0));
            if(it != r2.end()){
                ans = min(ans,(ll)(r1[i].second + it->second));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
