#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>

class RPN
{
    public:
        RPN(void);
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);
        ~RPN();
};

#endif

