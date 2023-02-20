#include <thread>

#include "ExVectrCore.hpp"
#include "ExVectrCore/topic.hpp"
#include "ExVectrCore/topic_subscribers.hpp"
#include "ExVectrCore/time_base.hpp"
#include "ExVectrCore/scheduler2.hpp"
#include "ExVectrCore/task_types.hpp"
#include "ExVectrCore/print.hpp"

#include "ExVectrWindowsPlatform.hpp"


class ThreadTest: public VCTR::Core::Task_Periodic {
public:

    int p_ = 0;

    ThreadTest(uint32_t p, const char* name) : VCTR::Core::Task_Periodic(name, 1*VCTR::Core::SECONDS, 0, 0) {
        setPriority(p);
        p_ = p;
        VCTR::Core::getSystemScheduler().addTask(*this);
    }

    void taskInit() override {

    }

    void taskThread() override {

        
        VCTR::Core::printM("Hello from task: %d, at time: %f \n", p_, VCTR::Core::NOWSeconds());

    }

};


ThreadTest test(1, "Test Task 1");
ThreadTest test2(2, "Test Task 2");


int main(int, char**) {

    VCTR::Core::initialise();
    
    while (VCTR::Core::NOW() < 30*VCTR::Core::SECONDS) {

        VCTR::Core::getSystemScheduler().tick();

        int64_t next = VCTR::Core::getSystemScheduler().getNextTaskRelease();

        std::this_thread::sleep_for(std::chrono::nanoseconds(next - VCTR::Core::NOW()));

    }

    VCTR::Core::printM("Runtime: %f \n", VCTR::Core::NOWSeconds());

    return 0;
 
}
