#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

class Cryptopals
{

   
    
private:
  

public:
    map<char, string> hex_table() {//hashmap hard hex->binary


        map<char, string> map;

        map['0'] = "0000";
        map['1'] = "0001";
        map['2'] = "0010";
        map['3'] = "0011";
        map['4'] = "0100";
        map['5'] = "0101";
        map['6'] = "0110";
        map['7'] = "0111";
        map['8'] = "1000";
        map['9'] = "1001";
        map['a'] = "1010";
        map['b'] = "1011";
        map['c'] = "1100";
        map['d'] = "1101";
        map['e'] = "1110";
        map['f'] = "1111";

        return map;

    }
    //

    string hex_binary_conversion(string hexString) {

        string returnString = "";
        //string error = "ERROR NOT VALID HEXADECIMAL!";

        map<char, string> hexBinary = hex_table();

        for (int i = 0; i < hexString.size(); i++) {

            if (isdigit(hexString[i])) {

                returnString += hexBinary.find(hexString[i])->second;
            }

            else {
                returnString += hexBinary.find(hexString[i])->second;

            }

        }


        return returnString;
    }

    string addSpaces(string insert, int spaces) {

        string returnString = "";

        int count = 0;


        for (int i = 0; i < insert.size(); i++) {

            if (count == spaces) {

                returnString += " ";

                i--;

                count = 0;

           }
            else {

                returnString += insert[i];
                count++;

            }

            
        }


        return returnString;
    }

    vector<int>conversion_bin_dec(string str, double power) {

        vector<int> returnVector;
        
        string newStr = "";

        istringstream iss(str);

        string x;
        
        while (iss>>x)
        {
            double p = power;

            double decimal = 0.0;


            for(int i = 0; i<x.size();i++){
            
                if (x[i] == '1') {

                    decimal += pow(2.0, p);
            }
                p--;
            }
            returnVector.push_back((int)decimal);

        }
        return returnVector;

    }

    string converstion_hex_b64(string hexString) {

        string returnString;

        string b64Reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        string bin2Dec = addSpaces(hex_binary_conversion(hexString), 6);

        vector<int> decimal = conversion_bin_dec(bin2Dec, 5.0);


        for (int i = 0; i < decimal.size(); i++) {

            returnString += b64Reference[decimal[i]];

        }
        return returnString;
    }
    string ascii_2_hex(string str) {

        stringstream ss;

        for (int i = 0; i< str.size(); i++) {

            ss << std::hex << (int)str[i];

        }
        return ss.str();



    }
    string fixedXOR(string str1,string str2) {

        if (str1.size() != str2.size()) {


            return "Error the strings are not equal length";
        }

        else {

            string returnString = "";


            //convert hex to binary with 8 bits

            str1 = addSpaces(hex_binary_conversion(str1), 8);
            str2 = addSpaces(hex_binary_conversion(str2), 8);

            //binary to decimal

            vector<int> vStr1 = conversion_bin_dec(str1, 7.0);
            vector<int> vStr2 = conversion_bin_dec(str2, 7.0);

            //XOR

            for (int i = 0; i < vStr1.size(); i++) {

                unsigned char a = vStr1[i];

                unsigned char b = vStr2[i];


                unsigned char x = a ^ b;


                returnString += x;

            }

            cout << "Ascii: " << returnString << endl;
            returnString = ascii_2_hex(returnString);
            return returnString;
        }



    }



}
;

