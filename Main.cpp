#include "Cryptopals.h"


int main() {


	Cryptopals test;

	string challenge = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

	cout << challenge << endl;

	cout << test.converstion_hex_b64(challenge) << endl;
	//end of CHALLENGE 1: Daniel Schroeder

	string chall2A = "1c0111001f010100061a024b53535009181c";
	string chall2B = "686974207468652062756c6c277320657965";

	cout << test.fixedXOR(chall2A, chall2B) << endl;

	//end of CHALLENGE 2: Daniel Schroeder
	return 0;
}