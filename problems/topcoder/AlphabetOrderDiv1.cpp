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

int dist[30][30];
class AlphabetOrderDiv1{
    public:
    string isOrdered(vector <string> words) {
        fill(*dist,*dist+900,0);
        for(int i = 0; i < 30;i++) dist[i][i] = 1;
        for(auto str:words){
            int n = (int)str.length();
            for(int i = 0; i < n;i++){
                for(int j = i+1; j < n;j++){
                    dist[str[i]-'a'][str[j]-'a'] = 1;
                }
            }
        }
        for(int i = 0; i < 30;i++){
            for(int j = 0; j < 30;j++){
                for(int k = 0; k < 30;k++){
                    dist[j][k] |= dist[j][i] & dist[i][k];
                }
            }
        }
        for(int i = 0; i < 30;i++){
            for(int j = i+1; j < 30;j++){
                if(dist[i][j] & dist[j][i]) return "Impossible";
            }
        }
        return "Possible";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"single","round","match"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, isOrdered(Arg0)); }
	void test_case_1() { string Arr0[] = {"topcoder","topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, isOrdered(Arg0)); }
	void test_case_2() { string Arr0[] = {"algorithm", "contest"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(2, Arg1, isOrdered(Arg0)); }
	void test_case_3() { string Arr0[] = {"pink","floyd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, isOrdered(Arg0)); }
	void test_case_4() { string Arr0[] = {"gimnasia","y","esgrima","la","plata"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, isOrdered(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    AlphabetOrderDiv1 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
