using System;
using LabCSharp.domain;

namespace LabCSharp.validators
{
    public class MatchValidator : Validators<Match>
    {
        public void validate(Match entity)
        {
            /*if (entity.DateTime > DateTime.Now)
            {
                throw new ValidationException("Invalid date");
            }*/
        }
    }
}