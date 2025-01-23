#pragma once
#include <mutex>
#include <shared_mutex>

#define SHARED_LOCK_SETTING shared_mutex _SMT
#define READ_LOCK shared_lock sl{ _SMT };
#define WRITE_LOCK lock_guard lg{ _SMT };

using byte = uint8_t;
using int16 = int16_t;
using uint16 = uint16_t;
using int32 = int32_t;
using int64 = int64_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using KnightRef = std::shared_ptr<class Knight>;