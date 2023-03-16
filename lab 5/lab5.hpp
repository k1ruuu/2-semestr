#pragma once
#include <iostream>
using namespace std;


class BoolVector {
private:

    size_t size_ = 0;
    size_t capacity_ = 1;
    bool* vec = nullptr;

public:

    BoolVector() = default;

    BoolVector(bool value) {
        if (capacity_ == size_) {
            capacity_ *= 2;
        }
        vec = new bool[capacity_];
        for (int i = 0; i < capacity_; i++) {
            vec[i] = value;
            size_++;
        }
    }

    bool& operator[](int index) {
        return vec[index];
    }

    size_t size() {
        return size_;
    }


    void push_back(bool value) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            bool* new_vec = new bool[capacity_];
            for (int i = 0; i < size_; i++) {
                new_vec[i] = vec[i];
            }
            delete[] vec;
            vec = new_vec;
        }
        vec[size_] = value;
        ++size_;
    }

    bool& at(int index) {
        if (index > size_) {
            throw out_of_range("index out of range");
        }
        return vec[index];
    }

    void insert(int index, bool value) {
        if (index > size_) {
            throw out_of_range("index out of range");
        }
        if (size_ == capacity_) {
            capacity_ *= 2;
            bool* new_vec = new bool[capacity_];
            for (int i = 0; i < index; i++) {
                new_vec[i] = vec[i];
            }
            new_vec[index] = value;
            for (int i = index + 1; i < size_ + 1; i++) {
                new_vec[i] = vec[i - 1];
            }
            delete[] vec;
            vec = new_vec;
            ++size_;
        }
        else {
            for (int i = size_; i > index; i--) {
                vec[i] = vec[i - 1];
            }
            vec[index] = value;
            ++size_;
        }
    }

    void erase(int index) {
        if (index > size_) {
            throw out_of_range("index out of range");
        }
        for (int i = index; i < size_ - 1; i++) {
            vec[i] = vec[i + 1];
        }
        --size_;
    }

    ~BoolVector() {}
};
void ifprint(BoolVector& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == false) {
            cout << "vashe ne true" << endl;
        }
        if (vec[i] == true)
            cout << "true" << endl;
        cout << sizeof(vec[i]) << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}