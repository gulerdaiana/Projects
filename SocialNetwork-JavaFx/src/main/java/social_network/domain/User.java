package social_network.domain;

import java.util.Objects;

/**
 * a class that holds the user's information.
 */
public class User extends Entity<Long> {
    private long ID;
    private String first_name;
    private String last_name;
    private String email;



    public User(Long ID, String first_name,String last_name, String email) {
        this.setId(ID);
        this.first_name = first_name;
        this.last_name = last_name;
        this.email = email;

    }

    public User(String email, String first_name, String last_name) {
        this.email = email;
        this.first_name = first_name;
        this.last_name = last_name;
    }

    /**
     * getter for user's name
     * @return user's name
     */
    public String getFirst_name() {
        return first_name;
    }

    public String getLast_name() {
        return last_name;
    }

    /**
     * getter for user's email
     * @return user's email
     */
    public String getEmail() {
        return email;
    }


    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "User{" +
                "ID=" + ID +
                ", first_name='" + first_name + '\'' +
                ", last_name='" + last_name + '\'' +
                ", email='" + email + '\'' +
                '}';
    }

    /**
     * the definition of when 2 users are considered equals
     * @param o the user to compare to
     * @return true if they are equal, false otherwise
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return ID == user.ID && email.equals(user.email);
    }

    @Override
    public int hashCode() {
        return Objects.hash(ID, email);
    }
}
