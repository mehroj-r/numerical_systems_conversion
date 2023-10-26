#include <iostream>
#include <cmath>
#include <string>
#include <typeinfo>
using namespace std;
 
string fix_hex(string item_to_fix) {
    string result = item_to_fix;
    string hexadecimal_letters[6] = {"A","B","C","D","E","F"};
    string hexadecimal_integers[6] = {"10","11","12","13","14","15"};

    for (int i=0; i < 7; i++){
        if (hexadecimal_letters[i] == item_to_fix){
            result = hexadecimal_integers[i];
            break;
        };
    };
    
    return result;
}


string any_to_decimal(int base, string number){
    string result, num;
    long long int temp = 0;
    int count = number.length() - 1;

    while (count != -1){
        num = number[count];
        if (base == 16){
            num = fix_hex(num);
        };
        temp = temp + (stoi(num))*pow(base, number.length()-count-1);
        count--;
    }

    result = to_string(temp);

    return result;
}
 
int main(){

    cout << any_to_decimal(8, "46547213657") << endl;
 
    return 0;
}