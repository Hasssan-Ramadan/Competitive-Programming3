// add using bitwise operations
int add(int a, int b) {
	while (b > 0) {
		int carry = a & b;
		a ^= b;
		b = carry << 1;
	}
	return a;
}

// product using bitwise operations
int product(int a, int b) {
	int c = 0;
	while (b > 0) {
		if ((b & 1) == 1) {
			c = add(c, a);
		}
		a <<= 1;
		b >>= 1;
	}
	return c;
}