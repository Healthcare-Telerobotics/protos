#include <memory>

#include "sdk.h"
#include "common.pb.h"

using namespace std;
using namespace github::com::pyrus::platform::protos;

void onSessionJoined(uint64_t sessionId);
void onSessionEnded(uint64_t sessionId);
unique_ptr<Frame> getFrame();
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
    cout << "Joined session" << sessionId << endl;
}

void onSessionEnded(uint64_t sessionId) {
    cout << "Session" << sessionId << "ended" << endl;
}

unique_ptr<Frame> getFrame() {
    return nullptr;
}

bool onFrame(Frame& frame) {
    return false;
}