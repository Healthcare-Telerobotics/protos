#include <functional>
#include "sdk.h"
#include "libsdk.h"

using namespace github::com::pyrus::platform::protos;

GoString createGoString(std::string str);

GoSlice createGoSlice(std::vector<int64_t> array);

// TODO: Get the callbacks working without a global instance
Sdk* instance;

Sdk::Sdk(std::string deviceServiceAddress,
	std::string sessionServiceAddress,
	std::string stateManagerServiceAddress,
	uint64_t deviceID,
	uint32_t devicePort,
	std::string deviceIP,
	std::vector<int64_t> produces,
	std::vector<int64_t> consumes,
	OnSession onSessionJoined,
	OnSession onSessionEnded,
	GetFrameCallback getFrameCallback,
	OnFrameCallback onFrameCallback,
	uint64_t sessionID,
	int getFrameIntervalMS
) :
    _deviceServiceAddress(deviceServiceAddress),
    _sessionServiceAddress(sessionServiceAddress),
    _stateManagerServiceAddress(stateManagerServiceAddress),
    _deviceID(deviceID),
    _devicePort(devicePort),
    _deviceIP(deviceIP),
    _produces(produces),
    _consumes(consumes),
    _onSessionJoined(onSessionJoined),
    _onSessionEnded(onSessionEnded),
    _getFrameCallback(getFrameCallback),
    _onFrameCallback(onFrameCallback),
    _sessionID(sessionID),
    _getFrameIntervalMS(getFrameIntervalMS)
{
    instance = this;

    libsdk_initialize(
        createGoString(_deviceServiceAddress),
        createGoString(_sessionServiceAddress),
        createGoString(_stateManagerServiceAddress),
        _deviceID,
        _devicePort,
        createGoString(_deviceIP),
        createGoSlice(_produces),
        createGoSlice(_consumes),
        _onSessionJoined,
        _onSessionEnded,
        Sdk::handleGetFrame,
        Sdk::handleOnFrame,
        _sessionID,
        _getFrameIntervalMS
    );
}

void Sdk::connect() {
    libsdk_connect(_deviceID);
}

bool Sdk::handleGetFrame(unsigned char* bufferPtr, int* sizePtr) {
    Frame* framePtr = instance->_getFrameCallback();
    if (framePtr == nullptr)
        return false;

    *sizePtr = framePtr->ByteSizeLong();
    return framePtr->SerializeToArray(bufferPtr, *sizePtr);
}

bool Sdk::handleOnFrame(unsigned char* bufferPtr, int size) {
    Frame frame;
    frame.ParseFromArray(bufferPtr, size);
    return instance->_onFrameCallback(&frame);
}

GoString createGoString(std::string str) {
    GoString goString;
    goString.p = str.c_str();
    goString.n = str.length();
    return goString;
}

GoSlice createGoSlice(std::vector<int64_t> array) {
    GoSlice goSlice;
    goSlice.data = array.data();
    goSlice.len = goSlice.cap = array.size();
    return goSlice;
}