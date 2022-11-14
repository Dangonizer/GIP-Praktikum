#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
using namespace std;
person extract_data(string eingabezeile)
{
    person data;
    for (int i = 0, count = 0; i < eingabezeile.length(); i++)
    {
        if (eingabezeile.at(i) != ',')
        {
            if (count == 0)
                data.nachname += eingabezeile.at(i);
            else if (count == 1)
                data.vorname += eingabezeile.at(i);
            else
                data.datum += eingabezeile.at(i);
        }
        else
        {
            count += 1;
        }
    }
    return data;
}
string trimme(string data)
{
    string helper = "";
    for (int i = 0; i < data.length(); i++)
    {
        if (data.at(i) != ' ')
            helper += data.at(i);
    }
    data = helper;
    return data;
}
void shorttext(string &kurztext, person p)
{
    kurztext += "<b>" + p.nachname + "</b>, " + p.vorname + "<br/>\n";
}
void longtext(string &langtext, person p)
{
    langtext += "<b>" + p.vorname + " " + p.nachname + "</b>, " + p.datum + "<br/>\n";
}
string replace(string input, char replace, string text)
{
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input.at(i) != replace)
            output += input.at(i);
        else
            output += text;
    }
    return output;
}
int main()
{
    string eingabezeile = "", kurztext = "", langtext = "";
    fstream daten("personendaten.txt", ios::in);
    while (bool(getline(daten, eingabezeile)))
    {
        person result = extract_data(eingabezeile);
        result.vorname = trimme(result.vorname);
        result.datum = trimme(result.datum);
        shorttext(kurztext, result);
        longtext(langtext, result);
    }
    fstream website_tmpl("webseite.html.tmpl", ios::in);
    fstream website("webseite.html", ios::out);
    while (bool(getline(website_tmpl, eingabezeile)))
    {
        eingabezeile = replace(eingabezeile, '%', kurztext);
        eingabezeile = replace(eingabezeile, '$', langtext);
        website << eingabezeile << endl;
    }
}