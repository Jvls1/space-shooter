#include "framework/Object.hpp"

namespace ss {
    Object::Object()
        : mIsPendingDestroy{false} {

    }

    Object::~Object() {

    }

    void Object::Destroy() {
        OnDestroy.Broadcast(this);
        mIsPendingDestroy = true;
    }

    weak<Object> Object::GetWeakRef() {
        return weak_from_this();
    }

    weak<const Object> Object::GetWeakRef() const {
        return weak_from_this();
    }
}