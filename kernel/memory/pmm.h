/*-
 * SPDX-License-Identifier: MIT
 *
 * MIT License
 *
 * Copyright (c) 2021 Abb1x
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef PMM
#define PMM

#define PAGE_SIZE 4096
#define MEM_OFFSET 0xffffffff80000000
#define SETBIT(i) bitmap[i / 8] = bitmap[i / 8] | (1 << (i % 8))
#define CLEARBIT(i) bitmap[i / 8] = bitmap[i / 8] & (~(1 << (i % 8)))

#include <boot/stivale2.h>
#include <libk/logging.h>
#include <stddef.h>

void PMM_init(struct stivale2_mmap_entry *memory_map, size_t memory_entries);

void *PMM_allocate_page();
void *PMM_allocate_pages(size_t count);

void *PMM_callocate_page();
void *PMM_callocate_pages(size_t count);

void PMM_free_page(void *adress);
void PMM_free_pages(void *adress, size_t count);

#endif
