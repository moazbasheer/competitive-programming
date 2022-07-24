#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
// int dx[]={1,-1,0,0,1,-1,1,-1};
// int dy[]={0,0,1,-1,1,1,-1,-1};
// freopen("input.txt" ,"r",stdin );
// freopen("output.txt","w",stdout);

void solve() {
    ll n, m, a, d; cin >> n >> m >> a >> d;
    ll ans = 0;
    for(int i0 = 0; i0 < 2; i0++) {
        for(int i1 = 0; i1 < 2; i1++) {
            for(int i2 = 0; i2 < 2; i2++) {
                for(int i3 = 0; i3 < 2; i3++) {
                    for(int i4 = 0; i4 < 2; i4++) {
                        ll k = 1;
                        ll cnt = 0;
                        if(i0) if(!cnt) k = a, cnt++; else k = lcm(k, a), cnt++;
                        if(i1) if(!cnt) k = a + d, cnt++; else k = lcm(k, (a + d)), cnt++;
                        if(i2) if(!cnt) k = a + 2 * d, cnt++; else k = lcm(k, (a + 2 * d)), cnt++;
                        if(i3) if(!cnt) k = a + 3 * d, cnt++; else k = lcm(k, (a + 3 * d)), cnt++;
                        if(i4) if(!cnt) k = a + 4 * d, cnt++; else k = lcm(k, (a + 4 * d)), cnt++;
                        if(cnt == 0)
                            continue;
                        int sign = ((cnt % 2 == 0)?-1:1);
                        ans += sign * ((m / k) - ((n - 1) / k));
                    }
                }
            }
        }
    }
    cout << (m - n + 1) - ans << "\n";
}

int main()
{
    fast();
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
