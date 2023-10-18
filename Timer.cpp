//
// Created by adamc on 19/10/2023.
//


#include "Timer.h"

long long int Timer::readQPC(){
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void Timer::startTimer(){
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    start = readQPC();
}

double Timer::stopTimer(){
    elapsed = readQPC() - start;
    std::cout << "Time [s] = " << std::fixed << std::setprecision(0) << (float)elapsed / frequency << std::endl;
    std::cout << "Time [ms] = " << std::fixed << std::setprecision(0) << (1000.0 * elapsed) / frequency << std::endl;
    std::cout << "Time [us] = " << std::fixed << std::setprecision(0) << (1000000.0 * elapsed) / frequency << std::endl << std::endl;

    double time = (1000000.0 * elapsed) / frequency;
    return time;
}

Timer::Timer() {

}
