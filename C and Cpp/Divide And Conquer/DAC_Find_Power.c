// finding the power of value using devide and conquer;

#include <stdio.h>

int power (int x, unsigned int y) {
    if (x == 0)
        return 0;

    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return (power(x, y/2) * power (x, y/2));
    else
        return (x * power(x, y/2) * power (x, y/2));
}

float extendedPower (float x, int y) {
    if (x == 0)
        return 0;
    
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return (extendedPower(x, y/2) * extendedPower(x, y/2));
    else{
        if (y > 0)
            return (x * extendedPower(x, y/2) * extendedPower(x, y/2));
        else
            return (extendedPower(x, y/2) * extendedPower(x, y/2))/x;
    }
}

int main (){
    printf("%d \n", power(2, 3));
    printf("%.4f \n", extendedPower(2, 3));
    printf("%.4f \n", extendedPower(2, -3));
    
    return 0;
}