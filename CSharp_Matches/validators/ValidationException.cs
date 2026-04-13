using System;

namespace LabCSharp.validators
{
    public class ValidationException:ApplicationException
    {
        public ValidationException(String message) : base(message)
        {
        }
    }
}