package social_network.domain;


public class UserDTOFriend {
    private String friendsSince;
    private String first_name;
    private String last_name;
    private long UID;

    public UserDTOFriend(User user,String friendsSince) {
        this.friendsSince = friendsSince;
        String firstName=user.getFirst_name();
        this.first_name = firstName;
        String lastName=user.getLast_name();
        this.last_name = lastName;

        UID= user.getId();
    }

    public long getUID() {
        return UID;
    }

    public String getFriendsSince() {
        return friendsSince;
    }

    public String getFirst_name() {
        return first_name;
    }

    public String getLast_name() {
        return last_name;
    }
}
