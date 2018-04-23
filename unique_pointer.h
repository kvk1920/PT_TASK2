//
// Created by kvk1920 on 20.04.18.
//

#ifndef TASK2_UNIQUE_POINTER_H
#define TASK2_UNIQUE_POINTER_H

#include <memory>

namespace std {

template <typename T, typename T2>
inline unique_ptr<T> move_cast(unique_ptr<T2>&& p) {
    return unique_ptr<T>(dynamic_cast<T*>(p.release()));
};

}

//#define UNIQE_PTR_IN_GLOBAL_NAMESPACE
#ifdef UNIQE_PTR_IN_GLOBAL_NAMESPACE
using std::unique_ptr;
using std::make_unique;
#endif

#endif //TASK2_UNIQUE_POINTER_H
