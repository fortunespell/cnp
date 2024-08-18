#include <stdio.h>
#include <math.h>

// Function to compute GCD of a and b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to find modular inverse of a under modulo m
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int main() {
    int p, q, n, phi, e, d, plaintext, ciphertext, decryptedtext;

    // Step 1: Choose prime numbers p and q
    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);

    // Step 2: Calculate n = p * q
    n = p * q;

    // Step 3: Calculate phi = (p - 1) * (q - 1)
    phi = (p - 1) * (q - 1);

    // Step 4: Choose e and calculate d
    printf("Enter a value for e (1 < e < %d) that is coprime with %d: ", phi, phi);
    scanf("%d", &e);
    while (gcd(e, phi) != 1) {
        printf("Invalid e. Choose another value for e: ");
        scanf("%d", &e);
    }
    d = mod_inverse(e, phi);

    // Display keys
    printf("Public Key: (e = %d, n = %d)\n", e, n);
    printf("Private Key: (d = %d, n = %d)\n", d, n);

    // Step 5: Encrypt the message
    printf("Enter plaintext (integer): ");
    scanf("%d", &plaintext);
    ciphertext = mod_exp(plaintext, e, n);
    printf("Ciphertext: %d\n", ciphertext);

    // Step 6: Decrypt the message
    decryptedtext = mod_exp(ciphertext, d, n);
    printf("Decrypted plaintext: %d\n", decryptedtext);

    return 0;
}
