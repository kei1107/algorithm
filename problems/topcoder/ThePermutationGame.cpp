#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;


const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

void PrimeFact(ll n,map<ll,ll>& mp){
    while(n!=1){
        if(n == 2 || n == 3){
            mp[n]++; n/=n;
            continue;
        }
        bool prime_flag = false;
        for(ll i = 2;i*i <= n;i++){
            if(n%i==0){
                mp[i]++; n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){mp[n]++; n/= n;}
    }
}
class ThePermutationGame {
    public:
    int findMin(int N) {
        ll res = 1;
        
        map<ll,ll> T;
        for(int i = 1; i <= N;i++){
            map<ll,ll> mp;
            PrimeFact(i, mp);
            for(auto p:mp) T[p.first] = max(T[p.first],p.second);
        }
        for(auto p:T) (res *= powmod(p.first,p.second))%=MOD;
        return (int)res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 6; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 27720; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 102; int Arg1 = 53580071; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 9999; int Arg1 = 927702802; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    ThePermutationGame ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
