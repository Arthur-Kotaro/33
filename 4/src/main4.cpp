#include "main4.hpp"

template <typename T>
void getValues(T* array, int length)
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter " << length << " values.\n";
    std::string input;
    for (int i = 0; i < length; ++i)
    {
        std::cout << "Enter value " << i+1 << " of " << length << " : ";
        std::getline(std::cin, input);
        try
        {
            if (std::is_same<T, int>())
            {
                array[i] = std::stoi(input);
            }
            if (std::is_same<T, long>())
            {
                array[i] = std::stol(input);
            }

            else if (std::is_same<T, float>())
            {
                array[i] = std::stof(input);
            }
            else if (std::is_same<T, double>())
            {
                array[i] = std::stod(input);
            }
        }
        catch (...)
        {
            std::cerr << "Incorrect type. Try again.\n";
            --i;
        }
    }
}


template <typename T>
T CalculateAverage(T* arr, int len)
{
    T sum = 0;
    for (int i = 0; i < len; ++i) sum += *(arr + i);
    return sum / len;
}

int main()
{
    unsigned int length;
    std::cout << "Enter size of array: ";
    std::cin >> length;
    int *int_arr = {new int[length]};
    std::cout << "(int numbers) ";
    getValues( int_arr, length);
    int intAverage = CalculateAverage( int_arr, length);
    delete [] int_arr;
    std::cout << "Average of arrays values: " << intAverage << std::endl;

    std::cout << "Enter size of array: ";
    std::cin >> length;
    float *float_arr = {new float[length]};
    std::cout << "(float numbers) ";
    getValues( float_arr, length);
    float floatAverage = CalculateAverage( float_arr, length);
    delete [] float_arr;
    std::cout << "Average of arrays values: " << floatAverage << std::endl;
    return 0;
}