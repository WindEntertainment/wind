import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps

class MyConanFile(ConanFile):
  name = "dreich"
  version = "1.0"
  settings = "os", "compiler", "build_type", "arch"
  generators = "CMakeDeps", "CMakeToolchain"
  exports_sources = "*"
  requires = [
    "spdlog/1.13.0",
    "yaml-cpp/0.8.0",
    "zlib/1.2.11",
    "stb/cci.20220909",
    "pugixml/1.13",
    "cxxopts/3.1.1",
    "glad/0.1.36",
    "glfw/3.3.8",
    "glm/cci.20230113",
    "boost/1.85.0"
  ]

  options = {
    "boost/*:header_only": ["ANY", True, False],
    "boost/*:without_charconv": ["ANY", True, False],
    "boost/*:without_container": ["ANY", True, False],
    "boost/*:without_system": ["ANY", True, False],
    "boost/*:without_filesystem": ["ANY", True, False],
    "boost/*:without_atomic": ["ANY", True, False],
    "boost/*:without_log": ["ANY", True, False],
    "boost/*:without_mpi": ["ANY", True, False],
    "boost/*:without_url": ["ANY", True, False],
    "boost/*:without_json": ["ANY", True, False],
    "boost/*:without_math": ["ANY", True, False],
    "boost/*:without_test": ["ANY", True, False],
    "boost/*:without_wave": ["ANY", True, False],
    "boost/*:without_fiber": ["ANY", True, False],
    "boost/*:without_graph": ["ANY", True, False],
    "boost/*:without_regex": ["ANY", True, False],
    "boost/*:without_timer": ["ANY", True, False],
    "boost/*:without_chrono": ["ANY", True, False],
    "boost/*:without_cobalt": ["ANY", True, False],
    "boost/*:without_locale": ["ANY", True, False],
    "boost/*:without_nowide": ["ANY", True, False],
    "boost/*:without_python": ["ANY", True, False],
    "boost/*:without_random": ["ANY", True, False],
    "boost/*:without_thread": ["ANY", True, False],
    "boost/*:without_context": ["ANY", True, False],
    "boost/*:without_contract": ["ANY", True, False],
    "boost/*:without_coroutine": ["ANY", True, False],
    "boost/*:without_date_time": ["ANY", True, False],
    "boost/*:without_exception": ["ANY", True, False],
    "boost/*:without_iostreams": ["ANY", True, False],
    "boost/*:without_stacktrace": ["ANY", True, False],
    "boost/*:without_type_erasure": ["ANY", True, False],
    "boost/*:without_serialization": ["ANY", True, False],
    "boost/*:without_graph_parallel": ["ANY", True, False],
    "boost/*:without_program_options": ["ANY", True, False],
    "boost/*:with_stacktrace_backtrace": ["ANY", True, False],
  }

  default_options = {
    "boost/*:header_only": False,
    "boost/*:without_charconv": False,
    "boost/*:without_container": False,
    "boost/*:without_system": False,
    "boost/*:without_filesystem": False,
    "boost/*:without_atomic": False,
    "boost/*:without_log": True,
    "boost/*:without_mpi": True,
    "boost/*:without_url": True,
    "boost/*:without_json": True,
    "boost/*:without_math": True,
    "boost/*:without_test": True,
    "boost/*:without_wave": True,
    "boost/*:without_fiber": True,
    "boost/*:without_graph": True,
    "boost/*:without_regex": True,
    "boost/*:without_timer": True,
    "boost/*:without_chrono": True,
    "boost/*:without_cobalt": True,
    "boost/*:without_locale": True,
    "boost/*:without_nowide": True,
    "boost/*:without_python": True,
    "boost/*:without_random": True,
    "boost/*:without_thread": True,
    "boost/*:without_context": True,
    "boost/*:without_contract": True,
    "boost/*:without_coroutine": True,
    "boost/*:without_date_time": True,
    "boost/*:without_exception": True,
    "boost/*:without_iostreams": True,
    "boost/*:without_stacktrace": True,
    "boost/*:without_type_erasure": True,
    "boost/*:without_serialization": True,
    "boost/*:without_graph_parallel": True,
    "boost/*:without_program_options": True,
    "boost/*:with_stacktrace_backtrace": True,
  }

  def layout(self):
    cmake_layout(self)

  def build(self):
    cmake = CMake(self)
    cmake.configure()
    cmake.build()

  def package_info(self):
    self.cpp_info.libs = ["Dreich"]
