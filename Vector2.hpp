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

#include <ostream>
#include <math.h>

static const double VECTOR2_MATH_PI = 3.14159265358979323846;

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
    Vector2 (const T& x, const T& y)
        : x (x), y (y)
    {}
    
    /// Copy constructor
    Vector2 (const Vector2& vector)
        : x (vector.x), y (vector.y)
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
    inline operator Vector2<to_T> () const
    {
        return Vector2<to_T> (static_cast<to_T> (x), static_cast<to_T> (y));
    }
    
    inline Vector2& operator= (const Vector2& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
    
    inline friend std::ostream& operator<< (std::ostream& os, const Vector2& vector2)
    {
        os << "x: " << vector2.x << " y: " << vector2.y;
        return os;
    }
    
    inline Vector2& operator+= (const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
    inline Vector2& operator-= (const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    
    inline Vector2& operator*= (const Vector2& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
    
    inline Vector2& operator/= (const Vector2& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }
    
    template<typename rhs_T>
    inline Vector2& operator+= (const rhs_T& rhs)
    {
        x += rhs;
        y += rhs;
        return *this;
    }
    
    template<typename rhs_T>
    inline Vector2& operator-= (const rhs_T& rhs)
    {
        x -= rhs;
        y -= rhs;
        return *this;
    }
    
    template<typename rhs_T>
    inline Vector2& operator*= (const rhs_T& rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }
    
    template<typename rhs_T>
    inline Vector2& operator/= (const rhs_T& rhs)
    {
        x /= rhs;
        y /= rhs;
        return *this;
    }
    
    inline Vector2 operator- () const
    {
        return Vector2 (-x, -y);
    }
    
    inline Vector2 operator+ (const Vector2& rhs) const
    {
        return Vector2 (x + rhs.x, y + rhs.y);
    }
    
    inline Vector2 operator- (const Vector2& rhs) const
    {
        return Vector2 (x - rhs.x, y - rhs.y);
    }
    
    inline Vector2 operator* (const Vector2& rhs) const 
    {
        return Vector2 (x * rhs.x, y * rhs.y);
    }
    
    inline Vector2 operator/ (const Vector2& rhs) const
    {
        return Vector2 (x / rhs.x, y / rhs.y);
    }
    
    template<typename rhs_T>
    inline Vector2 operator+ (const rhs_T& rhs) const
    {
        return Vector2 (x + rhs, y + rhs);
    }
    
    template<typename rhs_T>
    inline Vector2 operator- (const rhs_T& rhs) const
    {
        return Vector2 (x - rhs, y - rhs);
    }
    
    template<typename rhs_T>
    inline Vector2 operator* (const rhs_T& rhs) const
    {
        return Vector2 (x * rhs, y * rhs);
    }
    
    template<typename lhs_T>
    friend Vector2 operator+ (const lhs_T& lhs, const Vector2& rhs) 
    {
        return Vector2 (lhs + rhs.x, lhs + rhs.y);
    }
    
    template<typename lhs_T>
    inline friend Vector2 operator- (const lhs_T& lhs, const Vector2& rhs)
    {
        return Vector2 (lhs - rhs.x, lhs - rhs.y);
    }
    
    template<typename lhs_T>
    inline friend Vector2 operator* (const lhs_T& lhs, const Vector2& rhs)
    {
        return Vector2 (lhs * rhs.x, lhs * rhs.y);
    }
    
    template<typename lhs_T>
    inline friend Vector2 operator/ (const lhs_T& lhs, const Vector2& rhs)
    {
        return Vector2 (lhs / rhs.x, lhs / rhs.y);
    }
    
    template<typename rhs_T>
    inline Vector2 operator/ (const rhs_T& rhs) const
    {
        return Vector2 (x / rhs, y / rhs);
    }
    
    inline bool operator== (const Vector2& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    
    inline bool operator!= (const Vector2& rhs) const
    {
        return !(rhs == *this);
    }
    
    inline bool operator< (const Vector2& rhs) const
    {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }
    
    inline bool operator> (const Vector2& rhs) const
    {
        return rhs < *this;
    }
    
    inline bool operator<= (const Vector2& rhs) const
    {
        return !(rhs < *this);
    }
    
    inline bool operator>= (const Vector2& rhs) const
    {
        return !(*this < rhs);
    }
    
    // vector specific mathematical operations
    
    /// Returns the dot product of two vectors.
    inline double dot (const Vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    
    /// Returns magnitude ("length") of the vector.
    inline double magnitude () const
    {
        return sqrt (x * x + y * y);
    }
    
    /// Returns the squared magnitude ("length") of the vector. This saves one sqrt operation and 
    /// is therefore significant faster for comparing two vector magnitudes.
    inline double sqr_magnitude () const
    {
        return x * x + y * y;
    }
    
    /// Returns a vector with all elements as absolute values.
    inline Vector2 absolute () const
    {
        return Vector2 (abs (x), abs (y));
    }
    
    /// Returns the distance between both vectors.
    inline double distance (const Vector2& other) const
    {
        return sqrt ((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
    
    /// Returns the squared distance between both vectors. This is faster for comparisons as it saves 
    /// on one sqrt operation.
    inline double sqr_distance (const Vector2& other) const
    {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
    
    /// Linearly interpolates between this Vector2 and the given Vector2 using the provided value.
    inline Vector2 lerp (const Vector2& other, double value) const
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
    inline Vector2 lerp_unclamped (const Vector2& other, double value) const
    {
        return Vector2 (x + (other.x - x) * value,
                        y + (other.y - y) * value);
    }
    
    /// Returns a normalized copy of this vector. A normalized vector has magnitude/length equal to 1.0.
    inline Vector2 normalized () const
    {
        return *this / sqrt (x * x + y * y);
    }
    
    /// Returns a vector with the elements equal to the square root of the elements of this vector. 
    inline Vector2 square_root () const
    {
        return Vector2 (sqrt (x), sqrt (y));
    }
    
    /// Returns the reflection vector for this vector reflecting off a surface with the specified normal
    /// vector.
    inline Vector2 reflected (const Vector2& normal) const
    {
        Vector2 n = normal.normalized ();
        return static_cast<Vector2> (*this) - 2.0 * (static_cast<Vector2> (*this).dot (n)) * n;
    }
    
    /// Returns a copy of this Vector2 rotated by the given number of degrees. Using rotated_rad is faster
    /// if you already have radians.
    inline Vector2 rotated_deg (double angle_degrees) const
    {
        // convert to radians
        double radians = angle_degrees * (VECTOR2_MATH_PI / 180.0);
        return Vector2 (
                        x * sin (radians) + x * cos (radians),
                        x * cos (radians) - y * sin (radians));
    }
    
    /// Returns a copy of this Vector2 rotated by the given number of degrees. For degrees use
    /// rotated_deg.
    inline Vector2 rotated_rad (double angle_radians) const
    {
        return Vector2 (x * cos (angle_radians) - y * sin (angle_radians),
                        x * sin (angle_radians) + x * cos (angle_radians));
    }
};

// common type typedefs

/// float
typedef Vector2<float>              Vector2f;
/// double
typedef Vector2<double>             Vector2d;
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
