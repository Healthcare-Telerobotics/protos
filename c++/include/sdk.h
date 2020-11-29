#include <string>
#include <vector>

#include "callbacks.h"

class SDK {
public:
    SDK(std::string deviceServiceAddress,
	std::string sessionServiceAddress,
	std::string stateManagerServiceAddress,
	uint64_t deviceID,
	uint32_t devicePort,
	std::string deviceIP,
	std::vector<int64_t> produces,
	std::vector<int64_t> consumes,
	OnSession onSessionJoined,
	OnSession onSessionEnded,
	GetFrame getFrameCallback,
	OnFrame onFrameCallback,
	uint64_t sessionID,
	int getFrameIntervalMS) :
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
    {}

    void connect();

private:
    std::string _deviceServiceAddress;
	std::string _sessionServiceAddress;
	std::string _stateManagerServiceAddress;
	uint64_t _deviceID;
	uint32_t _devicePort;
	std::string _deviceIP;
	std::vector<int64_t> _produces;
	std::vector<int64_t> _consumes;
    OnSession _onSessionJoined;
	OnSession _onSessionEnded;
	GetFrame _getFrameCallback;
	OnFrame _onFrameCallback;
	uint64_t _sessionID;
	int _getFrameIntervalMS;
};