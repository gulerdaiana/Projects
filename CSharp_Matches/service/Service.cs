using System;
using System.Collections.Generic;
using System.Linq;
using LabCSharp.domain;
using LabCSharp.repository.MemoryRepo;

namespace LabCSharp.service
{
    public class Service
    {
        private Repository<int, Player> RepoPlayer;
        private Repository<int, Match> RepoMatch;
        private Repository<Tuple<int, int>, ActivePlayer> RepoActivePlayer;

        public Service(Repository<int, Player> repoPlayer, Repository<int, Match> repoMatch, Repository<Tuple<int, int>, ActivePlayer> repoActivePlayer)
        {
            RepoPlayer = repoPlayer;
            RepoMatch = repoMatch;
            RepoActivePlayer = repoActivePlayer;
        }

        public List<Player> findAllPlayers()
        {
            return RepoPlayer.findAll().ToList();
        }

        public List<Player> findPlayersByTeam(string team)
        {
            return RepoPlayer.findAll().Where(x => x.Team.NameT == team).ToList();
        }

        public List<Player> findPlayersByTeamAndMatch(string team, int match)
        {
            List<ActivePlayer> activePlayers = RepoActivePlayer.findAll()
                .Where(x => x.id.Item2 == match && RepoPlayer.findOne(x.id.Item1).Team.NameT == team).ToList();
            List<Player> players = new List<Player>();
            activePlayers.ForEach(x=>players.Add(RepoPlayer.findOne(x.id.Item1)));
            return players;
        }

        public List<Match> findMatchesByDate(DateTime date1, DateTime date2)
        {
            return RepoMatch.findAll().Where(x => x.DateTime.CompareTo(date1) >= 0 && x.DateTime.CompareTo(date2) <= 0)
                .ToList();
        }

        public Match getMatch(int id)
        {
            Match match = new Match();
            try
            {
                match = RepoMatch.findOne(id);
            }
            catch (Exception e)
            {
                return null;
            }

            return match;
        }

        public Tuple<string, string> getTeamByMatch(Match match)
        {
            return new Tuple<string, string>(match.Team1.NameT, match.Team2.NameT);
        }

        public int getScore(Match match, string team)
        {
            return RepoActivePlayer.findAll()
                .Where(x => x.id.Item2 == match.id && RepoPlayer.findOne(x.id.Item1).Team.NameT == team)
                .Sum(x => x.nrPoints);
        }
    }
}