#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>

using namespace std;

void ip_to_binary() {
    string ip;
    vector<int> numbers = {128, 64, 32, 16, 8, 4, 2, 1};

    cout << "Enter the IP address (format: xxx.xxx.xxx.xxx): ";
    cin >> ip;

    stringstream ss(ip);
    vector<int> parts;
    string part;

    // Splitting the IP address by '.'
    while (getline(ss, part, '.')) {
        parts.push_back(stoi(part)); // Convert each part to integer and store
    }

    if (parts.size() != 4) {
        cout << "Invalid IP address format!" << endl;
        return;
    }

    cout << "Binary representation: ";
    for (int i = 0; i < parts.size(); ++i) {
        bitset<8> binary_part(parts[i]); // Convert each part to 8-bit binary
        cout << binary_part;
        if (i != parts.size() - 1) {
            cout << ".";
        }
    }
    cout << endl;
}

void binary_to_ip() {
    string binary;
    cout << "Enter the binary representation (format: xxxxxxxx.xxxxxxxx.xxxxxxxx.xxxxxxxx): ";
    cin >> binary;

    stringstream ss(binary);
    vector<string> parts;
    string part;

    // Splitting the binary string by '.'
    while (getline(ss, part, '.')) {
        parts.push_back(part); // Store each binary part
    }

    if (parts.size() != 4) {
        cout << "Invalid binary format!" << endl;
        return;
    }

    cout << "IP address: ";
    for (int i = 0; i < parts.size(); ++i) {
        bitset<8> bits(parts[i]); // Convert each binary part to decimal
        cout << bits.to_ulong(); // Print the decimal value
        if (i != parts.size() - 1) {
            cout << ".";
        }
    }
    cout << endl;
}

int main() {
    int opt;

    while (true) {
        cout << "Do you want to convert:" << endl;
        cout << "1) IP to BINARY" << endl;
        cout << "2) BINARY to IP" << endl;
        cout << "3) Exit" << endl;
        cin >> opt;

        switch (opt) {
            case 1:
                ip_to_binary();
                break;
            case 2:
                binary_to_ip();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }

    return 0;
}

