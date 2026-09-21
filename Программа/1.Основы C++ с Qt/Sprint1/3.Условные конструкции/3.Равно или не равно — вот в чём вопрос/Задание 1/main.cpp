#include <iostream>

int main() {
    int first, second, fird;
    std::cin >> first >> second >> fird;

    int max = first;
    if (second > max) { 
        max = second; 
    }
    if (fird > max) { 
        max = fird; 
    }

    int min = first;
    if (second < min) { 
        min = second; 
    }
    if (fird < min) { 
        min = fird; 
    }

    std::cout << min << " " << max << std::endl;
    return 0;
}