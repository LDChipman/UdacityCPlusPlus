#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"

// forward declarations to avoid include cycle
class Vehicle;

template <class T>
class MessageQueue  {
public:
    void send(T &&msg);
    T receive();
    std::deque<T> _queue;

private:
    std::condition_variable _condition;
    std::mutex _mutex;
};

class TrafficLight : public TrafficObject
{
public:
    enum TrafficLightPhase {red, green};
    // constructor / destructor
    TrafficLight();

    // getters / setters

    // typical behaviour methods
    void waitForGreen();
    void simulate();
    TrafficLightPhase getCurrentPhase();

private:
    // typical behaviour methods
    void cycleThroughPhases();
    TrafficLightPhase _currentPhase;
    MessageQueue<TrafficLightPhase> _messageQueue;
};

#endif