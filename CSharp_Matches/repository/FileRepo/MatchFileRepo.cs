using LabCSharp.domain;
using LabCSharp.validators;

namespace LabCSharp.repository.FileRepo
{
    public class MatchFileRepo:FileRepository<int,Match>
    {
        public MatchFileRepo(Validators<Match> validator, string fileName) : base(validator, fileName, EntityFromFile.CreateMatch)
        {
        }
    }
}