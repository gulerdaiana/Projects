using LabCSharp.domain;

namespace LabCSharp.validators
{
    public class TeamValidator:Validators<Team>
    {
        public void validate(Team entity)
        {
            /*if (entity.NameT == null || entity.NameT == "")
            {
                throw new ValidationException("Invalid team");
            }*/
        }
    }
}