#ifndef RESULT_LIBRARY_H
#define RESULT_LIBRARY_H
#include <cstdint>
#include <string>

struct Error {
  std::string message;
  /**
   * Error code.<br/>
   * An error code of `0` mean there is no error.
   */
  uint64_t code = 0;
};

template <typename T> struct Result {
  T value;
  Error error;
  std::tuple<T, Error> unwrap() { return {value, error}; }
};

template <typename T> Result<T> success(T value);

template <typename T> Result<T> failure(std::string message, uint64_t code = 1);

#endif // RESULT_LIBRARY_H
