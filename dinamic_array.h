#ifndef DINAMIC_LIST_H
#define DINAMIC_LIST_H

class dinamic_list{
    private:
        int* date;
        int size;
    public:

        explicit dinamic_list(int tsize);
        ~dinamic_list();
        void print();
        void set(int index, int value);
        int get(int index) const;
        dinamic_list(const dinamic_list& other);
        void pushBack(int value);
        void add(const dinamic_list& other);
        void subtract(const dinamic_list& other);
};
#endif