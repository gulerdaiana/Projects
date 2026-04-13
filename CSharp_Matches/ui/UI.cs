using System;
using System.Collections.Generic;
using LabCSharp.domain;
using LabCSharp.service;

namespace LabCSharp.ui
{
    public class UI
    {
        private Service service;

        public UI(Service service)
        {
            this.service = service;
        }

        public void Menu()
        {
            System.Console.WriteLine("1.Players by team");
            System.Console.WriteLine("2.Active players by match");
            System.Console.WriteLine("3.Matches from a time period");
            System.Console.WriteLine("4.Score from a match");
            System.Console.WriteLine("0.Exit");
        }

        public void UIPlayersTeam()
        {
            System.Console.WriteLine("Team:");
            string team = System.Console.ReadLine();
            List<Player> players = service.findPlayersByTeam(team);
            players.ForEach(x=>System.Console.WriteLine(x));
        }

        public void UIActPlayersTeamMatch()
        {
            System.Console.WriteLine("Team:");
            string team = System.Console.ReadLine();
            System.Console.WriteLine("Id match:");
            int idMatch=Int32.Parse(System.Console.ReadLine());
            List<Player> players = service.findPlayersByTeamAndMatch(team, idMatch);
            players.ForEach(x=>System.Console.WriteLine(x));
        }

        public void UIMatchDate()
        {
            System.Console.WriteLine("First date:");
            DateTime date1 = DateTime.ParseExact(System.Console.ReadLine(),"dd/MM/yyyy",null);
            System.Console.WriteLine("Second date:");
            DateTime date2 = DateTime.ParseExact(System.Console.ReadLine(),"dd/MM/yyyy",null);
            List<Match> matches = service.findMatchesByDate(date1, date2);
            matches.ForEach(x=>System.Console.WriteLine(x));
        }

        public void UIMatchScore()
        {
            System.Console.WriteLine("Id match:");
            int idMatch=Int32.Parse(Console.ReadLine());
            Match match = service.getMatch(idMatch);
            Tuple<string, string> teams = service.getTeamByMatch(match);
            string team1 = teams.Item1;
            string team2 = teams.Item2;
            int score1 = service.getScore(match, team1);
            int score2 = service.getScore(match, team2);
            Console.WriteLine(team1+"  "+score1+" VS "+score2+"  "+team2);
        }

        public void run()
        {
            while (true)
            {
                Menu();
                System.Console.WriteLine("Select option:");
                string opt = System.Console.ReadLine();
                switch (opt)
                {
                    case "1":UIPlayersTeam();
                        break;
                    case "2":UIActPlayersTeamMatch();
                        break;
                    case "3":UIMatchDate();
                        break;
                    case "4":UIMatchScore();
                        break;
                    case "0": return;
                    default:System.Console.WriteLine("Invalid option");
                        break;
                }
            }
        }
    }
}