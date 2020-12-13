//
// Created by Grigory on 11.12.2020.
//
#pragma once
#include "Unit.h"
#include "Master.h"
namespace units {
    /*!
\brief Класс рабочий наследование от абстрактного класса Юнит
*/
    class Worker : public Unit {
    private:
        int Work_Count;
        /*!
\brief метод для реализации вывода через перегруженный оператор ввода в базовом абстрактном классе
*/
        std::ostream& show(std::ostream&)const override;
        /*!
\brief метод для реализации вввода через перегруженный оператор ввода в базовом абстрактном классе
*/
        std::istream& get(std::istream&) override;
    public:
        /*!
\brief перегруженный оператор присваивания
*/
        Worker & operator = (const Worker& Worker);
        /*!
\brief инициализирующий конструктор
*/
        explicit Worker(int id = 0, int Age = 20,int Work_Count = 7, int busy = -1):Unit(id, Age,busy),Work_Count(Work_Count){};
        /*!
\brief инициализирующий конструктор
*/
        Worker(int id , int Age, my_template::vector<int> Friend_group, my_template::vector<int> Enemy_group,int Work_Count,int busy):Unit(id, Age, Friend_group,Enemy_group,busy), Work_Count(Work_Count){};
        /*!
\brief функция прокачки мастера до рабочего
*/
        Master upgrade();
        /*!
\brief метод клонирования
*/
        Worker* clone() const override{return new Worker(*this);}
        /*!
\brief метод указывающий вид юнита(здесь 1 - рабочий)
*/
        int iAm() const override{return 2;}

        Worker(const Worker &Worker);

        int get_Age() const override{return Age;}
        my_template::vector<int> *get_Enemy_Group()  override{return &Enemy_group;}
        my_template::vector<int> *get_Friend_Group()  override{return &Friend_group;}
        int get_id() const override{return id;}
        void set_id(int id) override{this->id = id;}
        void set_Age(int Age) override{this->Age = Age;}
        void add_Enemy(int Enemy) override{Enemy_group.push_back(Enemy);}
        void add_Friend(int Friend) override{Friend_group.push_back(Friend);}
        void set_Work(int addition) override{this->Work_Count = addition;}
        int get_Work() override{return Work_Count;};
        void set_Busy(int busy) override{this->busy = busy;}
        int get_Busy() override{return busy;}
        ~Worker() override{Friend_group.clear(); Enemy_group.clear();};
    };
}

