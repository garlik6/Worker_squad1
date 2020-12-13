//
// Created by Grigory on 12.12.2020.
//

#include"../vector.h"
#include "../Units/Unit.h"
#include "../Units/Master.h"
#include"../Units/Worker.h"
#include "../Fields/Field.h"
#include "../crew/crew.h"
#include "dialog1.h"


int game()
{
    crew::crew crew1(true);// Создаем исходную команду
    while (true)
    {

        while (true)
        {

            int rc;
            while((rc = dialog_1::dialog1()))
                if(dialog_1::fptr[rc](&crew1))
                    break;
            printf("Thanks, the day is to begin");
            break;
        }
        // Проведена подготовка перед рабочим днем
        // Днем происходят следующие события
        //             :---Количество работы на полях уменьшается
        //             :---Добавление Случайного врага и случайного
        //             :---Вывод результатов дня
        //             :---Дальше все повторяется
        crew1.update_workload();
        crew1.show_progress();
        break;
    }


    return 0;
}





