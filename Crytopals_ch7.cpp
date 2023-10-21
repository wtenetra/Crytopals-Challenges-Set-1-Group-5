//The Cryptopals Crypto Challenges - Set 1 Challenge 7

#pragma warning(disable : 4996)


using namespace std;


#include "Crytopals_ch7.h"
//Follow the documentation: http://docs.huihoo.com/doxygen/openssl/1.0.1c/crypto_2aes_2aes_8h.html
int main()
{
	Cryptopals crypt;

	AES_KEY decryptKey;
	int bitMode = 128; //AES-128 mode

	string key = "YELLOW SUBMARINE";
	string message;

	
	ifstream infile;
	infile.open("ch7.txt");
	getline(infile, message, '\0');
	infile.close();
	

	message = crypt.b64_to_ascii(message);

	//Set the decrypt key before inverting AES
	AES_set_decrypt_key((const unsigned char*)key.c_str(), bitMode, &decryptKey);

	unsigned char* decrypted = new unsigned char[message.size() + 2];
	decrypted[message.size()] = '\0';

	//Using ECB means you divide the message into blocks based on the number of bits
	//in this case, 128 / 8 = 64 blocks;
	int blocks = bitMode / 8;


	for (int i = 0; i * blocks < message.size(); i++)
	{
		AES_ecb_encrypt((const unsigned char*)&(message.c_str()[i * blocks]), &decrypted[i * blocks], &decryptKey, AES_DECRYPT);
	}

	cout << decrypted << endl;
	

	return 0;


	
}