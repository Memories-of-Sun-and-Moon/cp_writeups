#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
}INIT;

int n, k;
int u[202020];
int a[202020], b[202020];


void solve(){
    cin >> n >> k;
    REP(i, n)cin >> u[i];
    REP(i, k)cin >> a[i] >> b[i];

    set<int> stations;

    map<int, int> idx_first, idx_end;

    REP(i, n){
        stations.insert(u[i]);
    }

    REP(i, n)idx_first[u[i]] = idx_end[u[i]] = -1;

    REP(i, n){
        if(idx_first[u[i]] != -1)continue;
        idx_first[u[i]] = i;
    }

    for(int i = n - 1;i >= 0;i--){
        if(idx_end[u[i]] != -1)continue;
        idx_end[u[i]] = i;
    }

    REP(i, k){
        if(stations.count(a[i]) == 0 || stations.count(b[i]) == 0){
            cout << "NO" << endl;
            continue;
        }
        if(idx_first[a[i]] < idx_end[b[i]]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}

int t;

int main(){
    cin >> t;
    while(t--){
        solve();
    }
}