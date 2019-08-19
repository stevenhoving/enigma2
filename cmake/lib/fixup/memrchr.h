#pragma once

inline void* memrchr(const void* bytes, int find_char, size_t len) {
    const unsigned char* cursor =
        reinterpret_cast<const unsigned char*>(bytes) + len - 1;
    unsigned char actual_char = find_char;
    for (; cursor >= bytes; --cursor) {
        if (*cursor == actual_char) {
            return const_cast<void*>(reinterpret_cast<const void*>(cursor));
        }
    }
    return NULL;
}
