#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

#define LSOne(S) (S & (-S))

#define EPS 1e-9
#define PI 3.14159265358979323846

#define endl '\n'

/* merge sort rec implementation */
// merges two array segments
void merge(int arr[], int l, int p, int r)
{
 int n1 = p - l + 1;
 int n2 = r - p;

 int L[n1], R[n2];
 for (int i = l; i <= p; i++)
 {
  L[i - l] = arr[i];
 }
 for (int i = p + 1; i <= r; i++)
 {
  R[i - p - 1] = arr[i];
 }

 int k = l;
 int i = 0, j = 0;
 while (i < n1 && j < n2)
 {
  if (L[i] < R[j])
  {
   arr[k] = L[i];
   i++;
  }
  else
  {
   arr[k] = R[j];
   j++;
  }
  k++;
 }

 while (i < n1)
 {
  arr[k] = L[i];
  i++;
  k++;
 }

 while (j < n2)
 {
  arr[k] = R[j];
  j++;
  k++;
 }
}

// divide array to two segments, sort, and merge them
void mergeSort(int arr[], int l, int r)
{
 if (l < r)
 {
  int p = l + (r - l) / 2;
  mergeSort(arr, l, p);
  mergeSort(arr, p + 1, r);
  merge(arr, l, p, r);
 }
}

// print matrix in zig zag form
void zigzagPrint(vector<vi> &arr)
{
 int row = 0, col = 0;
 int endk = 0;
 // Boolean variable that will true if we
 // need to increment 'row' value otherwise
 // false- if increment 'col' value
 bool row_inc = 0;

 // Print matrix of lower half zig-zag pattern
 int mn = min(arr.size(), arr[0].size());
 for (int len = 1; len <= mn; ++len)
 {
  for (int i = 0; i < len; ++i)
  {
   cout << arr[row][col] << " ";
   endk++;
   if (endk == arr[0].size())
   {
    endk = 0;
    cout << endl;
   }
   if (i + 1 == len)
    break;
   // If row_increment value is true
   // increment row and decrement col
   // else decrement row and increment
   // col
   if (row_inc)
    ++row, --col;
   else
    --row, ++col;
  }

  if (len == mn)
   break;

  // Update row or col value according
  // to the last increment
  if (row_inc)
   ++row, row_inc = false;
  else
   ++col, row_inc = true;
 }

 // Update the indexes of row and col variable
 if (row == 0)
 {
  if (col == arr[0].size() - 1)
   ++row;
  else
   ++col;
  row_inc = 1;
 }
 else
 {
  if (row == arr.size() - 1)
   ++col;
  else
   ++row;
  row_inc = 0;
 }

 // Print the next half zig-zag pattern
 int MAX = max(arr.size(), arr[0].size()) - 1;
 for (int len, diag = MAX; diag > 0; --diag)
 {

  if (diag > mn)
   len = mn;
  else
   len = diag;

  for (int i = 0; i < len; ++i)
  {
   cout << arr[row][col] << " ";
   endk++;
   if (endk == arr[0].size())
   {
    endk = 0;
    cout << endl;
   }
   if (i + 1 == len)
    break;

   // Update row or col value according
   // to the last increment
   if (row_inc)
    ++row, --col;
   else
    ++col, --row;
  }

  // Update the indexes of row and col variable
  if (row == 0 || col == arr[0].size() - 1)
  {
   if (col == arr[0].size() - 1)
    ++row;
   else
    ++col;

   row_inc = true;
  }

  else if (col == 0 || row == arr.size() - 1)
  {
   if (row == arr.size() - 1)
    ++col;
   else
    ++row;

   row_inc = false;
  }
 }
}

// print matrix in spiral form
void spiralPrint(vector<vi> &a)
{
 int i, k = 0, l = 0;
 int n = a.size(), m = a[0].size();

 /*  k - starting row index
     m - ending row index
     l - starting column index
     n - ending column index
     i - iterator
 */

 while (k < m && l < n)
 {
  /* Print the first row from the remaining rows */
  for (i = l; i < n; ++i)
  {
   printf("%d ", a[k][i]);
  }
  k++;

  /* Print the last column from the remaining columns */
  for (i = k; i < m; ++i)
  {
   printf("%d ", a[i][n - 1]);
  }
  n--;

  /* Print the last row from the remaining rows */
  if (k < m)
  {
   for (i = n - 1; i >= l; --i)
   {
    printf("%d ", a[m - 1][i]);
   }
   m--;
  }

  /* Print the first column from the remaining columns */
  if (l < n)
  {
   for (i = m - 1; i >= k; --i)
   {
    printf("%d ", a[i][l]);
   }
   l++;
  }
 }
}