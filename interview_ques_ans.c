
Skip to content
Using Gmail with screen readers
Enable desktop notifications for Gmail.   OK  No thanks
5 of 3,821
(no subject)
Inbox
	x
syed tabrez
	
11:35 AM (8 hours ago)
	
to me
//// finding count of occurance of an element in an sorted array with o(log n) time complexicity//////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int FirstOccurance(int a[], int low, int high, int val, int n)
{
    int mid;

mid = low+(high-low)/2;

if(mid==0||(a[mid] == val && a[mid-1] != val))
   return mid;

if(a[mid] >= val)
   return FirstOccurance(a, low, mid-1, val, n);
else
return FirstOccurance(a, mid+1, high, val, n);
}


int LastOccurance(int a[], int low, int high, int val, int n)
{
    int mid;

mid = low+(high-low)/2;

if(mid == n-1||(a[mid] == val && a[mid+1] != val))
   return mid;

if(a[mid] <= val)
   return LastOccurance(a, mid+1, high, val, n);
else
return LastOccurance(a, low, mid-1, val, n);
}


int main()
{
    int a[]={0,0,0,0,1,1,1,1,1,2,2,2,3,4,5};
int n = sizeof(a)/sizeof(a[0]);

printf("%d \n", LastOccurance(a,0,n-1,0,n)-FirstOccurance(a,0,n-1,0,n)+1 );

return 0;
}

///////////Depth first search of graph ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjnode {
    int data;
struct adjnode *link;
}AdjNode;

typedef struct adjlist {
    AdjNode *head;
}AdjList;

typedef struct graph {
    int v;
    AdjList *list;
}GRAPH;

void DFS_Util(GRAPH *graph, int v, int visited[])
{
    visited[v]=1;
printf("%d ", v);

AdjNode *temp = graph->list[v].head;

for(; temp->link; temp = temp->link) {
   if(!visited[temp->data])
   DFS_Util(graph, temp->data, visited[]);
}
}

void DFS(GRAPH *graph, int v)
{
    int visited[graph->v];
int i;

for(i=0; i<graph->v; i++)
   visited[i] = 0;

    DFS_util(graph, v, visited);
}

GRAPH *Initialize_graph(int v)
{
    GRAPH *temp;
int i;

temp = (GRAPH *)malloc(sizeof(GRAPH));
temp->v = v;
temp->list = (AdjList *)malloc(v*sizeof(AdjList));

for(i=0; i<v; i++)
   temp->list[i].head = NULL;

return temp;
}

void addEdge(GRAPH *graph, int src, int dst)
{
    AdjNode *temp = (AdjNode *)malloc(sizeof(AdjNode));
temp->data = src;
//temp->link = NULL;
temp->link = graph->list[dst].head;
graph->list[dst].head = temp;

temp = (AdjNode *)malloc(sizeof(AdjNode));
temp->data = dst;
//temp->link = NULL;
temp->link = graph->list[src].head;
graph->list[src].head = temp;
}

void addEdge1(GRAPH *graph, int src, int dst)
{
    AdjNode *temp = (AdjNode *)malloc(sizeof(AdjNode));
temp->data = dst;
//temp->link = NULL;
temp->link = graph->list[src].head;
graph->list[src].head = temp;

temp = (AdjNode *)malloc(sizeof(AdjNode));
temp->data = src;
//temp->link = NULL;
temp->link = graph->list[dst].head;
graph->list[dst].head = temp;
}

void print_graph(GRAPH *graph)
{
    int v;

for(v=0; v<graph->v; v++) {
   AdjNode *temp = graph->list[v].head;
while(temp) {
   printf("%d ", temp->data);
temp = temp->link;
}
printf("\n");
}
}

int main()
{
    GRAPH *graph;

graph = Initialize_graph(5);

addEdge1(graph, 0, 1);
addEdge1(graph, 0, 2);
addEdge1(graph, 1, 2);
addEdge1(graph, 2, 0);
addEdge1(graph, 2, 3);
addEdge1(graph, 3, 3);
addEdge1(graph, 3, 4);

print_graph(graph);

    return 0;
}

