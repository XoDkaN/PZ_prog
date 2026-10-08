#include<iostream>
#include"dinamic_array.h"

dinamic_list::dinamic_list(int tsize) : date(new int[tsize]()), size(tsize) {}

dinamic_list::~dinamic_list() {
    delete[] date;
}

void dinamic_list::print(){
    std::cout<<"[";
    for (int i = 0; i < size -1 ; i++){
        std::cout<< date[i]<< ", ";
    }
    std::cout<<date[size-1]<<"]"<<std::endl;
};

void dinamic_list::set(int index, int value) {
    if ((value >= -100 && value <= 100) && (index < size && index >= 0 )) {
        date[index] = value;
    }
}
int dinamic_list::get(int index) const {
    if (index < size && index >= 0 ){
        return date[index];
    }
}

dinamic_list::dinamic_list(const dinamic_list& other) {
    size = other.size;
    date = new int[size];          
    for (int i = 0; i < size; ++i) {
        date[i] = other.date[i];    
    }
}
void dinamic_list::pushBack(int value) {
    if (value >= -100 && value <= 100) {
        

    int* newDate = new int[size + 1];

    for (int i = 0; i < size; ++i) {
        newDate[i] = date[i];
    }

    newDate[size] = value;

    delete[] date;

    date = newDate;
    size = size + 1;
}
}
void dinamic_list::add(const dinamic_list& other) {
    for (int i = 0; i < size; ++i) {
        int otherValue = (i < other.size) ? other.date[i] : 0;
        date[i] = date[i] + otherValue;
}
}
void dinamic_list::subtract(const dinamic_list& other) {
    for (int i = 0; i < size; ++i) {
        int otherValue = (i < other.size) ? other.date[i] : 0;
        date[i] = date[i] - otherValue;
}


};