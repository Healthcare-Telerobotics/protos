# Telerobotics SDK
Telerobotics SDK is a C library for realtime communication between devices, algorithms and systems during electrophysiology simulations and procedures.

## Architecture Overview
![image](https://user-images.githubusercontent.com/2764891/99635233-854c5d00-29f6-11eb-9668-57845adb0265.png)

## Usage
The SDK can be integrated into any device, on any platform, in any language. Currently, there are wrappers around the library in Python, C# and NodeJS.

### Python Example
A simple example demonstrating how to initialize the SDK, send and received data.
```python
# Imports the telerobotics SDK
from telerobotics import Sdk

# Imports the telerobotics protobufs used later in the file
# These types are defined in protos/common.proto
from telerobotics_protos.common_pb2 import DataType, Frame, CatheterData, CatheterCoordinates, CatheterSensorCoordinates, Coordinates, Quaternion

# This callback is fired when
# a telerobotic simulation/procedure begins
def on_session_joined(session_id):
    print("Joined session", session_id)

# This callback is fired when
# a telerobotic simulation/procedure ends
def on_session_ended(session_id):
    print("Ssession", session_id, "ended")

# This callback is fired every frame.
# This is how you send data to remote devices.
# This example callback sends dummy catheter data.
# Other data types can be found in protos/common.proto
def get_frame_callback():
    frame = Frame()
    frame.catheterData.append(
        CatheterData(
            sensorId=0,
            coordinates= CatheterCoordinates(
                position=Coordinates(
                    x=0,
                    y=1,
                    z=2,
                ),
                rotation=Quaternion(
                    x=0,
                    y=1,
                    z=2,
                    w=1,
                ),
            ),
        )
    )
    
    return frame

# This callback is fired when the telerobotic
# simulation/procedure receives data. Data is
# encapsulted in the Frame message type defined
# in protos/common.proto
def on_frame_callback(frame):
    print(frame.electricalSignals)
    return True

# Defines the type of data this program produces and consumes
produces = (DataType.CatheterSensorCoordinates)
consumes = (DataType.ElectricalSignals)

# Initialize the SDK
sdk = Sdk(
    on_session_joined=on_session_joined,                                    # Called when a simulation/procedure begins
    on_session_ended=on_session_ended,                                      # Called when a simulation/procedure ends
    get_frame_callback=get_frame_callback,                                  # Called to get data every frame (see get_frame_freq below)
    on_frame_callback=on_frame_callback,                                    # Called when data is received
    produces=produces,                                                      # Defines the types of data this program produces, if any
    consumes=consumes,                                                      # Defines the types od data this program consumes, if any
    device_service_address="https://apis.telerobotics.com/devices",         # URL to the device service
    session_service_address="https://apis.telerobotics.com/sessions",       # URL to the session service
    state_manager_service_address="https://apis.telerobotics.com/states",   # URL to the state manager service
    device_id=1,                                                            # The unique id of this device/program
    device_port=3000,                                                       # The port this program will use to communicate with other devices
    get_frame_freq=30,                                                      # The frequency in milliseconds data is retrieved from this device
)

# Asynchronously connect to the telerobotic platform.
# When a session starts, the callbacks will start firing.
sdk.connect_async()
```

## Installation
The Telerobotics SDK is in alpha. For access to the SDK, services and other resources, please contact Ryan James.