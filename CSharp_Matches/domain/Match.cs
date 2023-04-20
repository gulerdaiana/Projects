using System;

namespace LabCSharp.domain
{
    public class Match : Entity<int>
    {
        public Team Team1 { get; set; }
        public Team Team2 { get; set; }

        public DateTime DateTime { get; set; }

        public override string ToString()
        {
            return id + ";" + Team1 + ";" + Team2 + ";" + DateTime;
        }
    }
}