#include<bits/stdc++.h>
using namespace std;
#define loop(i,n)   for (long long i=0;i<n;i++)
#define loop1(i,n)   for (long long i=1;i<=n;i++)
#define loopr(i,n)   for (long long i=n;i>0;i--)
#define loops(i, a, n)   for (long long i=a;i<=n;i++)
#define el cout<<"\n";
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#define iint int
// #define int long long int
#define ll long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define MOD 1000000007
#define MOD2 998244353
#define put(x) cout << x << "\n";
#define vi vector<int>
#define tcase(t)  ll t;cin>>t;while(t--)
#define vb vector<bool>
#define pii pair<int, int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)   (a/gcd(a/b, b))
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
long long powerLL(long long x, long long n, long long mod) {
    long long result = 1;
    while (n) {
        if (n & 1) {
            result = result * x % mod;
        }
        x = x * x % mod;
        n = n / 2;
    }
    return result;
}
string toBinary(unsigned n)// decimal to binary
{
    if (n == 0) {
        return "";
    }
    return toBinary(n / 2) + to_string(n % 2);
}
int binSearchFirstOccur(int arr[], int l, int h, int key) {
    if (l > h) {
        return -1;
    }
    int mid = l + (h - l) / 2;
    if (arr[mid] == key) {
        if ((mid - 1) >= l && arr[mid - 1] == key) { // Basically mid!=0
            return binSearchFirstOccur(arr, l, mid - 1, key);
        }
        else {
            return mid;
        }
    }
    if (arr[mid] > key) {
        return binSearchFirstOccur(arr, l, mid - 1, key);
    }
    else {
        return binSearchFirstOccur(arr, mid + 1, h, key);
    }
}
// while (cin >> arr[n++]); take value till null eg i\o 1+2+3 arr = 1,2,3
// * means value at operator
// & means address of operator
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#define fast_io                        ios_base::sync_with_stdio(false);cin.tie(NULL);
/*---------------------------------------------------------------------------
// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.
-----------------------------------------------------------------------------*/
// Main Code



int main() {
    fast_io;
    init_code();

    ll n ;
    cin >> n;
    cout << powerLL(2, n, MOD);


    return 0;
}
