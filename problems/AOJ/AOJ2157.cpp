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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2157>
 問題文============================================================
 各セルに0-9の数字が見える状態になっている状態の長さkのダイヤルが二つある。
 数字の変更の仕方として、
 
 任意の連続する区間の数字を全て同じ大きさ分だけ回転することができるとき、
 ダイヤル１からダイヤル２への状態にするために必要な最小回転回数を求めよ
 =================================================================
 解説=============================================================
 
 この問題は愚直にやれば良い、
 ただ、探索範囲を狭めるために、
 回転に関しては負の方向にx回転することは正の方向に10-x回転させることと同義であるということ、
 また、幅優先探索の要領で探索すれば、初めてダイヤル２の状態となった時が最小回転回数にできるので、
 探索を打ち切れる
 ================================================================
 */

class InitVal{
public:
    static bool INIT_B_VAL;
    static short INIT_SHRT_VAL;
    static unsigned short INIT_USHRT_VAL;
    static int INIT_I_VAL;
    static unsigned int INIT_UI_VAL;
    static long long INIT_LL_VAL;
    static unsigned long long INIT_ULL_VAL;
    static char INIT_C_VAL;
    static string INIT_STR_VAL;
    static float INIT_F_VAL;
    static double INIT_D_VAL;
    static long double INIT_LD_VAL;
    
    operator bool () {return INIT_B_VAL; }
    operator short () {return INIT_SHRT_VAL; }
    operator unsigned short () {return INIT_USHRT_VAL; }
    operator int () {return INIT_I_VAL; }
    operator unsigned int (){return INIT_UI_VAL; }
    operator long long () {return INIT_LL_VAL;}
    operator unsigned long long (){return INIT_ULL_VAL;}
    operator char () {return INIT_C_VAL; }
    operator string () {return INIT_STR_VAL; }
    operator float () {return INIT_F_VAL; }
    operator double () {return INIT_D_VAL; }
    operator long double (){return INIT_LD_VAL;}
    
    static void SetVal(bool _b){ INIT_B_VAL = _b;}
    static void SetVal(short _s){ INIT_STR_VAL = _s;}
    static void SetVal(unsigned short _us){INIT_USHRT_VAL = _us; }
    static void SetVal(int _i){ INIT_I_VAL = _i;}
    static void SetVal(unsigned int _ui){INIT_UI_VAL = _ui; }
    static void SetVal(long long _ll){ INIT_LL_VAL = _ll; }
    static void SetVal(unsigned long long _ull){INIT_ULL_VAL = _ull;}
    static void SetVal(char _c){INIT_C_VAL = _c;}
    static void SetVal(string _s){INIT_STR_VAL = _s;}
    static void SetVal(float _f){ INIT_F_VAL = _f;}
    static void SetVal(double _d){INIT_D_VAL = _d;}
    static void SetVal(long double _ld){ INIT_LD_VAL = _ld;}
};
bool InitVal::INIT_B_VAL = bool();
short InitVal::INIT_SHRT_VAL = short();
unsigned short InitVal::INIT_USHRT_VAL = ushort();
int InitVal::INIT_I_VAL = int();
unsigned int InitVal::INIT_UI_VAL = u_int();
long long InitVal::INIT_LL_VAL = int64_t();
unsigned long long InitVal::INIT_ULL_VAL = u_int64_t();
char InitVal::INIT_C_VAL = char();
string InitVal::INIT_STR_VAL = string();
float InitVal::INIT_F_VAL = float();
double InitVal::INIT_D_VAL = double();
long double InitVal::INIT_LD_VAL = static_cast<long double>(double()); //!! long_doubleデフォルトコンストラクタ名が分からん

template<typename T>
class InitMap:public InitVal{
public:
    T val;
    InitMap():val(InitVal()){}
    InitMap(T init):val(init){};
    static T GetInitVal(){ return InitVal(); }
    static void SetInitVal(T init){ InitVal::SetVal(init); }
    
