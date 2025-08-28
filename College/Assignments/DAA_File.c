/// 8
/*#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *right_child;
  struct node *left_child;
};

struct node* new_node(int x){
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp->data = x;
  temp->left_child = NULL;
  temp->right_child = NULL;

  return temp;
}

struct node* search(struct node * root, int x){
  if (root == NULL || root->data == x)
    return root;
  else if (x > root->data)
    return search(root->right_child, x);
  else
    return search(root->left_child, x);
}

struct node* insert(struct node * root, int x){
  if (root == NULL)
    return new_node(x);
  else if (x > root->data)
    root->right_child = insert(root->right_child, x);
  else
    root -> left_child = insert(root->left_child, x);
  return root;
}
struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root->left_child != NULL)
    return find_minimum(root->left_child);
  return root;
}

struct node* delete(struct node * root, int x) {

  if (root == NULL)
    return NULL;
  if (x > root->data)
    root->right_child = delete(root->right_child, x);
  else if (x < root->data)
    root->left_child = delete(root->left_child, x);
  else {
    if (root->left_child == NULL && root->right_child == NULL){
      free(root);
      return NULL;
    }
    else if (root->left_child == NULL || root->right_child == NULL){
      struct node *temp;
      if (root->left_child == NULL)
        temp = root->right_child;
      else
        temp = root->left_child;
      free(root);
      return temp;
    }
    else {
      struct node *temp = find_minimum(root->right_child);
      root->data = temp->data;
      root->right_child = delete(root->right_child, temp->data);
    }
  }
  return root;
}

void inorder(struct node *root){
  if (root != NULL)
  {
    inorder(root->left_child);
    printf(" %d ", root->data);
    inorder(root->right_child);
  }
}

int main() {
  struct node *root;
  root = new_node(20);
  insert(root, 5);
  insert(root, 1);
  insert(root, 15);
  insert(root, 9);
  insert(root, 7);
  insert(root, 12);
  insert(root, 30);
  insert(root, 25);
  insert(root, 40);
  insert(root, 45);
  insert(root, 42);

  inorder(root);
  printf("\n");

  root = delete(root, 1);

  root = delete(root, 40);

  root = delete(root, 45);

  root = delete(root, 9);

  inorder(root);
  printf("\n");

  return 0;
}*/

///9 from GFG
/*#include <limits.h>
#include <stdio.h>

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j) return 0;
    int k;
    int min = INT_MAX;
    int count;
    for (k = i; k < j; k++) 
    {
        count = MatrixChainOrder(p, i, k)+ MatrixChainOrder(p, k + 1, j)+ p[i - 1] * p[k] * p[j];
        if (count < min) min = count;
    }
    return min;
}
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ",MatrixChainOrder(arr, 1, N - 1));
    return 0;
}*/

/// 10
/*#include<stdio.h>
int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() {
   int val[] = {20, 25, 40};
   int wt[] = {25, 20, 30};
   int W = 50;
   int n = sizeof(val)/sizeof(val[0]);
   printf("The solution is : %d", knapsack(W, wt, val, n));
   return 0;
}*/

/// 11
/*#include <stdio.h>

int main(){
    int n = 5;
    int wt[10] = {3, 3, 2, 5, 1};
    int profit[10] = {10, 15, 10, 12, 8};
    int W = 10;
    int cur_w;
    float tot_v;
    int i, maxi;
    int used[10];
    for (i = 0; i < n; ++i) used[i] = 0;
    cur_w = W;
    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i) if ((used[i] == 0) && ((maxi == -1) || ((float)profit[i]/wt[i] > (float)profit[maxi]/wt[maxi]))) maxi = i;
        used[maxi] = 1;
        cur_w -= wt[maxi];
        tot_v += profit[maxi];
        if (cur_w >= 0) printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1, profit[maxi], wt[maxi], cur_w);
        else {
            printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((1 + (float)cur_w/wt[maxi]) * 100), profit[maxi], wt[maxi], maxi + 1);
            tot_v -= profit[maxi];
            tot_v += (1 + (float)cur_w/wt[maxi]) * profit[maxi];
        }
    }
    printf("Filled the bag with objects worth %.2f.\n", tot_v);
    return 0;
}*/

