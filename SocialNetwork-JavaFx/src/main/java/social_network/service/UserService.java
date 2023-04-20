package social_network.service;


import social_network.Validators.ValidatorType;
import social_network.domain.Friendship;
import social_network.domain.User;
import social_network.exceptions.ValidationException;
import social_network.repository.Repository;

public class UserService extends BaseService<Long, User> {
    private final Repository<Long, Friendship> friendshipRepo;



    /**
     * creates a user
     * @param ID the new user's id
     * @param email the new user's email
     * @param first_name the new user's first name
     * @param last_name the new user's last name
     * @return the new user
     */
    public User getUserID(Long ID,String email,String first_name,String last_name) {
        return new User(ID,first_name,last_name, email);
    }

    public UserService(Repository<Long, User> repository, Repository<Long, Friendship> friendshipRepo) {
        super(ValidatorType.USER, repository);
        this.friendshipRepo = friendshipRepo;
    }



    /**
     * creates a new instance of the user and adds it to the repo
     * @param ID the id of the user
     * @param email the email of the user
     * @param first_name the first name of the user
     * @param last_name the last name of the user
     * @throws ValidationException if the user is invalid
     */
    //!!!!!!!!!!!!!!!!!
    public void addUserID(Long ID, String email, String first_name, String last_name) throws ValidationException {
        User user = getUserID(ID,email, first_name, last_name);
        super.addEntity(user);
    }

    /**
     * Removes a user and the removes all the friendships related to him
     * @param userId the id of the removed user
     * @return the removed user
     */
    @Override
    public Long deleteEntity(Long userId) {
        Long deletedId = super.deleteEntity(userId);
        friendshipRepo.findAll()
                .forEach(friendship -> {
                    if (friendship.getIdUser1().equals(userId) || friendship.getIdUser2().equals(userId)) {
                        friendshipRepo.delete(friendship.getId());
                    }
                });
        return deletedId;
    }
    public User searchUtilizator(String email){
        return repository.findOne_email(email);
    }

    public User searchUtilizator_id(Long id){
        return repository.findOne(id);
    }


}
