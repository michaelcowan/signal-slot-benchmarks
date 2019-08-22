#include "../hpp/benchmark_ass.hpp"

NOINLINE(void Ass::initialize())
{
    // NOOP
}
NOINLINE(void Ass::validate_assert(std::size_t N))
{
    return Benchmark<Signal, Ass>::validation_assert(N);
}    
NOINLINE(double Ass::construction(std::size_t N))
{
    return Benchmark<Signal, Ass>::construction(N);
}
NOINLINE(double Ass::destruction(std::size_t N))
{
    return Benchmark<Signal, Ass>::destruction(N);
}
NOINLINE(double Ass::connection(std::size_t N))
{
    return Benchmark<Signal, Ass>::connection(N);
}
NOINLINE(double Ass::emission(std::size_t N))
{
    return Benchmark<Signal, Ass>::emission(N);
}
NOINLINE(double Ass::combined(std::size_t N))
{
    return Benchmark<Signal, Ass>::combined(N);
}
NOINLINE(double Ass::threaded(std::size_t N))
{
    // NOT IMPLEMENTED FOR THIS LIB
    return 0.0;
}
