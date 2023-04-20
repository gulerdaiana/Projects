using System;

namespace LabCSharp.domain
{
    public enum Type
    {
        PARTICIPANT,
        RESERVE
    }

    public class ActivePlayer : Entity<Tuple<int, int>>
    {
        public int nrPoints { get; set; }

        public Type Type { get; set; }
    }
}