//////////counting no of islands in an array///////////////////////////
//////// 1 or group of 1 consider as an island here ///////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 5
#define C 5

int is_valid(int a[][C], int i, int j, int visited[][C])
{
    return (i<R && i>=0 && j>=0 && j<C) && (a[i][i] && !visited[i][j]);
}

void DFS(int a[][C], int i, int j, visited[][C])
{
    int d;
int r_dir[]={-1,-1,-1,0,1,1,1,0};
int c_dir[]={-1,0,1,1,1,0,-1,-1};

visited[i][j] = 1;

for(d=0; d<8; d++) {

if(is_valid(a, i+r_dir[d], j+c_dir[d], visited))
   DFS(a, i+r_dir[d], j+c_dir[d], visited);

}
}

int Num_Of_islands(int a[][C], int r, int c)
{
    int visited[r][c];
int i, j, count=0;

memset(visited, 0, sizeof(visited));

for(i=0; i<r; i++) {
   for(j=0; j<c; j++) {
   if(a[i][j] && !visited[i][j]) {
   DFS(a, i, j, visited);
count++;
}
}
}
return count;
}

int main()
{
    int a[][C] = {{1,1,0,0,0},
    {0,1,0,0,1},
    {1,0,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1}};

    printf("%d \n", Num_Of_islands(a, R, C));
    return 0;
}

///////largest island /////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define R 5
#define C 5

int is_valid(int a[][C], int i, int j, int visited[][C])
{
    return (i<R && i>=0 && j>=0 && j<C) && (a[i][i] && !visited[i][j]);
}

void DFS(int a[][C], int i, int j, int visited[][C], int *count)
{
    int d;
int r_dir[]={-1,-1,-1,0,1,1,1,0};
int c_dir[]={-1,0,1,1,1,0,-1,-1};

visited[i][j] = 1;

for(d=0; d<8; d++) {

if(is_valid(a, i+r_dir[d], j+c_dir[d], visited)) {
   *count +=1;
   DFS(a, i+r_dir[d], j+c_dir[d], visited, count);
}

}
}

int Num_Of_islands(int a[][C], int r, int c)
{
    int visited[r][c];
int i, j;
int count, big_island;

big_island = 0;
memset(visited, 0, sizeof(visited));

for(i=0; i<r; i++) {
   for(j=0; j<c; j++) {
   count=0;
   if(a[i][j] && !visited[i][j]) {
   DFS(a, i, j, visited, count);

if(count > big_island)
   big_island = count;
}
}
}
return big_island;
}

int main()
{
    int a[][C] = {{1,1,0,0,0},
    {0,1,0,0,1},
    {1,0,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1}};

    printf("%d \n", Num_Of_islands(a, R, C));
    return 0;
}

////////word break problem /////////
//////// checking whether we can form proper words with the given string /////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sub_str(char str[], int first, int last)
{
    int i, k, size;

size = last-first+2;
char *temp=(char *)malloc(size*sizeof(char));

for(i=0,k=first; i<=size-1 && k<=last; i++,k++)
   temp[i] = str[k];
temp[size]='\0';

return temp;
}

int dictionary_contains(char *str)
{
    char dictionary[][]={"mobile","samsung","sam","sung",
"man","mango","icecream","and",
 "go", "i","like","ice","cream"};
int i, size;

size = sizeof(dictionary)/sizeof(dictionary[0]);

for(i=0; i<size; i++)
   if(strncmp(dictionary[i], str) == 0)
   return 1;
return 0;
}

int wordBreak(char str[])
{
    int size;

size = strlen(str);
if(size == 0)
   return 1;
int i;
for(i=1; i<size; i++) {
   if(dictionary_contains(str,0,i)
   && wordBreak(str, i, size-i))
   return 1;
}
return 0;
}
int main()
{
    printf("%d \n",wordBreak("likesamsung"));
    return 0;
}
////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateRight(int a[], int n, int index, int outOfindex)
{
    int temp, i;

temp = a[index];

for(i=index; i>outOfindex; i--)
   a[i] = a[i-1];
a[outOfindex] = temp;
}

