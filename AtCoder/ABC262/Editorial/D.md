# I Hate Non-integer Number

## 解説

$k$ 個の整数の平均値が整数となるのは， $k$ 個の整数の総和が $k$ の倍数になるときである．

$L = 1, 2, \cdots, N$ について， $L$ 個の整数の和が $L$ の倍数になる場合の数を， DP で求める．

$DP[i][j][k] := (i番目まででj個選んだ整数の和を l で割ったあまりが k である場合の数)$

```C++
int main(){
    cin >> n;
    REP(i, n)cin >> a[i];
    LL ans = 0;

    for(int l = 1;l <= n;l++){
        REP(i, 101)REP(j, 101)REP(k, 101)dp[i][j][k] = 0;
        dp[0][0][0] = 1;
        REP(i, n)REP(j, n)REP(k, l){
            //erabu
            dp[i + 1][j + 1][(k + a[i]) % l] += dp[i][j][k];
            dp[i + 1][j + 1][(k + a[i]) % l] %= mod;
            //erabanai
            dp[i + 1][j][k] += dp[i][j][k];
            dp[i + 1][j][k] %= mod;
        }
        LL num = 0;
        num += dp[n][l][0];
        num %= mod;
        ans += num;
        ans %= mod;
    }
    cout << ans << endl;
}
```
