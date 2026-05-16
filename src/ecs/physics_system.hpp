#pragma once
#include "physics_component.hpp"
#include "transform_component.hpp"
#include "component_store.hpp"
#include <cmath>

namespace PhysicsSystem {

    inline void update(
        ComponentStore<PhysicsComponent>& physicsStore,
        ComponentStore<TransformComponent>& transformStore,
        float dt)
    {
        for (auto& [entity, physics] : physicsStore) {
            if (physics.isStatic) continue;

            auto* transform = transformStore.get(entity);
            if (!transform) continue;

            physics.velocity.y -= physics.gravity * dt;

            transform->position.x += physics.velocity.x * dt;
            transform->position.y += physics.velocity.y * dt;
            transform->position.z += physics.velocity.z * dt;

            if (transform->position.y <= physics.floorY) {
                transform->position.y = physics.floorY;
                physics.velocity.y = -physics.velocity.y * physics.restitution;
                physics.velocity.x *= physics.restitution;
                physics.velocity.z *= physics.restitution;
                if (std::fabs(physics.velocity.y) < 0.5f)
                    physics.velocity.y = 0.0f;
            }
        }
    }

} // namespace PhysicsSystem
