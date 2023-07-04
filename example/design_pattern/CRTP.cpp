// CRTP (Curiously Recursing Template Pattern)

#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

// Normal Polymorphism
class Animal {
public:
    Animal() = default;
    virtual void bark() = 0;
};

class Dog : public Animal{
public:
    Dog(){
    }
    void bark(){
        // std::cout << "Dog with normal polymorphism" << std::endl;
    }
};

// CRTP
template <typename T>
class TAnimal {
public:
    TAnimal() = default;
    virtual void Bark(){
        return static_cast<T*>(this)->BarkImpl(); // 중요!!
    }
};

class TDog : public TAnimal<TDog>{ // 상속할 때 실제 type을 추가
public:
    TDog(){
    }
    void BarkImpl(){
    }
};

template<typename T>
void TryBark(TAnimal<T> &animal) {
    animal.Bark();
}

int main(){
    int num_iter = 10000;
    std::shared_ptr<Animal> pointer;
    pointer = std::make_shared<Dog>();

    auto start_ts = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i < num_iter ; i ++){
        pointer->bark();
    }
    auto end_ts = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(end_ts-start_ts).count();
    std::cout << "Elaps time with normal polymorphism: " << elapsed_time_ms << " ms" << std::endl;

    
    Dog dog;
    start_ts = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i < num_iter ; i ++){
        dog.bark();
    }
    end_ts = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(end_ts-start_ts).count();
    std::cout << "Elaps time without polymorphism: " << elapsed_time_ms << " ms" << std::endl;

    TDog tdog;
    start_ts = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i < num_iter ; i ++){
        TryBark(tdog);
    }
    end_ts = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(end_ts-start_ts).count();
    std::cout << "Elaps time with CRTP: " << elapsed_time_ms << " ms" << std::endl;

    return 0;
}
