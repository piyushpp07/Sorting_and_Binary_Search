#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;

void init_code() {
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
//finding the minimum element index so that we can swap it with the first one
int minele(vector<int>&v, int start, int end)
{
   int ele = v[start], idx = start;
   for (int i = start + 1 ; i < end; i++)
   {
      if (v[i] < ele)
      {
         ele = v[i];
         idx = i;
      }
   }
   return idx;
}
//selection sort
void selection_sort(vector<int>&v)
{  int n = v.size();
   for (int i = 0; i < n; i++)
   {
      int index = minele(v, i , n);
      if (index != i)
         swap(v[index], v[i]);
   }
}
//bubble_sort
void bubble_sort(vector<int>&v)
{
   int n = v.size();
   int x = n;
   for (int i = 0; i < n; i++)
   {
      for (int  j = 0; j < n - i - 1; j++)
      {  if (v[j] > v[j + 1])
            swap(v[j], v[j + 1]);
      }
   }
}
//bubble_sort_optimized
void bubble_sort_optimized(vector<int>&v)
{
   int n = v.size();
   int x = n;
   for (int i = 0; i < n; i++)
   {  bool sw = false;   //to reduce no of check if the array is not swapping means it is already sorted
      for (int  j = 0; j < n - i - 1; j++)
      {  if (v[j] > v[j + 1])
         {
            sw = true;
            swap(v[j], v[j + 1]);
         }
      }
      if (sw == false)
         break;
   }
}

//merge function for merge_sort
void merge(vector<int>&v, int l, int mid, int r)
{
   int s1 = mid - l + 1;
   int s2 = r - mid;
   int a1[s1];
   int a2[s2];
   for (int i = 0; i < s1; i++)
      a1[i] = v[l + i];
   for (int i = 0; i < s2; i++)
      a2[i] = v[mid + i + 1];
   int i = 0, j = 0, k = l;
   while (i < s1 && j < s2)
   {
      if (a1[i] > a2[j])
         v[k++] = a2[j++];
      else
         v[k++] = a1[i++];
   }
   while (i < s1)
      v[k++] = a1[i++];
   while (j < s2)
      v[k++] = a2[j++];

}

//merge_sort
void merge_sort(vector<int>&v, int l, int r)
{
   if (l >= r)
      return ;
   else {
      int mid = l + (r - l) / 2;
      merge_sort(v, l, mid);
      merge_sort(v, mid + 1, r);
      merge(v, l, mid, r);
   }
}

int main() {
   init_code();
   int n = 0;
   cin >> n;
   vector<int>v(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> v[i];
   }
   // merge_sort(v, 0, n-1);
   // bubble_sort_optimized(v);
   selection_sort(v);
   for (auto i : v)
      cout << i << " ";
   return 0;
}
