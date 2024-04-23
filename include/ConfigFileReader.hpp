#ifndef CONFIGFILEREADER_H
#define CONFIGFILEREADER_H

#pragma once

class ConfigFileReader
{
    public:
        virtual bool open( string fileName ) = 0;
        virtual string getValueOf( string key ) = 0;
};

#endif