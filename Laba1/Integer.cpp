#include "Integer.h"
#include <iostream>
#include <string>
using namespace arbitary_precision_arithmetic;

Integer::Integer() {
    this->numbers = new unsigned long long[size]{0};
    sign = 1;
}

Integer::Integer(const Integer& digit) {
    this->numbers = new unsigned long long[digit.size];
    for (int i = 0; i < digit.size; i++) {
        this->numbers[i] = digit.numbers[i];
    }
    sign = digit.sign;
}

Integer::Integer(short a) : Integer::Integer() {
    this->numbers[0] = a;
    this->sign = 1 ? a >= 0: -1;
}

Integer::Integer(unsigned short a) : Integer::Integer() {
    this->numbers[0] = a;
}

Integer::Integer(long long a) : Integer::Integer() {
    this->numbers[0] = a;
    this->sign = 1 ? a >= 0 : -1;
}

Integer::Integer(int a) : Integer::Integer() {
    this->numbers[0] = a;
    this->sign = 1 ? a >= 0 : -1;
}

Integer::Integer(unsigned long long a) : Integer::Integer() {
    this->numbers[0] = a;
}

Integer::Integer(unsigned int a) : Integer::Integer() {
    this->numbers[0] = a;
}

Integer::Integer(char a) : Integer::Integer() {
    this->numbers[0] = (unsigned long long)a;
}

Integer::Integer(unsigned char a) : Integer::Integer() {
    this->numbers[0] = (unsigned long long)a;
}

Integer::Integer(long a) : Integer::Integer() {
    this->numbers[0] = a;
    this->sign = 1 ? a >= 0 : -1;
}

Integer::Integer(unsigned long a) : Integer::Integer() {
    this->numbers[0] = a;
}

Integer& Integer::operator=(const Integer& digit)
{
    delete[] this->numbers;
    this-> numbers = new unsigned long long[digit.size];
    for (int i = 0; i < digit.size; ++i) {
        numbers[i] = digit.numbers[i];
    }
    sign = digit.sign;
    return *this;
}

Integer& Integer::operator+=(const Integer& digit)
{
    if (this->size < digit.size)
    {
        unsigned long long* a = new unsigned long long[digit.size];
        for (int i = 0; i < this->size; i++)
        {
            a[i] = this->numbers[i];
        }
        this->size = digit.size;
        delete[] this->numbers;
        this->numbers = a;
    }
    if (this->sign == digit.sign) {
        for (int i = 0; i < size; i++) {
            this->numbers[i] += digit.numbers[i];
        }
        for (int i = 0; i < size - 1; i++)
        {
            if (this->numbers[i] >= BASE_DIGIT) {
                this->numbers[i] -= BASE_DIGIT;
                this->numbers[i + 1]++;
            }
        }
        if (this->numbers[size - 1] >= BASE_DIGIT) {
            unsigned long long* a = new unsigned long long[this->size + 1];
            for (int i = 0; i < this->size; i++)
            {
                a[i] = this->numbers[i];
            }
            this->size = size + 1;
            delete[] this->numbers;
            this->numbers = a;
            this->numbers[size - 2] -= BASE_DIGIT;
            this->numbers[size - 1] += 1;
        }
        return *this;
    }
    else
    {
        this->sign = *this < digit ? -1 : 1;
        for (int i = 0; i < this->size; i++) {
            this->numbers[i] -= digit.numbers[i];
        }

        for (int i = 0; i < this->size-1; i++) {
            if (this->numbers[i] < 0) {
                this->numbers[i] += BASE_DIGIT;
                this->numbers[i + 1]--;
            }
        }
        return *this;
    }
}

Integer Integer::operator+() const {
    return *this;
}

Integer Integer::operator+(const Integer& digit) const {
    Integer a(*this);
    a += digit;
    return a;
}

Integer& Integer::operator-=(const Integer& digit) {
    if (*this < digit)
    {
        this->sign = -1;
    }
    else
    {
        this->sign = 1;
    }

    if (this->size < digit.size)
    {
        unsigned long long* a = new unsigned long long[digit.size];
        for (int i = 0; i < this->size; i++)
        {
            a[i] = this->numbers[i];
        }
        this->size = digit.size;
        delete[] this->numbers;
        this->numbers = a;
    }
    if (this->sign == digit.sign) {
        for (int i = 0; i < size; i++) {
            this->numbers[i] -= digit.numbers[i];
        }

        for (int i = 0; i < size; i++) {
            if (this->numbers[i] < 0) {
                this->numbers[i] += BASE_DIGIT;
                this->numbers[i + 1]--;
            }
        }
        return *this;
    }
    else {
        return *this += digit;
    }
}

Integer Integer::operator-(const Integer& digit) const {
    Integer a(*this);
    a -= digit;
    return a;
}

Integer Integer::operator-() const {
    Integer a(*this);
    a.sign = -a.sign;
    return a;
}

Integer& Integer::operator++() {
    Integer a(1);
    *this += a;
    return *this;
}

Integer Integer::operator++(int) {
    Integer a(1);
    *this += a;
    return *this;
}

Integer& Integer::operator--() {
    Integer a(1);
    *this -= a;
    return *this;
}

Integer Integer::operator--(int) {
    Integer a(1);
    *this -= a;
    return *this;
}

