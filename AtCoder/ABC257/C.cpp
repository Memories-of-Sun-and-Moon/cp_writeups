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

int N;
string S;
int W[202020];

int main(){
    cin >> N;
    cin >> S;
    REP(i, N)cin >> W[i];
    vector<int> W_list, Adults, Children;
    REP(i, N){
        if(S[i] == '0')Children.push_back(W[i]);
        else Adults.push_back(W[i]);
    }
    Children.push_back(INF<int>());
    Children.push_back(-1);
    sort(W, W + N);
    sort(ALL(Children));
    sort(ALL(Adults));

    int ans = 0;
    REP(i, N){
        int num = 0;
        num += lower_bound(ALL(Children), W_list[i]) - Children.begin() - 1;
        num += Adults.end() - lower_bound(ALL(Adults), W_list[i]);
        chmax(ans, num);
    }
    int num = 0;
    num += lower_bound(ALL(Children), INF<int>()) - Children.begin() - 1;
    chmax(ans, num);
    cout << ans << endl;
}