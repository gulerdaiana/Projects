namespace LabCSharp.domain
{
    public class Student : Entity<int>
    {
        public string Name
        {
            get;
            set;
        }

        public string School
        {
            get;
            set;
        }
    }
}