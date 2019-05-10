/* File "Vector2.hpp" created April 2019
 * 
 * GitHub: https://github.com/lionkor/Vector2
 * 
 * MIT License
 * 
 * Copyright (c) 2019 Lion Kortlepel
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the 
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the 
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include <utility>
#include <limits>
#include <cstring>
#include <cfloat>
#include <cstdint> // int_fast types

// defining pi to enough digits to fill long double
template<typename T>
static constexpr T V2_PI { static_cast<T> (3.141592653589793238462643383279502884197169L) };

static bool f_equality (const float first, const float second);
static bool d_equality (const double first, const double second);
static bool ld_equality (const long double first, const long double second);

/// returns true if given type is float
template<typename T>
constexpr bool is_float () { return false; }
template<>
constexpr bool is_float<float> () { return true; }

/// returns true if given type is double
template<typename T>
constexpr bool is_double () { return false; }
template<>
constexpr bool is_double<double> () { return true; }

/// returns true if given type is long double
template<typename T>
constexpr bool is_long_double () { return false; }
template<>
constexpr bool is_long_double<long double> () { return true; }

/// Represents a 2D vector with two elements of type T and implements
/// all common operations associated with it.
template<typename T>
class Vector2
{
public:    
    /// First element of the Vector2.
    T x;
    /// Second element of the Vector2.
    T y;
    
    /// Constructor for Vector2 with first element equal to x and second element equal to y.
    Vector2 (T x, T y)
        : x (std::move (x)), y (std::move (y))
    {}
    
    /// Constructor for Vector2 with both elements equal to n. 
    explicit Vector2 (const T& n)
        : x (n), y (n)
    {}
    
    /// Constructor for Vector2 with both elements equal to their defaults.
    Vector2 ()
        : x (), y ()
    {}
    
    /// Templated conversion operator
    template<typename to_T>
    constexpr operator Vector2<to_T> () const
    {
        return Vector2<to_T> (static_cast<to_T> (x), static_cast<to_T> (y));
    }
    
    constexpr Vector2& operator+= (const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
    constexpr Vector2& operator-= (const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    
    constexpr Vector2& operator*= (const Vector2& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
    
    constexpr Vector2& operator/= (const Vector2& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }
    
    template<typename rhs_T>
    constexpr Vector2& operator+= (const rhs_T& rhs)
    {
        x += rhs;
        y += rhs;
        return *this;
    }
    
    template<typename rhs_T>
    constexpr Vector2& operator-= (const rhs_T& rhs)
    {
        x -= rhs;
        y -= rhs;
        return *this;
    }
    
    template<typename rhs_T>
    constexpr Vector2& operator*= (const rhs_T& rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }
    
    template<typename rhs_T>
    constexpr Vector2& operator/= (const rhs_T& rhs)
    {
        x /= rhs;
        y /= rhs;
        return *this;
    }
    
    constexpr Vector2 operator- () const
    {
        return Vector2 (-x, -y);
    }
    
    constexpr Vector2 operator+ (const Vector2& rhs) const
    {
        return Vector2 (x + rhs.x, y + rhs.y);
    }
    
    constexpr Vector2 operator- (const Vector2& rhs) const
    {
        return Vector2 (x - rhs.x, y - rhs.y);
    }
    
    constexpr Vector2 operator* (const Vector2& rhs) const 
    {
        return Vector2 (x * rhs.x, y * rhs.y);
    }
    
    constexpr Vector2 operator/ (const Vector2& rhs) const
    {
        return Vector2 (x / rhs.x, y / rhs.y);
    }
    
    template<typename rhs_T>
    constexpr Vector2 operator+ (const rhs_T& rhs) const
    {
        return Vector2 (x + rhs, y + rhs);
    }
    
    template<typename rhs_T>
    constexpr Vector2 operator- (const rhs_T& rhs) const
    {
        return Vector2 (x - rhs, y - rhs);
    }
    
    template<typename rhs_T>
    constexpr Vector2 operator* (const rhs_T& rhs) const
    {
        return Vector2 (x * rhs, y * rhs);
    }
    
    template<typename lhs_T>
    constexpr friend Vector2 operator+ (const lhs_T& lhs, const Vector2& rhs) 
    {
        return Vector2 (lhs + rhs.x, lhs + rhs.y);
    }
    
    template<typename lhs_T>
    constexpr friend Vector2 operator- (const lhs_T& lhs, const Vector2& rhs)
    {
        return Vector2 (lhs - rhs.x, lhs - rhs.y);
    }
    
    template<typename lhs_T>
    constexpr friend Vector2 operator* (const lhs_T& lhs, const Vector2& rhs)
    {
        return Vector2 (lhs * rhs.x, lhs * rhs.y);
    }
    
    template<typename lhs_T>
    constexpr friend Vector2 operator/ (const lhs_T& lhs, const Vector2& rhs)
    {
        return Vector2 (lhs / rhs.x, lhs / rhs.y);
    }
    
    template<typename rhs_T>
    constexpr Vector2 operator/ (const rhs_T& rhs) const
    {
        return Vector2 (x / rhs, y / rhs);
    }
    
    template<typename rhs_T>
    constexpr bool operator== (const Vector2<rhs_T>& rhs) const
    {
        // comparison of floats based on their accuracy
        if (is_float<T> () || is_float<rhs_T> ())
            return f_equality (x, rhs.x) &&
                   f_equality (y, rhs.y);
        else if (is_double<T> () || is_double<rhs_T> ()) 
            return d_equality (x, rhs.x) && 
                   d_equality (y, rhs.y);
        else if (is_long_double<T> () || is_double<rhs_T> ())
            return ld_equality (x, rhs.x) &&
                   ld_equality (y, rhs.y);
        else
            return x == rhs.x && y == rhs.y;
    }
    
    constexpr bool operator!= (const Vector2& rhs) const
    {
        return !(rhs == *this);
    }
    
    constexpr bool operator< (const Vector2& rhs) const
    {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }
    
    constexpr bool operator> (const Vector2& rhs) const
    {
        return rhs < *this;
    }
    
    constexpr bool operator<= (const Vector2& rhs) const
    {
        return !(rhs < *this);
    }
    
    constexpr bool operator>= (const Vector2& rhs) const
    {
        return !(*this < rhs);
    }
    
    // vector specific mathematical operations
    
    /// Returns the dot product of two vectors.
    constexpr auto dot (const Vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    
    /// Returns magnitude ("length") of the vector.
    constexpr auto magnitude () const
    {
        return sqrt (x * x + y * y);
    }
    
    /// Returns the squared magnitude ("length") of the vector. This saves one sqrt operation and 
    /// is therefore significant faster for comparing two vector magnitudes.
    constexpr auto sqr_magnitude () const
    {
        return x * x + y * y;
    }
    
    /// Returns a vector with all elements as absolute values.
    constexpr Vector2 absolute () const
    {
        return Vector2 (abs (x), abs (y));
    }
    
    /// Returns the distance between both vectors.
    constexpr auto distance (const Vector2& other) const
    {
        return sqrt ((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
    
    /// Returns the squared distance between both vectors. This is faster for comparisons as it saves 
    /// on one sqrt operation.
    constexpr auto sqr_distance (const Vector2& other) const
    {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
    
    /// Linearly interpolates between this Vector2 and the given Vector2 using the provided value.
    constexpr Vector2 lerp (const Vector2& other, double value) const
    {
        if (value > 1.0)
        {
            return other;
        }
        else if (value < 0.0)
        {
            return *this;
        }
        else
        {
            return Vector2 (x + (other.x - x) * value,
                            y + (other.y - y) * value);    
        }
    }
    
    /// Linearly interpolates between this Vector2 and the given Vector2 using the provided value.
    /// This version does not clamp between the two Vectors.
    constexpr Vector2 lerp_unclamped (const Vector2& other, double value) const
    {
        return Vector2 (x + (other.x - x) * value,
                        y + (other.y - y) * value);
    }
    
    /// Returns a normalized copy of this vector. A normalized vector has magnitude/length equal to 1.0.
    constexpr Vector2 normalized () const
    {
        return *this / sqrt (x * x + y * y);
    }
    
    /// Returns a vector with the elements equal to the square root of the elements of this vector. 
    constexpr Vector2 square_root () const
    {
        return Vector2 (sqrt (x), sqrt (y));
    }
    
    /// Returns the reflection vector for this vector reflecting off a surface with the specified normal
    /// vector.
    constexpr Vector2 reflected (const Vector2& normal) const
    {
        Vector2 n = normal.normalized ();
        return static_cast<Vector2> (*this) - 2.0 * (static_cast<Vector2> (*this).dot (n)) * n;
    }
    
    /// Returns a copy of this Vector2 rotated CLOCKWISE by the given number of degrees. Using rotated_rad is faster
    /// if you already have radians.
    constexpr Vector2 rotated_deg (double angle_degrees) const
    {
        // convert to radians
        double radians = angle_degrees * (V2_PI<long double> / 180.0);
        return Vector2 (
                         x * cos (radians) + y * sin (radians),
                        -x * sin (radians) + y * cos (radians));
    }
    
    /// Returns a copy of this Vector2 rotated CLOCKWISE by the given number of degrees. For degrees use
    /// rotated_deg.
    constexpr Vector2 rotated_rad (double angle_radians) const
    {
        return Vector2 (
                 x * cos (angle_radians) + y * sin (angle_radians),
                -x * sin (angle_radians) + y * cos (angle_radians));
    }
};

// The following is hacked together from a bitbashing.io article about floating point comparisons.

// According to the standard, there are three floating point types: float, double, long double.
// For this reason the below code will only cover those. For other types, either cast or write
// your own functions. 

// The defines make it possible to override the function used for comparison. In case you need
// something faster & less accurate, you can use a simple `abs(a-b) < epsilon` for a big epsilon 
// like 0.00001. The functions used below attempt to make epsilon as accurate as possible.

// float comparisons
#ifndef VECTOR2_FLOAT_COMPARE 
#define VECTOR2_FLOAT_COMPARE(first, second) f_equality(first, second)
#endif

// double comparisons
#ifndef VECTOR2_DOUBLE_COMPARE
#define VECTOR2_DOUBLE_COMPARE(first, second) d_equality(first, second)
#endif

// long double comparisons
#ifndef VECTOR2_LONG_DOUBLE_COMPARE
#define VECTOR2_LONG_DOUBLE_COMPARE(first, second) ld_equality(first, second)
#endif

// ulp = unit of least precision

// NOTE: The following approach, although quite unsafe, is used because EPSILONs are very inaccurate when comparing 
// floats much larger than or much closer to zero than 1.0. Epsilon is only really accurate around 1.0,
// so that is why this method is used instead. 
// Instead of this, boost's floating point comparison(s) (which do a similar thing) may be used, but this header
// does not want to introduce such a big dependency.

template<typename int_T, typename float_T>
static int_T ulp_distance (const float_T a, const float_T b)
{
    if (a == b) return 0;
    
    const auto max = std::numeric_limits<int_T>::max ();
    
    // check for NaN and inf
    if (std::isnan (a) || std::isnan (b)) return max;
    if (std::isinf (a) || std::isinf (b)) return max;
    
    static_assert (sizeof (float_T) == sizeof (int_T), "float and/or int are/is a weird size");
    
    int_T ia;
    int_T ib;
    
    // copy memory to integer memory so we can compare them
    // and find out the proper ulp
    memcpy (&ia, &a, sizeof (float_T));
    memcpy (&ib, &b, sizeof (float_T));
    
    // check that they're both signed or both unsigned
    if ((ia < 0) != (ib < 0)) return max;
    
    int_T distance = ia - ib;
    
    if (distance < 0) distance = -distance;
    
    return distance;
}

bool f_equality (const float first, const float second)
{
    return fabs (first - second) <= 1.0f / ulp_distance<int32_t, float> (first, second);
}

bool d_equality (const double first, const double second)
{
    return fabs (first - second) <= 1.0 / ulp_distance<int64_t, double> (first, second);
}

bool ld_equality (const long double first, const long double second)
{
    // uses LDBL_EPSILON since no int with equivalent size to long double exists
    return fabsl (first - second) <= LDBL_EPSILON;
}


// common type typedefs

/// float
typedef Vector2<float>              Vector2f;
/// double
typedef Vector2<double>             Vector2d;
/// long double
typedef Vector2<long double>        Vector2ld;
/// char
typedef Vector2<signed char>        Vector2c;
/// unsigned char
typedef Vector2<unsigned char>      Vector2uc;
/// int
typedef Vector2<signed int>         Vector2i;
/// unsigned int
typedef Vector2<unsigned int>       Vector2u;
/// long
typedef Vector2<signed long>        Vector2l;
/// unsigned long
typedef Vector2<unsigned long>      Vector2ul;
/// long long
typedef Vector2<signed long long>   Vector2ll;
/// unsigned long long
typedef Vector2<unsigned long long> Vector2ull;
// /// bool
// typedef Vector2<bool>               Vector2b;

// int_fast typedefs
/// fast 8 bit int
typedef Vector2<int_fast8_t>        Vector2i8;
/// fast 16 bit int
typedef Vector2<int_fast16_t>       Vector2i16;
/// fast 32 bit int
typedef Vector2<int_fast32_t>       Vector2i32;
/// fast 64 bit int
typedef Vector2<int_fast64_t>       Vector2i64;

// uint_fast typedefs

/// fast 8 bit unsigned int
typedef Vector2<uint_fast8_t>       Vector2u8;
/// fast 16 bit unsigned int
typedef Vector2<uint_fast16_t>      Vector2u16;
/// fast 32 bit unsigned int
typedef Vector2<uint_fast32_t>      Vector2u32;
/// fast 64 bit unsigned int
typedef Vector2<uint_fast64_t>      Vector2u64;
#endif //VECTOR2_HPP
