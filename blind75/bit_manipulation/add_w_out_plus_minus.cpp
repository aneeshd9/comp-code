class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = static_cast<unsigned>(carry) << 1;
        }
        return a;
    }
};