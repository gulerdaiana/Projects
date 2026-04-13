using LabCSharp.domain;

namespace LabCSharp.validators
{
    public class StudentValidator:Validators<Student>
    {
        public void validate(Student entity)
        {
            /*if (entity.Name == null || entity.Name == "")
            {
                throw new ValidationException("Invalid name");
            }

            if (entity.School == null || entity.School == "")
            {
                throw new ValidationException("Invalid school");
            }*/
        }
    }
}