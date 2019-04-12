
#include <stdint.h>

#define ICG_ATTR        __attribute__((section(".icg_sec")))

ICG_ATTR const uint32_t icg_val[8] =
{
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
};

