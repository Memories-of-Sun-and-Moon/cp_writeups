# G - Triangle

## 解説

$A_{ij} = 1$ のときに、 $A_i$ AND $A_j$ のビット数が、求める組の数であると言い換えられる。

bitset を使うことで 64 倍高速化ができれば、間に合う。

```C++
int n;
bitset<3000> a[3000];

int main(){
    cin >> n;
    REP(i, n){
        string s;
        cin >> s;
        REP(j, n)if(s[j] == '1' && i < j)a[i][j] = 1;
    }
    LL ans = 0;
    REP(i, n)REP(j, n){
        if(i >= j)continue;
        if(!a[i][j])continue;
        bitset<3000> tmp = a[i] & a[j];
        ans += tmp.count();
    }
    cout << ans << endl;
}
```
