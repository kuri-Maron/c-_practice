/**
 * 
 * 生存期間の確認 コンポジションの場合（ノーマル変数の場合）
 * 
 */


#include<iostream>
#include<string.h>


class Tire{
private:
int weight;
char size;
public:
Tire():weight(150),size('L'){}
explicit Tire(int weight_,char size_): weight(weight_),size(size_){}

void print(){
printf("TireInfometion:\nweight:%d\nsize:%c\n\n",weight,size);
}
int getWeight(){return weight;}
int getSize(){return size;}

void setSize(char size){
    this->size=size;
}

};


class Car{
private:
std::string name;
Tire tire;      //参照変数を定義した場合、引数なしコンストラクタは宣言できない（参照を初期化しなければならないから）
public:
// Car(): name("XXX"),tire(0,'S') {}
// Car(): name("XXX"),tire(0,'A') {}
// Car(std::string name_,Tire tire_) : name(name_),tire(tire_) {}

Car(Tire& tire_) : name("XXX"),tire(tire_) {}

Tire& getTire(){
return tire;
}

void carPrint(){
    printf("CarInfometion:\nname:%s\ntire:%d,%c\n",name.c_str(),tire.getWeight(),tire.getSize());
}

};


void funcWorld1(Tire& tire){
    std::cout << "Hello, world___1" << std::endl;

Car Refercar(tire);
Refercar.carPrint();

tire.setSize('L');

Refercar.carPrint();

Refercar.getTire().setSize('G');
Refercar.carPrint();

//この関数のスコープを抜けたら、このクルマのタイヤは死ぬ
}

void funcWorld2(Tire tire){
     std::cout << "Hello, world___2" << std::endl;

Car Refercar(tire);
Refercar.carPrint();

tire.setSize('Z');

Refercar.carPrint();


//しかし、この関数のスコープを抜けると、Refercarと共にサイズZのtireも消える。
}

int main(){
  
Tire tire(50,'M');

Car OrijinalCar(tire);
OrijinalCar.getTire().setSize('O');
OrijinalCar.carPrint();

  funcWorld1(tire);

tire.print();

// funcWorld2(tire);
// //ワールド2のスコープが終わった後に、サイズがZのタイヤは存在しないやろ？？

// tire.print();

}