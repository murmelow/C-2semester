// 1)Определить объект Date как класс и включить в него методы а)подсчета количества дней между двумя датами, б) определения даты +/- N дней.
// 2)Определить объект комплексные числа как класс и включить в него методы сложения, умножения, вычитания и деления комплексных чисел. (без переопределения операторов).

#include <iostream>

class Date {
    private:
        int m_day;
        int m_month;
        int m_year;

        static bool isLeap(int y) {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        }

        static int daysMonth(int m, int y) {
            static int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
            if (m == 2 && isLeap(y)) return 29;
            return days[m - 1];
        }

        // Из даты в кол-во дней
        static long toDays(int d, int m, int y) {
            long days = d;

            for (int year = 1; year < y; ++year) {
                days += isLeap(year) ? 366 : 365;
            }

            for (int month = 1; month < m; ++month) {
                days += daysMonth(month, y);
            }

            return days;
        }

        // Из кол-ва дней в дату
        static Date fromDays(long days) {
            int y = 1;
            while(true) {
                int dy = isLeap(y) ? 366 : 365;
                if (days > dy) {
                    days -= dy;
                    ++y;
                }
                else break;
            }

            int m = 1;
            while(true) {
                int dm = daysMonth(m, y);
                if(days > dm) {
                    days -= dm;
                    ++m;
                }
                else break;
            }

            return Date((int)days, m, y);
        }

    public:
        Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y) {}

        void print() const {
            std::cout << m_day << "/" << m_month << "/" << m_year << '\n';
        }

        // а) Разница в днях
        static long daysBetween(const Date& a, const Date& b) {
            return std::labs(toDays(a.m_day, a.m_month, a.m_year) - toDays(b.m_day, b.m_month, b.m_year));
        }

        // б) Дата +/- N дней
        Date addDays(long n) const {
            long total = toDays(m_day, m_month, m_year);
            total += n;
            return fromDays(total);
        }
};

class Complex {
    private:
        double re;
        double im;
    public:
        Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

        void print() const {
        std::cout << re
                  << (im >= 0 ? " + " : " - ")
                  << std::abs(im) << "i\n";
        }
        
        // Сложение
        Complex add(const Complex& other) const {
            return Complex(re + other.re, im + other.im);
        }

        // Вычитание
        Complex sub(const Complex& other) const {
            return Complex(re - other.re, im - other.im);
        }

        // Умножение
        Complex mul(const Complex& other) const {
            return Complex(
                re * other.re - im * other.im,
                re * other.im + im * other.re
            );
        }

        // Деление
        Complex div(const Complex& other) const {
            double denom = other.re * other.re + other.im * other.im;

            return Complex(
                (re * other.re + im * other.im) / denom,
                (im * other.re - re * other.im) / denom
            );
        }
};

int main() {

    // Date
    Date d1(12, 11, 2018);
    Date d2(1, 4, 2026);

    std::cout << "Days between: "
              << Date::daysBetween(d1, d2) << "\n";

    Date future = d1.addDays(1000);
    future.print();

    Date past = d1.addDays(-500);
    past.print();

    // Complex
    Complex a(4, 3);
    Complex b(2, -1);

    Complex c1 = a.add(b);
    Complex c2 = a.sub(b);
    Complex c3 = a.mul(b);
    Complex c4 = a.div(b);

    c1.print();
    c2.print();
    c3.print();
    c4.print();
}