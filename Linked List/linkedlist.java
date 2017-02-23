class linkedlist{

	Node head;
	static class Node{
	
		int data;
		Node next;
		
		Node(int d)
		{
			data = d;
		}
	}
	
	public void print()
	{
		Node n=head;
		System.out.println("The elements of the linked list are-");
		while(n!=null)
		{
			System.out.println(n.data);
			n = n.next;
		}
	}
	
	public void push(int element)
	{
		Node temp = new Node(element);
		temp.next = head;
		head = temp;
	} 
	
	public static void main(String areg[])
	{
		linkedlist ll = new linkedlist();
		
		ll.head = new Node(1);
		ll.push(2);
		ll.push(3);
		ll.push(4);
		
		ll.print();
	}
}
