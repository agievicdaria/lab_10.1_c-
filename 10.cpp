#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool openFile(const string& filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл: " << filePath << endl;
        return false;
    }

    return true;
}

bool searchForPair(ifstream& file) {
    char prevChar = '\0', currentChar;
    bool foundPair = false;

    while (file.get(currentChar)) {
        if ((prevChar == 'n' && currentChar == 'o') ||
            (prevChar == 'o' && currentChar == 'n')) {
            foundPair = true;
            break;
        }

        prevChar = currentChar;
    }

    return foundPair;
}

bool isThereOnOrNo(const string& filePath) {
    if (!openFile(filePath)) {
        return false;
    }

    ifstream file(filePath);
    bool foundPair = searchForPair(file);
    file.close();

    if (foundPair) {
        cout << "У файлі є пара сусідніх букв 'no' або 'on'." << endl;
    } else {
        cout << "У файлі немає пари сусідніх букв 'no' або 'on'." << endl;
    }

    return foundPair;
}

int main() {
    string filePath = "t.txt";
    isThereOnOrNo(filePath);

    return 0;
}
