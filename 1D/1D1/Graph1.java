import java.util.*;
import java.util.Map.Entry;
class Stack
{
	int top=-1;
	String data[] = new String[50];
	void push(String str)
	{
		++top;
		data[top]=str;
		
	}
	String pop()
	{
		return data[top--];
	}
	Boolean isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	String top()
	{
		return data[top];
	}
}
public class Graph1
{
	static String root_vertex;
	static int edge_count=0,vertex_count,time=1;
	static HashSet<String> hashset = new HashSet<String>();
	static ArrayList<Integer> list = new ArrayList<Integer>();
	static HashMap<String,HashSet<String>> hashmap1 = new HashMap<String,HashSet<String>>();
	static HashMap<String,ArrayList<Integer>> hashmap2= new HashMap<String,ArrayList<Integer>>();
	Scanner sc = new Scanner(System.in);
	//Display Adjacency List
	public void displayAdjacencyList()
	{
		for(Map.Entry<String,HashSet<String>> entry : hashmap1.entrySet())
			System.out.println("key : "+entry.getKey()+"------->"+entry.getValue());
	}
	public void displayArrayList()
	{
		for(Map.Entry<String,ArrayList<Integer>> entry : hashmap2.entrySet())
			System.out.println("key : "+entry.getKey()+"------->"+entry.getValue());
	}
	//Add edge to the Graph
	public void addEdge(String src,String dest)
	{
		if(!hashmap1.containsKey(src))
		{
			hashmap1.put(src, new HashSet<String>());
			hashmap2.put(src,new ArrayList<Integer>(Arrays.asList(0,0,0,0,0)));
		}
		if(dest!= null)
		hashmap1.get(src).add(dest);
		else
			return;
		if(!hashmap1.containsKey(dest))
		{
			hashmap1.put(dest, new HashSet<String>());
			hashmap2.put(dest,new ArrayList<Integer>(Arrays.asList(0,0,0,0,0)));
		}
		int in = hashmap2.get(dest).get(3)+1;
		hashmap2.get(dest).set(3,in);
		displayAdjacencyList();
	}
	//DFS
	public void dfs()
	{
		int x=0;
		Stack stack = new Stack();
		stack.push(root_vertex);
		hashmap2.get(root_vertex).set(1,time++);
		vertex_count=hashmap1.size();
		System.out.println("DFS TRAVERSAL : ");
		while(hashmap2.get(root_vertex).get(0)==0 || !stack.isEmpty())
		{
			if(hashmap2.get(root_vertex).get(0)==0)
			{
				x++;
				System.out.print(root_vertex+" ");
				hashmap2.get(root_vertex).set(0,1);
			}
			Iterator<String> itr=hashmap1.get(root_vertex).iterator();
			while(itr.hasNext())
			{
				String dup = itr.next();
				if(hashmap2.get(dup).get(0)==0)
				{
					hashmap2.get(dup).set(1,time++);
					stack.push(dup);
				}
			}
			//System.out.println(stack.top());
			if(hashmap2.get(stack.top()).get(0)!=0)
			{
				hashmap2.get(root_vertex).set(2,time++);
				stack.pop();
			}
			
			if(stack.isEmpty())
			{
				if(vertex_count==x)
					break;
				else
				{
					for(Map.Entry<String,HashSet<String>> entry2 : hashmap1.entrySet())
					{
						String a=entry2.getKey();
						if(hashmap2.get(a).get(0)==0)
						{
							stack.push(a);
							break;
						}
					}
				}
			}
			root_vertex = new String(stack.top());
		}
	}
	//Topological Order
	@SuppressWarnings("unchecked")
	public void topoLogicalOrdering()
	{
		dfs();
		System.out.println();
		displayArrayList();
		LinkedList l=new LinkedList(hashmap2.entrySet());
		Collections.sort(l,new Comparator<Map.Entry<String,ArrayList<Integer>>>() {
			public int compare(Map.Entry<String,ArrayList<Integer>> o1,Map.Entry<String,ArrayList<Integer>> o2)
			{
				return o2.getValue().get(2).compareTo(o1.getValue().get(2));
			}
		});
		System.out.println("Topological Order :");
		System.out.println(l);
	}
	@SuppressWarnings("unchecked")
	public void topoLogicalOrdering1()
	{
		int flag=0;
		System.out.println("TOPOLOGICAL ORDERING : ");
		while(!hashmap1.isEmpty())
		{
			for(Map.Entry<String,ArrayList<Integer>> entry : hashmap2.entrySet())
			{
				int num=hashmap1.size();
				String s = entry.getKey();
				int arg = hashmap2.get(s).get(3);
				if(num==1 && hashmap2.get(s).get(4)==0)
				{
					flag=1;
					System.out.print(s+" ");
					hashmap1.remove(s);
					break;
				}
				if(arg == 0 && hashmap2.get(s).get(4)==0)
				{
					Iterator itr=hashmap1.get(s).iterator();
					while(itr.hasNext())
					{
						String dup = (String) itr.next();
						int in = hashmap2.get(dup).get(3);
						hashmap2.get(dup).set(3,in-1);
					}
					System.out.print(s+" ");
					hashmap1.remove(s);
					hashmap2.get(s).set(4,1);
					num--;
				}
			}
			if(flag==1)
				break;
			
		}
	}
	//Main function
	public static void main(String[] args) 
	{
		Graph1 obj = new Graph1();
		Scanner sc = new Scanner(System.in);
		int done=0;
		while(done != 1)
		{
			if(done==1)
				break;
			System.out.println("Enter Prerequisite : ");
			String src = sc.next();
			System.out.println("Enter Course : ");
			String dest = sc.next();
			edge_count++;
			if(edge_count==1)
				root_vertex= new String(src);
			if(dest.equals("null"))
				obj.addEdge(src, null);
			else
				obj.addEdge(src,dest);
			System.out.println("Do you Wish to Enter another Edge(y/n) : ");
			String ans=sc.next();
			if(ans.equals("n"))
				done=1;
		}
		System.out.println("\n1.Topological_Ordering 1\n2.Toplogical_Ordering 2");
		int ch = sc.nextInt();
		switch(ch)
		{
		case 1: obj.topoLogicalOrdering();break;
		case 2: obj.topoLogicalOrdering1();break;
		default: System.out.println("Please Enter a Valid Choice!!");
		}
	}
}
