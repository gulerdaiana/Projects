package social_network.repository.database;

public enum UserField {
    ID, FIRST_NAME, LAST_NAME, EMAIL;

    public String getSqlValue() {
        return switch (this) {
            case ID -> "id";
            case FIRST_NAME -> "first_name";
            case LAST_NAME -> "last_name";
            case EMAIL -> "email";
        };
    }
}
