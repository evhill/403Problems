Pairing Heap Implementation

Brief:
	This is an implementation of a minimum pairing heap, which is used to 
	represent a minimum priority queue structure. It has a very fast running time for 
	most operations. They can be used with Dijkstra's and Prim's algorithm,
	and also work well with Minimum Spanning Tree problems. 
	
Running time:
	Total (without test generating code) = log(n)
		most of the methods I implemented take constant time to perform. The only
		heavy lifting occurs in deleteMin which takes log(n) time. 
				
	getMin() = O(1);
		getMin runs in constant time as the root of the heap will always be the 
		smallest entity in the heap. 
	
	insert() = O(1)
		Insert runs in constant time, since we are only comparing the new node to the
		original root (or min) value. Should the new value be less than the current
		root, then the root becomes the child of this new node and the new node becomes
		the new root. Recombining the heap into a sorted order occurs once we've 
		deleted the root and need to find the new value of min.
		
	merge() = O(1)
		Merge takes constant time since we are again only comparing two values of 
		two nodes. Whichever node has a value greater than the second node becomes
		the child of the second node. 
	
	deleteMin = mergePairs = log(n)
		Delete min runs in log(n) time since we need to run through at least log
		number of nodes in order to recombine the heap once the root has been
		deleted. Merge Pairs takes all of the children of the current root and 
		and merges them in 

Tests:
    Basic Insert Test: I create a pairing heap and insert 20 predefined unsorted elements
		and then remove the minimum from the heap 20 times. I compare this 
		to the i (ex i = 0 to 19) value in a for loop. If they don't match then 
		the heap has failed. 
		
	Stress Insert Test: I create 175000 random integers between the values of 0-175000
		and insert them both into a priority queue and the pairing heap. Once again
		I perform a getMin() operation on both the priority queue and the pairing heap
		and compare the values. If they don't match then the pairing heap has failed.
		Shows the first 10 values. 
		
	Future Tests: Minimum Spanning Tree/Shortest Path
	    I was planning on implementing a Dijkstra or Kruskal MST solution using my
		pairing heap. However, I think my code is a little two specialized and would
		need to be refactored to allow for custom objects/general types. 
		
Resources Used:
	https://en.wikipedia.org/wiki/Pairing_heap
	https://www.cise.ufl.edu/~sahni/dsaaj/enrich/c13/pairing.htm
	https://www.cs.cmu.edu/~sleator/papers/pairing-heaps.pdf
	http://www.cs.princeton.edu/~sssix/papers/rp-heaps-journal.pdf
	http://www.cs.princeton.edu/courses/archive/spr11/cos423/Lectures/Heaps.pdf

	