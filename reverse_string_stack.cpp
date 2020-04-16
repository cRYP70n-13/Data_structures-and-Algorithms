#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>

using namespace std;
// vector push_back push front top empty pop make_pair long long insert begin end
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair <int,int> > vpi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define Z size()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define L length()
#define show(a) cerr << " *** " << a << endl;
#define show1(a) cerr << " /// " << a << endl;
#define valid(a,b,c) (a >= b && a < c ? 1 : 0)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int mod = (int)1e9 + 7;
void smxl(ll &a, ll b){if (a < b)a=b;}
void smnl(ll &a, ll b){if (a > b)a=b;}
void adsl(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void misl(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
void smx(ll &a, ll b){if (a < b)a=b;}
void smn(ll &a, ll b){if (a > b)a=b;}
void ads(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void mis(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
ll gcd(ll a, ll b) {return (b==0? a:gcd(b,a%b));}
ll egcd(ll a, ll b, ll & x, ll & y) {if (a == 0){x = 0;y = 1;return b;}ll x1, y1;ll d = egcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
ll mbinp(ll a, ll b){a %= mod;if (b == 0)return 1;ll ans = mbinp(a, b/2);ll tmp = (ans * ans) % mod;if (b % 2)return ((tmp * a) % mod);return ((tmp) % mod);}
ll binp(ll a, ll b){if (b == 0)return 1;ll ans = binp(a, b/2);ll tmp = (ans * ans);if (b % 2)return ((tmp * a));return ((tmp));}

bool cmp(pair <ll , pair <ll, ll > > &a, pair <ll ,pair <ll, ll > > &b)
{
	return (a.F < b.F);
}

// Defining the stack Node
class Stack
{
    public:
        int top;
        unsigned capacity;
        char *array;
};

// The function that Creates the stack
Stack   *createStack(unsigned capacity)
{
    Stack *stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new char[(stack->capacity * sizeof(char))];
    return stack;
}

// Implement the isFull function to check if my stack is full or not
bool     isFull(Stack *stack)
{ return stack->top == stack->capacity - 1; }

// Implement the isEmpty function to check if my stack is empty or not yet
bool     isEmpty(Stack *stack)
{ return stack->top == -1; }

// Implement the push function to push my items to my stack
void    push(Stack *stack, char item)
{
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

// Implement the pop function to remove the top element from my stack
char    pop(Stack *stack)
{
    if (isEmpty(stack)) return -1;
    return (stack->array[stack->top--]);
}

// And now this is the reverse function
void    revrse(char *str)
{
    int n = strlen(str);
    Stack *stack = createStack(n);
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
    // and now it's to pop all our value
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

int   main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    char str[] = "cRYP70N";
    revrse(str);

    cout << "reversed string is: " << str;
	return (0);
}
