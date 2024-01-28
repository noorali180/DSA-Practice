function fibonacciRecursive(n) {
  if (n < 0) {
    return "Invalid input. Please provide a non-negative integer.";
  } else if (n === 0) {
    return 0;
  } else if (n === 1) {
    return 1;
  } else {
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
  }
}

// Example: Find the 7th Fibonacci number (index 6)
let result = fibonacciRecursive(5);
console.log(result);
