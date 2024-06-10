#include <supermod/exceptions/Error.hpp>

sm::Error::Error(const std::string& message) : exception(message.c_str()) {}