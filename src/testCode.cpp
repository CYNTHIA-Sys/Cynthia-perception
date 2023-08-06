#include "cynthia-perception/core.h"

int main(int, char**)
{
    cy::mat window("Test Window", 800, 600);
    if(window.create_window())
    {
        window.run();
    }
    return 0;
}