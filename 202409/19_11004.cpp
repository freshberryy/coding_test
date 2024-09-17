#include<bits/stdc++.h>
using namespace std;
int n, k, x;
vector<int> a;
int partition(int s, int e){
    if(s + 1 == e){
        if(a[s] > a[e]){
            swap(a[s], a[e]);
        }
        return e;
    }
    int m = (s + e) / 2;
    swap(a[s], a[m]);
    int pivot = a[s];
    int i = s + 1, j = e;
    while(i <= j){
        while(pivot < a[j] && j > 0) j--;
        while(pivot > a[i] && i < a.size() - 1) i++;
        if(i <= j) swap(a[i++], a[j--]);
    }
    a[s] = a[j];
    a[j] = pivot;
    return j;
}
void quicksort(int s, int e, int k){
    int pivot = partition(s, e);
    if(pivot == k)return;
    else if(k < pivot) quicksort(s, pivot - 1, k);
    else quicksort(pivot + 1, e, k);
}
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    quicksort(0, n - 1, k - 1);
    cout << a[k - 1];
}