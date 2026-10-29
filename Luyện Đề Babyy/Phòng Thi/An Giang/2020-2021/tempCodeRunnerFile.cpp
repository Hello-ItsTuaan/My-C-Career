

    for (char j : cleanedChuoi1Va2) {
        if (isupper(j)) {
            upper.push_back(j);
        } else {
            lower.push_back(j);
        }
    }

    for (char i : upper) {
        std::cout << i;
    }

    for (char i : lower) {
        std::cout << i;
    }


    return 0;