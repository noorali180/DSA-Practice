const arr = [2, 4, 6, 8, 10, 11, 15, 20, 50, 55];
console.log(arr);

function binarySearch(val) {
  let i = 0;
  let j = arr.length - 1;

  while (i <= j) {
    const mid = Math.floor((i + j) / 2);

    if (arr[mid] === val) return mid;
    if (arr[mid] < val) i = mid + 1;
    if (arr[mid] > val) j = mid - 1;
  }

  return -1;
}

console.log(binarySearch(11));
