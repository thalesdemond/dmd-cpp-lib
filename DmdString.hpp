#include <iostream>
#include <cstring>
#include <cstddef>
#include <array>

namespace Dmd
{

template <size_t S>
struct string
{
    ~string()
    {
        printf("(-1)");
    }

    string() : v{""} , size(0)
    {
        printf("1->");
    }

    template<size_t S1>
    string(const char (&s)[S1]) : v{""} , size(std::min(S, S1))
    {
        printf("2->");
        snprintf(v.data(), S, "%s", s);
    }

    string(const string<S>& other) : v(other.v), size(S)
    {
        printf("3->");
    }

    string<S>& operator=(const string<S>& s)
    {
        printf("4->");
        v = s.v;
        size = s.size;
        return *this;
    }

    string(const string<S>&& other)
    : v(std::move(other.v)), size(std::move(other.size))
    {
        printf("5->");
    }

    template<size_t S1>
    operator string<S1> ()
    {
        char temp0[S1];   
        printf("(converte %i to %i)->", S, S1);     
        snprintf(temp0, S1, "%s", v.data());
        return (temp0);
    }

    const char* c_str() const
    {
        return (v.data());
    }

    string<S> operator+(const string<S>& other) const
    {
        char temp0[S];
        snprintf(temp0, S, "%s%s", v.data(), other.v.data());
        return temp0;
    }

    string<S>& operator+=(const string<S>& other)
    {
        *this = *this + other;
        return (*this);
    }
private:
    std::array<char, S> v;
    size_t size;
};

template <size_t S>
string<S> toString(int n)
{
    char saida[S];
    snprintf(saida, S, "%i", n);
    return saida;
}

template <size_t S>
string<S> toString(long n)
{
    char saida[S];
    snprintf(saida, S, "%i", n);
    return saida;
}

template <size_t S>
string<S> toString(float n)
{
    char saida[S];
    snprintf(saida, S, "%f", n);
    return saida;
}

template <size_t S>
string<S> toString(double n)
{
    char saida[S];
    snprintf(saida, S, "%lf", n);
    return saida;
}

template <size_t S>
constexpr string<S> makestring(const char (&s)[S])
{
    return s;
}

}
