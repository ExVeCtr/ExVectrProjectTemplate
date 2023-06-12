#include <Arduino.h>

#include "ExVectrCore.hpp"

#include "ExVectrArduinoPlatform.hpp"


// Use the EXVECTR namespace. Reduces typing.
using namespace VCTR;


/**
 * @brief Prints "Hello World!" to the serial port every second.
 */
class HelloWorldPrinter : public Core::Task_Periodic {
public:

    HelloWorldPrinter() : Task_Periodic("Hello World Printer task", 1*Core::SECONDS)
    {
        Core::getSystemScheduler().addTask(*this);
    }


    void taskInit() override
    {
        Serial.begin(9600);
    }

    void taskThread() override
    {   

        Core::printM("Hello World!\n");

    }


};


// Create the hello world printer task. Auto adds itself to the scheduler.
HelloWorldPrinter printer;

void setup()
{

    // Initialise the platform implementation.
    VCTR::Core::initialise();

}

void loop()
{

    // Tick the scheduler. Will run all tasks that are due.
    VCTR::Core::getSystemScheduler().tick();

}