void rearrange(int a[], int n)
{
    int i, outOfindex;

outOfindex = -1;

for(i=0; i<n; i++) {
   if(outOfindex >= 0) {
   
if((a[i]>=0 && a[outOfindex]<0) || (a[i]<0 && a[outOfindex]>0))
   rotateRight(a, n, i, outOfindex);

if(i-outOfindex > 2)
   outOfindex = outOfindex + 2;
else
   outOfindex = -1;
}

if(outOfindex == -1) {
   if(((a[i]>=0) && !(i&0x01)) || ((a[i]<0) && (i&0x01)))
   outOfindex = i;
}
}
}

void print_array(int a[] , int n)
{
    int i;

for(i=0; i<n; i++)
   printf("%d ", a[i]);
printf("\n");
}

int main()
{
    int a[]={-5,-2,5,2,4,7,1,8,0,-8};
int n = sizeof(a)/sizeof(a[0]);

print_array(a, n);

rearrange(a,n);

print_array(a, n);

    return 0;
}





void max_in_every_window(int a[], int n)
{
    int i,var;

var = 0;
for(i=1; i<k; i++)
   if(a[i]>a[var])
   var = i;


for(; i<n; i++) {
   printf("%d ", a[var]);
        if((i-k < k)||(i-k >=k) && (a[var]<a[i]))
var = i;
}
}





void reverse(LIST **head)
{
    LIST *temp = *head;
LIST *
}

typedef struct node {
    int data;
struct node *link;
}LIST;

LIST *intersection(LIST *l1, LIST *l2)
{
    int size1,size2,diff;

size1 = sizeof_list(l1);  //get the size of list1
size2 = sizwof_list(l2);  //get the size of list2

diff = abs(size1-size2);  // get the difference

    if(size2 > size1)         // swap the head pointers for program convenience
   swap(&l1,&l2);

    while(diff >=1) {        // move l1 head diff times
   l1 = l1->link;
diff--;
}

while(l1->link && l2->link && l1->link != l2->link) {
   l1 = l1->link;
l2 = l2->link;
}

return l1 ? ((l1->link == l2->link)? l1 : NULL) : NULL;
}


#include <stdio.h>
#include <stdio.h>

int sum_of_digits(int num)
{
    int sum, rem;

sum=0;

while(num>0) {
   rem = num%10;
num = num/10;
sum += rem;
if(sum>=10) {
   num = num*100+sum;
sum=0;
}
}
return sum;
}


int main()
{
    int num=459;
int sum;

printf("%d\n", sum_of_digits(num));

    return 0;
}


//////////water tap problem//////////////////
int water_tap(int a[], int n)
{
    int left_max[n],right_max[n];
int i, water_tapped=0;

left_max[0]=a[0];
right_max[n-1]=a[n-1];

for(i=1; i<n-1; i++) {
   left_max[i]=MAX(a[i], left_max[i-1]);
right_max[n-i-1]=MAX(a[n-i-1], right_max[n-i]);
}

for(i=0; i<n; i++) {
   water_tapped += MIN(left_max[i], right_max[i])-a[i];
}

return water_tapped;
}


//////////////// kth largest in a running stream ///////////////////

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
*a = *b;
*b = temp;
}
void min_heapify(int a[], int s, int n)
{
    int l,r,smallest;

l=2*s+1;
r=2*s+2;
smallest = s;

if(l<n && a[l] < a[smallest])
   smallest = l;

if(r<n && a[r] < a[smallest])
   smallest = r;

if(smallest != s) {
   swap(&a[s], &a[smallest]);
min_heapify(a,smallest, n);
}
}

void min_heap(int a[], int n)
{
    int i=n/2-1;

while(i-- >=0)
   min_heapify(a,i,n);

for(i=n-1; i>=0; i--) {
        swap(&a[0], &a[i]);
min_heapify(a,0, i);
}
}

