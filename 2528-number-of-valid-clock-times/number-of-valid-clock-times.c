int countTime(char* time) {
    int hours = 1, minutes = 1;

    // Check hours possibilities
    if (time[0] == '?' && time[1] == '?') {
        hours = 24;
    } else if (time[0] == '?') {
        if (time[1] >= '0' && time[1] <= '3') {
            hours = 3; // 0 to 2
        } else {
            hours = 2; // 0 to 1
        }
    } else if (time[1] == '?') {
        if (time[0] == '2') {
            hours = 4; // 0 to 3
        } else {
            hours = 10; // 0 to 9
        }
    }

    // Check minutes possibilities
    if (time[3] == '?' && time[4] == '?') {
        minutes = 60;
    } else if (time[3] == '?') {
        minutes = 6; // 0 to 5
    } else if (time[4] == '?') {
        minutes = 10; // 0 to 9
    }

    return hours * minutes;
}