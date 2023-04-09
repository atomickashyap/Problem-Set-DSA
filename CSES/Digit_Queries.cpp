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


vector<ll> v(18, 0);

void cal(vector<ll> &v)
{
    for (ll i = 1; i <= 17; i++)
    {
        v[i] = ((9 * i * pow(10, i - 1)));
    }
    return;
}

ll solve()
{
    cal(v);

    // printing value of v
    // for(auto i:v)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;


    ll query = 1;
    cin >> query;
    while (query--)
    {
        ll k;
        cin >> k;

        ll sum = 0;
        ll length_of_number = 0;
        for (ll i = 0; i <= 17; i++)
        {
            sum += v[i];
            if (sum <= k)
            {
                length_of_number = i + 1;
            }
            else
            {
                break;
            }
        }


        sum -= v[length_of_number];
        // cout<<"sum : "<<sum<<endl;
        ll difference = k - sum;
        // cout<<"difference : "<<difference<<endl;
        ll starting_number = pow(10, length_of_number - 1);
        ll distance_from_starting_number = (difference / length_of_number);
        // sum += (distance_from_starting_number * length_of_number);
        ll actual_number = starting_number + distance_from_starting_number - 1;
        ll remainder = difference % length_of_number;
        // cout<<"remainder : "<<remainder<<endl;
        // cout<<"actual_number : "<<actual_number<<endl;
        // cout<<"sum : "<<sum<<endl;
        if (remainder == 0)
        {
            cout << actual_number % 10 << endl;
        }
        else
        {
            actual_number++;
            // cout<<"final actual number : "<<actual_number<<endl;
            remainder = length_of_number - remainder;
            while (remainder--)
            {
                actual_number /= 10;
            }
            cout << actual_number % 10 << endl;
        }
    }

    return 0;
}

int main() {
    fast_io;
    init_code();

    solve();

    return 0;
}
