/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

#pragma once

static inline void wfi(void)
{
    asm volatile("wfi" ::: "memory");
}

static inline void dsb(void)
{
    asm volatile("dsb sy" ::: "memory");
}

static inline void dmb(void)
{
    asm volatile("dmb sy" ::: "memory");
}

static inline void isb(void)
{
    asm volatile("isb" ::: "memory");
}


#define MRS(reg, v)  asm volatile("mrs %0," reg : "=r"(v))
#define MSR(reg, v)                                \
    do {                                           \
        word_t _v = v;                             \
        asm volatile("msr " reg ",%0" :: "r" (_v));\
    } while(0)
