//
// Created by kralizekmd on 09.01.2018
//

#include "gates/delay.h"

namespace Logicon {
    Delay::Delay(ID id) : Gate(GATE_TYPE::DELAY, id), delay(1) {
        signals.push_back(0);
    }

    void Delay::update() {
        if (delay == 0) setOutputState(0, getInputState(0));
        else{
            setOutputState(0, signals.back());
            signals.pop_back();
            signals.push_front(getInputState(0));
        }
    }

    void Delay::setDelay(Tick delay) {
        this->delay=delay;
        this->signals.resize(delay,0);
    }

    const std::list<State> & Delay::getDelayList() const {
        return this->signals;
    }

    Tick Delay::getDelay() {
        return this->delay;
    }

    void Delay::setDelayList(const std::list<State> &delayList) {
        this->signals = delayList;
    }
} // namespace Logicon