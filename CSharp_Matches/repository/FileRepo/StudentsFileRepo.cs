using LabCSharp.domain;
using LabCSharp.validators;

namespace LabCSharp.repository.FileRepo
{
    public class StudentsFileRepo:FileRepository<int,Student>
    {
        public StudentsFileRepo(Validators<Student> validator, string fileName) : base(validator, fileName, EntityFromFile.CreateStudent)
        {
        }
    }
}