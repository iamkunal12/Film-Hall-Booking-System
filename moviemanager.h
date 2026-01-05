#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include <map>
#include <QString>

class MovieManager
{
public:
    static std::map<QString, bool> movieAvailable;  // only declaration
};

#endif
