
        cardNumber += 1;
        result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if (result % 10 == 0) {
        std::cout << cardNumber << "\n";
    } else {
        std::cout << "*******************" << cardNumber;
    }
    }