/// 12 from GFG
/*#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

struct MinHeapNode
{
  char data;
  unsigned freq;
  struct MinHeapNode *left, *right;
};

struct MinHeap
{
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

struct MinHeapNode *newNode(char data, unsigned freq)
{
  struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}
struct MinHeap *createMinHeap(unsigned capacity)
{
  struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
  return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a,struct MinHeapNode **b)
{
  struct MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) smallest = left;
  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) smallest = right;
  if (smallest != idx)
  {
    swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

int isSizeOne(struct MinHeap *minHeap)
{
  return (minHeap->size == 1);
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
  struct MinHeapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

void insertMinHeap(struct MinHeap *minHeap,struct MinHeapNode *minHeapNode)
{
  ++minHeap->size;
  int i = minHeap->size - 1;
  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
  {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap *minHeap)
{
  int n = minHeap->size - 1;
  int i;
  for (i = (n - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
  int i;
  for (i = 0; i < n; ++i) printf("%d", arr[i]);
  printf("\n");
}

int isLeaf(struct MinHeapNode *root)
{
  return !(root->left) && !(root->right);
}
struct MinHeap *createAndBuildMinHeap(char data[],int freq[], int size)
{
  struct MinHeap *minHeap = createMinHeap(size);
  for (int i = 0; i < size; ++i) minHeap->array[i] = newNode(data[i], freq[i]);
  minHeap->size = size;
  buildMinHeap(minHeap);
  return minHeap;
}

struct MinHeapNode *buildHuffmanTree(char data[],int freq[], int size)
{
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
  while (!isSizeOne(minHeap))
  {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void printCodes(struct MinHeapNode *root, int arr[],int top)
{
  if (root->left)
  {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }
  if (root->right)
  {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root))
  {
    printf("%c: ", root->data);
    printArr(arr, top);
  }
}

void HuffmanCodes(char data[], int freq[], int size)
{
  struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);
}

int main()
{
  char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(arr) / sizeof(arr[0]);
  HuffmanCodes(arr, freq, size);
  return 0;
}*/

/// 13
/*#include <stdio.h>
#include <stdlib.h>

int applyfind(int i, int* p)
{
    while(p[i] != 0)
        i=p[i];
    return i;
}
int applyunion(int i,int j, int* p)
{
    if(i!=j) {
        p[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
  const int inf = 999999;
  int k, a, b, u, v, n, ne = 1;
  int mincost = 0;
  int cost[3][3] = {{0, 10, 20},{12, 0,15},{16, 18, 0}};
  int  p[9] = {0};
  n = 3;
  int i, j;
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          if (cost[i][j] == 0) {
              cost[i][j] = inf;
          }
      }
  }
  printf("Minimum Cost Spanning Tree: \n");
  while(ne < n) {
      int min_val = inf;
      for(i=0; i<n; i++) {
          for(j=0; j <n; j++) {
              if(cost[i][j] < min_val) {
                  min_val = cost[i][j];
                  a = u = i;
                  b = v = j;
              }
          }
      }
      u = applyfind(u,p);
      v = applyfind(v,p);
      if(applyunion(u, v, p) != 0) {
          printf("%d -> %d\n", a, b);
          mincost +=min_val;
      }
      cost[a][b] = cost[b][a] = 999;
      ne++;
  }
  printf("Minimum cost = %d",mincost);
  return 0;
}*/

/// 14
/*#include<stdio.h>
#include<stdbool.h>

#define INF 9999999
#define V 5


int main() {
  int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
  };
  int no_edge;
  int selected[V];
  for(int k = 0;k<V;k++) selected[k] = false;
  no_edge = 0;
  selected[0] = true;

  int x;
  int y;

  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}*/

/// 15
/*#include <stdio.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = 999, min_index;
    for (int v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min) min = dist[v], min_index = v;
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++){
        dist[i] = 999, sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != 999 && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
        }
    }
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
                    };
    dijkstra(graph, 0);
    return 0;
}*/

