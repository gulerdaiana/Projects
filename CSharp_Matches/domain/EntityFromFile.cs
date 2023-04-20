using System;

namespace LabCSharp.domain
{
    public class EntityFromFile
    {
        public static Student CreateStudent(string line)
        {
            string[] fields = line.Split(',');
            Student student = new Student()
            {
                id = Int32.Parse(fields[0]),
                Name = fields[1]
            };
            return student;
        }

        public static Player CreatePlayer(string line)
        {
            string[] fields = line.Split(',');
            Player player = new Player()
            {
                id = Int32.Parse(fields[0]),
                Name = fields[1],
                School = fields[2],
                Team = new Team()
                {
                    NameT = fields[3]
                }
            };
            return player;
        }

        public static Match CreateMatch(string line)
        {
            string[] fields = line.Split(',');
            Match match = new Match()
            {
                id = Int32.Parse(fields[0]),
                Team1 = new Team()
                {
                    NameT = fields[1]
                },
                Team2 = new Team()
                {
                    NameT = fields[2]
                },
                DateTime = DateTime.ParseExact(fields[3],"dd/MM/yyyy",null)
            };
            return match;
        }

        public static ActivePlayer CreateActivePlayer(string line)
        {
            string[] fields = line.Split(',');
            ActivePlayer activePlayer = new ActivePlayer()
            {
                id = new Tuple<int, int>(Int32.Parse(fields[0]), Int32.Parse(fields[1])),
                nrPoints = Int32.Parse(fields[2]),
                Type = fields[3] == "PARTICIPANT" ? Type.PARTICIPANT : Type.RESERVE
            };
            return activePlayer;
        }
    }
}