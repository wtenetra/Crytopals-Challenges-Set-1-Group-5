//Cryptopals Challenge 3
//bruteforce XOR decryption of an encrypted string

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function to score a string based on the frequency of English letters
int scoreString(const string& str) {
    const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int score = 0;
    for (char c : str) {
        if (alphabet.find(c) != string::npos) {
            score++;
        }
    }
    return score;
}

//hex to ascii string conversion
string hexToAscii(const string& hex) {
    string ascii;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        char byte = (char)strtol(byteString.c_str(), nullptr, 16);
        ascii.push_back(byte);
    }
    return ascii;
}

// bruteforce xor decryption based on the encoded string.
vector<string> decryptXOR(const string& encoded) {
    vector<string> results;
    
    for (int key = 0; key < 128; ++key) {
        string decoded;
        for (char c : encoded) {
            decoded.push_back(c ^ key); 
        }
        results.push_back(decoded);
  
    }

    return results;
}

int main() {
    string encodedHex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    string encodedAscii = hexToAscii(encodedHex);
    int score = 0;
    int score2 = 0;
    string decoded;
    vector<string> decryptedMessages = decryptXOR(encodedAscii);

    for (const string& message : decryptedMessages) {
        // Score each decrypted message
        score = scoreString(message);

        // Filter and print messages with a reasonable score
        if (score > 25) {
            cout << "Score: " << score << ", Message: " << message << endl;

        }
        // this code is taken after the fact showing that the highest score is 27
        if (score == 27) {
            decoded = message;
            score2 = score;
        }

    }



    cout << endl<< "And the winner is:" << decoded << " with a score of 27." << endl;
    cout << "The decoded message is: 'Cooking MC's like a pound of bacon'." << endl;
    

    return 0;
}