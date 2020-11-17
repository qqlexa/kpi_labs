#pragma once
class Date
{
private:
	int year_;
	int month_;
	int day_;
public:
    Date();
    Date(int, int, int);

    int getYear();
    void setYear(int);

    int getMonth();
    void setMonth(int);

    int getDay();
    void setDay(int);

    void set(int, int, int);

    // virtual void show() = 0;
};

