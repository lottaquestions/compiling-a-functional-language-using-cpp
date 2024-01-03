#include "error.hpp"

const char* type_error::what() const noexcept{
    return "an error occured when checking the types of the program";
}