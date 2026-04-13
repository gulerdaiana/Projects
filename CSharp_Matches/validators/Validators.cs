namespace LabCSharp.validators
{
    public interface Validators<E>
    {
        void validate(E entity);
    }
}