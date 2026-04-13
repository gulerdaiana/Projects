using LabCSharp.domain;
using LabCSharp.validators;

namespace LabCSharp.repository.FileRepo
{
    public class PlayersFileRepo:FileRepository<int,Player>
    {
        public PlayersFileRepo(Validators<Player> validator, string fileName) : base(validator, fileName, EntityFromFile.CreatePlayer)
        {
        }
    }
}