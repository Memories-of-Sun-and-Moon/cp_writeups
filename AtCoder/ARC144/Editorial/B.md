# B - Gift Tax

## 解説

値を決め打ちして、二分探索を行う。

```C++
int n, a, b;
LL c[303030];
 
bool calc(LL num){
    LL upcnt = 0, downcnt = 0;
    REP(i, n){
        if(c[i] >= num){
            downcnt += (c[i] - num) / b;
        }else{
            upcnt += (num - c[i]) / a;
            if((num - c[i]) % a != 0)upcnt++;
        }
    }
    //cout << num << " " << upcnt << " " << downcnt << endl;
    return (upcnt <= downcnt);
}
 
int main(){
    cin >> n >> a >> b;
    REP(i, n)cin >> c[i];
    LL l = 0, r = 10000000000LL;
 
    while(r - l > 1){
        LL mid = (l + r) / 2;
        if(calc(mid)){
            l = mid;
        }else {
            r = mid;
        }
    }
    cout << l << endl;
}
```