namespace LabCSharp.domain
{
    public class Team : Entity<int>
    {
        public string NameT
        {
            get;
            set;
        }

        public override string ToString()
        {
            return NameT;
        }
    }
}