#pragma once

#include "portable_endian.h"

#define LITTLE_ENDIAN 1
#define BYTE_ORDER LITTLE_ENDIAN

#define bswap_16 htobe16