/// 16
/*#include <stdio.h>
#include <stdlib.h>

void floydWarshall(int **graph, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main(void)
{
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **graph = (int **)malloc((long unsigned) n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc((long unsigned) n * sizeof(int));
    }
    printf("Enter the edges: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("The original graph is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    floydWarshall(graph, n);
    printf("The shortest path matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/

/// 17
/*#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool flag = false;
void printValues(int A[], int size){
  printf("{");
  for (int i = 0; i < size; i++) {
    printf(" %d ", A[i]);
  }
  printf("}");
  printf("\n");
}
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
   if (target_sum == sum) {
      flag = true;
      printValues(t, t_size);
      subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
      return;
   }
   else {
      for (int i = ite; i < s_size; i++) {
         t[t_size] = s[i];
         subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
      }
   }
}
void generateSubsets(int s[], int size, int target_sum){
   int* tuplet_vector = (int*)malloc(size * sizeof(int));
   subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
   free(tuplet_vector);
}
int main(){
   int set[] = {1, 2, 5, 6, 8};
   int size = sizeof(set) / sizeof(set[0]);
   printf("The set is ");
   printValues(set , size);
   generateSubsets(set, size, 9);
   if(!flag) printf("\n!! No solution possible !!\n");
   return 0;
}*/

/// 18
/*#include<stdio.h>
#include<math.h>

int board[20],count;

//function for printing the solution
void print(int n)
{
  int i,j;
  printf("\n\nSolution %d:\n\n",++count);

  for(i=1;i<=n;++i)
    printf("\t%d",i);

  for(i=1;i<=n;++i)
  {
    printf("\n\n%d",i);
    for(j=1;j<=n;++j) //for nxn board
    {
    if(board[i]==j)
      printf("\tQ"); //queen at i,j position
    else
      printf("\t-"); //empty slot
    }
  }
}

  // funtion to check conflicts
  // If no conflict for desired postion returns 1 otherwise returns 0
int place(int row,int column)
{
  int i;
  for(i=1;i<=row-1;++i)
  {
    //checking column and digonal conflicts
    if(board[i]==column)
    return 0;
    else
    if(abs(board[i]-column)==abs(i-row))
      return 0;
  }

  return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int row,int n)
{
  int column;
  for(column=1;column<=n;++column)
  {
    if(place(row,column))
    {
    board[row]=column; //no conflicts so place queen
    if(row==n) //dead end
      print(n); //printing the board configuration
    else //try queen with next position
      queen(row+1,n);
    }
  }
}

int main()
{
  int n,i,j;
  void queen(int row,int n);
  printf(" - N Queens Problem Using Backtracking -");
  printf("\n\nEnter number of Queens: ");
  scanf("%d",&n);
  queen(1,n);
  return 0;
}*/

/// 19
/// Solution-1
/*#include <stdio.h>
#include <conio.h>

static int m, n;
static int c = 0;
static int count = 0;
int g[50][50];
int x[50];

void nextValue(int k);
void GraphColoring(int k);
void main()
{
  int i, j;
  int temp;
  printf("\nEnter the number of nodes: ");
  scanf("%d", &n);
  /*
   printf("\nIf edge exists then enter 1 else enter 0 \n");
   for(i=1; i<=n; i++)
   {
    x[i]=0;
    for(j=1; j<=n; j++)
    {
     if(i==j)
      g[i][j]=0;
     else
     {
      printf("%d -> %d: " , i, j);
      scanf("%d", &temp);
      g[i][j]=g[j][i]=temp;
     }

    }

   }

  */
/*printf("\nEnter Adjacency Matrix:\n");
for (i = 1; i <= n; i++)
{
  for (j = 1; j <= n; j++)
  {
    scanf("%d", &g[i][j]);
  }
}
printf("\nPossible Solutions are\n");
for (m = 1; m <= n; m++)
{
  if (c == 1)
  {
    break;
  }
  GraphColoring(1);
}
printf("\nThe chromatic number is %d", m - 1);

// in for loop, m gets incremented first and then the condition is checked

// so it is m minus 1

printf("\nThe total number of solutions is %d", count);

getch();
}

void GraphColoring(int k)

{

int i;

while (1)

{

  nextValue(k);

  if (x[k] == 0)

  {

    return;
  }

  if (k == n)

  {

    c = 1;

    for (i = 1; i <= n; i++)

    {

      printf("%d ", x[i]);
    }

    count++;

    printf("\n");
  }

  else

    GraphColoring(k + 1);
}
}

void nextValue(int k)

{

int j;

while (1)

{

  x[k] = (x[k] + 1) % (m + 1);

  if (x[k] == 0)

  {

    return;
  }

  for (j = 1; j <= n; j++)

  {

    if (g[k][j] == 1 && x[k] == x[j])

      break;
  }

  if (j == (n + 1))

  {

    return;
  }
}
}*/

