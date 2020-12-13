




#pragma once
#include "Unit.h"
namespace units {
    /*!
\brief Класс мастер
*/
    class Master : public Unit {
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
\brief инициализирующий конструктор
*/
        explicit Master(int id = 0, int Age = 20,int Work_Count = 5, int busy =-1):Unit(id, Age,busy),Work_Count(Work_Count){};
        /*!
\brief перегруженный оператор присваивания
*/
        Master & operator = (const Master& Master);
        /*!
\brief инициализирующий конструктор
*/
        Master(int id, int Age, my_template::vector<int> Friend_group, my_template::vector<int> Enemy_group,int Work_count, int busy)
                            :Unit(id, Age,Friend_group,Enemy_group,busy), Work_Count(Work_count){};

        Master(const Master &Master);
        /*!
\brief метод клонирования
*/

        Master* clone() const override
        {
            return new Master(*this);
        }
        /*!
\brief метод указывающий вид юнита(здесь 2 - мастер)
*/
        int iAm() const override
        {
            return 2;
        }
        int get_Age() const override
        {
            return Age;
        }
        my_template::vector<int> *get_Enemy_Group()  override
        {
            return &Enemy_group;
        }
        my_template::vector<int> *get_Friend_Group()  override
        {
            return &Friend_group;
        }
        int get_id() const override
        {
            return id;
        }
        void set_id(int id) override
        {
            this->id = id;
        }
        void set_Age(int Age) override
        {
            this->Age = Age;
        }
        void add_Enemy(int Enemy) override
        {
            Enemy_group.push_back(Enemy);
        }
        void add_Friend(int Friend) override
        {
            Friend_group.push_back(Friend);
        }
        void set_Work(int Multiplier) override
        {
            this->Work_Count = Multiplier;
        }
        int get_Work() override{return Work_Count;};
        void set_Busy(int busy) override
        {
            this->busy = busy;
        }
        int get_Busy() override
        {
            return busy;
        }

    };

}
