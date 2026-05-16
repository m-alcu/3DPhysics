#pragma once
#include "../slib.hpp"

struct PhysicsComponent {
    bool isStatic = true;
    slib::vec3 velocity{0.0f, 0.0f, 0.0f};
    float restitution = 0.7f;   // bounce coefficient: 0 = no bounce, 1 = perfect
    float gravity = 980.0f;     // acceleration in world units/s²
    float floorY = 0.0f;        // Y coordinate of the floor plane
};
