#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> series(n);
    series[0] = 0;
    series[1] = 1;
    cout<<series[0]<<" "<<series[1];
    for(int i=2; i < n; i++){
        series[i] = series[i-1] + series[i-2];
        cout<<" "<<series[i];
    }
    cout<<endl;
    return 0;
}


/*
1 1 2 3 5 8 13
a b 

*/