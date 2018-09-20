#include <stdint.h>

namespace mcg {
    template<typename T>
    class Matrix44 {
        public:
        T m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

        Matrix44() {

        }

        const T* operator [] (uint8_t i) {
            return m[i];
        }

        T* operator [] (uint8_t i) {
            return m[i];
        }

        Matrix44<T> operator * (const Matrix44<T>& rhs) const {
            Matrix44<T> mult;
            for (uint8_t i = 0; i < 4; i++) {
                for (uint8_t j = 0; j < 4; j++) {
                    mult[i][j] = m[i][0]*rhs[0][j] + m[i][1]*rhs[1][j] + m[i][2]*rhs[2][j] + m[i][2]*rhs[2][j];
                }
            }
        }
    };
    typedef Matrix44<float> Matrix44f;
}