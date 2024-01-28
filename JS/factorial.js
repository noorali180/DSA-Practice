function factorial(n) {
  if (n < 0) {
    return "Invalid input. Please provide a non-negative integer.";
  } else if (n === 0 || n === 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Example: Find the factorial of 5
let result = factorial(5);
console.log(result);
