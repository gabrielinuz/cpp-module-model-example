#ifndef LOGGEABLE_H
#define LOGGEABLE_H
#pragma once

#include<iostream>
#include<memory>
#include<Logger.hpp>

using namespace std;

class Loggeable
{
    public:
        virtual void setLogger(shared_ptr<Logger>) = 0;
};

#endif