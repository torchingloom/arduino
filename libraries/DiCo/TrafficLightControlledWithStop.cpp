#include "TrafficLightControlledWithStop.h"
#include "Arduino.h"

TrafficLightControlledWithStop::TrafficLightControlledWithStop(int r, int y, int g, int d, RailSwitch* rs):
TrafficLightControlled(r, y, g, d), rail_switch(rs)
{
}

void TrafficLightControlledWithStop::setup()
{
    TrafficLightControlled::setup();
    rail_switch->setup();
}

void TrafficLightControlledWithStop::onStateChange(int _state)
{
    switch (stateGet()) {
        case YELLOW:
            rail_switch->left();
            break;
        case GREEN:
            rail_switch->right();
            break;
    }
}
