# Crytopals Challenges Set 1
 
This repository contains the code for Set 1 of the Cryptopal Challenges. The goal of the project is to learn about cryptography and cryptosystems by completing these challenges.

 -  ## Project Structure Challenge 1
 - Put a breakdown of your files here Follow Tenetra's example (challenge 7)
   
 -  ## Project Structure Challenge 2
 - Put a breakdown of your files here Follow Tenetra's example (challenge 7)
   
 -  ## Project Structure Challenge 3
 - 'Cryptopals_Challenge3.2.cpp': Contains the main code for Challenge 3
   
 -  ## Project Structure Challenge 4
 - 'Cryptopals_Challenge4.cpp': Contains the main code for Challenge 4
 - 'thisfile.txt': Text file from the Cryptopals Challenge 4 website. (the direct link to the file is: https://cryptopals.com/static/challenge-data/4.txt)
   
 -  ## Project Structure Challenge 5
 - 'Challenge6.cpp': Contains the full code for challenge 6
 - '6.txt': Contains the text file need for decryption
   
 -  ## Project Structure Challenge 6
 - Put a breakdown of your files here Follow Tenetra's example (challenge 7)
   
 -  ## Project Structure Challenge 7
 - 'crypto.cpp': Contains the main code for Challenge 7
 - 'Crytopals.h': Header file with utility functions.
 - 'ch7.txt': Text file with Base64-encoded content encrypted via AES-128 in ECB mode.
   
 -  ## Project Structure Challenge 8
 - Put a breakdown of your files here Follow Tenetra's example (challenge 7)
 

## Getting Started

### Prerequisites for Challenge 7

To run this project, you will need OpenSSL library. You can install it using your system's package manager or by following the instructions on the [OpenSSL website](https://www.openssl.org/source/) or via YouTube link https://www.youtube.com/watch?v=PMHEoBkxYaQ.

### Running the Challenge 7 Project

1. Clone the repository
   'git clone https://github.com/wtenetra/Cryptopals-Challenges-Set-1-Group-5.git'
   
2. Save the "ch7.txt" text file in the same folder as the project. Use this code to open the text file for decrypting.
   'ifstream infile'
	  'infile.open("**ch7.txt**")'
	  'getline(infile, message, '\0')'
   ' infile.close()
   
3. Include this to use AES header from OpenSSL library
   '#include <openssl/aes.h>'
  - Use these functions in the header:
    - Cryptopals():  constructor
    - string b64_to_ascii(string str):  Base64 decoder to convert to its respective values
    -	string b64_encode(string str):  Base64 encoder
      
4. If you encounter a warning related to OpenSSL, you can disable it using the followign line in your code.
   '#pragma warning(disable : 4996)'

5.  This sets the decrypt key using the key YELLOW SUBMARINE
	  'AES_set_decrypt_key((const unsigned char*)key.c_str(), bitMode, &decryptKey)'

 ## Contributing
   Coding language used is C++. This project is for a group of collaborators from USM CSC414 Group 5, and contributions from the public are not allowed. If you are a member of Group 5 and want to contribute, follow these steps:
   1. Fork the repository to your own GitHub account.
   2. Clone your fork to your local machine.
   3. Create a new branch for your challenge.
   4. Make your changes and commit them with a descriptive message.
   5. Push your branch to your GitHub fork.
   6. Create a pull request to the original project repository, describing your changes
   7. Project maintainers will review your pull request and merge it.
   
 

 ## Acknowledgements
 Tigest Boutwell, Jacob Hall, Adrian Jackson, Daniel Schroeder, Chase Smith, and Tenetra Walton
 








