// File "Vector2.hpp" created April 2019
// Copyright (c) Lion Kortlepel 2019
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <ostream>

/// Represents a 2D vector with two elements of type T and implements
/// all common operations associated with it.
template<typename T>
class Vector2
{
public:
    /// Vector2 with both elements set to 1.0.
    static const Vector2 one = Vector2 (1.0, 1.0);
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

#endif //VECTOR2_HPP
