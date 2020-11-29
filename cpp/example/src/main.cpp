#include <memory>

#include "sdk.h"
#include "common.pb.h"

using namespace std;
using namespace github::com::pyrus::platform::protos;

void onSessionJoined(uint64_t sessionId);
void onSessionEnded(uint64_t sessionId);
bool getFrame(Frame& frame);
bool onFrame(Frame&);

int main() {
    Sdk sdk = Sdk("healthcaretelerobotics.com/devices",
        "healthcaretelerobotics.com/sessions",
        "healthcaretelerobotics.com/state",
        1,
        3000,
        { DataType::CatheterSensorCoordinates },
        { DataType::ElectricalSignals },
        onSessionJoined,
        onSessionEnded,
        getFrame,
        onFrame
    );

    sdk.connect();
}

void onSessionJoined(uint64_t sessionId) {
    cout << "Joined session " << sessionId << endl;
}

void onSessionEnded(uint64_t sessionId) {
    cout << "Session " << sessionId << " ended" << endl;
}

bool getFrame(Frame& frame) {
    CatheterData* catheterData = frame.add_catheterdata();
    catheterData->set_sensorid(0);
    CatheterCoordinates coordinates = catheterData->coordinates();
    
    Coordinates position = coordinates.position();
    position.set_x(1);
    position.set_y(2);
    position.set_z(3);

    Quaternion rotation = coordinates.rotation();
    rotation.set_x(1);
    rotation.set_y(2);
    rotation.set_z(3);
    rotation.set_w(1);

    return true;
}

bool onFrame(Frame& frame) {
    cout << "Frame: " << frame.DebugString() << endl;
    return true;
}