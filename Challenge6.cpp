#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iterator>
#include <cstdint>
#include <cassert>

using namespace std;

// Function to compute Hamming distance between two strings
int hammingDistance(const string& str1, const string& str2) {
    assert(str1.length() == str2.length());
    int distance = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        char xorResult = str1[i] ^ str2[i];
        while (xorResult) {
            distance += (xorResult & 1);
            xorResult >>= 1;
        }
    }
    return distance;
}

// Function to guess the key size
int guessKeySize(const vector<uint8_t>& ciphertext, int maxKeySize = 40) {
    vector<pair<int, double>> normalizedDistances;

    for (int keySize = 2; keySize <= maxKeySize; ++keySize) {
        double totalDistance = 0.0;

        for (int i = 0; i < keySize; ++i) {
            for (int j = i + keySize; j < static_cast<int>(ciphertext.size()); j += keySize) {
                string block1(ciphertext.begin() + i, ciphertext.begin() + i + keySize);
                string block2(ciphertext.begin() + j, ciphertext.begin() + j + keySize);

                totalDistance += hammingDistance(block1, block2);
            }
        }

        double normalizedDistance = totalDistance / keySize;
        normalizedDistances.push_back(make_pair(keySize, normalizedDistance));
    }

    auto minDistance = min_element(normalizedDistances.begin(), normalizedDistances.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    return minDistance->first;
}

// Function to break the repeating-key XOR encryption
string breakRepeatingKeyXor(const vector<uint8_t>& ciphertext, int keySize) {
    vector<string> blocks(keySize);
    vector<string> transposedBlocks(keySize, "");

    for (size_t i = 0; i < ciphertext.size(); ++i) {
        blocks[i % keySize] += ciphertext[i];
    }

    string key;

    for (const auto& block : blocks) {
        char bestKeyByte = 0;
        int bestScore = 0;

        for (int keyByte = 0; keyByte < 256; ++keyByte) {
            string decryptedBlock;

            for (char encryptedChar : block) {
                decryptedBlock += (encryptedChar ^ keyByte);
            }

            int score = 0;
            for (char c : decryptedBlock) {
                if (isalpha(c) || c == ' ') {
                    score++;
                }
            }

            if (score > bestScore) {
                bestScore = score;
                bestKeyByte = static_cast<char>(keyByte);
            }
        }

        key += bestKeyByte;
    }

    return key;
}

int main() {
    ifstream file("6.txt", ios::binary);

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read the base64-encoded ciphertext from the file
    string base64Ciphertext((istreambuf_iterator<char>(file)), {});
    vector<uint8_t> ciphertext;

    // Decode the base64 ciphertext into binary data
    copy(base64Ciphertext.begin(), base64Ciphertext.end(), back_inserter(ciphertext));

    int keySize = guessKeySize(ciphertext);
    string key = breakRepeatingKeyXor(ciphertext, keySize);

    string plaintext;

    for (size_t i = 0; i < ciphertext.size(); ++i) {
        plaintext += (ciphertext[i] ^ key[i % keySize]);
    }

    cout << plaintext << endl;

    return 0;
}
