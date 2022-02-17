#pragma once

#include <string>

namespace ktp { namespace Resources {

/**
 * @brief Gets the path to the resources directory.
 * @param sub_dir Specify a sub directory, ie. textures.
 * @return The full path to the resources directory (and subdirectory if instructed).
 */
std::string getResourcesPath(const std::string& sub_dir = "");

} } // namespace Resources / ktp
