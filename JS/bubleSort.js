const arr = [10, 2, 3, 44, 12, 22, 1, 39, 24, 50, 110, 5];

function bubleSort() {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      if (arr[j] >= arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

bubleSort();

console.log(arr);
