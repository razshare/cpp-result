#include "library.h"

template <typename T> Result<T> success(T value) {
    return Result<T>{
        value
      };
}

template <typename T> Result<T> failure(std::string message, const uint64_t code) {
    return Result<T>{
        .error = Error {
            .message = std::move(message),
            .code = code
          }
    };
}