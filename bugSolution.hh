function foo(x: ?int): ?int {
  if (x === null) {
    return null;
  }
  return x + 1;
}

function bar(x: ?int): ?int {
  if (x === null) {
    return null;
  }
  return foo(x) + 1;
}

function baz(x: ?int): ?int {
  if (x === null) {
    return null;
  }
  return bar(x) + 1;
}

function main(): void {
  echo baz(1);
  echo baz(null);
}
This version explicitly checks for null before performing the addition, preventing the runtime exception.