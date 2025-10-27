#pragma once
#include <iostream>
//#include <string>
#include <vector>

template<typename KeyType, typename ValueType>
struct Data
{
public:
    KeyType key;
    ValueType value;
    Data(){};
    Data(KeyType inKey, ValueType inValue): key(inKey), value(inValue) {};
};

template<typename KeyType, typename ValueType>
class Registry
{
    std::vector<Data<KeyType, ValueType>> data;
public:
    void add(Data<KeyType, ValueType> inData);
    void add(KeyType inKey, ValueType inValue);
    void remove(KeyType inKey);
    void print();
    Data<KeyType, ValueType> * find(KeyType inKey);
};