void kth_largest_InStream(int a[], int n, int k)
{
    int heap[k];
int i,count=0;

for(i=0; i<k; i++)
   heap[count++] = a[i];

min_heap(heap, k);
printf("%d\n", heap[0]);

for(; i<n; i++) {
if(a[i] > heap[0]) {
heap[k-1] = a[i];
min_heap(heap, k);
}
printf("%d\n", heap[0]);
}
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
int size;

size = sizeof(a)/sizeof(a[0]);

kth_largest_InStream(a, size, 3);
    return 0;
}


/////////merging k sorted arrays ////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct ele {
    int data;
    int i,j;
}ELE;
 
 
void swap(ELE *a, ELE *b)
{
    ELE temp = *a;
*a = *b;
*b = temp;
}

void min_heapify(ELE a[], int i, int n)
{
    int l,r,smallest;

    smallest = i;
    l=2*i+1;
    r=2*i+2;

    if(l<n && a[l].data < a[smallest].data)
        smallest = l;

    if(r<n && a[r].data < a[smallest].data)
        smallest = r;

    if(smallest != i) {
        swap(&a[i], &a[smallest]);
        min_heapify(a, smallest, n);
    }
}

void min_heap(ELE a[], int n)
{
    int i=n/2-1;

    while(i >= 0) {
        min_heapify(a,i,n);
i--;
}

    for(i=n-1; i>=0; i--) {
        swap(&a[0], &a[i]);
        min_heapify(a,0,i);
    }
}

void merge_k_largest_sorted_arrays(int a[][4], int n, int k)
{
    int count;
    int sa[n*k];
    ELE heap[k];

    for(count=0; count<k; count++) {
        heap[count].data = a[count][0];
        heap[count].i = count;
        heap[count].j = 1;
    }
    min_heap(heap, k);

    for(count=0; count<n*k; count++) {
        ELE temp = heap[k-1];
        sa[count] = temp.data;
        if(temp.j < n) {
            temp.data = a[temp.i][temp.j];
            temp.j += 1;
        } else {
            temp.data = INT_MAX;
        }
        heap[k-1] = temp;
        min_heap(heap,k);
    }
 
    for(count=0; count<n*k; count++)
        printf("%d ", sa[count]);
    printf("\n");
}
 
int main()
{
    int a[][4]={{2,6,12,34},
                 {1,9,20,1000},
                 {23,34,90,2000},
                 };
 
    int n,k;
 
k = sizeof(a)/sizeof(a[0]);
    n = sizeof(a[0])/sizeof(a[0][0]);
 
merge_k_largest_sorted_arrays(a, n, k);
 
    return 0;
 }
 
 
 
/////////////merge sort ///////////////////////
#include <stdio.h>
#include <string.h>

void merge(int a[], int l, int m, int r)
{
    int i,j,k;
int n1,n2;

n1=m-l+1;
n2=r-m;
int L1[n1];
int L2[n2];

for(i=0; i<n1; i++)
   L1[i] = a[i];
for(i=0; i<n2; i++)
   L2[i] = a[m+1+i];

i=0,j=0,k=l;
while(i<n1 && j<n2) {
   if(L1[i]<=L2[j])
   a[k] = L1[i++];
else
   a[k] = L2[j++];
k++;
}

while(i<n1)
   a[k++] = L1[i++];

while(j<n2)
   a[k++] = L2[j++];
}

void merge_sort_util(int a[], int l, int r)
{
    if(l < r) {
   int mid = l+(r-l)/2;

merge_sort_util(a, l, mid);
merge_sort_util(a, mid+1, r);

merge(a, l, mid, r);
}
}

void merge_sort(int a[])
{
    int n;

n=sizeof(a)/sizeof(a[0]);
merge_sort_util(a,0,n-1);
}

int main()
{
    int a[]={6,5,4,3,2,1};
int i;
merge_sort(a);

for(i=0; i<6; i++)
   printf("%d ", a[i]);
printf("\n");

    return 0;
}
////////////////////////////
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *p[4]={(int[]){1,2,3,4},
 (int[]){1,2,3,4,5,6},
 (int[]){1,2,3},
 (int[]){1,2,3,4,5}};

