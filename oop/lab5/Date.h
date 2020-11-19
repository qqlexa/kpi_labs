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

    Date(Date&);
    Date(Date*);

    int getYear();
    void setYear(int);

    int getMonth();
    void setMonth(int);

    int getDay();
    void setDay(int);

    void setDate(int, int, int);
    
    Date& getDate();

    // virtual void show() = 0;
};

