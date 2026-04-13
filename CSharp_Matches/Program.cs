using System;
using LabCSharp.domain;
using LabCSharp.repository.FileRepo;
using LabCSharp.repository.MemoryRepo;
using LabCSharp.service;
using LabCSharp.ui;
using LabCSharp.validators;

namespace LabCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Validators<Player> validPlayer = new PlayerValidator();
            Validators<Match> validMatch = new MatchValidator();
            Validators<ActivePlayer> validActivePlayer = new ActivePlayerValidator();
            Repository<int, Player> repoPlayer = new PlayersFileRepo(validPlayer, "/Users/daianaguler/Desktop/LabCSharp/players.txt");
            Repository<int, Match> repoMatch = new MatchFileRepo(validMatch, "/Users/daianaguler/Desktop/LabCSharp/matches.txt");
            Repository<Tuple<int,int>, ActivePlayer> repoActivePlayer= new ActivePlayersFileRepo(validActivePlayer, "/Users/daianaguler/Desktop/LabCSharp/activePlayers.txt");
            Service service = new Service(repoPlayer, repoMatch, repoActivePlayer);
            UI console = new UI(service);
            console.run();
        }
    }
}