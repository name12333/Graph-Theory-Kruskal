#pragma once
#include<iostream>
#include<string>

class Logger{
public:
    static void log(const std::string& msg);
    static void result(const std::string& msg);
};