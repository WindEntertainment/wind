#include <breeze/systems/system.h>
#include <renderer/renderer.h>

namespace soul_dungeon {
    class CameraControll : public wind::breeze::System {
    private:
        float m_yaw,
              m_pitch;
    public:
        float speed;
        float sensitivity;

        CameraControll();
        void update(entt::registry&) override;
    };
}