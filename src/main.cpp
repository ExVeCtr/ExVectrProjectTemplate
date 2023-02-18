#include "ExVectrCore/topic.hpp"
#include "ExVectrCore/topic_subscribers.hpp"
#include "ExVectrCore/time_base.hpp"

#include "ExVectrCore/scheduler2.hpp"
#include "ExVectrCore/task_types.hpp"

#include "ExVectrWindowsPlatform.hpp"

#include "ExVectrCore/print.hpp"


class ThreadTest: public VCTR::Core::Task_Periodic {
public:

    int p_ = 0;

    ThreadTest(uint32_t p) : VCTR::Core::Task_Periodic("Scheduler and task test", 1*VCTR::Core::SECONDS, 0, 0) {
        setPriority(p);
        p_ = p;
    }

    void taskInit() override {

    }

    void taskThread() override {

        
        VCTR::Core::printM("Hello from task: %d, at time: %f \n", p_, VCTR::Core::NOWSeconds());

    }

};



int main(int, char**) {

    VCTR::Core::Scheduler& scheduler = VCTR::Core::getSystemScheduler();
    ThreadTest test(1);
    ThreadTest test1(3);
    scheduler.addTask(test);
    scheduler.addTask(test1);

    while (VCTR::Core::NOW() < 30*VCTR::Core::SECONDS) {

        //VCTR::Core::Task_Threading::schedulerTick();
        scheduler.tick();

    }

    VCTR::Core::printM("Runtime: %f \n", VCTR::Core::NOWSeconds());

    return 0;
 
}
