#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Cinema represents the theatre.
// Composition: Cinema owns its screens.
class Cinema
{
private:
    string name;
    vector<Screen> screens;

public:
    // Constructor
    Cinema(string name)
    {
        this->name = name;
    }

    // Add a screen
    void addScreen(Screen screen)
    {
        screens.push_back(screen);
    }

    // Get cinema name
    string getName()
    {
        return name;
    }

    // Get screens
    vector<Screen>& getScreens()
    {
        return screens;
    }
};