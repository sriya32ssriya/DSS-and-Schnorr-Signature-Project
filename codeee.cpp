#include <iostream>
#include <cmath>
#include <cstdlib> // for exit()

using namespace std;

// Checking prime number
bool isPrime(int n) {
    if (n <= 1) 
        return false;
    if (n == 2 || n == 3) 
        return true;
    if (n % 2 == 0 || n % 3 == 0) 
        return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Inverse finding method 
long long modInverse(long long a, long long m) {
    for(int x = 0; x < m; x++){
        if ((a * x) % m == 1){
            return x;
        }
    }
    return -1; // inverse not found
}

// Check if h is a primitive root modulo p
bool isPrimitiveRoot(long long h, long long p) {
    long long phi = p - 1;
    for (long long i = 1; i <= phi; i++) {
        long long val = 1;
        for (long long j = 1; j <= i; j++) {
            val = (val * h) % p;
        }
        if (val == 1 && i < phi) {
            return false; // h^i ≡ 1 (mod p) for some i < p-1 → not primitive root
        }
    }
    return true;
}

class signature {
public:
    virtual void keygena() = 0;
    virtual void signatgena() = 0;
    virtual void signverf() = 0;
};

class dsa: public signature{
private:
    long long p, q, g, x, y, h, k, r, s, hm, w, u1, u2, v;

public:
    void keygena() override {
        // Input prime number p
        cout << "Enter prime number p: ";
        cin >> p;
        while (!isPrime(p)) {
            cout << "p must be a prime. Enter again: ";
            cin >> p;
        }

        // Input prime number q such that (p-1) % q == 0
        while (true) {
            cout << "Enter prime number q: ";
            cin >> q;
            if (!isPrime(q)) {
                cout << "q must be prime. Try again." << endl;
                continue;
            }
            if ((p - 1) % q == 0) {
                cout << "Valid input! p = " << p << ", q = " << q << endl;
                break;
            } else {
                cout << "Condition failed: (p - 1) must be divisible by q. Try again." << endl;
            }
        }

        // Input candidate h until it is a primitive root modulo p
        cout << "Enter candidate h (generator): ";
        cin >> h;
        while (!isPrimitiveRoot(h, p)) {
            cout << "Error: h is not a primitive root modulo p. Enter h again: ";
            cin >> h;
        }
        cout << "h is a valid primitive root modulo p." << endl;

        // Calculate g
        long long tempd = (p - 1) / q;
        g = (long long)pow(h, tempd) % p;

        // Input private key x (1 < x < q)
        cout << "Enter your private key x: ";
        cin >> x;
        while (x <= 1 || x >= q) {
            cout << "Enter your private key again (1 < x < q): ";
            cin >> x;
        }

        // Calculate public key y
        y = (long long)pow(g, x) % p;
    }

    void signatgena() override {
        cout << "Enter the k value: ";
        cin >> k;
        while(k <= 0 || k >= q){
            cout << "Enter your k value again: ";
            cin >> k;
        }

        r = ((long long)pow(g, k) % p) % q;

        cout << "Enter the hash value h(m): ";
        cin >> hm;
        while(hm <= 0){
            cout << "Enter h(m) again, it must be positive: ";
            cin >> hm;
        }

        long long s1 = (x * r) % q;
        long long k_inv = modInverse(k, q);
        s = (k_inv * ((hm + s1) % q)) % q;

        cout << "(r, s) = (" << r << ", " << s << ")" << endl;
    }

    void signverf() override {
        if (r <= 0 || s >= q) {
            cout << "Signature verification fail" << endl;
            return;
        }

        w = modInverse(s, q);
        u1 = (hm * w) % q;
        u2 = (r * w) % q;
        v = ((long long)pow(g, u1) % p * (long long)pow(y, u2) % p) % p;
        v = v % q;

        if (v == r) {
            cout << "Signature verified" << endl;
        } else {
            cout << "Signature verification fail" << endl;
        }
    }
};

class schnorrr : public signature {
private:
    long long p, q, x, y, g, k, r, s, e, r1, e1, hm;

public:
    void keygena() override {
        cout << "Enter prime number p: ";
        cin >> p;
        while (!isPrime(p)) {
            cout << "p must be a prime. Enter again: ";
            cin >> p;
        }

        while (true) {
            cout << "Enter prime number q: ";
            cin >> q;
            if (!isPrime(q)) { cout << "q must be prime. Try again." << endl; continue; }
            if ((p-1) % q == 0) { break; } 
            else { cout << "Condition fail (p-1 must be divisible by q)." << endl; }
        }

        cout << "Enter generator g: ";
        cin >> g;
        while((long long)pow(g, q) % p != 1) {
            cout << "g^q mod p != 1. Enter g again: ";
            cin >> g;
        }

        cout << "Enter private key x: ";
        cin >> x;
        while(x <= 1 || x >= q-1){
            cout << "Enter private key again (1 < x < q-1): ";
            cin >> x;
        }
        y = (long long)pow(g, x) % p;
    }

    void signatgena() override {
        cout << "Enter value k: ";
        cin >> k;
        while(k <= 1 || k >= q-1){
            cout << "Enter value k again: ";
            cin >> k;
        }

        r = (long long)pow(g, k) % p;
        cout << "Enter h(m): ";
        cin >> hm;
        while(hm < 1){
            cout << "h(m) must be positive: ";
            cin >> hm;
        }

        e = (hm + r) % q;
        s = (k + x * e) % q;

        cout << "(e, s) = (" << e << ", " << s << ")" << endl;
    }

    void signverf() override {
        long long r1_part1 = (long long)pow(g, s) % p;
        long long r1_part2 = (long long)pow(modInverse(y, p), e) % p;
        r1 = (r1_part1 * r1_part2) % p;
        e1 = (hm + r1) % q;

        if(e1 == e) cout << "Signature verified" << endl;
        else cout << "Signature not verified" << endl;
    }
};

int main() {
    int choi;
    cout << "Which signature do you want?" << endl;
    cout << "1. Digital Signature Algorithm (DSS)" << endl;
    cout << "2. Schnorr Signature Toy Version ALGORITHM" << endl;
    cout << "Choose one option: ";
    cin >> choi;

    if (choi == 1) {
        cout << "You chose Digital Signature Algorithm (DSS)." << endl;
        dsa dsaob;
        dsaob.keygena();
        dsaob.signatgena();
        dsaob.signverf();
    } else if (choi == 2) {
        cout << "You chose Schnorr Signature Toy Version ALGORITHM." << endl;
        schnorrr schob;
        schob.keygena();
        schob.signatgena();
        schob.signverf();
    } else {
        cout << "Invalid choice. Please select 1 or 2." << endl;
    }
    return 0;
}