using System;
using LabCSharp.domain;
using LabCSharp.validators;

namespace LabCSharp.repository.FileRepo
{
    public class ActivePlayersFileRepo:FileRepository<Tuple<int,int>,ActivePlayer>
    {
        public ActivePlayersFileRepo(Validators<ActivePlayer> validator, string fileName) : base(validator, fileName, EntityFromFile.CreateActivePlayer)
        {
        }
    }
}