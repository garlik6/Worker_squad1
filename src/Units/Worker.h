//
// Created by Grigory on 11.12.2020.
//

#ifndef UNTITLED6_WORKER_H
#define UNTITLED6_WORKER_H
#include "Unit.h"
namespace units {
    class Worker : public Unit {
    private:
        int Work_Count;
        std::ostream& show(std::ostream&)const override;
        std::istream& get(std::istream&) override;
    public:
        explicit Worker(int id = 0, int Age = 20):Unit(id, Age), Work_Count(5){};
        Worker* clone() const override
        {
            return new Worker(*this);
        }
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
        void set_Work(int addition) override
        {
            this->Work_Count = addition;
        }
    };
}
#endif //UNTITLED6_MASTER_H
