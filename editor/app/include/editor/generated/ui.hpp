#pragma once
#include <JavaScriptCore/JSRetainPtr.h>
#include <utils/includes.h>

namespace JsEvents {
namespace LoadProject {
struct Input {
  std::string name;
  int createdAt;
  std::string maps;
};
struct Output {
  bool success;
};
} // namespace LoadProject

class Methods {
  LoadProject::Output loadProject(const LoadProject::Input& input);
};
}; // namespace JsEvents

namespace CppEvents {
namespace SaveProject {
struct Input {
  std::string name;
  int createdAt;
  std::string maps;
};
struct Output {
  bool success;
};
} // namespace SaveProject

class Methods {
  SaveProject::Output saveProject(const SaveProject::Input& input);
};
}; // namespace CppEvents
