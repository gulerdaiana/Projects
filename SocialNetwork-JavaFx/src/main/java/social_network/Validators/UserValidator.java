package social_network.Validators;


import social_network.domain.User;
import social_network.exceptions.ValidationException;

public class UserValidator extends BaseValidator<User> {
    /**
     * Checks if the user has valid email and name
     *
     * @param user the given user
     * @throws ValidationException if the user is invalid
     */
    @Override
    public void validate(User user) throws ValidationException {
        String text = "";
        text += validateEmail(user.getEmail()) ? "" : "Email is invalid";
        text += validateText(user.getFirst_name()) ? "" : "First name is empty";
        text += validateText(user.getLast_name()) ? "" : "Last name is empty";
        if (!text.isEmpty()) throw new ValidationException(text);
    }
}