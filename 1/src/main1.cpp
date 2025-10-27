#include "main1.hpp"
#include <exception>

std::string getArticle()
{
    std::cout << "Enter an article: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) throw std::invalid_argument("empty articles name");
    return input;
}

int getQuantity()
{
    std::cout << "Enter the quantity: ";
    std::string input;
    std::getline(std::cin, input);
    int quantity = std::stoi(input);
    if (quantity < 0) throw std::invalid_argument("quantity less 0");
    return quantity;
}

void printMap(const std::map<std::string, int>& map)
{
    if (map.empty()) std::cout << "No goods found.\n";                        ////////////////
    for (const auto& item : map)
    {
        std::cout << item.first << "\t: " << item.second << "\n";
    }
    std::cout << std::endl;
}


void addArticleToCart(const std::string &article, const int quantity, std::map<std::string, int>& store, std::map<std::string, int>& cart)
{
    if (quantity < 0) throw std::invalid_argument("quantity less 0");
    auto it_store = store.find(article);
    if (it_store == store.end()) throw std::invalid_argument("article is not found");
    if (it_store->second < quantity) throw std::invalid_argument("requested quantity exceed the volume of reserves");

    it_store->second -= quantity;
    auto it_cart = cart.find(article);
    if (it_cart == cart.end()) cart.insert(std::make_pair(article, quantity));
    else it_cart->second += quantity;
    std::cout << article << " : " << quantity << " added to cart\n";
}

void removeArticleFromCart(const std::string& article, int quantity, std::map<std::string, int>& store, std::map<std::string, int>& cart)
{
    if (quantity < 0) throw std::invalid_argument("quantity < 0");
    auto it_cart = cart.find(article);
    if (it_cart == cart.end()) throw std::invalid_argument("article is not found in cart");
    if (it_cart->second < quantity) throw std::invalid_argument("quantity of goods in the cart less than you try to exclude");

    it_cart->second -= quantity;
    auto it_store = store.find(article);
    if (it_store == store.end()) store.insert(std::make_pair(article, quantity));
    else it_store->second += quantity;
    if (it_cart->second == 0) cart.erase(it_cart->first);
    std::cout << article << " : " << quantity << " removed from cart\n";
}

int main()
{
    std::map<std::string, int> store;
    std::map<std::string, int> store_cart;
    std::string article;
    int quantity;

    while (true)
    {
        try
        {
            std::cout << "Enter article or \'exit\' to finish store assortment input." <<std::endl;
            article = getArticle();
            if (article == "exit") break;
            quantity = getQuantity();
        }
        catch (const std::invalid_argument &x)
        {
            std::cerr << "Caught exception: " << x.what() << "\n";
            continue;
        }
        auto it = store.find(article);
        if (it == store.end()) store.insert(std::make_pair(article, quantity));
        else it->second += quantity;
    }
    std::cout << "\n******************************************************************\n\n";
    while (true)
    {
        std::cout << "Enter the command (add / remove / print / exit):\n";
        std::string command;
        //std::cin >> command;
        std::getline(std::cin, command);
        try
        {
            if (command == "exit") break;
            else if (command == "add")
            {
                std::string add_article = getArticle();
                int add_quantity = getQuantity();
                addArticleToCart(add_article, add_quantity, store, store_cart);
            }
            else if (command == "remove")
            {
                std::string rm_article = getArticle();
                int rm_quantity = getQuantity();
                removeArticleFromCart(rm_article, rm_quantity, store, store_cart);

            }
            else if (command == "print")
            {
                std::cout << "Store contents:\n";
                printMap(store);
                std::cout << "Cart contents:\n";
                printMap(store_cart);
            }
            else continue;
        }
        catch (const std::exception &x)
        {
            std::cerr << "Caught exception: " << x.what() << "\n";
        }
        catch (...)
        {
            std::cerr << "An exception has occurred.\n";
        }
    }
    return 0;
}