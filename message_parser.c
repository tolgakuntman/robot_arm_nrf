#include "message_parser.h"
#include <string.h>

bool parse_robot_message(const char *raw_data, robot_command_t *out) {
    if (!raw_data || !out) return false;

    // Copy the 8-byte type
    memcpy(out->message_type, raw_data, 8);

    // Extract fields
    out->ship_id = (uint8_t)raw_data[8];
    out->row = (uint8_t)raw_data[9];
    out->col = (uint8_t)raw_data[10];
    out->horizontal = (raw_data[11] != 0);  // Treat non-zero as true

    return true;
}
