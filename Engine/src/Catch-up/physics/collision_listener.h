#pragma once

#include "box2d\b2_world_callbacks.h"
#include "box2d\b2_contact.h"

#include <iostream>

namespace Engine
{
    void collisionDetect(b2Contact* contact) {
        b2Fixture* fixtureA = contact->GetFixtureA();
        b2Fixture* fixtureB = contact->GetFixtureB();
        b2Body* bodyA = fixtureA->GetBody();
        b2Body* bodyB = fixtureB->GetBody();

        std::cout << "Столкновение обнаружено!" << std::endl;

        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
        b2Vec2 collisionPoint = worldManifold.points[0];
        std::cout << "Точка столкновения: (" << collisionPoint.x << ", " << collisionPoint.y << ")" << std::endl;
    }

    class CollisionListener : public ::b2ContactListener {

        void BeginContact(b2Contact* contact) override {
            collisionDetect(contact);
        }
    };
}