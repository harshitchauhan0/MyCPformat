// ░░░░░██╗░█████╗░██╗  ░██████╗██╗░░██╗██████╗░███████╗███████╗  ██████╗░░█████╗░███╗░░░███╗
// ░░░░░██║██╔══██╗██║  ██╔════╝██║░░██║██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗████╗░████║
// ░░░░░██║███████║██║  ╚█████╗░███████║██████╔╝█████╗░░█████╗░░  ██████╔╝███████║██╔████╔██║
// ██╗░░██║██╔══██║██║  ░╚═══██╗██╔══██║██╔══██╗██╔══╝░░██╔══╝░░  ██╔══██╗██╔══██║██║╚██╔╝██║
// ╚█████╔╝██║░░██║██║  ██████╔╝██║░░██║██║░░██║███████╗███████╗  ██║░░██║██║░░██║██║░╚═╝░██║
// ░╚════╝░╚═╝░░╚═╝╚═╝  ╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚══════╝  ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░╚═╝

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <climits>
#include <assert.h>
#include <chrono>

//-----macros-----//

#define ll long long
#define ull unsigned long long
#define ld long double
#define vii vector<ll>
#define pii pair<ll, ll>
#define vvi vector<vii>
#define vpi vector<pair<ll, ll>>
#define mll map<ll, ll>
#define uml unordered_map<ll, ll>
#define pql priority_queue<ll, vii>
#define pqg priority_queue<ll, vii, greater<ll>>
#define ff first
#define ss second
#define pb push_back
const int d1[4] = {-1,0,+1,0};
const int d2[4] = {0,-1,0,+1};
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size();
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;

using namespace std;

// -------- functions of c++ (not STL of course) -------- //

