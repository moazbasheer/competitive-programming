#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
ll mod = 1e9 + 7;
long long power(ll n, ll k){
    if(k==0) return 1;
    ll sq=(power(n,k/2)) % mod;
    sq=(sq*sq) % mod;
    if(k%2==1)
        sq=(sq*n) % mod;
    return sq;
}
set<int> primeFactors(int n)
{
    set<int> s;
    while (n % 2 == 0)
    {
        s.insert(2);
        n /=2;
    }
    for (ll i = 3; i*i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n /=i;
        }
    }
    if (n > 2)
        s.insert(n);
    return s;
}
int countDivisors(int n)
{
    set<int> s;
    int cnt = 0;

    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0)
            if (n / i == i)
                cnt ++;
            else
                cnt += 2;
    }
    return cnt;
}
ll nCr(ll n, ll r) {
    if(r > n - r) r = n - r;
    ll ans = 1;
    for(int i = 1; i <= r; i++)
        ans *= (n - r + i)/i;
    return ans;
}
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
/*
vector<ll> parent;
vector<ll> numGroup;
void setParents(int n) {
    parent.resize(n + 1);
    numGroup.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        numGroup[i] = 1;
    }
}
ll find(ll i) {
    if(i == parent[i])
        return i;
    return parent[i] = find(parent[i]);
}
void Union(ll x, ll y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return ;
    if(numGroup[x] >= numGroup[y]) {
        parent[y] = x;
        numGroup[x] += numGroup[y];
    } else {
        parent[x] = y;
        numGroup[y] += numGroup[x];
    }
}
*/
class SegTree {
    int leftmost, rightmost;
    SegTree* left, *right;
    int sum;
    public:
    SegTree(int leftmost, int rightmost, int a[]) {
        this->leftmost = leftmost;
        this->rightmost = rightmost;
        if(leftmost == rightmost) {
            this->sum = a[leftmost];
            return;
        }
        this->left = new SegTree(leftmost, (leftmost + rightmost) / 2, a);
        this->right = new SegTree((leftmost + rightmost) / 2 + 1, rightmost, a);
        this->sum = this->left->sum + this->right->sum;
    }
    void pointUpdate(int index, int new_value) {
        if(leftmost == rightmost) {
            this->sum = new_value;
        }
        if(index <= (leftmost + rightmost) / 2) {
            left->pointUpdate(index, new_value);
        } else {
            right->pointUpdate(index, new_value);
        }
        this->sum = this->left->sum + this->right->sum;
    }
    int range_sum(int l, int r) {
        if(l > rightmost || r < leftmost) return 0;
        if(l <= leftmost && r >= rightmost)
            return this->sum;
        return left->range_sum(l, r) + right->range_sum(l, r);
    }
};
void solve() {

}

int main()
{
    fast();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
