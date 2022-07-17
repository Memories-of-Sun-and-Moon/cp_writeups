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
int p[202020];
int ans[202020];
int par[202020];
set<pair<int, int>> st;

int main(){
    cin >> n >> k;
    REP(i, n)cin >> p[i];

    if(k == 1){
        REP(i, n){
            ans[p[i]] = i + 1;
        }
        for(int i = 1;i <= n;i++){
            cout << ans[i] << endl;
        }
        return 0;
    }

    REP(i, 202020)par[i] = -1;
    REP(i, 202020)ans[i] = -1;
    REP(i, n){
        auto it = st.lower_bound({p[i], 0});
        if(it == st.end()){
            st.insert({p[i], 1});
        }else{
            par[p[i]] = it->first;
            int sz = it->second + 1;
            st.erase(it);
            if(sz == k){
                int cur = p[i];
                while(cur != -1){
                    ans[cur] = i + 1;
                    cur = par[cur];
                }
            }else{
                st.insert({p[i], sz});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << endl;
    }
}