Integer::~Integer()
{
    delete[] numbers;
}

Integer Integer::operator*(const Integer& digit) const {
    Integer a(*this);
    a *= digit;
    return a;
}

Integer& Integer::operator*=(const Integer& digit)
{
    Integer& res(*this);
    res.sign = this->sign == digit.sign ? 1 : -1;
    /*unsigned long long* a = new unsigned long long[res.size + digit.size];
    for (int i = 0; i < res.size; i++)
    {
        a[i] = res.numbers[i];
    }
    res.size = res.size + digit.size;
    delete[] res.numbers;
    res.numbers = a;*/
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < digit.size; j++) {
            res.numbers[i + j] = this->numbers[i] * digit.numbers[j];
        }
    }
    for (int i = 0; i < res.size - 1; i++) {
        res.numbers[i + 1] += res.numbers[i] / BASE_DIGIT;
        res.numbers[i] %= BASE_DIGIT;
    }

    return res;
}

bool Integer::operator==(const Integer& digit) const {
    if (this->sign != digit.sign)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (this->numbers[i] != digit.numbers[i])
            {
                return false;
            }
        }
        return true;
    }
}

bool Integer::operator!=(const Integer& digit) const {
    if (this->sign != digit.sign)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (this->numbers[i] != digit.numbers[i])
            {
                return true;
            }
        }
        return false;
    }
}

bool Integer::operator<(const Integer& digit) const {
    if (this->sign < digit.sign)
    {
        return true;
    }
    else if((this->sign > digit.sign))
    {
        return false;
    }
    else
    {
        if (this->sign < 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] > digit.numbers[i])
                {
                    return true;
                }
                else if(this->numbers[i] < digit.numbers[i])
                {
                    return false;
                }
            }
            return false;
        }
        if (this->sign > 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] > digit.numbers[i])
                {
                    return false;
                }
                else if (this->numbers[i] < digit.numbers[i])
                {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
}

bool Integer::operator>(const Integer& digit) const {
    if (this->sign > digit.sign)
    {
        return true;
    }
    else if ((this->sign < digit.sign))
    {
        return false;
    }
    else
    {
        if (this->sign < 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] < digit.numbers[i])
                {
                    return true;
                }
                else if (this->numbers[i] > digit.numbers[i])
                {
                    return false;
                }
            }
            return false;
        }
        if (this->sign > 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] < digit.numbers[i])
                {
                    return false;
                }
                else if (this->numbers[i] > digit.numbers[i])
                {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

bool Integer::operator<=(const Integer& digit) const {
    if (this->sign < digit.sign)
    {
        return true;
    }
    else if ((this->sign > digit.sign))
    {
        return false;
    }
    else
    {
        if (this->sign < 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] > digit.numbers[i])
                {
                    return true;
                }
                else if (this->numbers[i] < digit.numbers[i])
                {
                    return false;
                }
            }
            return true;
        }
        if (this->sign > 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] > digit.numbers[i])
                {
                    return false;
                }
                else if (this->numbers[i] < digit.numbers[i])
                {
                    return true;
                }
            }
            return true;
        }
        return true;
    }
    return true;
}

bool Integer::operator>=(const Integer& digit) const {
    if (this->sign > digit.sign)
    {
        return true;
    }
    else if ((this->sign < digit.sign))
    {
        return false;
    }
    else
    {
        if (this->sign < 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] < digit.numbers[i])
                {
                    return true;
                }
                else if (this->numbers[i] > digit.numbers[i])
                {
                    return false;
                }
            }
            return true;
        }
        if (this->sign > 0)
        {
            for (int i = this->size - 1; i >= 0; i--)
            {
                if (this->numbers[i] < digit.numbers[i])
                {
                    return false;
                }
                else if (this->numbers[i] > digit.numbers[i])
                {
                    return true;
                }
            }
            return true;
        }
        return true;
    }
    return true;
}

Integer::operator bool() const {
    Integer a(0);
    if (*this == a)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Integer::operator char() const {
    return static_cast<char>(this->numbers[0]) ? this->sign > 0: -static_cast<char>(this->numbers[0]);
}

Integer::operator char unsigned() const {
    int i = static_cast<unsigned int>(this->numbers[0]);
    return static_cast<unsigned char>(i);
}

Integer::operator short unsigned int() const {
    return static_cast<unsigned short>(this->numbers[0]);
}

Integer::operator short int() const {
    return static_cast<short>(this->numbers[0]) ? this->sign > 0: -static_cast<short>(this->numbers[0]);
}

Integer::operator unsigned int() const {
    return static_cast<unsigned int>(this->numbers[0]);
}

Integer::operator int() const {
    return static_cast<int>(this->numbers[0]) ? this->sign > 0: -static_cast<int>(this->numbers[0]);
}

Integer::operator long unsigned int() const {
    return static_cast<unsigned long>(this->numbers[0]);
}

Integer::operator long int() const {
    return static_cast<long>(this->numbers[0]) ? this->sign > 0: -static_cast<long>(this->numbers[0]);
}

Integer::operator long long unsigned int() const {
    return static_cast<unsigned long long>(this->numbers[0]);
}

Integer::operator long long int() const {
    return static_cast<long long>(this->numbers[0]) ? this->sign > 0: -static_cast<long long>(this->numbers[0]);
}