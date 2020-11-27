# Vector2

**No longer in development. Use `glm` instead.**

<sub>Contact: development@kortlepel.com</sub>

- [Overview](#overview)
- [Features](#features)
- [Development Progress](#development-progress)
- [Notes](#notes)
- [How to use](#how-to-use)
    - [Construct a vector](#construct-a-vector)
    - [Vector operations](#vector-operations)

## Overview

This is a templated header-only class for a 2D Vector, written in C++17, with all common vector operations and some useful additional methods.


## Features

* **Header**-only, **MIT** licensed, **templated**.

* All equality- and relational operators

* **Supported operations:**
    - \+ \- \* \/ with another vector
    - \+ \- \* \/ with any scalar (templated)
    - rotation ([deg](#rotate-(degrees)) & [rad](#rotate-(radians)))
    - [reflection (using surface normal)](#reflect-off-surface-with-normal_vec)
    - [distance](#distance-to-other_vec) & [squared distance](#squared-distance-to-other_vec)
    - [magnitude (length)](#magnitude) & [squared magnitude](#squared-magnitude)
    - [normalization](#normalize)
    - [dot product](#dot-product-with-other_vec)
    - linear interpolation ([clamped](#linearly-interpolate-with-other_vec) & [unclamped](#linearly-interpolate-with-other_vec-unclamped))
    - [square root](#square-root)

* Typedefs for all primitive types (`Vector2f, Vector2i, Vector2d`, etc.)


## Development Progress

- [x] Common operators
- [x] Templated operators
- [x] License (MIT)
- [ ] Full in-source documentation
- [x] Common operations like normalizing, dot/cross/scalar product, distance, magnitude, etc.
- [x] _Extra fancy_ operations like linear interpolation, abs, rotation, reflection

## Notes

- Floating point equality comparisons have been implemented roughly following [this article](https://bitbashing.io/comparing-floats.html). Feel free to override the functions used by `#define`-ing 
`VECTOR2_FLOAT_COMPARE`, `VECTOR2_DOUBLE_COMPARE` and `VECTOR2_LONG_DOUBLE_COMPARE` for float, double and long double comparisons, respectively. They're used like `FUNCTION(first_float, second_float)`.
- Vector-rotation is implemented to rotate CLOCKWISE.
- `rotated_rad` _is possibly_ faster than `rotated_deg`, since the latter converts from degrees to radians first.
- The typedefs which specify size (for example `Vector2i8`) use `int_fast8_t` and similar (`fast` variant). Feel free to open an issue if this causes problems

## How to use

It should be intuitive, but here's *how intuitive*:

### **Construct a vector**

With typedefs...

```cpp
Vector2f vec {};                // (0, 0)

Vector2u vec (6);               // (6, 6)

Vector2d vec { 2.0, 5.0 };      // (2.0, 5.0)

Vector2i vec (6, -15);          // (6, -15)
```

...or the typey way:

```cpp
Vector2<long double> vec (2.5L, -18.5L);
```

### **Vector Operations**


#### rotate (degrees)
```cpp
auto result_vec = vec.rotated_deg (45.0);
```

#### rotate (radians)
```cpp
auto result_vec = vec.rotated_rad (PI / 3.0);
```

#### linearly interpolate with `other_vec`
```cpp
auto result_vec = vec.lerp (other_vec, 0.75);
```

#### linearly interpolate with `other_vec` unclamped
<sup>unclamped means that the value is **not** restricted between 0.0 and 1.0.</sup>
```cpp
auto result_vec = vec.lerp_unclamped (other_vec, 1.5);
```

#### reflect off surface with `normal_vec`
```cpp
auto result_vec = vec.reflected (normal_vec);
```

#### distance to `other_vec`
```cpp
auto result_vec = vec.distance (other_vec);
```

#### squared distance to `other_vec`
```cpp
auto result_vec = vec.sqr_distance (other_vec);
```

#### magnitude
```cpp
double mag = vec.magnitude ();
```

#### squared magnitude
```cpp
double sqr_mag = vec.sqr_magnitude ();
```

#### dot product with `other_vec`
```cpp
auto result_vec = vec.dot (other_vec);
```

#### square root
```cpp
auto result_vec = vec.square_root ();
```

#### normalize
```cpp
result_vec = vec.normalized ();
```
