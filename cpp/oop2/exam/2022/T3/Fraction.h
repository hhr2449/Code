#pragma once
#include <bits/stdc++.h>
using namespace std;
class Fraction {
    public:
        long long up, down;
        Fraction(long long f) {
            this->up = f;
            this->down = 1;
        }
        Fraction() {}
        long long gcd(long long a, long long b){//求解最大公约数
            return b ? gcd(b, a % b) : a;
        }
        Fraction operator+(Fraction f) {
            Fraction res;
            res.up = this->up*f.down + this->down*f.up;
            res.down = this->down*f.down;
            long long g = gcd(res.up, res.down);
            res.up/=g;
            res.down/=g;
            return res;
        }
        Fraction operator-(Fraction f) {
            Fraction res;
            res.up = this->up*f.down - this->down*f.up;
            res.down = this->down*f.down;
            long long g = gcd(res.up, res.down);
            res.up/=g;
            res.down/=g; 
            return res;
        }
        Fraction operator*(Fraction f) {
            Fraction res;
            res.up = this->up*f.up;
            res.down = this->down*f.down;
            long long g = gcd(res.up, res.down);
            res.up/=g;
            res.down/=g; 
            return res;
        }
        Fraction operator/(Fraction f) {
            Fraction res;
            res.up = this->up*f.down;
            res.down = this->down*f.up;
            long long g = gcd(res.up, res.down);
            res.up/=g;
            res.down/=g; 
            return res;
        }
        Fraction& operator=(Fraction f) {
            this->up = f.up;
            this->down = f.down;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
            if(f.down == 1) {
                out << f.up;
                return out;
            }
            out << f.up << '/' << f.down ;
            return out;
        }
};