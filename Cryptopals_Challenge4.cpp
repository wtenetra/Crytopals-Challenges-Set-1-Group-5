//Cryptopals Challenge 4 
//bruteforcce XOR decryption of an encrypted file
//displays the decoded string
//follows the same logic as Challenge 3 just with a few added steps

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//Function for Hex to Ascii conversion
string hexToAscii(const string& hex) {
    string ascii;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        char byte = (char)strtol(byteString.c_str(), nullptr, 16);
        ascii.push_back(byte);
    }
    return ascii;
}

//function to XOR values
vector<string> decryptXOR(const string& encoded) {
    vector<string> results;

    for (int key = 0; key < 256; ++key) {
        string decoded;
        for (char c : encoded) {
            decoded.push_back(c ^ key);
        }
        results.push_back(decoded);
    }

    return results;


}

// Function to calculate a score based on the frequency of letters in a string
int calculateScore(const string& str) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int score = 0;
    for (char c : str) {
        if (alphabet.find(c) != string::npos) {
            score++;
        }
    }
    return score;
}

int main() {
    // Load the content of the file
    ifstream file("thisfile.txt"); // MAKE SURE thisfile.txt IS IN THE SAME FOLDER AS THE .CPP FILE
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    vector<string> topMessages;  // To store the top N messages
    vector<int> topScores;       // To store the top N scores
    int topN = 10;

    // Processes each line
    for (const string& encodedHex : lines) {
        string encodedAscii = hexToAscii(encodedHex);

        vector<string> decryptedMessages = decryptXOR(encodedAscii);

        for (const string& message : decryptedMessages) {
            int score = calculateScore(message);

            // Stores the top N messages and scores
            if (topMessages.size() < topN) {
                topMessages.push_back(message);
                topScores.push_back(score);
            }
            else {
                // Finds the minimum score in the topScores 
                int minScore = topScores[0];
                int minScoreIndex = 0;
                for (int i = 1; i < topN; ++i) {
                    if (topScores[i] < minScore) {
                        minScore = topScores[i];
                        minScoreIndex = i;
                    }
                }

                // Replaces the lowest score in the top N if a higher score is found
                if (score > minScore) {
                    topMessages[minScoreIndex] = message;
                    topScores[minScoreIndex] = score;
                }
            }
        }
    }

    // Prints the top 10 scores and messages
    cout << "Top " << topN << " Decrypted Messages and Their Scores:" << endl;
    for (int i = 0; i < topN; ++i) {
        cout << "Score: " << topScores[i] << ", Message: " << topMessages[i] << endl;
    }
    cout << "The decrypted message is: 'Now that the party is jumping'." << endl;// I hard coded this after the fact based on the results of the top 10 messages 
    return 0;
}