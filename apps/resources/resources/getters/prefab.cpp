#include "prefab.h"
#include <asset-bundler/objects/text.h>
#include <dom/xml.h>

namespace wind {
    namespace resources {
        template<>
        stdgame::Prefab* get(const char* _name) {
            auto source = get<assets::Text>(_name);
            if (!source)
                return nullptr;

            try {
                dom::Document* doc = dom::XML::LoadRAW(source->text.c_str(), source->text.size());
            
                auto res = new stdgame::Prefab(_name, doc);
                delete source;

                return res;
            } catch (std::invalid_argument& ex) {
                log().error() << "Prefab [" << _name << "] incorrect: " << ex.what();
                delete source;
                
                return nullptr;
            }
        }
    }
}