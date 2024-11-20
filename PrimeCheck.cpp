#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define  int    long long
#define  mod    1000000007
#define  modd   998244353
#define  inf    INT32_MAX
#define  INF    9e18
#define  ff     first
#define  ss     second
#define  pb     push_back
#define  nl     '\n'
#define  sz(s)  (int)((s).size())
#define  all(x) (x).begin(),(x).end()

template<typename T1, typename T2> static inline void umin(T1 &x, T2 y) {if (y < x) x = y;}
template<typename T1, typename T2> static inline void umax(T1 &x, T2 y) {if (y > x) x = y;}

typedef pair   <int,int>       pii;
typedef vector <int>           vi;
typedef vector <vector<int>>   vvi;
typedef vector <pair<int,int>> vpi;
typedef map    <int,int>       mii;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
    #define debug(x...)
#endif

#define pd(ar, n) cerr << #ar << " = [ "; for (int i = 0; i < n; i++) {cerr << ar[i] << " ";} cerr << "] " << endl;
#define pdd(ar, n, m) cerr << #ar << endl; for (int i = 0; i < n; i++) {{cerr << " [ "; for (int j = 0; j < m; j++) {cerr << ar[i][j] << " ";}; cerr << "]" << endl;}};

void __print (int x) {cerr << x;}
void __print (double x) {cerr << x;}
void __print (char x) {cerr << "'" << x << "'";}
void __print (const string &x) {cerr << '"' << x << '"';}
void __print (bool x) {cerr << (x ? "True" : "False");}
void _print() {cerr << "]\n";}
template <typename A, typename B> void __print (const pair<A,B> &x) {cerr << "("; __print(x.first); cerr << ","; __print(x.second); cerr << ")";}
template <typename A> void __print (const A &x) {int f = 0; cerr << "{"; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template <typename A, typename... B> void _print (A t, B... v) {__print(t); if (sizeof...(v)) cerr << ","; _print(v...);} 
template <typename T1, typename T2> istream& operator>>(istream &istream, pair <T1,T2> &p) {return (istream >> p.ff >> p.ss);}
template <typename T1, typename T2> ostream& operator<<(ostream &ostream , pair <T1,T2> &p) { ostream << p.ff << ' ' << p.ss << endl; return ostream;}
template <typename T> istream& operator>>(istream &istream, vector <T> &v) {for (auto &i : v) istream >> i;  return istream;}
template <typename T> ostream& operator<<(ostream &ostream, vector <T> &v) {for (auto &i : v) ostream << i << ' ';  return ostream;}
template <typename T> void print(T &&t) {cout << t << "\n";}
template <typename T, typename... Args> void print(T &&t, Args &&... args) {cout << t << " "; print(forward<Args>(args)...);}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool IsPrimeLinear(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool IsPrimeLinear2(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool IsPrimeSqrt(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

class PrimeSieve {
    private:
        int size;
        vector <bool> IsPrime;

        void Process() {
            IsPrime[0] = IsPrime[1] = 0;

            for (int i = 2; i * i <= size; i++) {
                if (IsPrime[i]) {
                    for (int j = i * i; j <= size; j += i) {
                        IsPrime[j] = false;
                    }
                }
            }
        }

    public:
        PrimeSieve(int size) {
            this->size = size;
            IsPrime = vector <bool> (size + 1, 1);
            Process();
        }

        bool IsPrimeNum(int &num) {
            return IsPrime[num];
        }
};

void Solve () {
    int n;
    cin >> n;

    // cout << IsPrimeLinear(n) << ' ' << IsPrimeLinear2(n) << ' ' << IsPrimeSqrt(n) << endl;

    PrimeSieve primeSieve = PrimeSieve(n);

    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        cout << i << ' ' << primeSieve.IsPrimeNum(i) << endl
    } 
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    int TestCases = 1;
    // cin >> TestCases;
    for (int test = 1; test <= TestCases; test++) {
        // cout << "Case #" << test << ": ";
        Solve();
    }
    return 0;
}