package main

import "fmt"

type Node struct {
	val   int
	left  *Node
	right *Node
}
type BTree struct {
	root *Node
}

func InorderRecursive(node *Node) {
	if node == nil {
		return

	}
	InorderRecursive(node.left)
	fmt.Printf("%d ", node.val)
	InorderRecursive(node.right)
}

func preorderRecursive(node *Node) {
	if node == nil {
		return

	}
	fmt.Printf("%d ", node.val)
	preorderRecursive(node.left)
	preorderRecursive(node.right)
}

func postorderRecursive(node *Node) {
	if node == nil {
		return

	}
	postorderRecursive(node.left)
	postorderRecursive(node.right)
	fmt.Printf("%d ", node.val)
}

func (t *BTree) BSTadd(v int) *BTree {
	if t.root == nil {
		t.root = &Node{val: v, left: nil, right: nil}
	} else {
		if v <= t.root.val {
			if t.root.left == nil {
				t.root.left = &Node{val: v, left: nil, right: nil}
			} else {
				t.root.left.Nodeadd(v)
			}
		} else {
			if t.root.right == nil {
				t.root.right = &Node{val: v, left: nil, right: nil}
			} else {
				t.root.right.Nodeadd(v)
			}
		}
	}
	return t

}
func (node *Node) Nodeadd(v int) {
	if node == nil {
		node = &Node{val: v, left: nil, right: nil}
	} else {
		if v <= node.val {
			if node.left == nil {
				node.left = &Node{val: v, left: nil, right: nil}
			} else {
				node.left.Nodeadd(v)
			}
		} else {
			if node.right == nil {
				node.right = &Node{val: v, left: nil, right: nil}
			} else {
				node.right.Nodeadd(v)
			}
		}
	}
	// node.val = v
	// node.left = nil
	// node.right = nil
	// print(node.val," " )
}

func main() {
	tree := &BTree{}
	list := [7]int{4, 6, 2, 20, 1, 3, 18}

	for _, s := range list {
		tree.BSTadd(s)
	}
	println()

	fmt.Print("Inorder Traversal - recursive solution : ")
	InorderRecursive(tree.root)
	fmt.Println()
	fmt.Print("Preorder Traversal - recursive solution : ")
	preorderRecursive(tree.root)
	fmt.Println()
	fmt.Print("Postorder Traversal - recursive solution : ")
	postorderRecursive(tree.root)
	fmt.Println()
}
