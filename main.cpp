#include <iostream>
#include <algorithm>
#include <cstring>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        if(n == 1)
            return "1";
        std::string num = countAndSay(n - 1);
        std::string new_num;
        while(!num.empty())
        {
            char temp = *num.begin();
            auto it = std::remove(num.begin(), num.end(), temp);
            size_t count = std::distance(it, num.end());
            new_num += std::to_string(count) + temp;
            num.erase(it, num.end());
        }
        return new_num;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    try
    {
        if(argc > 1)
        {
            int num = std::stoi(argv[1]);
            if(num < 1)
                throw std::logic_error("Number must be more than 0");
            std::cout << sol.countAndSay(num) << "\n";
        }
    }
    catch(const std::exception & except)
    {
        std::cout << "ERROR: " << except.what() << "\n";
    }
    
}