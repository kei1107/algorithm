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
class ColorfulGarden {
public:
    vector <string> rearrange(vector <string> garden) {
        vector<string> res;
        int n = (int)garden[0].length();
        map<char,int> mp; for(auto vec:garden) for(auto c:vec) mp[c]++;
        vector<pair<int,char>> vals;
        for(auto p:mp) if(p.second > n) return res; else vals.push_back({p.second,p.first});
        
        res = vector<string>(2,string(n,'#'));
        sort(vals.begin(),vals.end());
        for(auto it:vals){
            char c = it.second;
            int left = it.first;
            for(int i = 0; i < n;i++){
                if(left==0) break;
                if(res[i%2][i]=='#'){
                    res[i%2][i]=c;
                    left--;
                }
            }
            for(int i = 0; i < n;i++){
                if(left==0) break;
                if(res[!(i%2)][i]=='#'){
                    res[!(i%2)][i]=c;
                    left--;
                }
            }
        }
        
        cout << res[0] << endl;
        cout << res[1] << endl;
        
        for(int i = 0; i < n;i++){
            if(res[0][i]==res[1][i]) return vector<string>();
            if(i!=n-1 && res[0][i]==res[0][i+1]) return vector<string>();
            if(i!=n-1 && res[1][i]==res[1][i+1]) return vector<string>();
        }
        
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = {"aa",
        "bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ba", "ab" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, rearrange(Arg0)); }
    void test_case_1() { string Arr0[] = {"xxxx",
        "xxxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, rearrange(Arg0)); }
    void test_case_2() { string Arr0[] = {"abcd",
        "abcd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcd", "dcba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, rearrange(Arg0)); }
    void test_case_3() { string Arr0[] = {"abcdefghijklm",
        "nopqrstuvwxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcdefghijklm", "nopqrstuvwxyz" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, rearrange(Arg0)); }
    void test_case_4() { string Arr0[] = {"aaa",
        "aab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, rearrange(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    ColorfulGarden ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
