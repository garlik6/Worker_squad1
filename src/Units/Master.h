




#ifndef UNTITLED6_WORKER_H
#define UNTITLED6_WORKER_H
#include "Unit.h"
namespace units {

    class Master : public Unit {
    private:
        int Work_Count;
        std::ostream& show(std::ostream&)const override;
        std::istream& get(std::istream&) override;
    public:
        explicit Master(int id = 0, int Age = 20):Unit(id, Age), Work_Count(2){};
        Master* clone() const override
        {
            return new Master(*this);
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
        void set_Work(int Multiplier) override
        {
            this->Work_Count = Multiplier;
        }

    };

}
#endif //UNTITLED6_MASTER_H
