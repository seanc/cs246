# Topics
- Generic Classes & Functions
- Array data structure problems
- Runtime & Big-O Notation

### Generic Functions:
Defining: 
```cpp
template <typename T>
T Max(T a, T b) {
  return (a >= b) ? a : b;
}
```

Usage:
```cpp
int main () {
  std::cout << Max<int>(1,2);
}
```

### Generic Classes
Defining:
```cpp
template <class T>

class IteratorInterface {
  public:
    /** virtual methods ... */
};
```

Usage:
```cpp
template <class T>

class Iterator : public IteratorInterface<T> {
  T* data;
  int count;
}
```

Notes:
- When inheriting generic classes,
