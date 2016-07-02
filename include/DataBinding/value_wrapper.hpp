#pragma once

#include "model.hpp"

#include <array>

namespace model {

template <typename T>
class NestedValueWrapper : public ModelValue<T> {
public:
    NestedValueWrapper(ModelMember *owner, const T &t)
            : ModelValue<T>(owner)
            , t(t) {
    }

    T get() const override {
        return t;
    }

protected:
    T t;
};

template <typename T>
class ValueWrapper : public NestedValueWrapper<T> {
public:
    using NestedValueWrapper<T>::NestedValueWrapper;

    void set(const T &u, bool do_notify = true) override {
        this->t = u;
        if (do_notify) {
            this->broadcast();
        }
    }
};

}  // namespace model
