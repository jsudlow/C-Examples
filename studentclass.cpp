

public class Student
{
	private int studentID;
	private int gradeLevel;
	private boolean honorRoll;


	public Student(int s, int g)
	{
		studentID = s;
		gradeLevel = g;
		honorRoll = false;
	}

	public Student(int s)
	{
		studentID = s;
		gradeLevel = 9;
		honorRoll = false;
	}
}



Student one = new Student(12, 13);
