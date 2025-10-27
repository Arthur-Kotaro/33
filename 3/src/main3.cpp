#include "main3.hpp"
//#define DEBUG

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::add(Data<KeyType, ValueType> inData)
{
    data.push_back(inData);
}

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::add(KeyType inKey, ValueType inValue)
{
    Data<KeyType, ValueType> inData;
    inData.key = inKey;
    inData.value = inValue;
    data.push_back(inData);
}

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::remove(KeyType inKey)
{
    bool foundAndDeleted = false;
    for (auto iter = data.begin(); iter < data.end(); ++iter)
    {
        if(iter->key == inKey)
        {
            data.erase(iter);
            foundAndDeleted = true;
        }
    }
    std::cout << "Object " << inKey;
    if(foundAndDeleted) std::cout << " deleted.\n";
    else                std::cout << " not found.\n";
}

template<typename KeyType, typename ValueType>
Data<KeyType, ValueType> * Registry<KeyType, ValueType>::find(KeyType inKey)
{
    if(data.empty())
    {
        std::cout << "Registry is empty.\n";
        return nullptr;
    }
    else
    {
        for (auto iter = 0; iter < data.size(); ++iter)
        {
            if(data[iter].key == inKey) return &data[iter];
        }
        return nullptr;
    }
}

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::print()
{
    if(data.empty()) std::cout << "Registry is empty.\n";
    else
    {
        std::cout << "Registry Contents:\n";
        for (auto iter = data.begin(); iter < data.end(); ++iter)
        {
            std::cout << iter->key << " : " << iter->value << std::endl;
        }
    }
}





int main()
{
    Registry<std::string, int> reg_str_int;
    Registry<std::string, std::string> reg_str_str;
    Registry<float, int> reg_float_int;

    std::cout << "\n\nAdd pairs \"apples : 10\" and \"citizens : 696438\" to reg_str_int\n";
    reg_str_int.add("apples", 10);
    reg_str_int.add("citizens", 696438);
    reg_str_int.print();
    std::cout << "\n\nRemove \"apples\" from reg_str_int\n";
    reg_str_int.remove("apples");
    reg_str_int.print();


    std::cout << "\n\nAdd pairs \"Cat : Vasya\" and \"writer : Lovecraft\" to reg_str_str\n";
    reg_str_str.add("Cat", "Vasya");
    reg_str_str.add("writer", "Lovecraft");
    reg_str_str.print();
    std::cout << "\n\nRemove \"Cat\" from reg_str_str\n";
    reg_str_str.remove("Cat");
    reg_str_str.print();


    std::cout << "\n\nAdd pairs \"36.6 : 5\" and \"5.56 : 11\" to reg_float_int\n";
    reg_float_int.add(36.6, 5);
    reg_float_int.add(5.56, 11);
    reg_float_int.print();
    std::cout << "\n\nAdd pair \"36.6 : 5\" to reg_float_int once more\n";
    reg_float_int.add(36.6, 5);
    reg_float_int.print();
    std::cout << "\n\nRemove \"5.56\" from reg_str_str\n";
    reg_float_int.remove(5.56);
    reg_float_int.print();


    return 0;
}