// Solution-2
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 4
bool graph[V][V] = {
   {0, 1, 1, 1},
   {1, 0, 1, 0},
   {1, 1, 0, 1},
   {1, 0, 1, 0}
};
void showColors(int color[]) {
   printf("Assigned Colors are:\n");
   for (int i = 0; i < V; i++)
      printf("%d ", color[i]);
   printf("\n");
}
//check whether putting a color valid for v
bool isValid(int v, int color[], int c) {
   for (int i = 0; i < V; i++)
      if (graph[v][i] && c == color[i])
         return false;
   return true;
}
bool graphColoring(int colors, int color[], int vertex) {
   //when all vertices are considered
   if (vertex == V)
      return true;
   for (int col = 1; col <= colors; col++) {
      //check whether color is valid or not
      if (isValid(vertex, color, col)) {
         color[vertex] = col;
         // go for additional vertices
         if (graphColoring(colors, color, vertex + 1))
            return true;
         color[vertex] = 0;
      }
   }
   //when no colors can be assigned
   return false;
}
bool checkSolution(int m) {
   //make color matrix for each vertex
   int *color = (int *)malloc(V * sizeof(int));
   for (int i = 0; i < V; i++)
      //initially set to 0
      color[i] = 0;
   //for vertex 0 check graph coloring
   if (graphColoring(m, color, 0) == false) {
      printf("Solution does not exist.\n");
      free(color);
      return false;
   }
   showColors(color);
   free(color);
   return true;
}

int main() {
   // Number of colors
   int colors = 3;
   checkSolution(colors);
   return 0;
}*/

/// 20
/*#include <stdio.h>
#include <conio.h>

int a[10][10], visited[10], n, cost = 0;

void get()
{
  int i, j;
  printf("Enter No.of Cities: ");
  scanf("%d", &n);
  printf("\nEnter Cost Matrix: \n");
  for (i = 0; i < n; i++)
  {
    printf("\n Enter Elements of Row #: %d\n", i + 1);
    for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
    visited[i] = 0;
  }
  printf("\n\nThe cost list is:\n\n");
  for (i = 0; i < n; i++)
  {
    printf("\n\n");
    for (j = 0; j < n; j++) printf("\t %d", a[i][j]);
  }
}

int least(int c)
{
  int i, nc = 999;
  int min = 999, kmin;
  for (i = 0; i < n; i++)
  {
    if ((a[c][i] != 0) && (visited[i] == 0))
      if (a[c][i] < min)
      {
        min = a[i][0] + a[c][i];
        kmin = a[c][i];
        nc = i;
      }
  }
  if (min != 999)
    cost += kmin;
  return nc;
}

void mincost(int city)
{
  int i, ncity;
  visited[city] = 1;
  printf("%d ->", city + 1);
  ncity = least(city);
  if (ncity == 999)
  {
    ncity = 0;
    printf("%d", ncity + 1);
    cost += a[city][ncity];
    return;
  }
  mincost(ncity);
}

void put()
{
  printf("\n\nMinimum cost: ");
  printf("%d\n", cost);
}

void main()
{
  get();
  printf("\n\nThe Path is:\n\n");
  mincost(0);
  put();
}*/

