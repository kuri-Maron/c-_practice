#include<iostream>
#include<string.h>


class Tire{
private:
int weight;
int size;
public:
Tire():weight(150),size(10){}
explicit Tire(int weight_,int size_): weight(weight_),size(size_){}

void print(){
printf("weight:%d\nsize:%d\n\n",weight,size);
}
int getWeight(){return weight;}
int getSize(){return size;}


};


class Car{
private:
std::string name;
Tire tire;
public:
Car(): name("abc"),tire(30,50) {}

Car(std::string name_,Tire tire_) : name(name_),tire(tire_) {}

Tire getTire(){
return tire;
}

void carPrint(){
    printf("name:%s\ntire:%d,%d\n",name.c_str(),tire.getWeight(),tire.getSize());
}

};




int main(){
    std::cout << "Hello, world" << std::endl;

    Tire tire1;
    Tire tire2(50,5);

    // tire1.print();
    // tire2.print();

    Car car1("XXX",tire2);
    Car car2;

    // car1.getTire().print();
    car1.carPrint();
    car2.carPrint();

}