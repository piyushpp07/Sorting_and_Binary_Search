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
   merge_sort(v, 0, n-1);
   for (auto i : v)
      cout << i << " ";
   return 0;
}
