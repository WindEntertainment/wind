#include "camera_controll.h"
#include "../game.h"

#include <system/events/mouse.h>
#include <system/events/keyboard.h>

namespace soul_dungeon {
    CameraControll::CameraControll() {
        m_pitch = m_yaw = 0.f;
        speed = 3.f; 
        sensitivity = 0.5f;
    }

    void CameraControll::update(entt::registry& registry) {
        registry.view<renderer::Camera>().each([&](auto entity, auto& camera) {
            // ROTATION
            m_yaw   += system::Mouse::offset().x * sensitivity;
            m_pitch += system::Mouse::offset().y * sensitivity;

            if (m_pitch > 89.0f)
                m_pitch = 89.0f;
            if (m_pitch < -89.0f)
                m_pitch = -89.0f;

            glm::vec3 look;
            look.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
            look.y = sin(glm::radians(m_pitch));
            look.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
            camera.front = glm::normalize(look);

            // MOVEMENT
            float ds = speed * system::Application::deltaTime();
            auto direction = vec3{ camera.front.x, 0, camera.front.z };
            if (system::Keyboard::isKey(GLFW_KEY_W)) 
                camera.position += ds * direction;
            if (system::Keyboard::isKey(GLFW_KEY_S))
                camera.position -= ds * direction;
            if (system::Keyboard::isKey(GLFW_KEY_A))
                camera.position -= glm::normalize(glm::cross(direction, camera.up)) * ds;
            if (system::Keyboard::isKey(GLFW_KEY_D))
                camera.position += glm::normalize(glm::cross(direction, camera.up)) * ds;
            //
        });
    }
}