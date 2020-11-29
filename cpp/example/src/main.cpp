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
    Sdk sdk = Sdk("apis.healthcaretelerobotics.com:30000",
        "apis.healthcaretelerobotics.com:30000",
        "apis.healthcaretelerobotics.com:30005",
        8,
        3000,
        { DataType::CatheterSensorCoordinates },
        { DataType::RobotControls },
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
    catheterData->set_sensorid(1);
    CatheterCoordinates* coordinates = new CatheterCoordinates();
    catheterData->set_allocated_coordinates(coordinates);
    
    Coordinates* position = new Coordinates();
    coordinates->set_allocated_position(position);
    position->set_x(0.01);
    position->set_y(0.02);
    position->set_z(0.03);

    Quaternion* rotation = new Quaternion();
    coordinates->set_allocated_rotation(rotation);
    rotation->set_x(0.01);
    rotation->set_y(0.02);
    rotation->set_z(0.03);
    rotation->set_w(1);

    // cout << "Frame: " << frame.DebugString() << endl;

    return true;
}

bool onFrame(Frame& frame) {
    // cout << "Frame: " << frame.DebugString() << endl;
    return true;
}