#include <iostream>
#include <string>
using namespace std;

//it store only 3 things title,language,duration
class Movie{
private:
    string title;
    string language;
    int duration;

public:
    // Constructor to initialize movie details
    Movie(string title, string language, int duration)
    {
        this->title = title;
        this->language = language;
        this->duration = duration;
    }

    // Returns movie title
    string getTitle()
    {
        return title;
    }

    // Returns movie language
    string getLanguage()
    {
        return language;
    }

    // Returns movie duration
    int getDuration()
    {
        return duration;
    }
};