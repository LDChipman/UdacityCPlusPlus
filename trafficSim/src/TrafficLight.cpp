#include <iostream>
#include <random>
#include <thread>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */
 
template <typename T>
T MessageQueue<T>::receive()
{
    std::unique_lock<std::mutex> lock(_mutex);
    _condition.wait(lock);
    T msg = _queue.front();
    _queue.pop_front();
    return std::move(msg);
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _queue.clear();
    _queue.emplace_back(msg);
    _condition.notify_one();

}

/* Implementation of class "TrafficLight" */

TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (_messageQueue.receive() == green){
            return;
        }
        
    }
    
}

TrafficLight::TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate(){
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}


// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases(){
    std::chrono::time_point<std::chrono::system_clock> lastUpdate;
    int cycleDuration = ((rand()%3)+4)*1000;

    lastUpdate = std::chrono::system_clock::now();
    while (true) {

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        long timeSinceLastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - lastUpdate).count();
        if (timeSinceLastUpdate >= cycleDuration){

            //Switches between green and red
            switch (_currentPhase){
            case red:
                _currentPhase = green;
                break;
            
            case green:
                _currentPhase = red;
                break;
            }

            // Sends the current phase to the queue
            _messageQueue.send(std::move(_currentPhase));

            lastUpdate = std::chrono::system_clock::now();
        }
    }
}