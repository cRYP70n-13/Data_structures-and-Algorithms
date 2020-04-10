#include <climits>
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

// this is the node's structure of my stack
class StackNode {
    public:
        int data;
        StackNode *next;
};

// try to implement a funcion to create a new Node we gonna need it to build our stack
StackNode   *newNode(int data)
{
    StackNode *newStackNode = new StackNode();
    newStackNode->data = data;
    newStackNode->next = NULL;
    return newStackNode;
}

// Check if my stack is empty
int     isEmpty(StackNode *head)
{
    return (!head);
}

// To push the new nodes to my stack
void    push(StackNode **head, int new_data)
{
    StackNode *new_stack_node = new StackNode();
    new_stack_node->data = new_data;
    new_stack_node->next = *head;
    *head = new_stack_node;
    cout << new_data << " Pushed succesfully to the stack\n";
}

// to pop from my stack returning the last element in the stack LIFO
int     pop(StackNode **head)
{
    int popped;
    if (isEmpty(*head))
        return INT_MIN;
    StackNode *tmp = *head;
    *head = (*head)->next;
    popped = tmp->data;
    free(tmp);
    return popped;
}

// and here i have to implement the peek function to return the top of the stack like pop()
int     peek(StackNode *head)
{
    if (isEmpty(head))
        return INT_MIN;
    return head->data;
}

int   main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout << pop(&root) << " popped from stack\n";

    cout << "Top element is " << peek(root) << endl;
	return (0);
}
