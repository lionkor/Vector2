# Vector2

<sub>Contact: development@kortlepel.com</sub>

## Overview

This is a templated header-only class for a 2D Vector, written in C++17, with all common vector operations and some useful additional methods.

## Features

* Header-only & MIT licensed.

* All common operators are implemented and templated ones are used, for math with non-primitive types.

* Consistent naming and documentation.

* Many useful typedefs with consistent naming, like `Vector2f` and `Vector2i`.

* Written for speed and ease-of-use.

* Many useful methods like rotation, reflection and interpolation.

### Progress

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
- The typedefs which specify size (for example `Vector2i8`) use `int_fast8_t` and similar (`fast` variant). Feel free to open an issue if this causes problems.
