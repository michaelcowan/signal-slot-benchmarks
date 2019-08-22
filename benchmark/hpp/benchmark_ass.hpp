#pragma once

#include "../lib/michaelcowan/ass/ass.hpp"


#include "../../benchmark.hpp"

class Ass
{
    ass::Slot<Rng&> slot = ass::Slot<Rng&>([](Rng& rng) {});

    NOINLINE(void handler(Rng& rng))
    {
        volatile std::size_t a = rng(); (void)a;
    }

    public:

    using Slot = ass::Slot<Rng&>;
    using Signal = ass::Signal<Rng&>;

    template <typename Subject, typename Foo>
    static void connect_method(Subject& subject, Foo& foo)
    {
        foo.slot = ass::Slot<Rng&>(&foo, &Foo::handler);
        subject.connect(foo.slot);
    }
    template <typename Subject>
    static void emit_method(Subject& subject, Rng& rng)
    {
        subject.emit(rng);
    }

    // Used for switching policies at runtime
    static void initialize();

    static void validate_assert(std::size_t);
    static double construction(std::size_t);
    static double destruction(std::size_t);
    static double connection(std::size_t);
    static double emission(std::size_t);
    static double combined(std::size_t);

    // NOT IMPLEMENTED FOR THIS LIB
    static double threaded(std::size_t);

    static constexpr const char* C_LIB_NAME = "michaelcowan ass";
    static constexpr const char* C_LIB_SOURCE_URL = "https://github.com/michaelcowan/ass";
    static constexpr const char* C_LIB_FILE = "benchmark_ass";
    static constexpr const char* C_LIB_IS_HEADER_ONLY = "X";
    static constexpr const char* C_LIB_DATA_STRUCTURE = "std::vector";
    static constexpr const char* C_LIB_IS_THREAD_SAFE = "-";
};
