import java.util.*;
class Trieds 
{
	class TrieNode
	{
		Map<Character,TrieNode> child;
		boolean eow;
		public TrieNode()
		{
			child = new HashMap<>();
			eow = false;
		}
	}
	private final TrieNode root;
	public Trieds() 
	{
		root = new TrieNode();
	}
	public void insert(String word)
	{
		TrieNode current = root;
		for(int i=0;i<word.length();i++)
		{
			char ch = word.charAt(i);
			TrieNode node = current.child.get(ch);
			if(node==null)
			{
				node=new TrieNode();
				current.child.put(ch,node);
			}
			current=node;
		}
		current.eow=true;
	}
	public void printTrie(TrieNode current,String prefix)
	{
		for(Map.Entry<Character, TrieNode> entry : current.child.entrySet())
		{
			String offset;
			offset=prefix;
			char ch = entry.getKey();
			offset+=ch;	
			TrieNode node = entry.getValue();
			if(node!=null)
			{
				current = node;
				if(current.eow==true)
					System.out.println(offset);	
			}
			printTrie(current,offset);
		}		
	}
	public void search(String prefix)
		{
			TrieNode current = root;
			for(int i=0;i<prefix.length();i++)
			{
				char ch = prefix.charAt(i);
				TrieNode node = current.child.get(ch);
				if(node==null)
					System.out.println("No Matching Students");
				current=node;	
			}
			printTrie(current,prefix);	
		}
}
public class Trie
{
	static HashMap<String,ArrayList<String>> hashmap1 = new HashMap<String,ArrayList<String>>();
	static Scanner sc = new Scanner(System.in);
	static void printRegStudents(String string,String x)
	{
		Trieds obj =new Trieds();
		ArrayList<String> temp = hashmap1.get(string);
		for(int i=0;i<temp.size();i++)
			obj.insert(temp.get(i));
		System.out.println("Trie Formed Sucessfully!!");
		obj.search(x);
				
	}
	public static void main(String[] args)
	{
		
		System.out.println("Enter Number of Courses : ");
		int num_of_courses = sc.nextInt();
		for(int i=0;i<num_of_courses;i++)
		{
			ArrayList<String> temp = new ArrayList<String>();
			System.out.println("Enter Course Name : ");
			String cname = sc.next();
			System.out.println("Enter Num of registered Students :");
			int num_of_students = sc.nextInt();
			for(int j=0;j<num_of_students;j++)
			{
				System.out.println("Enter Student Name "+(j+1)+" :");
				temp.add(sc.next());
			}
			hashmap1.put(cname, temp);
			System.out.println(hashmap1);
		}
		System.out.println("Enter Course Name for Trie : ");
		String string = sc.next();
		System.out.println("Enter prefix : ");
		String x = sc.next();
		if(x.equals("null"))
			System.out.println(hashmap1.get(string));
		else
			printRegStudents(string,x);
	}
}
