#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef bool (*GetFrame) (unsigned char*, int*);
static inline bool get_frame(GetFrame ptr, unsigned char* buffer, int* bufferSizePtr) {
    return (ptr)(buffer, bufferSizePtr);
}

typedef bool (*OnFrame) (unsigned char*, int);
static inline bool on_frame(OnFrame ptr, unsigned char* buffer, int bufferSize) {
    return (ptr)(buffer, bufferSize);
}

typedef void (*OnSession) (uint64_t);
static inline void on_session(OnSession ptr, uint64_t sessionId) {
    (ptr)(sessionId);
}

#endif // CALLBACKS_H