#pragma once
#include "pipe.h"

namespace wind {
namespace asset_pipeline {

class DefaultPipe : public AssetPipe {
public:
  virtual void compile(const fs::path& source, const fs::path& destination) override {
    std::ifstream input(_source, std::ios_base::in);
    std::ofstream output(_destination, std::ios_base::binary);

    if (!input.is_open()) {
      spdlog::error("Cannot open source file: {}", _source.string());
      return;
    }

    if (!output.is_open()) {
      spdlog::error("Cannot open destination file: {}", _destination.string());
      return;
    }

    output.write(reinterpret_cast<char*>(m_id), sizeof(asset_id));

    std::string fileContent;
    {
      std::stringstream buffer;
      buffer << input.rdbuf();
      fileContent = buffer.str();
    }

    size_t zippedSize = compressBound(fileContent.size());
    char* zipped = new char[zippedSize];

    auto result = compress(reinterpret_cast<Bytef*>(zipped), &zippedSize, reinterpret_cast<const Bytef*>(fileContent.c_str()), fileContent.size());
    if (result != Z_OK) {
      spdlog::error("Cannot compress data");
      return;
    }

    output.write(reinterpret_cast<char*>((asset_id)fileContent.size()), sizeof(asset_id));
    output.write(zipped, zippedSize);

    input.close();
    output.close();

    delete[] zipped;
  }

  DefaultPipe()
      : AssetPipe("default"){};
};

} // namespace asset_pipeline
} // namespace wind