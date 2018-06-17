unsigned xor128_x = 123456789, xor128_y = 362436069, xor128_z = 521288629, xor128_w = 88675123;
unsigned xor128() {
	unsigned t = xor128_x ^ (xor128_x << 11);
	xor128_x = xor128_y; xor128_y = xor128_z; xor128_z = xor128_w;
	return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}
