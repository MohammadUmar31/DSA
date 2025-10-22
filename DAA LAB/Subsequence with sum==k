#include <bits/stdc++.h>
using namespace std;
void subsequence_with_sum_k(int i, vector<int> &v, int sum, int arr[], int n, int k)
{
    if(i>=n)
    {
        if(sum == k){
            for(auto k:v) cout<<k<<" ";
            cout<<endl;
        }
        return;
    }
    //Pick
    v.push_back(arr[i]);
    sum += arr[i];
    subsequence_with_sum_k( i+1, v, sum, arr, n, k);

    //Not pick
    v.pop_back();
    sum -= arr[i];
    subsequence_with_sum_k( i+1, v, sum, arr, n, k);
}
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> v;
    subsequence_with_sum_k(0, v, 0, arr, n, k);
    return 0;
}