// 21
/*#include<stdio.h>
#include<stdlib.h>

int matrix[25][25], visited_cities[10], limit, cost = 0;

int tsp(int c)
{
  int count, nearest_city = 999;
  int minimum = 999, temp;
  for (count = 0; count < limit; count++)
  {
    if ((matrix[c][count] != 0) && (visited_cities[count] == 0))
    {
      if (matrix[c][count] < minimum)
      {
        minimum = matrix[count][0] + matrix[c][count];
      }
      temp = matrix[c][count];
      nearest_city = count;
    }
  }
  if (minimum != 999)
  {
    cost = cost + temp;
  }
  return nearest_city;
}

void minimum_cost(int city)
{
  int nearest_city;
  visited_cities[city] = 1;
  printf("%d ", city + 1);
  nearest_city = tsp(city);
  if (nearest_city == 999)
  {
    nearest_city = 0;
    printf("%d", nearest_city + 1);
    cost = cost + matrix[city][nearest_city];
    return;
  }
  minimum_cost(nearest_city);
}

int main()
{
  int i, j;
  printf("Enter Total Number of Cities:\t");
  scanf("%d", &limit);
  printf("\nEnter Cost Matrix\n");
  for (i = 0; i < limit; i++)
  {
    printf("\nEnter %d Elements in Row[%d]\n", limit, i + 1);
    for (j = 0; j < limit; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
    visited_cities[i] = 0;
  }
  printf("\nEntered Cost Matrix\n");
  for (i = 0; i < limit; i++)
  {
    printf("\n");
    for (j = 0; j < limit; j++)
    {
      printf("%d ", matrix[i][j]);
    }
  }
  printf("\n\nPath:\t");
  minimum_cost(0);
  printf("\n\nMinimum Cost: \t");
  printf("%d\n", cost);
  return 0;
}*/

/// 22 from GFG
/*#include <stdio.h>

#define V 5

void printSolution(int path[]);

int isSafe(int v, int graph[V][V], int path[], int pos)
{
  if (graph[path[pos - 1]][v] == 0)
    return 0;
  for (int i = 0; i < pos; i++)
    if (path[i] == v)
      return 0;

  return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos)
{
  if (pos == V)
  {
    if (graph[path[pos - 1]][path[0]] == 1)
      return 1;
    else
      return 0;
  }
  for (int v = 1; v < V; v++)
  {
    if (isSafe(v, graph, path, pos))
    {
      path[pos] = v;
      if (hamCycleUtil(graph, path, pos + 1) == 1)
        return 1;
      path[pos] = -1;
    }
  }
  return 0;
}

int hamCycle(int graph[V][V])
{
  int path[V];
  for (int i = 0; i < V; i++)
    path[i] = -1;
  path[0] = 0;
  if (hamCycleUtil(graph, path, 1) == 0)
  {
    printf("\nSolution does not exist");
    return 0;
  }

  printSolution(path);
  return 1;
}

void printSolution(int path[])
{
  printf("Solution Exists:"
         " Following is one Hamiltonian Cycle \n");
  for (int i = 0; i < V; i++)
    printf(" %d ", path[i]);

  printf(" %d ", path[0]);
  printf("\n");
}

int main()
{
  int graph1[V][V] = {
      {0, 1, 0, 1, 0},
      {1, 0, 1, 1, 1},
      {0, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
      {0, 1, 1, 1, 0},
  };
  hamCycle(graph1);
  int graph2[V][V] = {
      {0, 1, 0, 1, 0},
      {1, 0, 1, 1, 1},
      {0, 1, 0, 0, 1},
      {1, 1, 0, 0, 0},
      {0, 1, 1, 0, 0},
  };

  hamCycle(graph2);
  return 0;
}*/

/// 23 from GFG
/*#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{

  char id;
  int dead;
  int profit;
} Job;

int compare(const void *a, const void *b)
{
  Job *temp1 = (Job *)a;
  Job *temp2 = (Job *)b;
  return (temp2->profit - temp1->profit);
}

int min(int num1, int num2)
{
  return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(Job arr[], int n)
{
  qsort(arr, n, sizeof(Job), compare);

  int result[n];
  bool slot[n];

  for (int i = 0; i < n; i++)
    slot[i] = false;

  for (int i = 0; i < n; i++)
  {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
    {
      if (slot[j] == false)
      {
        result[j] = i;
        slot[j] = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (slot[i])
      printf("%c ", arr[result[i]].id);
}

int main()
{
  Job arr[] = {{'a', 2, 100},
               {'b', 1, 19},
               {'c', 2, 27},
               {'d', 1, 25},
               {'e', 3, 15}};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Following is maximum profit sequence of jobs \n");
  printJobScheduling(arr, n);
  return 0;
}*/