#include "framework/Object.hpp"

namespace ss {
    Object::Object()
        : mIsPendingDestroy{false} {

    }

    Object::~Object() {

    }

    void Object::Destroy() {
        mIsPendingDestroy = true;
    }
}