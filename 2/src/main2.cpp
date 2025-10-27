#include "main2.hpp"

const int bootsNum = 3;



class fishExc: public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Congratulations! You win!";
    }
};


class bootExc: public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Wow! It looks like you have got a boot! Successful wearing of the boot. Game over.";
    }
};

enum State
{
    empty, fish, boot, checked
};


void showLake(const State (&field)[])
{
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "-------------------\n";
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "|  ";
            if (*(field + (i * 3) + j) == empty) std:: cout << 'x' << "  ";
            else if (*(field + (i * 3) + j) == fish) std:: cout << 'f' << "  ";
            else std:: cout << 'b' << "  ";
        }
        std::cout << "|\n";
    }
    std::cout << "-------------------\n";
    std::cout << "f - fish\n";
    std::cout << "b - boot\n";
    std::cout << "x - empty\n";
}

void showCheckLake(const State (&field)[])
{
    std::cout << "\n      A     B     C\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "   -------------------\n";
        std::cout << i + 1 << "  ";
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "|  ";
            if (*(field + (i * 3) + j) == checked) std:: cout << 'x' << "  ";
            else std:: cout << '?' << "  ";
        }
        std::cout << "|\n";
    }
    std::cout << "   -------------------\n";
}

void lineCasting(State (&field)[])
{
    unsigned int position = 0;
    std::string input;
    while (true)
    {
        std::cout << "Choose position in format LETTER+NUMBER. For example \"A3\" : ";
        std::cin >> input;
        if(input[0] < 'A' || input[0] > 'C') continue;
        if(input[1] < '1' || input[1] > '3') continue;
        break;
    }
    position = (3 * (input[1] - '1') ) + input[0] - 'A';


    if (field[position] == fish) throw fishExc();
    else if (field[position] == boot) throw bootExc();
    else field[position] = checked;
}


int main()
{
    srand(std::time(nullptr));
    State field[9] {empty};
    int position = 0;

    position = std::rand() % 9;
    field[position] = State::fish;
    for (int i = 0; i < bootsNum; ++i)
    {
        while(true)
        {
            position = std::rand() % 9;
            if (field[position] == State::empty)
            {
                field[position] = State::boot;
                break;
            }
        }
    }
    //showLake(field);

    std::cout << std::endl << std::endl;

    showCheckLake(field);
    int movesNumber = 0;
    while (true)
    {
        movesNumber++;
        try
        {
            lineCasting(field);
        }
        catch (const fishExc &x)
        {
            std::cout << x.what() << " Turns number equals to " << movesNumber << std::endl;
            break;
        }
        catch (const bootExc &x)
        {
            std::cout << x.what() << std::endl;
            break;
        }
        showCheckLake(field);
    }
    showLake(field);
    return 0;
}
