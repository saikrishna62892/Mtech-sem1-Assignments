import java.util.*;
public class Graph2 
{
	static String root_vertex;
	static int edge_count=0,n;
	HashMap<String,HashSet<String>> hashmap1 = new HashMap<String,HashSet<String>>();
	ArrayList<String> name = new ArrayList<String>();
	ArrayList<Float> cgpa = new ArrayList<Float>();
	HashMap<String,HashSet<String>> pre = new HashMap<String,HashSet<String>>();
	Scanner sc = new Scanner(System.in);
	//Display Adjacency List
	public void displayAdjacencyList()
	{
		for(Map.Entry<String,HashSet<String>> entry : hashmap1.entrySet())
			System.out.println("key : "+entry.getKey()+"------->"+entry.getValue());
	}
	//Add edge to the Graph
	public void addEdge(String src,String dest)
	{
		if(!hashmap1.containsKey(src))
			hashmap1.put(src, new HashSet<String>());
		if(dest!= null)
			hashmap1.get(src).add(dest);
		displayAdjacencyList();
	}
	//Student_input
	void studentInput()
	{
		System.out.println("Enter Num of Students : ");
		n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter Name :");
			String sname = sc.next();
			name.add(sname);
			System.out.println("Enter CGPA :");
			float scgpa = sc.nextFloat();
			cgpa.add(scgpa);
			System.out.println("Enter Num of Prerequisites learned : ");
			int num = sc.nextInt();
			HashSet<String> temp = new HashSet<String>();
			for(int j=0;j<num;j++)
			{
				System.out.println("Enter Prerequisite "+(j+1)+" : ");
				String course = sc.next();
				temp.add(course);
			}
			pre.put(sname, temp);
		}
	}
	void findCourse()
	{
		for(Map.Entry<String,HashSet<String>> entry : pre.entrySet())
		{
			String key = entry.getKey();
			HashSet<String> temp = entry.getValue();
			HashSet<String> a = new HashSet<String>();
			Iterator itr = temp.iterator();
			while(itr.hasNext())
			{
				String dup = (String) itr.next();
				a.addAll(hashmap1.get(dup));
			}
			pre.get(key).addAll(a);
		}
		System.out.println(pre);
	}
	void commonCourse()
	{
		findCourse();
		int size=pre.size();
		ArrayList<String> keylist = new ArrayList<String>();
		HashSet<String> temp1 = new HashSet<String>();
		HashSet<String> temp2 = new HashSet<String>();
		HashSet<String> temp3 = new HashSet<String>();
		HashSet<String> temp4 = new HashSet<String>();
		for(Map.Entry<String,HashSet<String>> entry : pre.entrySet())
			keylist.add(entry.getKey());
		for(int i=0;i<size-1;i++)
		{
			if(i==0)
				temp1=pre.get(keylist.get(i));
			temp2=pre.get(keylist.get(i+1));
			Iterator itr1 = temp1.iterator();
			while(itr1.hasNext())
			{
				String cmp1 = (String) itr1.next();
				Iterator itr2 = temp2.iterator();
				while(itr2.hasNext())
				{
					String cmp2 = (String)itr2.next();
					if(cmp1.equals(cmp2))
						temp3.add(cmp1);
				}
			}
			temp1=temp3;	
		}
		System.out.println("Common Courses--->"+temp1);	
	}
	//Main function
	public static void main(String[] args) 
	{
		Graph2 obj = new Graph2();
		Scanner sc = new Scanner(System.in);
		int done=0;
		while(done != 1)
		{
			if(done==1)
				break;
			System.out.println("Enter Prerequisite : ");
			String src = sc.next();
			System.out.println("Enter Course :");
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
		obj.studentInput();
		obj.commonCourse();
	}
}
