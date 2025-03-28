#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char message_type[8];  // Not null-terminated!
    uint8_t ship_id;
    uint8_t row;
    uint8_t col;
    uint8_t horizontal;
} robot_command_t;

bool parse_robot_message(const char *raw_data, robot_command_t *out);
