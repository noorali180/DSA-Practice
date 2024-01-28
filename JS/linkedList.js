class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  append(data) {
    const newNode = new Node(data);

    if (this.head === null) this.head = newNode;
    else {
      let temp = this.head;
      while (temp.next !== null) {
        temp = temp.next;
      }
      temp.next = newNode;
    }
  }

  prepend(data) {
    const newNode = new Node(data);
    if (this.head === null) this.head = newNode;
    else {
      newNode.next = this.head.next;
      this.head = newNode;
    }
  }

  delete() {
    let temp = this.head;

    while (temp.next.next !== null) {
      temp = temp.next;
    }
    temp.next = null;
  }

  insert(pos, data) {
    const newNode = new Node(data);

    if (this.head === null) return;
    else {
      let temp = this.head;

      for (let i = 0; i < pos - 1; i++) {
        temp = temp.next;
      }
      newNode.next = temp.next;
      temp.next = newNode;
    }
  }

  display() {
    let temp = this.head;

    if (this.head === null) return;
    else {
      while (temp !== null) {
        console.log(temp.data);
        temp = temp.next;
      }
    }
  }
}

const list = new LinkedList();

list.append(3);
list.append(6);
list.append(9);
list.append(10);
list.prepend(5);
list.insert(2, 22);
list.display();
