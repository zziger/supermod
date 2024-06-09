#include <supermod/exceptions/Error.hpp>

Error::Error(const std::string& message) : exception(message.c_str()) {}