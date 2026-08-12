/* Test that the toolchain can assemble Zcmp instructions */

/* No clobber list, deliberately. This file exists to check that the ASSEMBLER accepts
 * cm.mvsa01/cm.mva01s -- see the note in pico_riscv_gcc.cmake about the toolchains that
 * shipped a GCC with Zcmp support and a binutils without it. It is compiled to a throwaway
 * object by pico_choose_compiler_flags() and never linked or run, so telling the compiler
 * which registers the asm modifies buys nothing here.
 *
 * It costs something, though: the probe compiles with no optimization flags, and at -O0
 * s0 is the frame pointer, which GCC 15 refuses to let an asm statement clobber
 * ("error: s0 cannot be used in 'asm' here"). That made this test fail on a toolchain that
 * fully supports Zcmp -- riscv-toolchain-15-x64-win, GCC 15.2.0, where both instructions
 * assemble fine -- so the probe silently fell through to a flag set without Zca/Zcb/Zcmp.
 * A capability probe that fails for a reason unrelated to the capability is worse than no
 * probe, because the fallback is silent.
 *
 * Naming the registers only inside the asm string keeps this a pure assembler test: the
 * string is opaque to the compiler, so no register allocation constraint applies, while
 * an assembler lacking these instructions still rejects it. */
void _start(void) {
    asm volatile ("cm.mvsa01 s0, s1");
    asm volatile ("cm.mva01s s0, s1");
}
