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

bool dp[2][501][501];
class BearFair {
    public:
    string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
        fill(**dp,**dp+2*501*501,false);
        vector<int> info(b+2,-1);
        int m = (int)upTo.size();
        for(int i = 0; i < m;i++){
            if(info[upTo[i]]!=-1 && info[upTo[i]] != quantity[i]) return "unfair";
            info[upTo[i]] = quantity[i];
        }
        
        int cur = 0,next = 1;
        dp[cur][0][0] = true;
        for(int i = 1; i <= b;i++){
            for(int j = 0; j <= 500; j++){
                for(int k = 0; k <= 500;k++){
                    if(dp[cur][j][k]){
                        if(info[i]==-1){
                            dp[next][j][k] = dp[cur][j][k];
                            if(j+k<n){
                                dp[next][j+(i%2==0)][k+(i%2==1)] = dp[cur][j][k];
                            }
                        }else{
                            if(j+k==info[i]){
                                dp[next][j][k] = dp[cur][j][k];
                            }
                            if(info[i]!=-1&&j+k==info[i]-1){
                                dp[next][j+(i%2==0)][k+(i%2==1)] = dp[cur][j][k];
                            }
                        }
                    }
                    dp[cur][j][k] = false;
                }
            }
            swap(cur,next);
        }
        
        if(dp[cur][n/2][n/2]) return "fair";
        else return "unfair";
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 321; int Arr2[] = {6,12,2,3,9,8,10,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,3,0,0,1,0,2,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "fair"; verify_case(0, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 6; int Arr2[] = {3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "unfair"; verify_case(1, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "unfair"; verify_case(2, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 1000; int Arr2[] = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "fair"; verify_case(3, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 1000; int Arr2[] = {400,600}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "unfair"; verify_case(4, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    BearFair ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
