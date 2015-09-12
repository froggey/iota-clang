// RUN: %clang -v -c -malign-double %s -target i686-unknown-linux 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-I686 %s

// CHECK-I686: -cc1
// CHECK-I686: -mllvm -malign-double
// CHECK-I686-NOT: backend data layout {{'[^']+'}} does not match expected target description {{'[^']+'}}

// RUN: %clang -v -c -malign-double %s -target x86_64-unknown-linux 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-X86_64 %s

// CHECK-X86_64: -cc1
// CHECK-X86_64: -mllvm -malign-double

// RUN: not %clang -v -c -mno-align-double %s -target i686-unknown-linux 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-NO-I686 %s

// CHECK-NO-I686: unknown argument: '-mno-align-double'

// RUN: not %clang -v -c -mno-align-double %s -target x86_64-unknown-linux 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-NO-X86_64 %s

// CHECK-NO-X86_64: unknown argument: '-mno-align-double'