printf("%d\n", sizeof(p[0])/sizeof(p[0][0]));

    return 0;
}



//////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *p=(int[]){1,2,3,4};

printf("%d\n", sizeof(p)/sizeof(p[0]));

    return 0;
}

#include <string.h>
#include <stdio.h>
int main(){
printf("%d %d\n",sizeof("string"),strlen("string"));
return 0;
}


//////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

int main()
{
    int a[]={10,20,30,40,50,60};
int *p1=a;
int *p2=a+5;

printf("%d\n", p2-p1);
printf("%d\n", (char *)p2-(char *)p1);
    return 0;
}

///////////serialize and deserializing tree //////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#define MARKER -1

typedef struct node {
    int data;
struct node *left, *right;
}NODE;

NODE *create_node(int val)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
temp->data = val;

return temp;
}

void serialize_tree(NODE *root, FILE *fp)
{
    if(root == NULL) {
   fprintf(fp,"%d", MARKER);
return;
}

fprintf(fp,"%d", root->data);
serialize_tree(root->left, fp);
serialize_tree(root->right, fp);
}

void deserialize_tree(NODE *root, FILE *fp)
{
    int val;

if(!fscanf(fp, "%d", &val) || val == MARKER)
   return;

root = create_node(val);
deserialize_tree(root->left, fp);
deserialize_tree(root->right, fp);
}


void inorder_traversal(NODE *root)
{
    if(!root)
   return;

inorder_traversal(root->left);
printf("%d ", root->data);
inorder_traversal(root->right);
}

int main()
{
    NODE *root = create_node(20);
    root->left = create_node(8);
    root->right = create_node(22);
    root->left->left = create_node(4);
    root->left->right = create_node(12);
    root->left->right->left = create_node(10);
    root->left->right->right = create_node(14);

    inorder_traversal(root);
printf("\n");

    FILE *fp;

    fp = fopen("tree.txt", "w");
    if(fp == NULL) {
   printf("could not open the file\n");
return 0;
    }

serialize_tree(root, fp);

fclose(fp);

NODE *dhead=NULL;

fp = fopen("tree.txt", "r");
if(fp == NULL) {
   printf("could not open the file\n");
return 0;
    }
deserialize_tree(dhead, fp);
fclose(fp);

    inorder_traversal(dhead);
printf("\n");

    return 0;
}

//////////////medium in an running stream of integers ////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 128
#define MIN_HEAP 1
#define MAX_HEAP 0

typedef struct heap {
    int data[MAX];
    int size;
}HEAP;

HEAP *Initialize_heap()
{
    HEAP *temp=(HEAP *)malloc(sizeof(HEAP));
   
    temp->size=0;
   
    return temp;
}

