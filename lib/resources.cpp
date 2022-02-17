#include "resources.hpp"
#include <filesystem>

std::string ktp::Resources::getResourcesPath(const std::string& sub_dir) {
  const std::string kPROJECT_NAME = "pong-SFML";
  constexpr auto kRESOURCES_FOLDER = "resources";

  #ifdef _WIN32
    constexpr auto kPATH_SEPARATOR = '\\';
  #else
    constexpr auto kPATH_SEPARATOR = '/';
  #endif

  auto path {std::filesystem::current_path().string()};
  const auto kPos {path.rfind(kPROJECT_NAME) + kPROJECT_NAME.length()};

  path = path.substr(0, kPos) + kPATH_SEPARATOR + kRESOURCES_FOLDER + kPATH_SEPARATOR;
  return sub_dir.empty() ? path : path + sub_dir + kPATH_SEPARATOR;
}
