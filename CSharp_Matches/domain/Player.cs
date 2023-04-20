namespace LabCSharp.domain
{
    public class Player : Student
    {
        public Team Team { get; set; }

        public override string ToString()
        {
            return id + ";" + Name + ";" + School + ";" + Team;
        }
    }
}