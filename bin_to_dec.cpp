#include<iostream>
#include<vector>

using namespace std;

int bin_to_dec(int num);
int dec_to_binary(int num);
int dec_bin_toggle_dec(int num);

int main(){
    int num;
    cin>>num;
    int result = dec_bin_toggle_dec(num);
    cout<<result<<endl;
    return 0;
}

int bin_to_dec(int num){
    int dec =0;
    int num_len = 0;
    while(num/10 > 0){
        int digit = num % 10;
        dec = dec + digit * pow(2, num_len);
        num = num/10;
        num_len++;
    }
    dec = dec + num * pow(2, num_len);
    return dec;
}

int dec_to_binary(int num){
    int bin = 0;
    while(num / 2 > 0){
        int digit = num % 2;
        bin = bin * 10 + digit;
        num /= 2;
    }
    bin = bin * 10 + 1;
    return bin;

}

int dec_bin_toggle_dec(int num){
    int num_copy = num; // 4
    int comp = 0;
   
    while(num_copy / 2 > 0){ //10, 1, 0
        comp =  2 * comp + 1; // 1, 11
        num_copy /= 2; //10, 1
    }
    comp =  2 * comp + 1; // 111
    int result = comp ^ num; //3
    return result;
}
/*
101001 / 10 = 10100, 1, num_len = 0, dec = 1 (10100 > 0)
10100 / 10 = 1010, 0, num_len = 1, dec = 1 + 0 (1010 > 0)
1010 / 10 = 101, 0, num_len = 2, dec = 1 + 0 (101 > 0)
101 / 10 = 10, 1, num_len = 3, dec = 1 + 8 (10100 > 0)
10 / 10 = 1, 0, num_len = 4, dec = 9 + 0 (10100 > 0)
1 / 10 = 0, 1, num_len = 5, dec = 9 + 32 (10100 > 0)
dec = 41



23 / 2 = 11, 1, bin = 1 (11>0)
11 / 2 = 5, 1, bin = 10 + 1 (5>0)
5 / 2 = 2, 1, bin = 110 + 1 (2>0)
2 / 2 = 1, 0, bin = 1110 + 0 (1>0)
1 / 2 = 0, 1, bin = 11100 + 1
bin - 11101

1010101
1111111 (EXOR)
0101010
*/