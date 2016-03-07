// RUN: not %clang_cc1 -triple spir-unknown-unknown %s -S -o - 2>&1 | FileCheck %s

// CHECK: error: unable to create target: 'No available targets are compatible with this triple, see -version for the available targets.'
