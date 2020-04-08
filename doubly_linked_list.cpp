/**
 ** @File: Doubly linked lists
 ** @Language: C++
 ** @Author: cRYP70N
 ** @Date: 08/04/2020
**/

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

// this is the structure of my doubly linked list
class Node {
    public:
        int data;
        Node *next;
        Node *prev;
};

// Here i wanna discover this new concepts off data structures
void    push(Node **head, int new_data)
{
    // Creating a new node and allocat memory for it
    Node *new_node = new Node();

    // Puting the data inside of our new node
    new_node->data = new_data;

    // Setting the next of the new data to the head
    new_node->next = *head;

    // Setting the prev to NULL
    new_node->prev = NULL;

    // change the prev of the head to new_node
    if (*head != NULL)
        (*head)->prev = new_node;

    // Setting the head to the new node
    *head = new_node;
}

// Trying to implement a function to add a node after a given node
void    insertAftr(Node *prev_node, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;

    // Here we set the next pointer of our new node to the next node
    new_node->next = prev_node->next;

    // Here we set the next pointer of our prev_node to the node we just created
    prev_node->next = new_node;

    // Setting the prev pointer of our new node to the previous node
    new_node->prev = prev_node;

    // Setting the last pointer the prev of the Next node to the one we just created
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

// M gonna try to implement the append function to add an item at the end of the list
void    append(Node **head, int new_data)
{
    Node *new_node = new Node();

    // Puting the data in our new node
    new_node->data = new_data;

    // Puting the next of our new_node to NULL since it's gonna be the last one
    new_node->next = NULL;

    // Creating a tmp Node to traverse our list and set it equal to the head
    Node *current = *head;

    // But now we need to check if our list is empty
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    // Starting my loop
    while (current != NULL)
        current = current->next;

    // we achieved the last node so now we have to change the pointers
    current->next = new_node;
    new_node->prev = current;

    return;
}

// Okay and now i will implement a function that insert a Node after a given one
void    insertAfter(Node *prev_node, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void    print_list(Node *node)
{
    Node *current;
    cout << "Traversal in forward direction\n";
    while (node != NULL)
    {
        cout << node->data << endl;
        current = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction\n";
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->prev;
    }
}

// Trying to implement a function to delete a node from our doubly linked list
void    deleteNode(Node **head, Node *del)
{
    if (*head == NULL || del == NULL)
        return ;
    if (*head == del)
        *head = del->next;
    if (*head->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}

// My Main function
int   main(void)
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);

    insertAfter(head->next, 8);

    cout << "the created DLL is: ";
    print_list(head);
	return (0);
}
