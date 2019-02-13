/**
*参照渡しの検証。集約候補
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
Tire& tire;      //参照変数を定義した場合、引数なしコンストラクタは宣言できない（参照を初期化しなければならないから）
public:
// Car(): name("XXX"),tire(0,'S') {}
// Car(): name("XXX"),tire(0,'A') {}
// Car(std::string name_,Tire tire_) : name(name_),tire(tire_) {}

Car(Tire& tire_) : name("XXX"),tire(tire_) {}

Tire getTire(){
return tire;
}

void carPrint(){
    printf("CarInfometion:\nname:%s\ntire:%d,%c\n",name.c_str(),tire.getWeight(),tire.getSize());
}

};




int main(){
    // std::cout << "Hello, world" << std::endl;


    Tire tire2(50,'M');

    // Car car2;  //ノーマル生成！
    // Car car1("car1",tire2);
    Car Refercar3(tire2);

    // car1.carPrint();
    Refercar3.carPrint();
    
   //tire2のサイズを変更するよ！
   tire2.setSize('L');
   tire2.print(); 

    // car1.carPrint();
    Refercar3.carPrint();

}

