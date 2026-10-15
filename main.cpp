#include"dinamic_array.h"
#include<iostream>

int main(){
    setlocale(LC_ALL,"Russian");
    
        std::wcout<<L"===== Создание и вывод ====="<<std::endl;
        dinamic_list a(3), b(3);
        a.set(0, 10); a.set(1, 20); a.set(2, 30);
        b.set(0, 1);  b.set(1, 2);  b.set(2, 3);

        std::cout << "a = "; a.print();  
        std::cout << "b = "; b.print();  

        std::wcout<<L"===== Конструктор копирования ====="<<std::endl;
        dinamic_list a_copy(a); 
        a.set(0, 11); a.set(1, 21); a.set(2, 31);
        std::cout << "a_copy = "; a_copy.print(); 

        std::wcout<<L"===== Добавление элементов ====="<<std::endl;
        std::cout << "a = "; a.print();  
        a.pushBack(100);
        std::cout << "a = "; a.print();

        std::wcout<<L"===== Одинаковые размеры ====="<<std::endl;
        a.add(b);
        std::cout << "a.add(b) -> "; a.print();  

        std::wcout<<L"===== Разные размеры ====="<<std::endl;
        dinamic_list c(5), d(3);
        c.set(0, 10); c.set(1, 20); c.set(2, 30); c.set(3, 40); c.set(4, 50);
        d.set(0, 1);  d.set(1, 2);  d.set(2, 3);

        std::cout << "c = "; c.print();  
        std::cout << "d = "; d.print();    

        c.add(d);
        std::cout << "c.add(d) -> "; c.print();
        

        std::wcout<<L"===== Вычитание ====="<<std::endl;
        dinamic_list e(4), f(2);
        e.set(0, 50); e.set(1, 40); e.set(2, 30); e.set(3, 20);
        f.set(0, 5);  f.set(1, 10);

        std::cout << "e = "; e.print();   
        std::cout << "f = "; f.print();      
        e.subtract(f);
        std::cout << "e.subtract(f) -> "; e.print();
    

    return 0;
}
