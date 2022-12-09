#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& vec, int l, int r){
    if(l >= r) return;
    int pivot = vec[l];
    vector<int> smaller;
    vector<int> larger;
    for(int i=l+1;i<=r;i++){
        if(vec[i] >= pivot) larger.push_back(vec[i]);
        else smaller.push_back(vec[i]);
    }
    int i;
    for(i=0;i<smaller.size();i++){
        vec[l+i] = smaller[i];
    }
    int pivotLocation = l+i;
    vec[pivotLocation] = pivot;
    for(i=0;i<larger.size();i++){
        vec[r - i] = larger[i];
    }
    quickSort(vec, l, pivotLocation - 1);
    quickSort(vec, pivotLocation + 1, r);
}

int main(){
    vector<int> vec = {4,3,9,1,5,4,3,4,5,5,5,5,5555,333,2,2,2,3,4,3,566,2363,63,246643,6,436,43,646};
    int n = vec.size();

    for(auto num : vec) cout<<num<<" ";
    cout<<endl;
    quickSort(vec, 0, n-1);
    for(auto num : vec) cout<<num<<" ";
    cout<<endl;
    return 0;
}
