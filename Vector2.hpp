/* File "Vector2.hpp" created April 2019
 * Copyright (c) Lion Kortlepel 2019
 * 
 * This templated class contains all common operations for a 2D Vector.
 * I decided to document everything so that even someone not quite familiar
 * with vector maths could confidently use it.
 */




#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <ostream>
#include <math.h>

/// Represents a 2D vector with two elements of type T and implements
/// all common operations associated with it.
template<typename T>
class Vector2
{
public:
    /// Vector2 with both elements set to 1.0.
    static const Vector2 one  = Vector2 (1.0, 1.0);
    
    /// Vector2 with both elements set to 0.0.
    static const Vector2 zero = Vector2 (0.0, 0.0);
    
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
    
    Vector2& operator= (const Vector2& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
    
    friend std::ostream& operator<< (std::ostream& os, const Vector2& vector2)
    {
        os << "x: " << vector2.x << " y: " << vector2.y;
        return os;
    }
    
    Vector2& operator+= (const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
    Vector2& operator-= (const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    
    Vector2& operator*= (const Vector2& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
    
    Vector2& operator/= (const Vector2& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }
    
    template<typename rhs_T>
    Vector2& operator+= (const rhs_T& rhs)
    {
        x += rhs;
        y += rhs;
        return *this;
    }
    
    template<typename rhs_T>
    Vector2& operator-= (const rhs_T& rhs)
    {
        x -= rhs;
        y -= rhs;
        return *this;
    }
    
    template<typename rhs_T>
    Vector2& operator*= (const rhs_T& rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }
    
    template<typename rhs_T>
    Vector2& operator/= (const rhs_T& rhs)
    {
        x /= rhs;
        y /= rhs;
        return *this;
    }
    
    Vector2 operator+ (const Vector2& rhs)
    {
        return Vector2 (x + rhs.x, y + rhs.y);
    }
    
    Vector2 operator- (const Vector2& rhs)
    {
        return Vector2 (x - rhs.x, y - rhs.y);
    }
    
    Vector2 operator* (const Vector2& rhs)
    {
        return Vector2 (x * rhs.x, y * rhs.y);
    }
    
    Vector2 operator/ (const Vector2& rhs)
    {
        return Vector2 (x / rhs.x, y / rhs.y);
    }
    
    template<typename rhs_T>
    Vector2 operator+ (const rhs_T& rhs)
    {
        return Vector2 (x + rhs, y + rhs);
    }
    
    template<typename rhs_T>
    Vector2 operator- (const rhs_T& rhs)
    {
        return Vector2 (x - rhs, y - rhs);
    }
    
    template<typename rhs_T>
    Vector2 operator* (const rhs_T& rhs)
    {
        return Vector2 (x * rhs, y * rhs);
    }
    
    template<typename rhs_T>
    Vector2 operator/ (const rhs_T& rhs)
    {
        return Vector2 (x / rhs, y / rhs);
    }
    
    bool operator== (const Vector2& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    
    bool operator!= (const Vector2& rhs) const
    {
        return !(rhs == *this);
    }
    
    bool operator< (const Vector2& rhs) const
    {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }
    
    bool operator> (const Vector2& rhs) const
    {
        return rhs < *this;
    }
    
    bool operator<= (const Vector2& rhs) const
    {
        return !(rhs < *this);
    }
    
    bool operator>= (const Vector2& rhs) const
    {
        return !(*this < rhs);
    }
    
    // vector specific mathematical operations
    
    
    double dot (const Vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    
    /// Returns magnitude ("length") of the vector.
    double magnitude () const
    {
        
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

// int_fast typedefs

typedef Vector2<int_fast8_t>        Vector2i8;
typedef Vector2<int_fast16_t>       Vector2i16;
typedef Vector2<int_fast32_t>       Vector2i32;
typedef Vector2<int_fast64_t>       Vector2i64;

// uint_fast typedefs

typedef Vector2<uint_fast8_t>       Vector2u8;
typedef Vector2<uint_fast16_t>      Vector2u16;
typedef Vector2<uint_fast32_t>      Vector2u32;
typedef Vector2<uint_fast64_t>      Vector2u64;
#endif //VECTOR2_HPP
