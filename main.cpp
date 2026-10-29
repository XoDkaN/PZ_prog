#include"dinamic_array.h"
#include<iostream>
#include <windows.h>

int main(){
    SetConsoleOutputCP(65001); 
    try {
        std::cout<<"===== Создание и вывод =====\n";
        dinamic_list<int> a(3), b(3);
        a.set(0, 10); a.set(1, 20); a.set(2, 30);
        b.set(0, 1);  b.set(1, 2);  b.set(2, 3);

        std::cout << "a = "; a.print();  
        std::cout << "b = "; b.print();  

        std::cout<<"===== Конструктор копирования =====\n";
        dinamic_list a_copy(a); 
        a.set(0, 11); a.set(1, 21); a.set(2, 31);
        std::cout << "a_copy = "; a_copy.print(); 

        std::cout<<"===== Добавление элементов =====\n";
        std::cout << "a = "; a.print();  
        a.pushBack(100);
        std::cout << "a = "; a.print();

        std::cout<<"===== Одинаковые размеры =====\n";
        std::cout << "a_copy = "; a_copy.print();
        std::cout << "b = "; b.print();
        a_copy.add(b);
        std::cout << "a_copy.add(b) -> "; a_copy.print();  

        std::cout<<"===== Разные размеры =====\n";
        dinamic_list<int> c(5), d(3);
        c.set(0, 10); c.set(1, 20); c.set(2, 30); c.set(3, 40); c.set(4, 50);
        d.set(0, 1);  d.set(1, 2);  d.set(2, 3);

        std::cout << "c = "; c.print();  
        std::cout << "d = "; d.print();    

        c.add(d);
        std::cout << "c.add(d) -> "; c.print();
        

        std::cout<<"===== Вычитание =====\n";
        dinamic_list<int> e(4), f(2);
        e.set(0, 50); e.set(1, 40); e.set(2, 30); e.set(3, 20);
        f.set(0, 5);  f.set(1, 10);

        std::cout << "e = "; e.print();   
        std::cout << "f = "; f.print();      
        e.subtract(f);
        std::cout << "e.subtract(f) -> "; e.print();

        std::cout<<"===== Исключения =====\n";
        try {
            a.set(5, 10);
        }
        catch (const std::out_of_range& e) {
        std::cout << "a.set(5, 10): " << e.what() << "\n";}

        try {
            a.set(0, 500);
        }
        catch (const std::invalid_argument& e) {
        std::cout << "a.set(0, 500): " << e.what() << "\n";}

        try {
            throw std::bad_alloc();
        } 
        catch (const std::bad_alloc& e) {
        std::cout << "Caught bad_alloc: " << e.what() << "\n";
        }

        std::cout<<"===== Расстояние =====\n";
        dinamic_list<int> g(4);
        dinamic_list<double> h(4);
        g.set(0, 1); g.set(1, 4); g.set(2, 6); g.set(3, 2);
        h.set(0, 5.1); h.set(1, 2.7); h.set(2, 3.3); h.set(3, 1.4);
        std::cout << "g = "; g.print(); 
        std::cout << "h = "; h.print();
        std::cout<< "Расстояние g и h : " << h.distance(g) << "\n";
        dinamic_list<bool> k(4);
        k.set(0, true); k.set(1, false); k.set(2, true); k.set(3, false);
        std::cout << "k = "; k.print();
        try {
            std::cout << "Расстояние h и k: " << h.distance(k) << "\n";
            } catch (const std::bad_typeid& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            }
        std::cout << "f = "; f.print(); 
        try {
            std::cout << "Расстояние h и f: " << h.distance(f) << "\n";
            } catch (const std::bad_typeid& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            }
    }
    catch (const std::exception& e) {
    std::cout << "Ошибка : " << e.what() << "\n";
    }
    return 0;
}