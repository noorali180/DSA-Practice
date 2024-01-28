const arr = [10, 2, 3, 44, 12, 22, 1, 39, 24, 50, 110, 5];

function insertionSort() {
  for (let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;
    while (arr[j] > key && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

insertionSort();

console.log(arr);
