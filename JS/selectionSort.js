const arr = [10, 2, 3, 44, 12, 22, 1, 39, 24, 50, 110, 5];

function selectionSort() {
  for (let i = 0; i < arr.length; i++) {
    let min = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[min] > arr[j]) min = j;
    }

    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}

console.log(arr);
selectionSort();
console.log(arr);
