#pragma once
#include <utils/utils.h>
#include <zlib.h>

#ifdef WIND_PIPE_WRITE
#include <yaml-cpp/yaml.h>
#endif

namespace wind {

using asset_id = unsigned int;

class AssetPipe {
  friend class AssetPipeline;

protected:
  asset_id m_id;

public:
#ifdef WIND_PIPE_WRITE
  virtual void config(YAML::Node& config){};
  virtual void compile(const fs::path& _source, const fs::path& _destination) = 0;
#endif

  virtual void* load(unsigned char* bytes, size_t size) = 0;

  asset_id id() const {
    return m_id;
  }

  AssetPipe(const char* _id) {
    std::hash<const char*> hasher;
    m_id = hasher(_id);
  }
};

} // namespace wind