#pragma once

#include <string>

namespace base64
{
    auto encode_string(const std::string &data)->std::string;
    auto decode_string(const std::string &str)->std::string;

    auto encode(const std::uint8_t *data, const std::streamsize size)->std::string;
} // namespace base64
