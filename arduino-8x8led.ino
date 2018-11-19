/* This is a work in progress. */

/* I am making use of LedControl library from
 * https://github.com/wayoda/LedControl */

#include <LedControl.h>

/* I got the following table by making use of LED matrix editor.  LED Matrix
 * Editor is an online tool for editing and creating animations for 8x8 LED
 * matrices. It is free and easy to use.
 * https://xantorohara.github.io/led-matrix-editor/ */

const uint64_t A = 0x6666667e66663c00;
const uint64_t B = 0x3e66663e66663e00;
const uint64_t C = 0x3c66060606663c00;
const uint64_t D = 0x3e66666666663e00;
const uint64_t E = 0x7e06063e06067e00;
const uint64_t F = 0x0606063e06067e00;
const uint64_t G = 0x3c66760606663c00;
const uint64_t H = 0x6666667e66666600;
const uint64_t I = 0x3c18181818183c00;
const uint64_t J = 0x1c36363030307800;
const uint64_t K = 0x66361e0e1e366600;
const uint64_t L = 0x7e06060606060600;
const uint64_t M = 0xc6c6c6d6feeec600;
const uint64_t N = 0xc6c6e6f6decec600;
const uint64_t O = 0x3c66666666663c00;
const uint64_t P = 0x06063e6666663e00;
const uint64_t Q = 0x603c766666663c00;
const uint64_t R = 0x66361e3e66663e00;
const uint64_t S = 0x3c66603c06663c00;
const uint64_t T = 0x18181818185a7e00;
const uint64_t U = 0x7c66666666666600;
const uint64_t V = 0x183c666666666600;
const uint64_t W = 0xc6eefed6c6c6c600;
const uint64_t X = 0xc6c66c386cc6c600;
const uint64_t Y = 0x1818183c66666600;
const uint64_t Z = 0x7e060c1830607e00;
const uint64_t a = 0x7c667c603c000000;
const uint64_t b = 0x3e66663e06060600;
const uint64_t c = 0x3c6606663c000000;
const uint64_t d = 0x7c66667c60606000;
const uint64_t e = 0x3c067e663c000000;
const uint64_t f = 0x0c0c3e0c0c6c3800;
const uint64_t g = 0x3c607c66667c0000;
const uint64_t h = 0x6666663e06060600;
const uint64_t i = 0x3c18181800180000;
const uint64_t j = 0x1c36363030003000;
const uint64_t k = 0x66361e3666060600;
const uint64_t l = 0x1818181818181800;
const uint64_t m = 0xd6d6feeec6000000;
const uint64_t n = 0x6666667e3e000000;
const uint64_t o = 0x3c6666663c000000;
const uint64_t p = 0x06063e66663e0000;
const uint64_t q = 0xf0b03c36363c0000;
const uint64_t r = 0x060666663e000000;
const uint64_t s = 0x3e403c027c000000;
const uint64_t t = 0x1818187e18180000;
const uint64_t u = 0x7c66666666000000;
const uint64_t v = 0x183c666600000000;
const uint64_t w = 0x7cd6d6d6c6000000;
const uint64_t x = 0x663c183c66000000;
const uint64_t y = 0x3c607c6666000000;
const uint64_t z = 0x3c0c18303c000000;

const uint64_t alpha[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R,
                          S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, i, j,
                          k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

const int len = sizeof(alpha) / sizeof(alpha[0]);

int DIN = 12;
int CS = 11;
int CLK = 10;

const unsigned long sec_1 = 1000;
LedControl lc = LedControl(DIN, CLK, CS);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 12);
  lc.clearDisplay(0);
}

void show(uint64_t val) {
  for (int i = 7, j = 0; i >= 0; --i, ++j) {
    byte row = (val >> (i * 8)) & 0xFF;
    lc.setRow(0, j, row);
  }
}

void loop() {
  for (int i = 0; i < len; ++i) {
    show(alpha[i]);
    delay(sec_1);
    lc.clearDisplay(0);
    delay(sec_1);
  }
}
