#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string generateAttempt(string charset, int length) {
    string attempt = "";
    for (int i = 0; i < length; i++) attempt += charset[rand() % charset.length()];
    return attempt;
}

void bruteForce(string password) {
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string attempt;
    int attempts = 0;

    clock_t start = clock();
    while (attempt != password) {
        attempt = generateAttempt(charset, password.length());
        attempts++;
    }
    clock_t end = clock();
    
    cout << "Password Cracked: " << attempt << " in " << attempts << " attempts!\n";
    cout << "Time Taken: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
}

int main() {
    string password = "C0d3!";
    cout << "Attempting to brute-force password: " << password << "\n";
    bruteForce(password);
    return 0;
}
