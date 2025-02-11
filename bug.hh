function foo(x: int): int {
  return x + 1;
}

function bar(x: int): int {
  return foo(x) + 1;
}

function baz(x: int): int {
  return bar(x) + 1;
}

function main(): void {
  echo baz(1);
}
This code compiles and works correctly.  However, a subtle bug can be introduced if you modify the type hints. For example:

function foo(x: ?int): ?int {
  return x + 1;
}

function bar(x: ?int): ?int {
  return foo(x) + 1;
}

function baz(x: ?int): ?int {
  return bar(x) + 1;
}

function main(): void {
  echo baz(1);
}
Now, with nullable ints, this will throw a runtime error if `x` is ever null at any point in the chain. This happens silently during runtime and is easily missed during debugging.