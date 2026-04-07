
#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog constuctor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    _type = copy._type;
    std::cout << "Dog copy constuctor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if ( this != &copy )
    {
        Animal::operator=(copy);
        _type = copy._type;
    }
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
