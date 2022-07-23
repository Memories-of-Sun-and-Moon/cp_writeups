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

int n;
int t[202020];
LL a[202020];
LL c;

bool ansbit[30];

bool ruibit[202020][30][2];

int main(){
    cin >> n >> c;
    REP(i, 30){
        if(c & (1LL << i))ansbit[i] = 1;
    }
    REP(i, n){
        cin >> t[i] >> a[i];
        vector<bool> abit(30, 0);
        REP(j, 30)if(a[i] & (1LL << j))abit[j] = 1;
        if(!i){
            REP(j, 30){
                if(t[i] == 1)ruibit[i][j][0] = (0 & abit[j]), ruibit[i][j][1] = (1 & abit[j]);
                if(t[i] == 2)ruibit[i][j][0] = (0 | abit[j]), ruibit[i][j][1] = (1 | abit[j]);
                if(t[i] == 3)ruibit[i][j][0] = (0 ^ abit[j]), ruibit[i][j][1] = (1 ^ abit[j]);
            }
            REP(j, 30){
                ansbit[j] = ruibit[i][j][ansbit[j]];
            }
        }else{
            REP(j, 30)REP(k, 2){
                if(t[i] == 1)ruibit[i][j][k] = (ruibit[i - 1][j][k] & abit[j]);
                if(t[i] == 2)ruibit[i][j][k] = (ruibit[i - 1][j][k] | abit[j]);
                if(t[i] == 3)ruibit[i][j][k] = (ruibit[i - 1][j][k] ^ abit[j]);
            }
            REP(j, 30){
                ansbit[j] = ruibit[i][j][ansbit[j]];
            }
        }
        LL tmp = 0;
        REP(j, 30){
            if(ansbit[j])tmp += (1LL << j);
        }
        cout << tmp << endl;
    }
}