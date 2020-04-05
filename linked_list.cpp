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

// this is the structure of our node that's we gonna use in our linked list
class Node {
	public:
		int data;
		Node *next;
};

//this is the function used to print the content of our linked list
void	print_linked_list(Node *list)
{
	while (list != NULL)
	{
		cout << list->data << endl;
		list = list->next;
	}
}

// i wanna try implement the push function to add a node in the head of a linked list
void	push(Node **head_ref, int new_data)
{
	// 1. allocate the memory for the new node
	Node *new_node = new Node();

	// 2. put the data in the new node
	new_node->data = new_data;

	// 3. Make the next of new node as head
	new_node->next = *head_ref;

	// 4. Move the head to point to the new node
	*head_ref = new_node;
}

// trying to implement insertAfter() function
void	insert_after(Node *prev_node, int new_data)
{
	if (prev_node == NULL)
		cout << "Go fuck ur self this is not valid!!\n";

	// 1. allocate the memory for the new node
	Node *new_node = new Node();

	// 2. put the data in the new node
	new_node->data = new_data;

	// 3. Make the next of the new node to the next one
	new_node->next = prev_node->next;

	// 4. move the next of the prev node as new node
	prev_node->next = new_node;
}

// trying to implement append() to add a node at the end of the linked list
void	append(Node **head_ref, int new_data)
{
	// 1. Create a new instande to our node
	Node *new_node = new Node();

	// 2. Create a new last node and give it the value of the first one to traverse our linked list
	Node *last = *head_ref;

	// 3. add our data to our new node
	new_node->data = new_data;

	// 4. Give the null value to our last node
	new_node->next = NULL;

	// 5. check if our linked list is impety if its the case add this node as the only one
	if (*head_ref == NULL)
       *head_ref = new_node; 

	// 6. traverse our linked list till the end 
	while (last->next != NULL)
		last = last->next;

	// 7. give the last item of our previous linked list the value of this one that we just created
	last->next = new_node;
}

int     main(void)
{
	// let's begin with creating tree nodes 
	Node *head = NULL;
	Node *second = NULL;
	Node *three = NULL;

	// the new keyword in C++ is like malloc in C so here we allocated memory for our node
	head = new Node();
	second = new Node();
	three = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = three;

	three->data = 3;
	three->next = NULL;

	// Insert 7 at the beginning.
    push(&head, 7);

    // Insert 1 at the beginning.
    push(&head, 1);

	// Insert 19 at the end
	append(&head, 19);

	// Insert 17 at the end also
	append(&head, 17);

	// Insert an element after the third Node
	insert_after(three, 18);

	print_linked_list(head);
	return (0);
}