# A - Digit Sum of 2x

## 解説

$M = 2N$ になる（要証明）

$1, 2, 3, 4$ を使って、桁和が $N$ になる整数が $x$ になる（要証明）

```C++
int n;

int main(){
    cin >> n;
    cout << 2 * n << endl;
    string ans = "";
    int m = n;
    while(m >= 4){
        ans += "4";
        m -= 4;
    }
    if(m != 0){
        ans = char('0' + m) + ans;
    }
    cout << ans << endl;
}
```