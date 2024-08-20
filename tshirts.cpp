#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    // Test boundary values and some out-of-bounds values
    assert(size(37) == 'S');
    assert(size(38) == 'M');  // This test is meant to fail
    assert(size(40) == 'M');
    assert(size(42) == 'M');  // This test is meant to fail
    assert(size(43) == 'L');
    assert(size(50) == 'L');  // This test is meant to fail
    std::cout << "All is well (maybe!)\n";
    return 0;
}
