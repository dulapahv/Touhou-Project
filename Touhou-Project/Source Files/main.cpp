#include "touhou_project.h"

int main(void) {
    touhou_project *game = new touhou_project();
    delete(game);

    return 0;
}