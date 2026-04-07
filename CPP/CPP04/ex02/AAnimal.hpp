
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &copy);
        virtual ~AAnimal();
        std::string getType() const;
        virtual void makeSound() const = 0;
    protected:
        std::string _type;

};

#endif
