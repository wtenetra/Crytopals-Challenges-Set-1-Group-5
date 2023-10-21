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
#include <openssl/aes.h>

using namespace std;

#define INT_MAX 1000000

class Cryptopals 

{
public:
	//Constructor
	Cryptopals();

	//Base64 Decoder
	string b64_to_ascii(string str);

	//Base64 Encoder
	string b64_encode(string str);




};


//Constructor
Cryptopals::Cryptopals() {}



//Base64 Decoder
string Cryptopals::b64_to_ascii(string str)
{
	//First convert the base64 to it's respective values
	// Use this as a reference to get the position of each character:
	// ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/

	//Base64 characters
	const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	string ascii;
	int val = 0, bits = 0;

	for (char c : str)
	{
		if (c == '=')
			break; //Padding found, stop decoding

		size_t index = base64_chars.find(c);

		if (index != string::npos)
		{
			val = (static_cast<unsigned long long>(val) << 6) | index;
			bits += 6;

			if (bits >= 8)
			{
				bits -= 8;
				ascii += static_cast<char>((val >> bits) & 0xFF);

			}
		}
		else
		{
			//Ignore characters not in the Base64 character set
		}
	}

	return ascii;



}

//Base64 Encoder
string Cryptopals::b64_encode(string str)
{
	string newStr = "";
	string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	//Number of bytes per 12 bits
	int bytes = str.size() / 3;
	int padding = str.size() % 3;

	//Padding must be either 0 or 1
	if (padding > 1)
	{
		return newStr;
	}

	//Number of characters to be encoded is 3
	int count = bytes * 3;

	unsigned long long h = 0;

	int i = 0;
	for (i = 0; i < count; i += 3) //iterate every 3 chars
	{
		//Get every 3 chars
		char a[2] = { str[i], 0 };
		char b[2] = { str[i + 1], 0 };
		char c[2] = { str[i + 2], 0 };

		//Now, convert each hex character (base 16) to it's equivalent decimal number
		//and merge them into one variable
		h = strtoull(a, nullptr, 16) << 8; //shift left by 8 bits
		h |= strtoull(b, nullptr, 16) << 4; //shift left by 4 bits
		h |= strtoull(c, nullptr, 16); //no shift required only the first 2 characters need

		//HEX: 0x3F -> DEC: 63 -> ASCII: ?

		newStr += ref[0x3F & (h >> 6)]; //first b64 char; shift to right by 6 bits
		newStr += ref[0x3F & h]; //second b64 char
	}

	//if padding is required
	//Follows the same pattern as the above.
	if (padding == 1)
	{
		char a[2] = { str[i], 0 };
		h = strtoull(a, nullptr, 16) << 8; // shift left by 8 bits
		newStr += ref[0x3F & (h >> 6)];
		newStr += '='; //add this towards the end of the encoded string
	}

	return newStr;
}

