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

string break_hex(string item_to_fix) {
    string result = item_to_fix;
    string hexadecimal_letters[6] = {"A","B","C","D","E","F"};
    string hexadecimal_integers[6] = {"10","11","12","13","14","15"};

    for (int i=0; i < 7; i++){
        if (hexadecimal_integers[i] == item_to_fix){
            result = hexadecimal_letters[i];
            break;
        };
    };
    
    return result;
}

string any_to_decimal(int base, string number){
    /*Converts from binary, octal, hexadecimal numeric systems to decimal*/
    string result, num;
    long long int temp = 0;
    int count = number.length() - 1;

    while (count != -1){
        num = number[count];
        if (base == 16 && int(num[0])>=65 & int(num[0]<=70) ){
            num = fix_hex(num);
        };
        temp = temp + (stoi(num))*pow(base, number.length()-count-1);
        count--;
    }

    result = to_string(temp);

    return result;
}
 
string decimal_to_any(int base, long long int number){
    /*Converts from decimal to binary, octal, hexadecimal numeric systems*/
    string result, cache;
    long long int whole_part=base, temp=number; 
    int remainder_part, count=0;

    while (whole_part >= base){ //
        whole_part = temp/base;
        remainder_part = temp%base;
        if (remainder_part >= 10 && base == 16){
            cache = break_hex(to_string(remainder_part));
            result.insert(0, cache);
            temp = temp/base;
            count++;
            continue;
        };
        result.insert(0, to_string(remainder_part));
        temp = temp/base;
        count++;
    };

    result.insert(0, to_string(whole_part));

    return result;
}


int main(){

    cout << any_to_decimal(16, "123A") << endl;
    cout << decimal_to_any(16, 73927) << endl;

    return 0;
}