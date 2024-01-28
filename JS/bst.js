class Node {
  constructor(key) {
    this.key = key;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  // Insert a key into the tree
  insert(key) {
    this.root = this._insertRec(this.root, key);
  }

  _insertRec(root, key) {
    if (root === null) {
      return new Node(key);
    }

    if (key < root.key) {
      root.left = this._insertRec(root.left, key);
    } else if (key > root.key) {
      root.right = this._insertRec(root.right, key);
    }

    return root;
  }

  // Delete a key from the tree
  delete(key) {
    this.root = this._deleteRec(this.root, key);
  }

  _deleteRec(root, key) {
    if (root === null) {
      return null;
    }

    if (key < root.key) {
      root.left = this._deleteRec(root.left, key);
    } else if (key > root.key) {
      root.right = this._deleteRec(root.right, key);
    } else {
      // Node with only one child or no child
      if (root.left === null) {
        return root.right;
      } else if (root.right === null) {
        return root.left;
      }

      // Node with two children, get the inorder successor
      root.key = this._minValueNode(root.right);

      // Delete the inorder successor
      root.right = this._deleteRec(root.right, root.key);
    }

    return root;
  }

  _minValueNode(node) {
    let current = node;
    while (current.left !== null) {
      current = current.left;
    }
    return current.key;
  }

  // Search for a key in the tree
  search(key) {
    return this._searchRec(this.root, key);
  }

  _searchRec(root, key) {
    if (root === null || root.key === key) {
      return root;
    }

    if (key < root.key) {
      return this._searchRec(root.left, key);
    }

    return this._searchRec(root.right, key);
  }

  // Traversal: In-order, Pre-order, Post-order
  inOrder() {
    this._inOrderRec(this.root);
  }

  _inOrderRec(root) {
    if (root !== null) {
      this._inOrderRec(root.left);
      console.log(root.key);
      this._inOrderRec(root.right);
    }
  }

  preOrder() {
    this._preOrderRec(this.root);
  }

  _preOrderRec(root) {
    if (root !== null) {
      console.log(root.key);
      this._preOrderRec(root.left);
      this._preOrderRec(root.right);
    }
  }

  postOrder() {
    this._postOrderRec(this.root);
  }

  _postOrderRec(root) {
    if (root !== null) {
      this._postOrderRec(root.left);
      this._postOrderRec(root.right);
      console.log(root.key);
    }
  }
}

// Example usage
const bst = new BinarySearchTree();
bst.insert(50);
bst.insert(30);
bst.insert(20);
bst.insert(40);
bst.insert(70);
bst.insert(60);
bst.insert(80);

console.log("In-order traversal:");
bst.inOrder();

console.log("\nDeleting key 20:");
bst.delete(20);
bst.inOrder();
