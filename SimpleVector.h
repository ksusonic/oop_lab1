#include <algorithm>
#include <cstdint>
using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size);
    SimpleVector(const SimpleVector<T> &vector);
//    SimpleVector(const SimpleVector<T> &&vector);
    ~SimpleVector();

    T& operator[](size_t index);
    T& operator[](size_t index) const;

    T* begin();
    T* end();
    T* begin() const;
    T* end() const;

    size_t Size() const;

    void PushBack(T value);

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void ExpandIfNeeded();
};

template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
        : data(new T[size])
        , size(size)
        , capacity(size)
{
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T> &vector) {
    this->data = vector.data;
    this->size = vector.size;
    this->capacity = vector.capacity;
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    std::cout << "~SimpleVector begin\n";
    delete[] data;
    std::cout << "~SimpleVector end\n";
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
T &SimpleVector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const {
    return size;
}

template <typename T>
void SimpleVector<T>::PushBack(T value) {
    ExpandIfNeeded();
    data[size++] = move(value);
}

template <typename T>
void SimpleVector<T>::ExpandIfNeeded() {
    if (size >= capacity) {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        // используем перемещение
        move(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
}

template <typename T>
T* SimpleVector<T>::begin() {
    return data;
}

template <typename T>
T* SimpleVector<T>::end() {
    return data + size;
}

template <typename T>
T* SimpleVector<T>::begin() const {
    return data;
}

template <typename T>
T* SimpleVector<T>::end() const {
    return data + size;
}
