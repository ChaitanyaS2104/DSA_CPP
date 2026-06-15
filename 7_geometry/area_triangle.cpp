#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double s1,s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    double s = (s1 + s2 + s3 ) / 2;
    cout<<s<<endl;
    double num = s * (s - s1) * (s - s2) * (s - s3);
    cout<<num<<endl;
    double area = pow(num, 0.5);
    cout<<area<<endl;
    return 0;
}