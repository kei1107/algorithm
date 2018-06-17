ostream &operator<<(ostream &os, __int128_t value) {
    if (ostream::sentry(os)) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[64];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(ios_base::badbit);
        }
    }
    return os;
}

istream &operator>>(istream &is, __int128_t &value) {
    string in;
    is >> in;
    value = 0;
    for (const char &c : in) {
        if ('0' <= c && c <= '9') value = 10 * value + (c - '0');
    }
    if (in[0] == '-') value *= -1;
    return is;
}

// ==========================================================

ostream &operator<<(ostream &os, __uint128_t value) {
    if (ostream::sentry(os)) {
        char buffer[64];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[value % 10];
            value /= 10;
        } while (value != 0);
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(ios_base::badbit);
        }
    }
    return os;
}

istream &operator>>(istream &is, __uint128_t &value) {
    string in;
    is >> in;
    value = 0;
    for (const char &c : in) {
        if ('0' <= c && c <= '9') value = 10 * value + (c - '0');
    }
    return is;
}
