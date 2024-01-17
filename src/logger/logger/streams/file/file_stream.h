#include "logger/streams/logger_stream.h"

namespace wind {
    namespace logger {
        class FileStream : public Stream {
        public:
            FileStream(const string&& path, const char* (*name)(void) = nullptr);
            ~FileStream();
        private:
            std::ofstream m_file;
        public:
            void write(const string& msg) override;
        };
    }
}