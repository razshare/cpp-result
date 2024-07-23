# What is this?

This is an implementation of `Result<T>` in C++.

# Opinions & Usage

Do not throw exceptions in your code.

Instead, use the provided `success()` and `failure()` functions and return `Error` objects.

Both functions make use of generic templates, so they are type safe.

```c++
auto [name, error] = success("world").unwrap();
```

Here, `name_result` is of type `Result<std::string>`.

Every single time your have `Result<T>` on your hands, you **must** unwrap it and check the error.

This gives you type safety and ensures you always know, at the language server level and compile time, when something can go wrong.

```c++
auto [name, error] = success("world").unwrap();
if(error.code > 0){
    // Something is wrong.
    return;
}

std::cout << "hello " << name;
```