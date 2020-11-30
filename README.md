# Telerobotics SDK
Telerobotics SDK is a C library for realtime communication between devices, algorithms and systems during electrophysiology simulations and procedures.

## Architecture Overview
![image](https://user-images.githubusercontent.com/2764891/99635233-854c5d00-29f6-11eb-9668-57845adb0265.png)

## Usage
The SDK can be integrated into any device, on any platform, in any language. Currently, there are wrappers around the library in C++, Python, C# and NodeJS.

### C++ Example
A simple example demonstrating how to initialize the SDK, send and received data.
```cpp
#include "sdk.h"
#include "common.pb.h"

using namespace std;
using namespace github::com::pyrus::platform::protos;

void onSessionJoined(uint64_t sessionId);
void onSessionEnded(uint64_t sessionId);
bool getFrame(Frame& frame);
bool onFrame(Frame&);

int main() {
    // Initialize the SDK
    Sdk sdk = Sdk("apis.healthcaretelerobotics.com:30000",
        "apis.healthcaretelerobotics.com:30000",
        "apis.healthcaretelerobotics.com:30005",
        8,                                                  // The unique device id
        3000,                                               // The port for communication
        { DataType::CatheterSensorCoordinates },            // The type this device produces
        { DataType::RobotControls },                        // The type this device consumes
        onSessionJoined,                                    // Session joined callback
        onSessionEnded,                                     // Session ended callback
        getFrame,                                           // Get data callback
        onFrame                                             // On data callback
    );

    sdk.connect();
}

// Session joined callback
void onSessionJoined(uint64_t sessionId) {
    cout << "Joined session " << sessionId << endl;
    
}

// Session ended callback
void onSessionEnded(uint64_t sessionId) {
    cout << "Session " << sessionId << " ended" << endl;
}

// Called every frame
// This is where you send data
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

// Called when data is received
bool onFrame(Frame& frame) {
    // cout << "Frame: " << frame.DebugString() << endl;
    return true;
}
```

## Installation
The Telerobotics SDK is in alpha. I plan to have all resources openly available soon. In the meantime, for access to the SDK, services and other resources, please contact Ryan James.