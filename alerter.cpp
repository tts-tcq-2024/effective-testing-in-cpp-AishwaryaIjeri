#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Simulate always returning a failure
    return 500;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1; // Increment on failure
    }
}

void testAlertFailureHandling() {
    alertFailureCount = 0; // Reset before testing

    // Call with values to simulate a failure
    alertInCelcius(100.0);
    alertInCelcius(200.0);

    // Expected failure count due to simulated failures
    assert(alertFailureCount == 2); // This test is meant to fail
}

int main() {
    testAlertFailureHandling();
    std::cout << "All tests passed!\n";
    return 0;
}
