#include<bits/stdc++.h>
using namespace std;
#define loop(i,n)   for (long long i=0;i<n;i++)
#define loop1(i,n)   for (long long i=1;i<n;i++)
#define loopr(i,n)   for (long long i=n;i>=0;i--)
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
int binSearchFirstOccur(vector<long long> arr, int l, int h, int key) {
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



/*---------------------------------------------------------------------------*/
//log(1,name)
typedef int DEBUG_LEVEL;
int d_level = 0;

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, const std::pair<const Key, Value>& p)
{
    os << p.first << " => " << p.second;
    return os;
}

template<typename Container>
void log(DEBUG_LEVEL level, const Container& c) {
    if (level >= d_level) {
        for (typename Container::const_iterator it = c.begin();
                it != c.end(); ++it)
            std::cout << *it << '\n';
    }
}

class MyClass
{
    int i;
    std::string s;
public:
    MyClass(int i, std::string s): i(i), s(s) {}

    // declare the operator<<() overload as a friend to grant access
    // to private members
    friend std::ostream& operator<<(std::ostream& os, const MyClass& mc);

};

// define the operator<<() for MyClass as a global function (required)
std::ostream& operator<<(std::ostream& os, const MyClass& mc)
{
    os << "{MyClass: " << mc.s << ": " << mc.i << "}";
    return os;
}
/*-----------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.
-----------------------------------------------------------------------------*/
// Main Code


int main() {
    fast_io;
    init_code();

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> req(n);
    vector<int> avail(m);
    for (int i = 0; i < n; i++)
        cin >> req[i];
    for (int i = 0; i < m; i++)
        cin >> avail[i];
    sort(req.begin(), req.end());
    sort(avail.begin(), avail.end());
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(req[i] - avail[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if (req[i] < avail[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans;

    // end_routine();
    return 0;
}
