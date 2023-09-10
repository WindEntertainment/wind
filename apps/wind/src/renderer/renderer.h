#include "../world/world.h"

namespace app {
    class Renderer {
    private:
        World* m_world;
    public:
        Renderer(World* _world);

        void render();
    };
}