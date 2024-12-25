#include <iostream>
#include <string>

using namespace std;

class MyString {
    char* arr;
    int Capacity;
public:
    MyString() {
        this->arr = new char[1];
        this->arr[0] = '\0';
        this->Capacity = 1;
    }

    MyString(const char* arr) {
        int amount = 0;
        while (arr[amount] != '\0') {
            amount++;
        }
        this->Capacity = amount + 1;
        this->arr = new char[this->Capacity];
        for (int i = 0; i < this->Capacity; i++) {
            this->arr[i] = arr[i];
        }
    }

    MyString(const MyString& other) {
        this->Capacity = other.Capacity;
        this->arr = new char[this->Capacity];
        for (int i = 0; i < this->Capacity; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    void append(char symbol) {
        int amount = size();
        char* tempArr = new char[amount + 2];
        for (int i = 0; i < amount; i++) {
            tempArr[i] = this->arr[i];
        }
        tempArr[amount] = symbol;
        tempArr[amount + 1] = '\0';
        delete[] this->arr;
        this->arr = tempArr;
        this->Capacity = amount + 2;
    }

    int size() const {
        int amount = 0;
        while (this->arr[amount] != '\0') {
            amount++;
        }
        return amount;
    }

    int capacity() const {
        return this->Capacity;
    }

    bool compare(MyString& other) {
        if (size() > other.size()) {
            return true;
        }
        else {
            false;
        }
    }

    void clear() {
        delete[] this->arr;
        this->arr = new char[1];
        this->arr[0] = '\0';
        this->Capacity = 1;
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        delete[] this->arr;
        this->Capacity = other.Capacity;
        this->arr = new char[this->Capacity];
        for (int i = 0; i < this->Capacity; i++) {
            this->arr[i] = other.arr[i];
        }
        return *this;
    }

    char& operator[](int index) {
        if (index < 0 || index >= size()) throw out_of_range("Index out of bounds");
        return this->arr[index];
    }

    friend ostream& operator<<(ostream& os, const MyString& str) {
        os << str.arr;
        return os;
    }

    void push_back(char symbol) {
        int amount = size();
        char* tempArr = new char[amount + 2];
        tempArr[0] = symbol;
        for (int i = 0; i < amount; i++) {
            tempArr[i + 1] = this->arr[i];
        }
        tempArr[amount + 1] = '\0';
        delete[] this->arr;
        this->arr = tempArr;
        this->Capacity = amount + 2;
    }

    void pop_back() {
        int amount = size();
        if (amount == 0) return;
        char* tempArr = new char[amount];
        for (int i = 0; i < amount - 1; i++) {
            tempArr[i] = this->arr[i];
        }
        tempArr[amount - 1] = '\0';
        delete[] this->arr;
        this->arr = tempArr;
        this->Capacity = amount;
    }

    int length() const {
        return size();
    }

    MyString copy() const {
        return MyString(*this);
    }

    int find(const char* substring) {
        int subLength = 0;
        while (substring[subLength] != '\0') {
            subLength++;
        }

        for (int i = 0; i <= size() - subLength; i++) {
            int j = 0;
            while (j < subLength && this->arr[i + j] == substring[j]) {
                j++;
            }
            if (j == subLength) return i;
        }
        return -1;
    }

    void insert(int index, const char* substring) {
        if (index < 0 || index > size()) {
            cout << ("Index out of bounds");
            exit(EXIT_FAILURE);
        }
        int subLength = 0;
        while (substring[subLength] != '\0') {
            subLength++;
        }

        int newSize = size() + subLength;
        char* tempArr = new char[newSize + 1];

        for (int i = 0; i < index; i++) {
            tempArr[i] = this->arr[i];
        }
        for (int i = 0; i < subLength; i++) {
            tempArr[index + i] = substring[i];
        }
        for (int i = index; i < size(); i++) {
            tempArr[subLength + i] = this->arr[i];
        }

        tempArr[newSize] = '\0';
        delete[] this->arr;
        this->arr = tempArr;
        this->Capacity = newSize + 1;
    }

    ~MyString() {
        delete[] this->arr;
    }
};

int main() {
    MyString str = "Lizar";
    cout << str << endl;
    str.append('H');
    cout << str << endl;
    str.push_back('K');
    cout << str << endl;
    str.pop_back();
    cout << str << endl;
    cout << str.size() << endl;
    cout << str.capacity() << endl;

    MyString str2 = str.copy();
    cout << str2 << endl;

    cout << str.find("za") << endl;

    str.insert(4, "Lol");
    cout << str << endl;

    str.clear();
    cout << str << endl;

    return 0;
}