# E - Integer Sequence Fair

## 解説

以下， $p = 998244353$ とする．

この問題は， $M^{K^N} \pmod p$ を求める問題である．

まず，注意しなければならないのが， $M^{(K^N)} = {(M^K)}^N$ は成立しないということ（ここで何回かミスった）．

また， $M^{K^N} \pmod p \equiv M^{(K^N \pmod p)} \pmod p$ も成立しないということに注意する．

フェルマーの小定理より， $b$ が素数の時 $a^{b - 1} \equiv 1 \pmod{b}$ が成立することを利用して考えることで，以下のようにして，オーバーフローを防ぎながら計算することができる．

$M^{(K^N)} = M^{q(p - 1) + r} = (M^{p - 1})^q \times M^r \equiv 1^q \times M^r = M^r \pmod p$

ただし， $K^N = q(p - 1) + r$ とする．

なお，累乗の計算は，繰り返し二乗法を使う．

## 補足

$M = 0, r = 0$ となるときがある．この時，答えは $0$ となり， $M^r = 1$ ではないことに注意する．

```C++
const LL mod = 998244353LL;

LL n, k, m;

int main(){
    cin >> n >> k >> m;
    if(m % mod == 0){
        cout << 0 << endl;
        return 0;
    }
    LL r = power(k, n, mod - 1);
    cout << power(m, r, mod) << endl;
}
```
