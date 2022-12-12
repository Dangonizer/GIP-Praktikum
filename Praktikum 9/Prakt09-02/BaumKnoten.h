#pragma once
class BaumKnoten
{
private:
    int data;
    BaumKnoten *links;
    BaumKnoten *rechts;

public:
    int get_data()
    {
        return data;
    }
    void set_data(int value)
    {
        data = value;
        return;
    }
    BaumKnoten *get_links()
    {
        return links;
    }
    void set_links(BaumKnoten *value)
    {
        links = value;
        return;
    }
    BaumKnoten *get_rechts()
    {
        return rechts;
    }
    void set_rechts(BaumKnoten *value)
    {
        rechts = value;
        return;
    }
    BaumKnoten(int d, BaumKnoten *l, BaumKnoten *r) : data{d}, links{l}, rechts{r} {}
    int ausgeben(unsigned int tiefe);
};