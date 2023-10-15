//Cryptopals-step1-challenge-5: this code converts ASCII to HEX

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Convert ASCII to HEX
string convAsciiToHex(string str)
{
    stringstream ss;
    for (int i = 0; i < str.size(); i++)
    {
        ss << std::hex << (int)str[i];
    }
    return ss.str();
}
//Repeating key XOR
string  repeatingKeyXOR(string str, string key)
{
    string newStr = "";
    int count = 0;

        /*
         Perform XOR against each character of the message against each character of the key.
        So if the key was "ICE" and the message is "abcdefg", it would be "a" against "I", then "b" against "C" and "c" against "E"
        but once it reaches the key's limit, you start again from the beginning of the key, which should be like: "d" against "I", "e" against "C" and so on.*/

    for (int i = 0; i < str.size(); i++) {
        unsigned char x = key[count];
        unsigned char y = str[i];
        unsigned char m = y ^ x;

        newStr += m;
        if (count == key.size() - 1)
        {
            count = 0;
        }
        else
        {
            count++;
        }
    }

    //2. Convert the ASCII message to Hexadecimal
    string final = "0";

    final += convAsciiToHex(newStr);

    return final;
}

int main()
{
    //Test cases provided
    char str = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
    char key = "ICE";

    cout << "ENCODED: " << repeatingKeyXOR(str, key) << endl;

    cout << "Original string:" << str << endl;

    return 0;
}
