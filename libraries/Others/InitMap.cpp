#include "bits/stdc++.h"
using namespace std;

/*
 自作クラス
 mapで初期値をデフォルトコンストラクタ以外にしたい時に使用する
 
 標準型とInitMap<T>に置ける　標準型が左側になる処理を行っていないため
 
 InitMap<int>(10) + x ( xはInitMap<int>の型)
 と行ったようにInitMapが左側にならない場合は初期化処理要
 
 これにより、InitMapから値を標準型に代入する場合も
 int x = InitMap<int>(10).val
 と言った風に取り出す
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

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
#define debug(x) cout << #x << ": " << x << endl
    cout << string(20,'=') << endl;
    InitMap<int>::SetInitVal(INT_MAX);
    InitMap<long long>::SetInitVal(LLONG_MAX);
    cout << InitMap<int>::GetInitVal() << endl;
    cout << InitMap<long long>::GetInitVal() << endl;
    cout << string(20,'=') << endl;
    
    InitMap<int>::SetInitVal(int(1e9));
    map<string,InitMap<int>> mp;
    debug(mp["INF"]);
    
    mp["a"] = 25; mp["b"] = 10;
    debug(mp["a"]); debug(mp["b"]);
    mp["a"] = mp["a"] + 10 + mp["b"];// * 20;
    mp["a"] = InitMap<int>(10) + mp["a"];
    mp["c"] = mp["a"] + mp["b"];
    cout << (InitMap<int>(45) == mp["a"]) << endl;
    debug((mp["a"]+mp["b"]));
    debug(mp["c"]);
    mp["c"] *=10;
    debug(mp["c"]);
    auto x = mp["c"];
    cout << x << " " << typeid(x).name() << endl;
    return 0;
}
