#include <iostream>

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    if ((N >= M && N <= K) || (N <= M && N >= K)) {
        std::cout << N;
    }
    else if ((M >= N && M <= K) || (M <= N && M >= K)) {
        std::cout << M;
    }
    else {
        std::cout << K;
    }

    return 0;
}