#ifndef DINAMIC_LIST_H
#define DINAMIC_LIST_H

#include <type_traits>
#include <stdexcept>
#include<iostream>
#include <cmath>      
#include <typeinfo>
template <class T>
class dinamic_list{
    private:
        T* data;
        int size;
        static void validate(const T& value);
        template <typename> friend class dinamic_list;
            
    public:

        explicit dinamic_list(int tsize);
        ~dinamic_list();
        void print() const;
        void set(int index, const T& value);
        T get(int index) const;
        dinamic_list(const dinamic_list& other);
        void pushBack(const T& value);
        void add(const dinamic_list& other);
        void subtract(const dinamic_list& other);
        template <class U> 
        friend std::ostream& operator<<(std::ostream& os, const dinamic_list<U>& arr);
        template <typename U>
        double distance(const dinamic_list<U>& other);
       
        
};

template <typename T>
dinamic_list<T>::dinamic_list(int tsize) : data(new T[tsize]()), size(tsize) {}

template <typename T>
dinamic_list<T>::~dinamic_list() {
    delete[] data;
}

template <typename T>
void dinamic_list<T>::print() const {
    std::cout << *this << std::endl;
}

template <typename T>
void dinamic_list<T>::set(int index, const T& value) {
    if (index >= size || index < 0 ) {
        throw std::out_of_range("out_of_range");
    }
    validate(value);
    data[index] = value;
    
}

template <typename T>
T dinamic_list<T>::get(int index) const {
    if (index >= size || index < 0 ){
        throw std::out_of_range("out_of_range");
    }
    return data[index];
}

template <typename T>
dinamic_list<T>::dinamic_list(const dinamic_list& other) {
    size = other.size;
    data = new T[size];          
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];    
    }
}

template <typename T>
void dinamic_list<T>::pushBack(const T& value) {
    validate(value);
    T* newdata = new T[size + 1];

    for (int i = 0; i < size; ++i) {
        newdata[i] = data[i];
    }

    newdata[size] = value;

    delete[] data;

    data = newdata;
    size = size + 1;
}


template <typename T>
void dinamic_list<T>::add(const dinamic_list& other) {
    for (int i = 0; i < size; ++i) {
        T otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] = data[i] + otherValue;
    }
}

template <typename T>
void dinamic_list<T>::subtract(const dinamic_list& other) {
    for (int i = 0; i < size; ++i) {
        T otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] = data[i] - otherValue;
    }
};

template <typename T>
void dinamic_list<T>::validate(const T& value){
            if constexpr (std::is_integral_v<T>) {
                if (value > 100 || value < -100) {
                    throw std::invalid_argument("invalid_argument");
                    }
                }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const dinamic_list<T>& arr) {
    os << "[";
    for (int i = 0; i < arr.size; ++i) {
        if (i) os << ", ";
        os << arr.data[i];
    }
    os << "]";
    return os;
}

template <typename T>
template <typename U>
double dinamic_list<T>::distance(const dinamic_list<U>& other) {
    if constexpr (!std::is_arithmetic_v<T> || !std::is_arithmetic_v<U>
              || std::is_same_v<T, bool> || std::is_same_v<U, bool>)
        throw std::bad_typeid();
    else {
        if (size != other.size)
            throw std::invalid_argument(
                "invalid_argument");
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            double diff = static_cast<double>(data[i])
                        - static_cast<double>(other.data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }
}
#endif