const ll mod = 1e9 + 7;
ll binarySearch(vii v, ll key)
{
    ll low = 0;
    ll high = v.size() - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (v[mid] == key)
        {
            return mid;
        }

        if (v[mid] < key)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

bool isPrime(ll n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (ll i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

bool isPowerOf2(ll num)
{
    while (num > 1)
    {
        if (num % 2)
        {
            return false;
        }
    }
    return true;
}

vii to_binary(ll num)
{
    vii ans;
    while (num > 0)
    {
        ans.pb(num % 2);
        num /= 2;
    }
    return ans;
}

ll to_decimal(vector<bool> binary)
{
    ll ans = 0;
    reverse(binary.begin(), binary.end());
    ll n = sz(binary);
    for (ll i = 0; i < n; i++)
        ans += (binary[i] ? pow(2, i) : 0);
    return ans;
}

vii countFreq(vii v, ll n)
{
    vii count(n, false);
    for (ll i = 0; i < n; i++)
    {
        count[v[i]]++;
    }
    return count;
}

vector<bool> ifVisited(vii v, ll n)
{
    vector<bool> visited(n, false);

    for (ll i = 0; i < n; i++)
    {
        if (visited[v[i]] == true)
        {
            continue;
        }
        else
        {
            visited[v[i]] = true;
        }
    }
    return visited;
}

vii suffix_min(vii v, ll n)
{
    vii suffix_mini(n, 0);
    suffix_mini[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_mini[i] = min(suffix_mini[i + 1], v[i]);
    }
    return suffix_mini;
}

vii suffix_max(vii v, ll n)
{
    vii suffix_maxi(n, 0);
    suffix_maxi[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_maxi[i] = max(suffix_maxi[i + 1], v[i]);
    }
    return suffix_maxi;
}

vii prefix_min(vii v, ll n)
{
    vii prefix_mini(n, 0);
    prefix_mini[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix_mini[i] = min(prefix_mini[i - 1], v[i]);
    }
    return prefix_mini;
}

vii prefix_max(vii v, ll n)
{
    vii prefix_maxi(n, 0);
    prefix_maxi[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix_maxi[i] = max(prefix_maxi[i - 1], v[i]);
    }
    return prefix_maxi;
}

unordered_map<ll, ll> freqByUMap(vii v, ll size)
{
    unordered_map<ll, ll> freqUMap;

    for (ll i = 0; i < size; i++)
    {
        freqUMap[v[i]]++;
    }

    return freqUMap;
}

map<ll, ll> freqByMap(vii v, ll size)
{
    map<ll, ll> freqMap;
    for (int i = 0; i < size; i++)
    {
        freqMap[v[i]]++;
    }

    return freqMap;
}

bool isVowel(char a)
{
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

ll gcd(ll a, ll b)
{
    while (a > 1 && b > 1)
    {
        if (a > b)
        {
            if (a % b == 0)
            {
                return b;
            }
            a = a % b;
        }
        else
        {
            if (b % a == 0)
            {
                return a;
            }
            b = b % a;
        }
    }
    return 1;
}

ll lcm(ll a, ll b)
{
    return (ll)(a * b) / gcd(a, b);
}

vii primeNums(int n)
{
    vector<bool> prime(n + 1, 1);
    vii ans;
    for (int j = 2; j * j <= n; j++)
    {
        if (prime[j] == true)
        {
            for (int i = j * j; i <= n; i += j)
            {
                prime[i] = false;
            }
            ans.push_back(j);
        }
    }

    return ans;
}

void takein(vii arr){
    for(int i = 0;i<arr.size();i++)  cin>>arr[i];
}

ll moduloMultiplication(ll x, ll y)
{
    ll res = 1;
    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }

        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll modInverse(ll n)
{
    return moduloMultiplication(n, mod - 2);
}

ll nCr(ll n, ll r)
{
    if (n < r)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }

    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }

    return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod;
}

void longPrint(vii v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void boolPrint(vii vis)
{
    for (auto i : vis)
    {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void inV(vector<T> &a)
{
    for (auto &i : a)
    {
        cin >> i;
    }
}

class SGT
{
public:
    vii seg;
    SGT(ll n)
    {
        seg.resize(4 * n + 1);
    }

    void point_update(ll idx, ll lo, ll hi, ll i, ll val)
    {
        if (lo == hi)
        {
            seg[idx] = val;
            return;
        }

        ll mid = (lo + hi) >> 1;
        if (i <= mid)
        {
            point_update(2 * idx + 1, lo, mid, i, val);
        }
        else
        {
            point_update(2 * idx + 2, mid + 1, hi, i, val);
        }

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll query(ll idx, ll l, ll r, ll lo, ll hi)
    {
        if (r < lo || hi < l)
        {
            return 0;
        }

        if (lo >= l && hi <= r)
        {
            return seg[idx];
        }

        ll mid = (lo + hi) >> 1;
        ll left = query(2 * idx + 1, l, r, lo, mid);
        ll right = query(2 * idx + 2, l, r, mid + 1, hi);

        return left ^ right;
    }

    void build(ll idx, ll lo, ll hi, vii &v)
    {
        if (lo == hi)
        {
            seg[idx] = v[lo];
            return;
        }

        ll mid = (lo + hi) >> 1;
        build(2 * idx + 1, lo, mid, v);
        build(2 * idx + 2, mid + 1, hi, v);
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
};

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2>

using safe_map = unordered_map<T1, T2, custom_hash>;

ll modinv(ll p, ll q)
{
    ll exp = mod - 2;
    while (exp > 0)
    {
        if (exp & 1)
        {
            p = (p * q) % mod;
        }

        q = (q * q) % mod;
        exp >>= 1;
    }
    return p;
}

vii factors(ll x)
{
    vii ans;
    int i = 1;
    while (i * i <= x)
    {
        if (x % i == 0)
        {
            ans.pb(i);
            if (x / i != i)
            {
                ans.pb(x / i);
            }
        }
        i++;
    }

    return ans;
}

class DSU
{
public:
    vii par;
    vii rank;

    DSU(ll n)
    {
        par.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
    }

    ll find(ll x)
    {
        if (par[x] != x)
        {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void merge(ll x, ll y)
    {
        ll nx = find(x);
        ll ny = find(y);

        if (nx != ny)
        {
            if (rank[nx] == rank[ny])
            {
                par[nx] = ny;
                rank[ny]++;
            }
            else if (rank[nx] > rank[ny])
            {
                par[ny] = nx;
            }
            else if (rank[nx] < rank[ny])
            {
                par[nx] = ny;
            }
        }
    }
};

ll binpow(ll base, ll exp)
{
    base %= mod;
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = res * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}
const ll inf = 1e18;
const ll ins = -1e18;

void solution(){
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    ll t = 1;
    while (t <= tt)
    {
        // cout << "Case #" << t << ": ";
        solution();
        t++;
    }
    return 0;
}
