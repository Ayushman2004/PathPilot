#include "directory_exists.h"
#include <filesystem>

bool directoryExists(const std::string& path) {
    return std::filesystem::exists(path) && std::filesystem::is_directory(path);
}
