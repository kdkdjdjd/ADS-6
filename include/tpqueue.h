// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <utility>
#include <algorithm>

template<typename T, int size>
class TPQueue {
 private:
    T * arr;
    int head;
    int count = 0;

 public:
    TPQueue() {
        arr = new T[size + 1];
        head = -1;
    }
    void push(T value) {
        if (head == -1) {
            arr[++head] = value;
        } else if (head == 0) {
            if (arr[head].prior < value.prior) {
                arr[++head] = value;
            } else {
                arr[++head] = value;
                std::swap(arr[0], arr[head]);
            }
        } else {
            count += 1;
            arr[++head] = value;
            for (int i = 0; i < count + 1; ++i) {
                for (int j = 0; j < count + 1; ++j) {
                    if (arr[j].prior > arr[j + 1].prior) {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
    T pop() {
        count -= 1;
        return arr[head--];
    }
    ~TPQueue() {
        delete[] arr;
    }
};
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
