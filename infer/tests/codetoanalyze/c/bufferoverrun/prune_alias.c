/*
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
void prune_alias_le_Ok(int x) {
  int a[1];

  if (x <= x) {
    a[0] = 0;
  } else {
    a[1] = 0;
  }
}

void prune_alias_ge_Ok(int x) {
  int a[1];

  if (x >= x) {
    a[0] = 0;
  } else {
    a[1] = 0;
  }
}

void prune_alias_eq_Ok(int x) {
  int a[1];

  if (x == x) {
    a[0] = 0;
  } else {
    a[1] = 0;
  }
}

void prune_alias_lt_Ok(int x) {
  int a[1];

  if (x < x) {
    a[1] = 0;
  }
}

void prune_alias_gt_Ok(int x) {
  int a[1];

  if (x > x) {
    a[1] = 0;
  }
}

void prune_alias_ne_Ok(int x) {
  int a[1];

  if (x != x) {
    a[1] = 0;
  }
}

void prune_alias_not_Ok(int x) {
  int a[1];

  if (!(x == x)) {
    a[1] = 0;
  }

  if (!(x <= x)) {
    a[1] = 0;
  }

  if (!(x >= x)) {
    a[1] = 0;
  }
}

void prune_alias_and_Ok(int x) {
  int a[1];

  if (x == x && x != x) {
    a[1] = 0;
  }
}

void prune_alias_or_Ok(int x, int y) {
  int a[1];

  if (x != x || y != y) {
    a[1] = 0;
  }
}

void prune_alias_exp_Ok(int x) {
  int a[1];

  if (x + 1 != x + 1) {
    a[1] = 0;
  }
}

void FP_prune_alias_exp_Ok(int x) {
  int a[1];

  if (x + 1 != 1 + x) {
    a[1] = 0;
  }
}

#include <stdlib.h>

void prune_arrblk_ne(int* x) {
  int* y = x + 10;

  if (x != y) {
    x[5] = 1;
  }
}

void call_prune_arrblk_ne_Ok() {
  int* x = (int*)malloc(sizeof(int) * 10);
  prune_arrblk_ne(x);
}

void call_prune_arrblk_ne_Bad() {
  int* x = (int*)malloc(sizeof(int) * 5);
  prune_arrblk_ne(x);
}

void prune_arrblk_eq(int* x) {
  int* y = x + 10;

  if (x == y) {
    x[5] = 1; /* unreachable */
  }
}

void FP_call_prune_arrblk_eq_Ok() {
  int* x = (int*)malloc(sizeof(int) * 5);
  prune_arrblk_eq(x);
}

void prune_minmax1_Ok(unsigned int x, unsigned int y) {
  if (x > 0) {
    if (y >= x + 1) {
      unsigned int z = y - 1;
    }
  }
}

void FP_call_prune_minmax1_Ok() { prune_minmax1_Ok(0, 0); }

void prune_minmax2_Ok(unsigned int x, unsigned int y) {
  if (x > y) {
    unsigned int z = x - y;
  }
}

void FP_call_prune_minmax2_Ok() { prune_minmax2_Ok(0, 2); }