void swap(int *a, int *b)
{
    int temp;
   
    temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(HEAP *h, int i, int n)
{
    int l,r,largest;
   
    largest = i;
    l=2*i+1;
    r=2*i+2;
   
    if(l<n && h->data[l] > h->data[largest])
        largest = l;
       
    if(r<n && h->data[r] > h->data[largest])
        largest = r;
       
    if(largest != i) {
        swap(&h->data[largest], &h->data[i]);
        max_heapify(h, largest, n);
    }
}

void max_heap_routine(HEAP *h)
{
    int i=(h->size)/2-1;
   
    while(i>=0) {
        max_heapify(h, i, h->size);
        i--;
    }
   
    for(i= h->size-1; i>=0; i--) {
        swap(&h->data[0], &h->data[i]);
        max_heapify(h, i, h->size);
    }
}

void min_heapify(HEAP *h, int i, int n)
{
    int l,r,smallest;
   
    smallest = i;
    l=2*i+1;
    r=2*i+2;
   
    if(l<n && h->data[l] < h->data[smallest])
        smallest = l;
       
    if(r<n && h->data[r] < h->data[smallest])
        smallest = r;
       
    if(smallest != i) {
        swap(&h->data[smallest], &h->data[i]);
        min_heapify(h, smallest, n);
    }
}

void min_heap_routine(HEAP *h)
{
    int i=(h->size)/2-1;
   
    while(i>=0) {
        min_heapify(h, i, h->size);
        i--;
    }
   
    for(i= h->size-1; i>=0; i--) {
        swap(&h->data[0], &h->data[i]);
        min_heapify(h, i, h->size);
    }
}

int HeapSizeSame(HEAP *min_heap, HEAP *max_heap)
{
    if(min_heap->size == max_heap->size)
        return 0;
    else if(min_heap->size > max_heap->size)
        return 1;
    else
        return -1;
}

void HeapInsert(HEAP *heap, int val, int flag)
{
    heap->data[heap->size] = val;
    heap->size +=1;
   
if(heap->size > 1) {
        if(flag)
            min_heap_routine(heap);
        else
            max_heap_routine(heap);
}
}

int GetTop(HEAP *heap)
{
    return heap->data[0];
}

int ExtractTop(HEAP *heap, int flag)
{
    int val;
   
    val = heap->data[0];
   
    if(flag) {
        heap->data[0] = INT_MIN;
        min_heap_routine(heap);
    } else {
        heap->data[0] = INT_MAX;
        max_heap_routine(heap);
    }
    heap->size -= 1;
   
    return val;
}

int get_mediam(HEAP *min_heap, HEAP *max_heap, int val, int m)
{
    int c = HeapSizeSame(min_heap, max_heap);

    switch(c) {
        case 0:
            if(val < m) {
                HeapInsert(min_heap, val, MIN_HEAP);
                m = GetTop(min_heap);
            } else {
                HeapInsert(max_heap, val, MAX_HEAP);
                m = GetTop(max_heap);
            }
        break;
       
        case 1:
            if(val < m) {
                HeapInsert(max_heap, ExtractTop(min_heap, MIN_HEAP), MAX_HEAP);
                HeapInsert(min_heap, val, MIN_HEAP);
            } else {
                HeapInsert(max_heap, val, MAX_HEAP);
            }
           
            m = (GetTop(min_heap)+GetTop(max_heap))/2;
        break;
       
        case -1:
            if(val < m) {
                HeapInsert(min_heap, val, MIN_HEAP);
            } else {
                HeapInsert(min_heap, ExtractTop(max_heap, MAX_HEAP), MIN_HEAP);
                HeapInsert(max_heap, val, MAX_HEAP);
            }
            m = (GetTop(min_heap)+GetTop(max_heap))/2;
        break;
    }
   
    return m;
}

int main()
{
    int a[]={5,15,1,3,2,8,7,9,10,6,11,4};
    int n, m, i;
    HEAP min_heap, max_heap;
   
    m=0;
min_heap->size = max_heap->size = 0;
    n = sizeof(a)/sizeof(a[0]);
    //min_heap = Initialize_heap();
    //max_heap = Initialize_heap();

    for(i=0; i<n; i++) {
        m = get_mediam(&min_heap, &max_heap, a[i], m);
        printf("%d\n", m);
    }
    return 0;
}


///////finding largest window with k no of intergers repeated //////////////////////

#include <stdio.h>
#include <string.h>
#include <limits.h>

int Largest_window(int a[], int n, int k)
{
    int i, max_len, count, start;
int hash[10];

max_len = INT_MIN;
count = start = 0;

memset(hash, 0, sizeof(hash));

for(i=0; i<n; i++) {
   hash[a[i]]++;
if(hash[a[i]] == 1)
   count++;

if((count == k) && (i == n-1))
   return i-start+1;

if(count == k+1) {
   
if(max_len < i-start)
   max_len = i-start;

while(count > k) {
   hash[a[start]]--;
if(hash[a[start]] == 0)
   count--;
start++;
}
}
}
return max_len;
}

int main()
{
    int a[]={1,2,3,1,4,3,4,1,2};
int size = sizeof(a)/sizeof(a[0]);

printf("%d \n", Largest_window(a,size, 3));
    return 0;
}









































































































	
	
	