    InitMap<T>& operator = (const T& o){ val = o; return (*this); }
    InitMap<T>& operator = (const InitMap<T>& o){ val = o.val; return (*this); }
    
    const InitMap<T> operator + (const T& o)const { return InitMap<T>(val+o);}
    const InitMap<T> operator + (const InitMap<T>& o) const{ return InitMap<T>(val+o.val);}
    const InitMap<T> operator - (const T& o)const { return InitMap<T>(val-o); }
    const InitMap<T> operator - (const InitMap<T>& o) const{ return InitMap<T>(val-o.val); }
    const InitMap<T> operator * (const T& o)const { return InitMap<T>(val*o);}
    const InitMap<T> operator * (const InitMap<T>& o) const{ return InitMap<T>(val*o.val); }
    const InitMap<T> operator / (const T& o)const { return InitMap<T>(val/o); }
    const InitMap<T> operator / (const InitMap<T>& o) const{ return InitMap<T>(val/o.val); }
    const InitMap<T> operator % (const T& o)const { return InitMap<T>(val%o); }
    const InitMap<T> operator % (const InitMap<T>& o) const{ return InitMap<T>(val%o.val); }
    
    InitMap<T>& operator += (const T& o){ val+=o; return (*this); }
    InitMap<T>& operator += (const InitMap<T>& o){ val+=o.val; return (*this); }
    InitMap<T>& operator -= (const T& o){val-=o; return (*this);}
    InitMap<T>& operator -= (const InitMap<T>& o){ val-=o.val; return (*this); }
    InitMap<T>& operator *= (const T& o){ val*=o; return (*this);}
    InitMap<T>& operator *= (const InitMap<T>& o){ val*=o.val; return (*this); }
    InitMap<T>& operator /= (const T& o){ val/=o; return (*this);}
    InitMap<T>& operator /= (const InitMap<T>& o){ val/=o.val; return (*this); }
    InitMap<T>& operator %= (const T& o){ val%=o; return (*this);}
    InitMap<T>& operator %= (const InitMap<T>& o){ val%=o.val; return (*this); }
    
    bool operator == (const T& o) const { return val == o; }
    bool operator == (const InitMap<T>& o) const { return val == o.val; }
    bool operator != (const T& o) const {return val!=o;}
    bool operator != (const InitMap<T>& o) const { return val != o.val; }
    bool operator < (const T& o) const { return val < o; }
    bool operator < (const InitMap<T>& o) const { return val < o.val; }
    bool operator <= (const T& o) const { return val <= o;}
    bool operator <= (const InitMap<T>& o) const { return val <= o.val; }
    bool operator > (const T& o) const {  return val > o;}
    bool operator > (const InitMap<T>& o) const { return val > o.val; }
    bool operator >= (const T& o) const { return val >= o;}
    bool operator >= (const InitMap<T>& o) const { return val == o.val; }
};
template<typename T> ostream& operator << (ostream& out,const InitMap<T>& o){ out << o.val; return out;}
template<typename T> istream& operator >> (istream& in, InitMap<T>& o){ in >> o.val; return in;}


ll solve(ll k){
    ll res = LINF;
    string S,T; cin >> S >> T;
    for(int i = 0; i < k;i++){ S[i] -= '0'; T[i] -= '0'; }
    InitMap<int>::SetInitVal(INT_MAX);
    
    queue<string> q;
    map<string,InitMap<int>> mp;
    
    mp[S] = 0;
    q.push(S);
    while(q.size()){
        string s = q.front(); q.pop();
        int dist = mp[s].val;
        if(s == T){
            res = dist;
            break;
        }
        
        int x = 0;
        while(s[x] == T[x]) x++;
        int diff = (T[x] - s[x] + 10)%10;
        for(int i = x; i < k;i++){
            (s[i] += diff)%=10;
            if(mp[s] > dist + 1){
                mp[s] = dist+1;
                q.push(s);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll k;
    while(cin >> k,k){
        cout << solve(k) << endl;
    }
    return 0;
}
