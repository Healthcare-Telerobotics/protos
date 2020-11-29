#include <string>
#include <vector>

#include "callbacks.h"
#include "protos/common.pb.h"

typedef github::com::pyrus::platform::protos::Frame* (*GetFrameCallback) ();
typedef bool (*OnFrameCallback) (github::com::pyrus::platform::protos::Frame*);

class Sdk {
public:
	Sdk(std::string deviceServiceAddress,
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
		int getFrameIntervalMS);

    void connect();

private:
	static bool handleGetFrame(unsigned char* bufferPtr, int* sizePtr);
	static bool handleOnFrame(unsigned char* bufferPtr, int size);

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
	GetFrameCallback _getFrameCallback;
	OnFrameCallback _onFrameCallback;
	uint64_t _sessionID;
	int _getFrameIntervalMS;
};